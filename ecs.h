#ifndef ECS_H_
#define ECS_H_

#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

// ############################ FOR EACH ############################
#define __ECS_EXPAND(x) x

#define __ECS_VA_NARGS_IMPL(                                                                                 \
     _1,  _2,  _3,  _4,  _5,  _6,  _7,  _8,                                                                  \
     _9, _10, _11, _12, _13, _14, _15, _16, N, ...) N

#define __ECS_VA_NARGS(...)                                                                                  \
    __ECS_VA_NARGS_IMPL(__VA_ARGS__,                                                                         \
        16, 15, 14, 13, 12, 11, 10, 9,                                                                       \
         8,  7,  6,  5,  4,  3, 2, 1)

#define __ECS_CAT_IMPL(a, b) a##b
#define __ECS_CAT(a, b) __ECS_CAT_IMPL(a, b)

#define __ECS_FOR_EACH(X, ...)                                                                               \
    __ECS_EXPAND(__ECS_CAT(__ECS_FOR_EACH_, __ECS_VA_NARGS(__VA_ARGS__))(X, __VA_ARGS__))

#define __ECS_FOR_EACH_1(X, a)                                                                               \
    X(a)

#define __ECS_FOR_EACH_2(X, a, ...)                                                                          \
    X(a) __ECS_FOR_EACH_1(X, __VA_ARGS__)

#define __ECS_FOR_EACH_3(X, a, ...)                                                                          \
    X(a) __ECS_FOR_EACH_2(X, __VA_ARGS__)

#define __ECS_FOR_EACH_4(X, a, ...)                                                                          \
    X(a) __ECS_FOR_EACH_3(X, __VA_ARGS__)

#define __ECS_FOR_EACH_5(X, a, ...)                                                                          \
    X(a) __ECS_FOR_EACH_4(X, __VA_ARGS__)

#define __ECS_FOR_EACH_6(X, a, ...)                                                                          \
    X(a) __ECS_FOR_EACH_5(X, __VA_ARGS__)

#define __ECS_FOR_EACH_7(X, a, ...)                                                                          \
    X(a) __ECS_FOR_EACH_6(X, __VA_ARGS__)

#define __ECS_FOR_EACH_8(X, a, ...)                                                                          \
    X(a) __ECS_FOR_EACH_7(X, __VA_ARGS__)

#define __ECS_FOR_EACH_9(X, a, ...)                                                                          \
    X(a) __ECS_FOR_EACH_8(X, __VA_ARGS__)

#define __ECS_FOR_EACH_10(X, a, ...)                                                                         \
    X(a) __ECS_FOR_EACH_9(X, __VA_ARGS__)

#define __ECS_FOR_EACH_11(X, a, ...)                                                                         \
    X(a) __ECS_FOR_EACH_10(X, __VA_ARGS__)

#define __ECS_FOR_EACH_12(X, a, ...)                                                                         \
    X(a) __ECS_FOR_EACH_11(X, __VA_ARGS__)

#define __ECS_FOR_EACH_13(X, a, ...)                                                                         \
    X(a) __ECS_FOR_EACH_12(X, __VA_ARGS__)

#define __ECS_FOR_EACH_14(X, a, ...)                                                                         \
    X(a) __ECS_FOR_EACH_13(X, __VA_ARGS__)

#define __ECS_FOR_EACH_15(X, a, ...)                                                                         \
    X(a) __ECS_FOR_EACH_14(X, __VA_ARGS__)

#define __ECS_FOR_EACH_16(X, a, ...)                                                                         \
    X(a) __ECS_FOR_EACH_15(X, __VA_ARGS__)

#define __ECS_FOR_EACH_COMMA(X, ...)                                                                         \
    __ECS_EXPAND(__ECS_CAT(__ECS_FOR_EACH_COMMA_, __ECS_VA_NARGS(__VA_ARGS__))(X, __VA_ARGS__))

#define __ECS_FOR_EACH_COMMA_1(X, a)                                                                         \
    X(a)

#define __ECS_FOR_EACH_COMMA_2(X, a, ...)                                                                    \
    X(a), __ECS_FOR_EACH_COMMA_1(X, __VA_ARGS__)

#define __ECS_FOR_EACH_COMMA_3(X, a, ...)                                                                    \
    X(a), __ECS_FOR_EACH_COMMA_2(X, __VA_ARGS__)

#define __ECS_FOR_EACH_COMMA_4(X, a, ...)                                                                    \
    X(a), __ECS_FOR_EACH_COMMA_3(X, __VA_ARGS__)

#define __ECS_FOR_EACH_COMMA_5(X, a, ...)                                                                    \
    X(a), __ECS_FOR_EACH_COMMA_4(X, __VA_ARGS__)

#define __ECS_FOR_EACH_COMMA_6(X, a, ...)                                                                    \
    X(a), __ECS_FOR_EACH_COMMA_5(X, __VA_ARGS__)

#define __ECS_FOR_EACH_COMMA_7(X, a, ...)                                                                    \
    X(a), __ECS_FOR_EACH_COMMA_6(X, __VA_ARGS__)

#define __ECS_FOR_EACH_COMMA_8(X, a, ...)                                                                    \
    X(a), __ECS_FOR_EACH_COMMA_7(X, __VA_ARGS__)

#define __ECS_FOR_EACH_COMMA_9(X, a, ...)                                                                    \
    X(a), __ECS_FOR_EACH_COMMA_8(X, __VA_ARGS__)

#define __ECS_FOR_EACH_COMMA_10(X, a, ...)                                                                   \
    X(a), __ECS_FOR_EACH_COMMA_9(X, __VA_ARGS__)

#define __ECS_FOR_EACH_COMMA_11(X, a, ...)                                                                   \
    X(a), __ECS_FOR_EACH_COMMA_10(X, __VA_ARGS__)

#define __ECS_FOR_EACH_COMMA_12(X, a, ...)                                                                   \
    X(a), __ECS_FOR_EACH_COMMA_11(X, __VA_ARGS__)

#define __ECS_FOR_EACH_COMMA_13(X, a, ...)                                                                   \
    X(a), __ECS_FOR_EACH_COMMA_12(X, __VA_ARGS__)

#define __ECS_FOR_EACH_COMMA_14(X, a, ...)                                                                   \
    X(a), __ECS_FOR_EACH_COMMA_13(X, __VA_ARGS__)

#define __ECS_FOR_EACH_COMMA_15(X, a, ...)                                                                   \
    X(a), __ECS_FOR_EACH_COMMA_14(X, __VA_ARGS__)

#define __ECS_FOR_EACH_COMMA_16(X, a, ...)                                                                   \
    X(a), __ECS_FOR_EACH_COMMA_15(X, __VA_ARGS__)

// ############################ FOR EACH ############################

// ############################ STORAGE #############################

typedef struct World_s World;
typedef enum __ECS_ComponentID_e __ECS_ComponentID;

typedef uint32_t Entity;
#define ECS_INVALID_INDEX UINT32_MAX
typedef struct {
    Entity *entities;
    void   *components;

    uint32_t *sparse;

    uint32_t count;
    uint32_t capacity;
    uint32_t sparse_capacity;

    size_t component_size;
} __ECS_ComponentStorage;

static void __ecs_component_storage_init(
    __ECS_ComponentStorage *s,
    size_t component_size
);
static void __ecs_component_storage_free(__ECS_ComponentStorage *s);
static void __ecs_component_storage_reserve_dense(
    __ECS_ComponentStorage *s,
    uint32_t new_capacity
);
static void __ecs_component_storage_reserve_sparse(
    __ECS_ComponentStorage *s,
    uint32_t entity
);
static bool __ecs_component_storage_has(
    const __ECS_ComponentStorage *s,
    Entity entity
);
static void *__ecs_component_storage_get(
    __ECS_ComponentStorage *s,
    Entity entity
);
static const void *__ecs_component_storage_get_const(
    const __ECS_ComponentStorage *s,
    Entity entity
);
static void *__ecs_component_storage_add_uninitialized(
    __ECS_ComponentStorage *s,
    Entity entity
);
static void *__ecs_component_storage_add(
    __ECS_ComponentStorage *s,
    Entity entity,
    const void *component
);
static void __ecs_component_storage_remove(
    __ECS_ComponentStorage *s,
    Entity entity
);

// ############################ STORAGE #############################

// ############################# QUERY ##############################

static bool __ecs_entity_matches_query(
    __ECS_ComponentStorage* components,
    Entity entity,
    const __ECS_ComponentID *query,
    uint32_t query_count
);

// ############################# QUERY ##############################

typedef void(*__ECS_SystemFn)(World*);
typedef struct {
    const char * system_name;
    __ECS_SystemFn system_fn;
    const __ECS_ComponentID* system_query;
    const size_t query_len;
} __ECS_SystemDescription;

#define __ECS_SECTION __attribute__((section("__ECS_SYSTEM"), used))
#define __ECS_COMPONENT_ID(ty) COMPONENT_ID_##ty
#define __ECS_GENERATE_COMPONENT_ID(ty) __ECS_COMPONENT_ID(ty),
#define __ECS_INIT_COMPONENT_STORAGE(ty)                              \
    __ecs_component_storage_init(&world.components[__ECS_COMPONENT_ID(ty)], sizeof(ty));
#define ecs_world_add(ty) __ecs_world_add_##ty
#define __ECS_GENERATE_ADD_COMPONENT_FN(ty) \
    ty* ecs_world_add(ty)(World* world, Entity e, ty value) \
    { \
        __ECS_ComponentStorage* storage = &world->components[__ECS_COMPONENT_ID(ty)]; \
        ty* dest = __ecs_component_storage_add(storage, e, &value); \
        return dest; \
    } 
#define __ECS_GENERATE_COMPONENT_ID_STRINGS(ty) "COMPONENT_ID_" #ty,
#define __ECS_COMPONENT_ID_STRING(ty) __ecs_component_id_names[__ECS_COMPONENT_ID(ty)]

#define ECS_CREATE_WORLD(FOR_EACH_COMPONENT)                          \
    enum __ECS_ComponentID_e {                                        \
        FOR_EACH_COMPONENT(__ECS_GENERATE_COMPONENT_ID)               \
        __ECS_COMPONENT_ID_COUNT,                                     \
    };                                                                \
    struct World_s {                                                  \
        __ECS_ComponentStorage components[__ECS_COMPONENT_ID_COUNT];  \
        Entity next_entity;                                           \
        int TODO;                                                     \
    };                                                                \
    FOR_EACH_COMPONENT(__ECS_GENERATE_ADD_COMPONENT_FN)               \
    const char* __ecs_component_id_names[] = {                        \
        FOR_EACH_COMPONENT(__ECS_GENERATE_COMPONENT_ID_STRINGS)       \
    };                                                                \
    void world_run(World* world)                                      \
    {                                                                 \
        extern const __ECS_SystemDescription __start___ECS_SYSTEM[];  \
        extern const __ECS_SystemDescription __stop___ECS_SYSTEM[];   \
        for (const __ECS_SystemDescription *s = __start___ECS_SYSTEM; \
            s < __stop___ECS_SYSTEM;                                  \
            s++)                                                      \
        {                                                             \
            s->system_fn(world);                                      \
        }                                                             \
    }                                                                 \
    World world_init(void)                                            \
    {                                                                 \
        World world = {0};                                            \
        FOR_EACH_COMPONENT(__ECS_INIT_COMPONENT_STORAGE)              \
        return world;                                                 \
    }                                                                 \
    Entity world_create_entity(World* world)                          \
    {                                                                 \
        return world->next_entity++;                                  \
    }                                                                 \
    static bool __ecs_entity_matches_query(                           \
        __ECS_ComponentStorage* components,                           \
        Entity entity,                                                \
        const __ECS_ComponentID *query,                               \
        uint32_t query_count                                          \
    ) {                                                               \
        for (uint32_t i = 0; i < query_count; i++) {                  \
            if (!__ecs_component_storage_has(                         \
                &components[query[i]],                                \
                entity                                                \
            )) {                                                      \
                return false;                                          \
            }                                                         \
        }                                                             \
                                                                      \
        return true;                                                 \
    }                                                                 \

#define __ECS_GET_COMPONENT_SIGNATURE_IMPL(ty, ident) ty* ident
#define __ECS_GET_COMPONENT_SIGNATURE(ty_ident) __ECS_GET_COMPONENT_SIGNATURE_IMPL ty_ident
#define __ECS_GET_COMPONENT_ID_IMPL(ty, ident) __ECS_GENERATE_COMPONENT_ID(ty)
#define __ECS_GET_COMPONENT_ID(ty_ident) __ECS_GET_COMPONENT_ID_IMPL ty_ident 
#define __ECS_GET_COMPONENT_TYPE(ty, ident) (ty*)
#define __ECS_GET_COMPONENT_STORAGE(ty, ident) &world->components[__ECS_COMPONENT_ID(ty)]
#define __ECS_GET_COMPONENT_REF(ty_ident) \
    __ECS_GET_COMPONENT_TYPE ty_ident \
    __ecs_component_storage_get( __ECS_GET_COMPONENT_STORAGE ty_ident, entity)

#define ECS_SYSTEM(name, ...)                                                                                             \
    static void name##_impl(World* world, Entity this, __ECS_FOR_EACH_COMMA(__ECS_GET_COMPONENT_SIGNATURE, __VA_ARGS__)); \
    static const __ECS_ComponentID name##_query[] = {                                                                     \
        __ECS_FOR_EACH(__ECS_GET_COMPONENT_ID, __VA_ARGS__)                                                               \
    };                                                                                                                    \
    static void name(World* world)                                                                                        \
    {                                                                                                                     \
        size_t query_count = sizeof(name##_query) / sizeof(name##_query[0]);                                              \
        __ECS_ComponentStorage *driver = &world->components[name##_query[0]];                                             \
        for (uint32_t i = 1; i < query_count; i++) {                                                                      \
            __ECS_ComponentStorage *candidate = &world->components[name##_query[i]];                                      \
            if (candidate->count < driver->count) {                                                                       \
                driver = candidate;                                                                                       \
            }                                                                                                             \
        }                                                                                                                 \
        for (uint32_t i = 0; i < driver->count; i++) {                                                                    \
            Entity entity = driver->entities[i];                                                                          \
            if (!__ecs_entity_matches_query(&world->components[0], entity, name##_query, query_count)) {                  \
                continue;                                                                                                 \
            }                                                                                                             \
            name##_impl(                                                                                                  \
                world,                                                                                                    \
                entity,                                                                                                   \
                __ECS_FOR_EACH_COMMA(__ECS_GET_COMPONENT_REF, __VA_ARGS__)                                                \
            );                                                                                                            \
        }                                                                                                                 \
    }                                                                                                                     \
    static const __ECS_SystemDescription name##_desc __ECS_SECTION = {                                                    \
        .system_name = #name,                                                                                             \
        .system_fn = name,                                                                                                \
        .system_query = name##_query,                                                                                     \
        .query_len = sizeof(name##_query) / sizeof(name##_query[0]),                                                      \
    };                                                                                                                    \
    static void name##_impl(World* world, Entity this, __ECS_FOR_EACH_COMMA(__ECS_GET_COMPONENT_SIGNATURE, __VA_ARGS__))

#endif

#ifdef ECS_IMPL

static void __ecs_component_storage_init(
    __ECS_ComponentStorage *s,
    size_t component_size
) {
    s->entities = NULL;
    s->components = NULL;
    s->sparse = NULL;

    s->count = 0;
    s->capacity = 0;
    s->sparse_capacity = 0;

    s->component_size = component_size;
}

static void __ecs_component_storage_free(__ECS_ComponentStorage *s) {
    free(s->entities);
    free(s->components);
    free(s->sparse);

    s->entities = NULL;
    s->components = NULL;
    s->sparse = NULL;

    s->count = 0;
    s->capacity = 0;
    s->sparse_capacity = 0;
    s->component_size = 0;
}

static void __ecs_component_storage_reserve_dense(
    __ECS_ComponentStorage *s,
    uint32_t new_capacity
) {
    if (new_capacity <= s->capacity) {
        return;
    }

    Entity *new_entities = realloc(
        s->entities,
        sizeof(Entity) * new_capacity
    );

    void *new_components = realloc(
        s->components,
        s->component_size * new_capacity
    );

    assert(new_entities != NULL);
    assert(new_components != NULL);

    s->entities = new_entities;
    s->components = new_components;
    s->capacity = new_capacity;
}

static void __ecs_component_storage_reserve_sparse(
    __ECS_ComponentStorage *s,
    uint32_t entity
) {
    if (entity < s->sparse_capacity) {
        return;
    }

    uint32_t old_capacity = s->sparse_capacity;
    uint32_t new_capacity = old_capacity ? old_capacity : 64;

    while (entity >= new_capacity) {
        new_capacity *= 2;
    }

    uint32_t *new_sparse = realloc(
        s->sparse,
        sizeof(uint32_t) * new_capacity
    );

    assert(new_sparse != NULL);

    for (uint32_t i = old_capacity; i < new_capacity; i++) {
        new_sparse[i] = ECS_INVALID_INDEX;
    }

    s->sparse = new_sparse;
    s->sparse_capacity = new_capacity;
}

static bool __ecs_component_storage_has(
    const __ECS_ComponentStorage *s,
    Entity entity
) {
    if (entity >= s->sparse_capacity) {
        return false;
    }

    uint32_t dense_index = s->sparse[entity];

    if (dense_index == ECS_INVALID_INDEX) {
        return false;
    }

    if (dense_index >= s->count) {
        return false;
    }

    return s->entities[dense_index] == entity;
}

static void *__ecs_component_storage_get(
    __ECS_ComponentStorage *s,
    Entity entity
) {
    if (!__ecs_component_storage_has(s, entity)) {
        return NULL;
    }

    uint32_t dense_index = s->sparse[entity];

    return (char *)s->components + dense_index * s->component_size;
}

static const void *__ecs_component_storage_get_const(
    const __ECS_ComponentStorage *s,
    Entity entity
) {
    if (!__ecs_component_storage_has(s, entity)) {
        return NULL;
    }

    uint32_t dense_index = s->sparse[entity];

    return (const char *)s->components + dense_index * s->component_size;
}

static void *__ecs_component_storage_add_uninitialized(
    __ECS_ComponentStorage *s,
    Entity entity
) {
    __ecs_component_storage_reserve_sparse(s, entity);

    if (__ecs_component_storage_has(s, entity)) {
        return __ecs_component_storage_get(s, entity);
    }

    if (s->count == s->capacity) {
        uint32_t new_capacity = s->capacity ? s->capacity * 2 : 64;
        __ecs_component_storage_reserve_dense(s, new_capacity);
    }

    uint32_t dense_index = s->count++;

    s->entities[dense_index] = entity;
    s->sparse[entity] = dense_index;

    return (char *)s->components + dense_index * s->component_size;
}

static void *__ecs_component_storage_add(
    __ECS_ComponentStorage *s,
    Entity entity,
    const void *component
) {
    void *dst = __ecs_component_storage_add_uninitialized(s, entity);
    memcpy(dst, component, s->component_size);
    return dst;
}

static void __ecs_component_storage_remove(
    __ECS_ComponentStorage *s,
    Entity entity
) {
    if (!__ecs_component_storage_has(s, entity)) {
        return;
    }

    uint32_t removed_index = s->sparse[entity];
    uint32_t last_index = s->count - 1;

    Entity moved_entity = s->entities[last_index];

    if (removed_index != last_index) {
        s->entities[removed_index] = s->entities[last_index];

        memcpy(
            (char *)s->components + removed_index * s->component_size,
            (char *)s->components + last_index * s->component_size,
            s->component_size
        );

        s->sparse[moved_entity] = removed_index;
    }

    s->sparse[entity] = ECS_INVALID_INDEX;
    s->count--;
}

#endif