#include <napi.h>

using namespace Napi;

String Hello(const CallbackInfo& info)
{
    Env env = info.Env();

    return String::New(env, "world");
}

Object Init(Env env, Object exports)
{
    exports.Set(String::New(env, "hello"), Function::New(env, Hello));

    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)
