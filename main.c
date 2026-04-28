#include <stdio.h>
#include <stdint.h>
#define ECS_IMPL
#include "ecs.h"

typedef struct {
    float x;
    float y;
} Position;

typedef struct {
    float dx;
    float dy;
} Velocity;

typedef struct {
    size_t count;
    size_t by;
} Counter;

typedef struct {
} Spawner;
typedef struct {
} Volatile;

#define COMPONENTS(DO) \
    DO(Position) \
    DO(Velocity) \
    DO(Counter) \
    DO(Spawner) \
    DO(Volatile)

ECS_CREATE_WORLD(COMPONENTS)

ECS_SYSTEM(spawner, (Spawner, s))
{
    Entity e = world_create_entity(world);
    entity_add_component(Counter)(world, e, (Counter){0, e});
    entity_add_component(Volatile)(world, e, (Volatile){});
    printf("Spawning Entity %u\n", e);
}

ECS_SYSTEM(counter, (Counter, c))
{
    c->count += c->by;
}
ECS_SYSTEM(debug_counter, (Counter, c))
{
    printf("e%u: Count: %lu\n", this, c->count);
}

ECS_SYSTEM(counter_destroyer, (Counter, c), (Volatile, v))
{
    if (c->count >= 5)
    {
        printf("e%u: Destroying entity because it's volatile\n", this);
        entity_destroy(world, this);
    }
}

ECS_SYSTEM(debug_volatile, (Volatile, v))
{
    printf("e%u is Volatile\n", this);
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
        printf("===============\n");
    }
}