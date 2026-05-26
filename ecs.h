#ifndef ECS_H_
#define ECS_H_

#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>

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
static void __ecs_component_storage_free(
    __ECS_ComponentStorage *s
);
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
    const __ECS_ComponentStorage* components,
    const Entity entity,
    const __ECS_ComponentID *query,
    const uint32_t query_count
);

// ############################# QUERY ##############################

// ########################### COMMANDS #############################
typedef enum {
    __ECS_COMMAND_DESTORY_ENTITY,
    __ECS_COMMAND_ADD_COMPONENT,
    __ECS_COMMAND_REMOVE_COMPONENT,
} __ECS_CommandKind;

typedef struct {
    __ECS_CommandKind kind;
    Entity entity;
    size_t data_size;
} __ECS_Command;

typedef struct {
    uint8_t* buffer;
    size_t size;
    size_t capacity;
    size_t start;

    Entity next_entity;
} __ECS_CommandBuffer;

#define __ECS_ENTITY_DEFERRED_BIT (0x80000000u)

static Entity __ecs_make_deferred_entity(uint32_t local_index);
static int __ecs_entity_is_deferred(Entity e);
static uint32_t __ecs_entity_deferred_index(Entity e);

#define cmd_entity_add_component(ty) cmd_entity_add_component_##ty
#define cmd_entity_remove_component(ty) cmd_entity_remove_component_##ty

static Entity cmd_create_entity(__ECS_CommandBuffer* cmd);
static void   cmd_destroy_entity(__ECS_CommandBuffer* cmd, Entity e);
void* __ecs_command_buffer_pop(__ECS_CommandBuffer* cb, size_t size);
void __ecs_command_buffer_push(__ECS_CommandBuffer* cb, void* data, size_t len);
void __ecs_command_buffer_create_entity(__ECS_CommandBuffer* cb, Entity e);
void __ecs_command_buffer_destroy_entity(__ECS_CommandBuffer* cb, Entity e);
void __ecs_command_buffer_add_component(
    __ECS_CommandBuffer* cb, 
    Entity e, 
    __ECS_ComponentID id, 
    void* component_data, 
    size_t component_size
);
void __ecs_command_buffer_remove_component(
    __ECS_CommandBuffer* cb, 
    Entity e, 
    __ECS_ComponentID id
);
void __ecs_command_handle(World* world, __ECS_Command cmd, __ECS_CommandBuffer* cb, Entity* resolved, size_t len);
void __ecs_command_buffer_drain(World* world, __ECS_CommandBuffer* cb);
void __ecs_command_buffer_free(__ECS_CommandBuffer* cb);
// ########################### COMMANDS #############################

// ############################ WORLD ###############################
#define __ECS_COMPONENT_ID(ty) COMPONENT_ID_##ty
void __ecs_world_destory_entity_immediate(World* world, Entity e);
// ############################ WORLD ###############################

// ############################ SYSTEM ###############################
typedef void(*__ECS_SystemFn)(World*, __ECS_CommandBuffer*);

typedef struct {
    const __ECS_SystemFn system_fn;
    __ECS_CommandBuffer cmd;
    World* world;
} __ECS_SystemJob;
typedef struct {
    const char** names;
    const size_t count;
} __ECS_SystemDependencyListBefore;
typedef struct {
    const char** names;
    const size_t count;
} __ECS_SystemDependencyListAfter;

typedef struct {
    const char * system_name;
    const __ECS_SystemFn system_fn;
    const __ECS_ComponentID* system_query;
    const size_t query_len;
    const __ECS_ComponentID* system_dependencies;
    const size_t dependencies_len;
    const __ECS_SystemDependencyListBefore deps_before;
    const __ECS_SystemDependencyListAfter deps_after;
    pthread_t* const thread;
    __ECS_SystemJob* const job;
} __ECS_SystemDescription;

typedef struct {
    const __ECS_SystemDescription** systems;
    uint32_t count;
} __ECS_ScheduleBatch;

typedef struct {
    __ECS_ScheduleBatch* batches;
    uint32_t count;
} __ECS_Schedule;

typedef enum {
    __ECS_SCHEDULE_OK,
    __ECS_SCHEDULE_ERROR_OUT_OF_MEMORY,
    __ECS_SCHEDULE_ERROR_MISSING_DEPENDENCY,
    __ECS_SCHEDULE_ERROR_CYCLE,
} __ECS_ScheduleResult;

#define __ECS_SECTION __attribute__((section("__ECS_SYSTEM"), used, aligned(sizeof(void *))))
#define __ECS_ARRAY_COUNT(x) ((sizeof(x)) / sizeof(x[0]))
#define __ECS_STRINGIFY_ARG(x) #x
#define __ECS_CREATE_DEP_NAMES(...) (const char *[]){                                  \
        __VA_OPT__(__ECS_FOR_EACH_COMMA(__ECS_STRINGIFY_ARG, __VA_ARGS__),)            \
        NULL                                                                           \
    }
#define __ECS_CREATE_DEP_COUNT(...) 0 __VA_OPT__(+ __ECS_ARRAY_COUNT((const char *[]){ \
        __ECS_FOR_EACH_COMMA(__ECS_STRINGIFY_ARG, __VA_ARGS__)                         \
    }))
#define ECS_BEFORE(...)                                                                \
    ((__ECS_SystemDependencyListBefore){                                                \
        .names = __ECS_CREATE_DEP_NAMES(__VA_ARGS__),                                  \
        .count = __ECS_CREATE_DEP_COUNT(__VA_ARGS__)                                   \
    })
#define ECS_AFTER(...)                                                                 \
    ((__ECS_SystemDependencyListAfter){                                               \
        .names = __ECS_CREATE_DEP_NAMES(__VA_ARGS__),                                  \
        .count = __ECS_CREATE_DEP_COUNT(__VA_ARGS__)                                   \
    })

#define COMP(ty, ident) (COMP, ty, ident)
#define RES(ty, ident)  (RES, ty, ident)
#define COMMANDS(ident) (CMDS, __ECS_CommandBuffer, ident)

#define __ECS_QUERY_ITEM_SIGNATURE(query, ty, ident) __ECS_QUERY_ITEM_SIGNATURE_##query(ty, ident)
#define __ECS_QUERY_ITEM_SIGNATURE_COMP(ty, ident) ty* ident,
#define __ECS_QUERY_ITEM_SIGNATURE_RES(ty, ident) ty* ident,
#define __ECS_QUERY_ITEM_SIGNATURE_CMDS(ty, ident) ty* ident,

#define __ECS_ADD_QUERY_ITEM_TO_SIGNATURE(query_item) __ECS_QUERY_ITEM_SIGNATURE query_item 
#define __ECS_SYSTEM_IMPL_SIGNATURE(name, ...)          \
    static void name##_impl(__ECS_FOR_EACH(__ECS_ADD_QUERY_ITEM_TO_SIGNATURE, __VA_ARGS__) Entity self)

#define __ECS_GET_QUERY_ID_IMPL(query, ty, ident) __ECS_GET_QUERY_ID_##query (ty)
#define __ECS_GET_QUERY_ID_COMP(ty) __ECS_COMPONENT_ID(ty),
#define __ECS_GET_QUERY_ID_RES(ty)
#define __ECS_GET_QUERY_ID_CMDS(ty) 

#define __ECS_GET_QUERY_ID(ty_ident) __ECS_GET_QUERY_ID_IMPL ty_ident 
#define __ECS_GENERATE_QUERY_LIST(name, ...)            \
    static const __ECS_ComponentID name##_query[] = {   \
        __ECS_FOR_EACH(__ECS_GET_QUERY_ID, __VA_ARGS__) \
    }

#define __ECS_GET_DEPENDENCY_ID_IMPL(query, ty, ident) __ECS_GET_DEPENDENCY_ID_##query (ty)
#define __ECS_GET_DEPENDENCY_ID_COMP(ty) __ECS_COMPONENT_ID(ty),
#define __ECS_GET_DEPENDENCY_ID_RES(ty)  __ECS_COMPONENT_ID(ty),
#define __ECS_GET_DEPENDENCY_ID_CMDS(ty) 
#define __ECS_GET_DEPENDENCY_ID(ty_ident) __ECS_GET_DEPENDENCY_ID_IMPL ty_ident 
#define __ECS_GENERATE_DEPENDENCY_LIST(name, ...)       \
    static const __ECS_ComponentID name##_dependencies[] = {   \
        __ECS_FOR_EACH(__ECS_GET_DEPENDENCY_ID, __VA_ARGS__) \
    }


#define __ECS_GET_QUERY_TYPE(query, ty, ident) (ty*)
#define __ECS_GET_QUERY_STORAGE(query, ty, ident) __ECS_GET_QUERY_STORAGE_##query(ty)
#define __ECS_GET_QUERY_STORAGE_COMP(ty) (ty*)__ecs_component_storage_get(&world->components[__ECS_COMPONENT_ID(ty)], entity),
#define __ECS_GET_QUERY_STORAGE_RES(ty) &world->resource_##ty,
#define __ECS_GET_QUERY_STORAGE_CMDS(ty) command_buffer,
#define __ECS_GET_QUERY_REF(query)                      \
    __ECS_GET_QUERY_STORAGE query

#define ECS_SYSTEM_DEPENDS(name, before, after, ...)                                                     \
    __ECS_SYSTEM_IMPL_SIGNATURE(name, __VA_ARGS__);                                                      \
    __ECS_GENERATE_QUERY_LIST(name, __VA_ARGS__);                                                        \
    __ECS_GENERATE_DEPENDENCY_LIST(name, __VA_ARGS__); \
    static void name(World* world, __ECS_CommandBuffer* command_buffer)                                  \
    {                                                                                                    \
        size_t query_count = sizeof(name##_query) / sizeof(name##_query[0]);                             \
        if (query_count == 0)\
        {\
            return;\
        }\
        const __ECS_ComponentStorage *driver = &world->components[name##_query[0]];                            \
        for (uint32_t i = 1; i < query_count; i++) {                                                     \
            const __ECS_ComponentStorage *candidate = &world->components[name##_query[i]];                     \
            if (candidate->count < driver->count) {                                                      \
                driver = candidate;                                                                      \
            }                                                                                            \
        }                                                                                                \
        for (uint32_t i = 0; i < driver->count; i++) {                                                   \
            Entity entity = driver->entities[i];                                                         \
            if (!__ecs_entity_matches_query(&world->components[0], entity, name##_query, query_count)) { \
                continue;                                                                                \
            }                                                                                            \
            name##_impl(                                                                                 \
                __ECS_FOR_EACH(__ECS_GET_QUERY_REF, __VA_ARGS__)                                   \
                entity                                                                                  \
            );                                                                                           \
        }                                                                                                \
        (void)(command_buffer); \
    }                                                                                                    \
    static pthread_t name##_thread; \
    static __ECS_SystemJob name##_job = { .system_fn = name, }; \
    static const __ECS_SystemDescription name##_desc __ECS_SECTION = {                                   \
        .system_name = #name,                                                                            \
        .system_fn = name,                                                                               \
        .system_query = name##_query, \
        .query_len = __ECS_ARRAY_COUNT(name##_query), \
        .system_dependencies = name##_dependencies, \
        .dependencies_len = __ECS_ARRAY_COUNT(name##_dependencies), \
        .deps_before = before,                                                                           \
        .deps_after = after,                                                                             \
        .thread = &name##_thread, \
        .job = &name##_job, \
    };                                                                                                   \
    __ECS_SYSTEM_IMPL_SIGNATURE(name, __VA_ARGS__)

#define ECS_SYSTEM(name, ...) ECS_SYSTEM_DEPENDS(name, ECS_BEFORE(), ECS_AFTER() __VA_OPT__(,) __VA_ARGS__) 

static int __ecs_find_system_index(
    const __ECS_SystemDescription *systems,
    uint32_t system_count,
    const char *name
);

static __ECS_ScheduleResult __ecs_build_schedule(
    const __ECS_SystemDescription *systems,
    uint32_t system_count,
    __ECS_Schedule *out_schedule
);
void __ecs_schedule_free(__ECS_Schedule* schedule);
static void __ecs_schedule_batch_run(const __ECS_ScheduleBatch* self, World* world);
static void __ecs_schedule_batch_print(const __ECS_ScheduleBatch* self);
// ############################ SYSTEM ###############################


#endif

#if defined(ECS_IMPL_COMPONENTS) && defined (ECS_IMPL_RESOURCES) 
// ############################ WORLD ###############################
#define __ECS_GENERATE_COMPONENT_ID(ty) __ECS_COMPONENT_ID(ty),
enum __ECS_ComponentID_e {
    ECS_IMPL_COMPONENTS(__ECS_GENERATE_COMPONENT_ID)
    ECS_IMPL_RESOURCES(__ECS_GENERATE_COMPONENT_ID)
    __ECS_COMPONENT_ID_COUNT,
};

#define __ECS_GENERATE_COMPONENT_ID_STRINGS(ty) "COMPONENT_ID_" #ty,
const char* __ecs_component_id_names[] = {                                                   
    ECS_IMPL_COMPONENTS(__ECS_GENERATE_COMPONENT_ID_STRINGS)      
    ECS_IMPL_RESOURCES(__ECS_GENERATE_COMPONENT_ID_STRINGS)
};

#define __ECS_ADD_RESROUCE_TO_WORLD(ty) ty resource_##ty;

struct World_s {                                                                             
    __ECS_ComponentStorage components[__ECS_COMPONENT_ID_COUNT];                             
    __ECS_CommandBuffer cmd_buffer;
    Entity next_entity;                                                                      
    __ECS_Schedule schedule;
    ECS_IMPL_RESOURCES(__ECS_ADD_RESROUCE_TO_WORLD)
};

void world_run(World* world)
{
    __ecs_command_buffer_drain(world, &world->cmd_buffer);
    for (uint32_t i = 0; i < world->schedule.count; i++)
    {
        __ECS_ScheduleBatch* batch = &world->schedule.batches[i];
        __ecs_schedule_batch_run(batch, world);
    }
}

void world_init(World* world)
{                                                                       

#define __ECS_INIT_COMPONENT_STORAGE(ty) \
    __ecs_component_storage_init(&world->components[__ECS_COMPONENT_ID(ty)], sizeof(ty));                                    
    ECS_IMPL_COMPONENTS(__ECS_INIT_COMPONENT_STORAGE)
    extern const __ECS_SystemDescription __start___ECS_SYSTEM[];
    extern const __ECS_SystemDescription __stop___ECS_SYSTEM[];

    __ECS_ScheduleResult result = __ecs_build_schedule(__start___ECS_SYSTEM, (__stop___ECS_SYSTEM - __start___ECS_SYSTEM), &world->schedule);
    if (result != __ECS_SCHEDULE_OK)
    {
        printf("Scheduling Error: %d\n", result);
    }
    assert(result == __ECS_SCHEDULE_OK);

    for (uint32_t i = 0; i < world->schedule.count; i++)
    {
        __ecs_schedule_batch_print(&world->schedule.batches[i]);
    }

}

void world_free(World* world)
{
    for (int i = 0; i < __ECS_COMPONENT_ID_COUNT; i++)
    {
        __ecs_component_storage_free(&world->components[i]);
    }

    __ecs_command_buffer_free(&world->cmd_buffer);
    __ecs_schedule_free(&world->schedule);
    
    extern const __ECS_SystemDescription __start___ECS_SYSTEM[];
    extern const __ECS_SystemDescription __stop___ECS_SYSTEM[];

    for (int i = 0; i < (__stop___ECS_SYSTEM - __start___ECS_SYSTEM); i++)
    {
        const __ECS_SystemDescription* sys = &__start___ECS_SYSTEM[i];
        __ecs_command_buffer_free(&sys->job->cmd);
    }

}

static Entity world_create_entity(World* world)
{
    return world->next_entity++;
}

void __ecs_world_destory_entity_immediate(World* world, Entity e)
{
    for (__ECS_ComponentStorage* storage = world->components;
            storage < &world->components[__ECS_COMPONENT_ID_COUNT];
            storage++)
    {
        __ecs_component_storage_remove(storage, e);
    }
}

// ############################ WORLD ###############################

// ############################ STORAGE #############################
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

static void __ecs_component_storage_free(__ECS_ComponentStorage* s)
{
    free(s->components);
    free(s->entities);
    free(s->sparse);
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
    assert(new_entities != NULL);

    void* new_components = NULL;
    if (s->component_size != 0)
    {
        new_components = realloc(
            s->components,
            s->component_size * new_capacity
        );
        assert(new_components != NULL);
    }

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
    const __ECS_ComponentStorage *s,
    Entity entity
) {
    if (!__ecs_component_storage_has(s, entity)) {
        return NULL;
    }

    uint32_t dense_index = s->sparse[entity];

    return (char *)s->components + dense_index * s->component_size;
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
// ############################ STORAGE #############################

// ############################# QUERY ##############################
static bool __ecs_entity_matches_query(                                                      
    const __ECS_ComponentStorage* components,                                                      
    const Entity entity,                                                                           
    const __ECS_ComponentID *query,                                                          
    const uint32_t query_count                                                                     
) {                                                                                          
    for (uint32_t i = 0; i < query_count; i++) {                                             
        if (!__ecs_component_storage_has(                                                    
            &components[query[i]],                                                           
            entity                                                                           
        )) {                                                                                 
            return false;                                                                    
        }                                                                                    
    }                                                                                        
                                                                                                
    return true;                                                                             
}
// ############################# QUERY ##############################

// ########################### COMMANDS #############################
#define __ECS_GENERATE_MODIFY_COMPONENT_FNS(ty)                                                                    \
    void cmd_entity_add_component(ty)(__ECS_CommandBuffer* cmd, Entity e, ty value)                                            \
    {                                                                                                          \
        __ecs_command_buffer_add_component(cmd, e, __ECS_COMPONENT_ID(ty), &value, sizeof(ty)); \
    }                                                                                                          \
    void cmd_entity_remove_component(ty)(__ECS_CommandBuffer* cmd, Entity e)                                                   \
    {                                                                                                          \
        __ecs_command_buffer_remove_component(cmd, e, __ECS_COMPONENT_ID(ty));                  \
    }

ECS_IMPL_COMPONENTS(__ECS_GENERATE_MODIFY_COMPONENT_FNS)

void __ecs_command_buffer_add_component(                                                     
    __ECS_CommandBuffer* cb,                                                                 
    Entity e,                                                                                
    __ECS_ComponentID id,                                                                    
    void* component_data,                                                                    
    size_t component_size                                                                    
)                                                                                            
{                                                                                            
    __ECS_Command cmd = {                                                                    
        .data_size = component_size + sizeof(id),                                            
        .kind = __ECS_COMMAND_ADD_COMPONENT,                                                 
        .entity = e,                                                                         
    };                                                                                       
    __ecs_command_buffer_push(cb, &cmd, sizeof(cmd));                                        
    __ecs_command_buffer_push(cb, &id, sizeof(id));                                          
    __ecs_command_buffer_push(cb, component_data, component_size);                           
}

void __ecs_command_handle(World* world, __ECS_Command cmd, __ECS_CommandBuffer* cb, Entity* resolved, size_t len)          
{

    Entity e = cmd.entity;
    if (__ecs_entity_is_deferred(e))
    {
        e = __ecs_entity_deferred_index(e);
        assert(e < len);
        e = resolved[e];
    }

    switch (cmd.kind)                                                                        
    {
        case __ECS_COMMAND_DESTORY_ENTITY:                                                   
        {                                                                                    
            __ecs_world_destory_entity_immediate(world, e);                         
        }                                                                                    
        break;                                                                               
        case __ECS_COMMAND_ADD_COMPONENT:                                                    
        {                                                                                    
            __ECS_ComponentID* id = __ecs_command_buffer_pop(cb, sizeof(__ECS_ComponentID)); 
            __ECS_ComponentStorage* storage = &world->components[*id];                       
            __ecs_component_storage_add(                                                     
                storage,                                                                     
                e,                                                                  
                __ecs_command_buffer_pop(cb, storage->component_size)                        
            );                                                                               
        }                                                                                    
        break;                                                                               
        case __ECS_COMMAND_REMOVE_COMPONENT:                                                 
        {                                                                                    
            __ECS_ComponentID* id = __ecs_command_buffer_pop(cb, sizeof(__ECS_ComponentID)); 
            __ECS_ComponentStorage* storage = &world->components[*id];                       
            __ecs_component_storage_remove(                                                  
                storage,                                                                     
                e                                                                   
            );                                                                               
        }                                                                                    
        break;                                                                               
        default:                                                                             
            assert(0 && "UNKNOWN COMMAND");                                                  
    }                                                                                        
}
 
Entity* __ecs_command_buffer_prepare_deferred_entities(__ECS_CommandBuffer* cmd, World* world)
{
    Entity* resolved = malloc(sizeof(Entity) * cmd->next_entity);
    assert(resolved != NULL);
    for (Entity i = 0; i < cmd->next_entity; i++)
    {
        resolved[i] = world_create_entity(world);
    }

    return resolved;
}

void __ecs_command_buffer_drain(World* world, __ECS_CommandBuffer* cb)                       
{

    Entity* resolved = __ecs_command_buffer_prepare_deferred_entities(cb, world);
    assert(resolved != NULL);
    while (cb->start < cb->size)
    {
        __ECS_Command* cmd = __ecs_command_buffer_pop(cb, sizeof(__ECS_Command));
        __ecs_command_handle(world, *cmd, cb, resolved, cb->next_entity);
    }

    free(resolved);
    cb->next_entity = 0;
}

void __ecs_command_buffer_remove_component(                                                  
    __ECS_CommandBuffer* cb,                                                                 
    Entity e,                                                                                
    __ECS_ComponentID id                                                                     
)                                                                                            
{                                                                                            
    __ECS_Command cmd = {                                                                    
        .data_size = sizeof(id),                                                             
        .kind = __ECS_COMMAND_REMOVE_COMPONENT,                                              
        .entity = e,                                                                         
    };                                                                                       
    __ecs_command_buffer_push(cb, &cmd, sizeof(cmd));                                        
    __ecs_command_buffer_push(cb, &id, sizeof(id));                                          
}

static Entity __ecs_make_deferred_entity(uint32_t local_index)
{
    return (Entity){ __ECS_ENTITY_DEFERRED_BIT | local_index };
}

static int __ecs_entity_is_deferred(Entity e)
{
    return (e & __ECS_ENTITY_DEFERRED_BIT) != 0;
}

static uint32_t __ecs_entity_deferred_index(Entity e)
{
    return e & ~__ECS_ENTITY_DEFERRED_BIT;
}

static void cmd_destroy_entity(__ECS_CommandBuffer* cmd, Entity e)
{   
    __ecs_command_buffer_destroy_entity(cmd, e);
}

static Entity cmd_create_entity(__ECS_CommandBuffer* cmd)
{
    return __ecs_make_deferred_entity(cmd->next_entity++);
}

void* __ecs_command_buffer_pop(__ECS_CommandBuffer* cb, size_t size)
{
    void* data = &cb->buffer[cb->start];
    cb->start += size;
    return data;
}

void __ecs_command_buffer_push_byte(__ECS_CommandBuffer* cb, uint8_t x)
{
    if (cb->size == cb->capacity) {
        uint32_t new_capacity = cb->capacity ? cb->capacity * 2 : 64;
        uint8_t* new_buffer = realloc(cb->buffer, sizeof(uint8_t) * new_capacity);
        assert(new_buffer != NULL);
        cb->capacity = new_capacity;
        cb->buffer = new_buffer;
    }

    cb->buffer[cb->size++] = x;
}
void __ecs_command_buffer_push(__ECS_CommandBuffer* cb, void* data, size_t len)
{
    uint8_t* xs = data;
    for (size_t i = 0; i < len; i++)
    {
        __ecs_command_buffer_push_byte(cb, xs[i]);
    }
}
void __ecs_command_buffer_destroy_entity(__ECS_CommandBuffer* cb, Entity e)
{
    __ECS_Command cmd = {
        .data_size = 0,
        .kind = __ECS_COMMAND_DESTORY_ENTITY,
        .entity = e,
    };
    __ecs_command_buffer_push(cb, &cmd, sizeof(cmd));
}

void __ecs_command_buffer_free(__ECS_CommandBuffer* cmd)
{
    free(cmd->buffer);
}

// ########################### COMMANDS #############################

// ############################ SYSTEM ###############################
static int __ecs_find_system_index(
    const __ECS_SystemDescription *systems,
    uint32_t system_count,
    const char *name
) {
    for (uint32_t i = 0; i < system_count; i++) {
        if (strcmp(systems[i].system_name, name) == 0) {
            return (int)i;
        }
    }

    return -1;
}

static void* __ecs_system_job(void* arg)
{

    __ECS_SystemJob* job = arg;
    job->system_fn(job->world, &job->cmd);

    return NULL;

}

static void __ecs_schedule_batch_run_multithreaded(const __ECS_ScheduleBatch* self, World* world)
{
    for (uint32_t i = 0; i < self->count; i++)
    {   
        self->systems[i]->job->world = world;
        
        int rc = pthread_create(
            self->systems[i]->thread,
            NULL,
            __ecs_system_job,
            self->systems[i]->job
        );
        assert(rc == 0);
    }
    
    for (uint32_t i = 0; i < self->count; i++) {
        pthread_join(*self->systems[i]->thread, NULL);
    }

    for (uint32_t i = 0; i < self->count; i++) {
        __ecs_command_buffer_drain(world, &self->systems[i]->job->cmd);
    }
}

static void __ecs_schedule_batch_run_singlethreaded(const __ECS_ScheduleBatch* self, World* world)
{
    for (uint32_t i = 0; i < self->count; i++)
    {
        self->systems[i]->system_fn(world, &self->systems[i]->job->cmd);
    }

    for (uint32_t i = 0; i < self->count; i++)
    {
        __ecs_command_buffer_drain(world, &self->systems[i]->job->cmd);
    }
}

static void __ecs_schedule_batch_run(const __ECS_ScheduleBatch* self, World* world)
{
    (self->count >= 2 ? 
        __ecs_schedule_batch_run_multithreaded : 
        __ecs_schedule_batch_run_singlethreaded)(self,world);
}

static const __ECS_SystemDescription* __ecs_schedule_batch_get_system(const __ECS_ScheduleBatch* self, size_t idx)
{
    if (self == NULL) return NULL;
    if (idx >= self->count) return NULL;

    return self->systems[idx];
}

static void __ecs_schedule_batch_print(const __ECS_ScheduleBatch* self)
{
    printf("[");
    for (uint32_t i = 0; i < self->count; i++)
    {
        printf(" %s", self->systems[i]->system_name);
    }
    printf(" ]\n");
}

static const __ECS_ComponentID* __ecs_system_get_dependencies(const __ECS_SystemDescription* self)
{
    if (self == NULL) return NULL;
    return self->system_dependencies;
}

static size_t __ecs_system_get_dependencies_len(const __ECS_SystemDescription* self)
{
    if (self == NULL) return 0;
    return self->dependencies_len;
}

static __ECS_ScheduleResult __ecs_build_schedule(
    const __ECS_SystemDescription *systems,
    uint32_t system_count,
    __ECS_Schedule *out_schedule
) {
    

    out_schedule->batches = NULL;
    out_schedule->count = 0;

    if (system_count == 0) {
        return __ECS_SCHEDULE_OK;
    }

    uint8_t *edges = calloc(system_count * system_count, sizeof(uint8_t));
    uint32_t *in_degree = calloc(system_count, sizeof(uint32_t));
    uint8_t *scheduled = calloc(system_count, sizeof(uint8_t));
    
    __ECS_ScheduleBatch *batches =
        malloc(sizeof(__ECS_ScheduleBatch) * system_count);

    if (!edges || !in_degree || !scheduled || !batches) {
        free(edges);
        free(in_degree);
        free(scheduled);
        free(batches);
        printf("OOM 1\n");
        return __ECS_SCHEDULE_ERROR_OUT_OF_MEMORY;
    }
    
    for (uint32_t i = 0; i < system_count; i++) {
        batches[i].systems = NULL;
        batches[i].count = 0;
    }

#define ECS_ADD_EDGE(from, to)                                      \
    do {                                                           \
        uint32_t __from = (uint32_t)(from);                        \
        uint32_t __to = (uint32_t)(to);                            \
        uint32_t __edge_index = __from * system_count + __to;      \
                                                                   \
        if (!edges[__edge_index]) {                                \
            edges[__edge_index] = 1;                               \
            in_degree[__to]++;                                     \
        }                                                          \
    } while (0)

    for (uint32_t system_index = 0; system_index < system_count; system_index++) {
        const __ECS_SystemDescription* system = &systems[system_index];


        for (uint32_t i = 0; i < system->deps_after.count; i++) {
            int dep_index = __ecs_find_system_index(
                systems,
                system_count,
                system->deps_after.names[i]
            );
            if (dep_index < 0) {
                free(edges);
                free(in_degree);
                free(scheduled);
                free(batches);
                return __ECS_SCHEDULE_ERROR_MISSING_DEPENDENCY;
            }

            /* system after dep => dep -> system */
            ECS_ADD_EDGE(dep_index, system_index);
            do {
                uint32_t __from = (uint32_t)(dep_index);
                uint32_t __to = (uint32_t)(system_index);
                uint32_t __edge_index = __from * system_count + __to;

                if (!edges[__edge_index]) {
                    edges[__edge_index] = 1;
                    in_degree[__to]++;
                }
            } while (0);
        }

        for (uint32_t i = 0; i < system->deps_before.count; i++) {
            int dep_index = __ecs_find_system_index(
                systems,
                system_count,
                system->deps_before.names[i]
            );
            if (dep_index < 0) {
                free(edges);
                free(in_degree);
                free(scheduled);
                free(batches);
                return __ECS_SCHEDULE_ERROR_MISSING_DEPENDENCY;
            }

            /* system before dep => system -> dep */
            ECS_ADD_EDGE(system_index, dep_index);
        }
    }

#undef ECS_ADD_EDGE

    uint32_t scheduled_count = 0;
    uint32_t batch_count = 0;

    while (scheduled_count < system_count) {
        uint32_t ready_count = 0;

        for (uint32_t i = 0; i < system_count; i++) {
            if (!scheduled[i] && in_degree[i] == 0) {
                ready_count++;
            }
        }

        if (ready_count == 0) {
            free(edges);
            free(in_degree);
            free(scheduled);

            for (uint32_t i = 0; i < batch_count; i++) {
                free((void *)batches[i].systems);
            }

            free(batches);

            return __ECS_SCHEDULE_ERROR_CYCLE;
        }


        const __ECS_SystemDescription **ready_systems =
            malloc(sizeof(__ECS_SystemDescription *) * ready_count);

        if (!ready_systems) {
            free(edges);
            free(in_degree);
            free(scheduled);

            for (uint32_t i = 0; i < batch_count; i++) {
                free((void *)batches[i].systems);
            }

            free(batches);
            printf("OOM 2\n");

            return __ECS_SCHEDULE_ERROR_OUT_OF_MEMORY;
        }

        uint32_t out = 0;

        for (uint32_t i = 0; i < system_count; i++) {
            if (!scheduled[i] && in_degree[i] == 0) {
                ready_systems[out++] = &systems[i];
                scheduled[i] = 1;
            }
        }

        batches[batch_count].systems = ready_systems;
        batches[batch_count].count = ready_count;
        batch_count++;

        /*
            Remove outgoing edges from all systems in this batch.

            Important: we remove edges after collecting the whole batch.
            That prevents a system unlocked by another system in the same
            pass from being included in the same batch.
        */
        for (uint32_t r = 0; r < ready_count; r++) {
            const __ECS_SystemDescription *ready = ready_systems[r];

            int from = __ecs_find_system_index(
                systems,
                system_count,
                ready->system_name
            );

            for (uint32_t to = 0; to < system_count; to++) {
                uint32_t edge_index = (uint32_t)from * system_count + to;

                if (edges[edge_index]) {
                    edges[edge_index] = 0;
                    in_degree[to]--;
                }
            }

            scheduled_count++;
        }
    }

    free(edges);
    free(in_degree);
    free(scheduled);

    __ECS_ScheduleBatch *shrunk = realloc(batches, sizeof(__ECS_ScheduleBatch) * batch_count);

    if (shrunk) {
        batches = shrunk;
    }

    out_schedule->batches = batches;
    out_schedule->count = batch_count;

    for (uint32_t i = 0; i < out_schedule->count; i++)
    {
        __ECS_ScheduleBatch* batch = &out_schedule->batches[i];
        
        for (uint32_t sys_idx0 = 0; sys_idx0 < batch->count - 1; sys_idx0++)
        {
            const __ECS_SystemDescription* sys = __ecs_schedule_batch_get_system(batch, sys_idx0);
            const __ECS_ComponentID* sys_dependencies = __ecs_system_get_dependencies(sys);
            const size_t sys_dependencies_len = __ecs_system_get_dependencies_len(sys);
            for (uint32_t sys_idx1 = sys_idx0 + 1; sys_idx1 < batch->count; sys_idx1++)
            {
                const __ECS_SystemDescription* sys2 = __ecs_schedule_batch_get_system(batch, sys_idx1);
                const __ECS_ComponentID* sys2_dependencies = __ecs_system_get_dependencies(sys2);
                const size_t sys2_dependencies_len = __ecs_system_get_dependencies_len(sys2);

                for (uint32_t q1 = 0; q1 < sys_dependencies_len; q1++)
                {
                    for (uint32_t q2 = 0; q2 < sys2_dependencies_len; q2++)
                    {
                        if (sys_dependencies[q1] == sys2_dependencies[q2])
                        {
                            printf("Unspecified dependency between systems `%s` and `%s`.\n", sys->system_name, sys2->system_name);
                            printf("Both utilize component `%s`.\n", __ecs_component_id_names[sys_dependencies[q1]]);
                            assert(0);
                        }
                    }
                }
                

            }
        }

    }

    return __ECS_SCHEDULE_OK;
}

void __ecs_schedule_free(__ECS_Schedule* schedule)
{
    for (uint32_t i = 0; i < schedule->count; i++)
    {
        free(schedule->batches[i].systems);
    }
    free(schedule->batches);
}
// ############################ SYSTEM ###############################

#endif