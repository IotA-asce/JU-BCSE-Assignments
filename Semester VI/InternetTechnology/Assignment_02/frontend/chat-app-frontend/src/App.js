import React from 'react';
import {
  BrowserRouter,
  Routes,
  Route
} from 'react-router-dom';


import './App.css';
import SignInSide from './components/SignInSide.js';
import Chat from './components/Chat';

function App() {
  return (
    <div className="App">
      <BrowserRouter >
        <Routes>
          <Route path="/" element={<SignInSide />} />
          <Route path="chat" element={<Chat />} />
          <Route path="*" element={<>error 404</>} /> 
        </Routes>
      </BrowserRouter>
    </div>
  )
}

export default App;
