import express from 'express';
import fs from 'fs';

const app = express();

app.use(express.static('public'));

app.get('/', (req, res) => {
  const html = fs.readFileSync('./pages/home.html', 'utf8');
  res.send(html);
});

app.get('/game', (req, res) => {
  const html = fs.readFileSync('./pages/game.html', 'utf8');
  res.send(html);
});

app.listen(3000, () => {
  console.log('Example app listening on port 3000!');
});