import * as React from 'react';
import { useState } from 'react';
import { useNavigate } from 'react-router-dom';
import Avatar from '@mui/material/Avatar';
import Button from '@mui/material/Button';
import CssBaseline from '@mui/material/CssBaseline';
import TextField from '@mui/material/TextField';
import Paper from '@mui/material/Paper';
import Box from '@mui/material/Box';
import Grid from '@mui/material/Grid';
import LockOutlinedIcon from '@mui/icons-material/LockOutlined';
import Typography from '@mui/material/Typography';
import { createTheme, ThemeProvider } from '@mui/material/styles';



const theme = createTheme();

export default function SignInSide() {

  const [url, setUrl] = useState('');
  const [room, setRoom] = useState('');
  const [uname, setUname] = useState('');

  let navigate = useNavigate();

  return (
    <ThemeProvider theme={theme}>
      <Grid container component="main" sx={{ height: '100vh' }}>
        <CssBaseline />
        <Grid
          item
          xs={false}
          sm={4}
          md={7}
          sx={{
            backgroundImage: 'url(https://source.unsplash.com/1600x900?nature)',
            backgroundRepeat: 'no-repeat',
            backgroundColor: (t) =>
              t.palette.mode === 'light' ? t.palette.grey[50] : t.palette.grey[900],
            backgroundSize: 'cover',
            backgroundPosition: 'center',
          }}
        />
        <Grid item xs={12} sm={8} md={5} component={Paper} elevation={6} square>
          <Box
            sx={{
              my: 8,
              mx: 4,
              display: 'flex',
              flexDirection: 'column',
              alignItems: 'center',
            }}
          >
            <Avatar sx={{ m: 1, bgcolor: 'secondary.main' }}>
              <LockOutlinedIcon />
            </Avatar>
            <Typography component="h1" variant="h5">
              Sign in
            </Typography>
            <Box 
              component="form" 
              noValidate 
              sx={{ mt: 1 }}>
              <TextField
                margin="normal"
                required
                fullWidth
                id="uname"
                label="Username"
                name="uname"
                autoComplete="off"
                autoFocus
                onChange={(event) => {
                  setUname(event.target.value);
                  setUrl(`/chat?name=${uname}&room=${room}`);
                  
                }}
              />
              <TextField
                margin="normal"
                required
                fullWidth
                name="room"
                label="Room"
                type="room"
                id="room"
                autoComplete="off"
                onChange={(event) => {
                  setRoom(event.target.value);
                  setUrl(`/chat?name=${uname}&room=${room}`);
                }}
              />
              <Button
                type="submit"
                fullWidth
                variant="contained"
                sx={{ mt: 3, mb: 2 }}
                onClick={(event) => {
                  event.preventDefault(); 
                  navigate(url);
                }}
              >
                Sign In
              </Button>
              {url}
            </Box>
          </Box>
        </Grid>
      </Grid>
    </ThemeProvider>
  );
}