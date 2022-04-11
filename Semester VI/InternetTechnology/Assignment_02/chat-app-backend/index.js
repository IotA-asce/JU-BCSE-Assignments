// const express = require('express');
// const socketio = require('socket.io')
// const http = require('http');
// const cors = require('cors');

// // const PORT = process.env.PORT || 8080;
// const PORT = 8080;
// const router = require('./router');

// const app = express();
// const server = http.createServer(app);
// const io = socketio(server);
// // const io = socketio(server);


// io.on('connection', (socket) => {
//     console.log('we have a new connection!!');

//     socket.on('join', ({name, room}) => {
//         console.log(name, room);
//     })

//     socket.on('disconnect', () => {
//         console.log('user left');
//     })
// });

// app.use(router);

// server.listen(PORT, () => {
//     console.log(`server has started on port : ${PORT}`);
// });


var app = require('express')();
var http = require('http').createServer(app);
const PORT = 8080;
var io = require('socket.io')(http);

const STATIC_CHANNELS = ['global_notifications', 'global_chat'];

http.listen(PORT, () => {
    console.log(`listening on *:${PORT}`);
});

io.on('connection', (socket) => { /* socket object may be used to send specific messages to the new connected client */
    console.log('new client connected');
    socket.emit('connection', null);
});