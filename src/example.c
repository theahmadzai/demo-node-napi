#include <assert.h>
#include <node_api.h>

napi_value add(napi_env env, const napi_callback_info info)
{
    napi_status status;

    size_t argc = 2;
    napi_value argv[2];
    status = napi_get_cb_info(env, info, &argc, argv, NULL, NULL);
    assert(status == napi_ok);

    int numbers[2];
    if (napi_get_value_int32(env, argv[0], &numbers[0]) != napi_ok || napi_get_value_int32(env, argv[1], &numbers[1]) != napi_ok) {
        napi_throw_error(env, NULL, "Invalid number was passed as argument");
    }

    napi_value result;
    int number = numbers[0] + numbers[1];
    status = napi_create_int32(env, number, &result);
    assert(status == napi_ok);

    return result;
}

napi_value test(napi_env env, const napi_callback_info info)
{
    napi_status status;

    size_t argc = 1;
    napi_value cb;
    status = napi_get_cb_info(env, info, &argc, &cb, NULL, NULL);
    assert(status == napi_ok);

    napi_value argv[1];
    status = napi_create_string_utf8(env, "Hello World!", NAPI_AUTO_LENGTH, argv);
    assert(status == napi_ok);

    napi_value global;
    status = napi_get_global(env, &global);
    assert(status == napi_ok);

    napi_value result;
    status = napi_call_function(env, global, cb, 1, argv, &result);
    assert(status == napi_ok);

    return NULL;
}

napi_value Init(napi_env env, napi_value exports)
{
    napi_status status;

    /**
      Binding for add function
  */
    napi_value add_r;
    status = napi_create_function(env, NULL, 0, add, NULL, &add_r);
    assert(status == napi_ok);
    status = napi_set_named_property(env, exports, "add", add_r);
    assert(status == napi_ok);

    /**
      Binding for test function
  */
    napi_value test_r;
    status = napi_create_function(env, NULL, 0, test, NULL, &test_r);
    assert(status == napi_ok);
    status = napi_set_named_property(env, exports, "test", test_r);
    assert(status == napi_ok);

    return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
