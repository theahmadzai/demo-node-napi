{
    "targets": [
        {
            "target_name": "example_c",
            "sources": [ "./src/example.c" ],
        },
        {
            "target_name": "example_cc",
            "sources": [ "./src/example.cc" ],
            "cflags!": [ "-fno-exceptions" ],
            "cflags_cc!": [ "-fno-exceptions" ],
            'include_dirs': [
                "<!@(node -p \"require('node-addon-api').include\")"
            ],
            'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ]
        }
    ]
}
