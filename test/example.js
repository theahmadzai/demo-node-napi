var example = require('bindings')('example');

console.log(example.add(3, 2));

example.test((arg) => {
    console.log(arg)
});
