#include <stdio.h>
#include <stdint.h>
typedef struct {
    size_t count;
    size_t by;
} Counter;

typedef struct {} Spawner;

#define ECS_IMPL_COMPONENTS(DO) \
    DO(Counter) \
    DO(Spawner)

#include "ecs.h"


ECS_SYSTEM(spawner, (Spawner, s))
{
    Entity e = world_create_entity(world);
    entity_add_component(Counter)(world, e, (Counter){0, 1});
    printf("Spawning Entity %u\n", e);
}

ECS_SYSTEM_DEPENDS(counter, ECS_BEFORE(debug_counter), ECS_AFTER(spawner), (Counter, c))
{
    c->count += c->by;
}

ECS_SYSTEM_DEPENDS(debug_counter, ECS_BEFORE(), ECS_AFTER(counter_destroyer), (Counter, c))
{
    printf("e%u: Count: %lu\n", this, c->count);
}

ECS_SYSTEM_DEPENDS(counter_destroyer, ECS_BEFORE(debug_counter), ECS_AFTER(counter), (Counter, c))
{
    if (c->count >= 5)
    {
        printf("Destroying Counter with eid: %d\n", this);
        entity_destroy(world, this);
    }
}

int main(){
    
    World w = world_init();

    {
        Entity e = world_create_entity(&w);
        entity_add_component(Spawner)(&w, e, (Spawner){});
    }

    for (int i = 0; i < 10; i++)
    {
        world_run(&w);
    }
}