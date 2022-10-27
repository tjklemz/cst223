const board = ['x', '-', '-', 'x', 'o', 'o', 'x', 'o', '-']

const isX = items => index => items[index] === 'x'
const hasAllX = combo => combo.every(isX(board))
const winCombos = [[0, 3, 6], [1, 4, 7]]
const hasWin = () => winCombos.some(hasAllX)


