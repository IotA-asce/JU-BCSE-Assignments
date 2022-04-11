import React, { useEffect, useState } from 'react';
import openSocket from 'socket.io-client';
import socketClient from 'socket.io-client'
import queryString from 'query-string';

const Chat = () => {
    const SERVER = 'http://127.0.0.1:8080';
    var socket = socketClient (SERVER);
    
    
    const [name, setName] = useState('');
    const [room, setRoom] = useState('');
    
    
    useEffect(() => {
        socket.on('connection', () => {
            console.log('connected to backend');
        })

        // const socket = io(ENDPOINT);

        // const parsed = queryString.parseUrl(window.location.href).query;
        // setName(parsed.name);
        // setRoom(parsed.room);

        // console.log(socket);
        // socket.emit('Join', {name, room});

    },[socket]);


    return (
        <div>
            <h1>
                yes this is chat
            </h1>
            <p>
                {room}
            </p>
            <p>
                {name}
            </p>
        </div>
    );
};

export default Chat;
