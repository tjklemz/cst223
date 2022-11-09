// Building blocks
// 1. Scalars
// 2. Lists
// 3. Bags
// 4. Lambdas

function forEach(fn, xs) {
  for (let i = 0; i < xs.length; ++i) {
    fn(xs[i])
  }
}

function map(fn, xs) {
  let newItems = []
  forEach(item => {
    newItems.push(fn(item))
  }, xs)
  return newItems
}

function filter(fn, xs) {
  let newItems = []
  forEach(item => {
    if (fn(item)) {
      newItems.push(item)
    }
  }, xs)
  return newItems
}

let nums = [1, 2, 3, 4, 5]
let newNums = filter(x => x % 2 == 0, nums)

