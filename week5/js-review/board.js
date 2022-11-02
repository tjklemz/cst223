const board = [['-', '-', '-'], ['-', '-', '-'], ['-', '-', '-']]

function addMark(mark, pos) {
  const [x, y] = pos
  board[x][y] = mark
}

function getBoard() {
  return board
}

module.exports = {
  addMark,
  getBoard
}
