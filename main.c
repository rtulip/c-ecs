#include <stdio.h>
#include <stdint.h>
typedef struct {
    size_t count;
} Counter;

typedef struct {} Spawner;
typedef int Foo;

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    int dx;
    int dy;
} Velocity;

#define ECS_IMPL_COMPONENTS(DO) \
    DO(Counter) \
    DO(Spawner) \
    DO(Velocity) \
    DO(Position)

#define ECS_IMPL_RESOURCES(DO) \
    DO(Foo)

#include "ecs.h"


ECS_SYSTEM(spawner, COMP(Spawner, s), COMMANDS(cmd))
{
    (void)(s);
    (void)(this);
    Entity e = cmd_create_entity(cmd);
    cmd_entity_add_component(Counter)(cmd, e, (Counter){0});
    printf("Spawning Entity 0x%X. Is Deferred: %s\n", e, __ecs_entity_is_deferred(e) ? "Yes" : "No");
}

ECS_SYSTEM(destroyer, COMP(Counter, c), COMMANDS(cmd))
{
    if (c->count == 5)
    {
        cmd_destroy_entity(cmd, this);
    }
}

ECS_SYSTEM_DEPENDS(counter, ECS_BEFORE(debug_counter), ECS_AFTER(spawner), COMP(Counter, c))
{
    (void)(this);
    c->count += 1;
}

ECS_SYSTEM(debug_counter, COMP(Counter, c))
{
    printf("e%u: Count: %lu\n", this, c->count);
}

ECS_SYSTEM(movement, COMP(Position, p), COMP(Velocity, v))
{
    (void)this;
    p->x += v->dx;
    p->y += v->dy;
}

ECS_SYSTEM_DEPENDS(print, ECS_BEFORE(), ECS_AFTER(movement), COMP(Position, p))
{
    printf("Entity[%d]: Position(%d, %d)\n", this, p->x, p->y);
}

int main(){

    World w = {0};
    world_init(&w);

    {
        Entity e = cmd_create_entity(&w.cmd_buffer);
        cmd_entity_add_component(Position)(&w.cmd_buffer, e, (Position){1,2});
        cmd_entity_add_component(Velocity)(&w.cmd_buffer, e, (Velocity){1,-1});
    }

    {
        Entity e = cmd_create_entity(&w.cmd_buffer);
        cmd_entity_add_component(Position)(&w.cmd_buffer, e, (Position){3,3});
        cmd_entity_add_component(Spawner)(&w.cmd_buffer, e, (Spawner){});
    }

    for (int i = 0; i < 10; i++)
    {
        world_run(&w);
    }

    world_free(&w);
}