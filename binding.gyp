{
    "targets": [
        {
            "target_name": "example_c",
            "sources": [ "./src/example.c" ],
        },
        {
            "target_name": "example_cc",
            "sources": [ "./src/example.cc" ],
            'include_dirs': ["<!@(node -p \"require('node-addon-api').include\")"],
            'dependencies': ["<!(node -p \"require('node-addon-api').gyp\")"],
            "cflags!": [ "-fno-exceptions" ],
            "cflags_cc!": [ "-fno-exceptions" ],
            'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ]
        }
    ]
}
