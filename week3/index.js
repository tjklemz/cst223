const express = require('express')

const app = express()

app.use(express.json())

const posts = ['this is my first post']

app.get('/', (req, res) => {
  res.send('Hello world!')
})

app.get('/posts', (req, res) => {
  res.json({posts})
})

app.post('/posts', (req, res) => {
  posts.push(req.body.text)
  res.end()
})

app.listen(3000)
