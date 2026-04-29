#include <stdio.h>
#include <stdint.h>
typedef struct {
    size_t count;
    size_t by;
} Counter;

typedef struct {} Spawner;
typedef int Foo;

#define ECS_IMPL_COMPONENTS(DO) \
    DO(Counter) \
    DO(Spawner)
#define ECS_IMPL_RESOURCES(DO) \
    DO(Foo)

#include "ecs.h"


ECS_SYSTEM(spawner, COMP(Spawner, s), RES(WorldResource, world_res))
{
    Entity e = world_create_entity(world_res->world);
    entity_add_component(Counter)(world_res->world, e, (Counter){0, 1});
    printf("Spawning Entity %u\n", e);
}

ECS_SYSTEM_DEPENDS(counter, ECS_BEFORE(debug_counter), ECS_AFTER(spawner), COMP(Counter, c))
{
    c->count += c->by;
}

ECS_SYSTEM(debug_counter, COMP(Counter, c))
{
    printf("e%u: Count: %lu\n", this, c->count);
}

int main(){

    printf("%ld\n", sizeof(__ECS_SystemDescription));

    World w = {0};
    world_init(&w);

    {
        Entity e = world_create_entity(&w);
        entity_add_component(Spawner)(&w, e, (Spawner){});
    }

    for (int i = 0; i < 10; i++)
    {
        world_run(&w);
    }
}