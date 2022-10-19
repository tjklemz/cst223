# Communicating over the Web

## Preliminary

If you're on Windows, I _highly_ recommend you take the time to set up WSL2. You can follow the instructions here: https://learn.microsoft.com/en-us/windows/wsl/install

And be sure to install the Windows Terminal app from the Microsoft App Store once that's done.

## JSON

A big reason we're able to use multiple languages is because we can share data language agnostically.

The primary format these days is JSON:  JavaScript Object Notation.

As you can see from the name, JavaScript has left its mark!

JSON is simpler than JS and is only concerned with representing simple data (no lambdas, etc).

Here is an example JSON:
```json
{
  "name": "bob",
  "age": 23,
  "hobbies": ["linux", "reading", "skydiving"]
}
```

As you can see, it's a Bag (a hashmap/object/dictionary/record). Each key needs to be wrapped in double-quotes, unlike full JS which is quite lax.

## Server

Let's set up an example server. In this directory, you'll see we have a `package.json`. This tells Node and NPM that it's ok to install `node_modules` here (code from the NPM repository).

Assuming you have the latest Node (v19) installed, run in a terminal in this directory:
```bash
npm i
```
and then:
```bash
node --watch index.js
```

If the `--watch` flag doesn't work, you can omit that and only run `node index.js`.

This starts a server on `localhost:3000`. A server is simply code listening for outside connections/requests. It does not, contrary to popular belief, require special equipment. Google famously ran some servers with super cheap consumer computers.

We are looking at the context of the Web (the internet), and so we're for now only looking at the HTTP protocol to keep things simple. Do be aware that other protocols exist, but of course HTTP is the most ubiquitous since we use that when visiting websites. And it turns out that we use that for APIs. This server is serving up a simple API for us.

## Client

Go to your web browser and type in: `http://localhost:3000` and then try `http://localhost:3000/posts`. You should see something on the page. If so, the server is working!

Let's try it programmatically. In another terminal (so that the server can stay running), open a Node REPL by typing:
```bash
node --experimental-fetch
```

This will allow us to play around with the requests. (You could also use cURL, a common tool.)

In that REPL, try:
```js
await fetch('http://localhost:3000/posts').then(data => data.json())
```

You should see some data returned. If so, congrats! You just programmatically retrieved data from a server.

Try giving it some data:
```js
const options = {method: 'POST', headers: {'Content-Type': 'application/json'}}
const data = {post: 'yay! another post!'}
await fetch('http://localhost:3000/posts', {...options, body: JSON.stringify(data) })
```

You should see it output a bunch of things. To see if it worked, try retrieving the posts again (you could hit the up-arrow a couple times to get the previous thing you typed):
```js
await fetch('http://localhost:3000/posts').then(data => data.json())
```

That should return the list of posts.

Notice how you can retrieve them from the web browser. That is, the data is on the server. It doesn't matter where the client is.

If you restart the server, we haven't persisted the data to a database. So it will reset to the initial data.
