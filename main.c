#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
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
    (void)(self);
    Entity e = cmd_create_entity(cmd);
    cmd_entity_add_component(Counter)(cmd, e, (Counter){0});
}

ECS_SYSTEM(destroyer, COMP(Counter, c), COMMANDS(cmd))
{
    if (c->count == 5)
    {
        cmd_destroy_entity(cmd, self);
    }
}

ECS_SYSTEM_DEPENDS(counter, ECS_BEFORE(debug_counter), ECS_AFTER(spawner), COMP(Counter, c))
{
    (void)(self);
    c->count += 1;
}

ECS_SYSTEM(debug_counter, COMP(Counter, c))
{
    printf("e%u: Count: %lu\n", self, c->count);
}

ECS_SYSTEM(movement, COMP(Position, p), COMP(Velocity, v))
{
    (void)self;
    p->x += v->dx;
    p->y += v->dy;
}

ECS_SYSTEM_DEPENDS(print, ECS_BEFORE(), ECS_AFTER(movement), COMP(Position, p))
{
    printf("Entity[%d]: Position(%d, %d)\n", self, p->x, p->y);
}

int main(){

    srand(12345);

    World w = {0};
    world_init(&w);

    {
        for (int i = 0; i < 10000; i++)
        {
            Entity e = cmd_create_entity(&w.cmd_buffer);
            Position p = {
                .x = rand() % 100,
                .y = rand() % 100,
            };
            Velocity v = {
                .dx = rand() % 100,
                .dy = rand() % 100,
            };
            cmd_entity_add_component(Position)(&w.cmd_buffer, e, p);
            cmd_entity_add_component(Velocity)(&w.cmd_buffer, e, v);
        }

    }

    {
        for (int i = 0; i < 10000; i++)
        {
            Entity e = cmd_create_entity(&w.cmd_buffer);
            cmd_entity_add_component(Spawner)(&w.cmd_buffer, e, (Spawner){});
        }
        
    }

    for (int i = 0; i < 100; i++)
    {
        world_run(&w);
    }

    world_free(&w);
}