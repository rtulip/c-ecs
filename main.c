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
} Counter;

typedef struct {
    enum {
        SHAPE_CIRCLE,
        SHAPE_RECT,
    } kind;
    union {
        float radius;
        struct {
            float width;
            float height;
        } dimensions; 
    };
} Shape; 

#define COMPONENTS(DO) \
    DO(Position) \
    DO(Velocity) \
    DO(Shape) \
    DO(Counter) \

ECS_CREATE_WORLD(COMPONENTS)

ECS_SYSTEM(movement, (Velocity, v), (Position, p))
{
    p->x += v->dx;
    p->y += v->dy;
}

ECS_SYSTEM(counter, (Counter, c))
{
    c->count++;
}

ECS_SYSTEM(friction, (Velocity, v))
{
    if (v->dx > 0.1)
    {
        v->dx -= 0.01;
    }
    else if (v->dx < -0.1)
    {
        v->dx += 0.01;
    }
    else
    {
        v->dx = 0; 
    }

    if (v->dy > 0.1)
    {
        v->dy -= 0.01;
    }
    else if (v->dy < -0.1)
    {
        v->dy += 0.01;
    }
    else
    {
        v->dy = 0; 
    }
}

ECS_SYSTEM(debug_movement, (Velocity, v), (Position, p))
{
    printf("e%u: P: (%f, %f) V: (%f, %f)\n", this, p->x, p->y, v->dx, v->dy);
}

ECS_SYSTEM(debug_counter, (Counter, c))
{
    printf("e%u: C: %lu\n", this, c->count);
}

int main(){
    
    World w = world_init();

    Entity e = world_create_entity(&w);
    ecs_world_add(Position)(&w, e, (Position){.x = 3, .y = 4});
    ecs_world_add(Velocity)(&w, e, (Velocity){.dx = -2, .dy = 1});
    ecs_world_add(Counter)(&w, e, (Counter){3});

    e = world_create_entity(&w);
    ecs_world_add(Position)(&w, e, (Position){0, 0});
    ecs_world_add(Counter)(&w, e, (Counter){0});

    for (int i = 0; i < 3; i++)
    {
        world_run(&w);
    }
    printf("-----------\n");
    ecs_world_add(Velocity)(&w, e, (Velocity){1,1});
    for (int i = 0; i < 3; i++)
    {
        world_run(&w);
    }
    

}