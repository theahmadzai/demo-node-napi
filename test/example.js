const example_c = require('../lib/example_c.js');
const example_cc = require('../lib/example_cc.js');
const assert = require('assert');

/**
 * napi <node_api.h>
 * example_c tests
 */
(function() {
    assert.strictEqual(example_c.add(3, 3), 6, 'Unexpected Result: 6');

    example_c.test((arg) => {
        assert.strictEqual(arg, 'Hello World!', 'Unexpected Result: Hello World!');
    });

    console.log('example_c: All tests passed!');
})();

/**
 * napi <napi.h>
 * example_cc tests
 */
(function() {
    assert.strictEqual(example_cc.hello(), 'world', 'Unexpected Result: world');

    console.log('example_cc: All tests passed!');
})();
