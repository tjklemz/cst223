var users = [{name: 'bob', age: 32}, {name: 'sally', age: 28}]

console.log('mapped:',
  ['bob', 'sally', 'joe'].map(item => item.toUpperCase())
)

console.log('filtered:', [1, 2, 3, 4, 5].filter(x => x % 2 == 0))

var lookup = users.reduce((all, item) => ({...all, [item.name]: item}), {})

console.log('my lookup:', lookup)

console.log('getting bob:', lookup['bob'])

