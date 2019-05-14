var example_c = require('bindings')('example_c');
var example_cc = require('bindings')('example_cc');

console.log(example_c.add(3, 2));

example_c.test((arg) => {
    console.log(arg)
});

console.log(example_cc.hello());
