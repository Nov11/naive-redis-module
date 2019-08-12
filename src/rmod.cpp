#include <naive_redis_module/redismodule.h>
#include <cstdlib>

int Rand_RedisCommand(RedisModuleCtx *ctx, RedisModuleString **argv, int argc) {
    RedisModule_ReplyWithLongLong(ctx, rand());
    return REDISMODULE_OK;
}

int Echo_RedisCommand(RedisModuleCtx *ctx, RedisModuleString **argv, int argc) {
    if (argc <= 1) {
        return RedisModule_WrongArity(ctx);
    }

    RedisModule_AutoMemory(ctx);

    RedisModule_ReplyWithArray(ctx, argc - 1);
    for (int i = 1; i < argc; i++) {
        RedisModule_ReplyWithString(ctx, argv[i]);
    }

    return REDISMODULE_OK;
}

extern "C" int RedisModule_OnLoad(RedisModuleCtx *ctx, RedisModuleString **argv, int argc) {
    if (RedisModule_Init(ctx, "rmod_module", 1, REDISMODULE_APIVER_1) == REDISMODULE_ERR)
        return REDISMODULE_ERR;

    if (RedisModule_CreateCommand(ctx, "rmod.rand", Rand_RedisCommand, "readonly fast", 1, 1, 1) == REDISMODULE_ERR)
        return REDISMODULE_ERR;

    if (RedisModule_CreateCommand(ctx, "rmod.echo", Echo_RedisCommand, "readonly fast", 1, 1, 1) == REDISMODULE_ERR)
        return REDISMODULE_ERR;


    return REDISMODULE_OK;
}