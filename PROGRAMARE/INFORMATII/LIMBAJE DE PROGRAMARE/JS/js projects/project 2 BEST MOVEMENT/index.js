let canvas = document.querySelector("canvas");
let c = canvas.getContext("2d");

canvas.width = window.innerWidth;
canvas.height = window.innerHeight;

let character = {
  x: window.innerWidth / 2,
  y: window.innerHeight / 2,
  size: 20,
  color: "blue",
};

let speed = {
  x: 0,
  y: 0,
  acceleration: 4,
  maxSpeed: 100,
};

let pressKey = [];
window.addEventListener("keydown", (event) => {
  if (!pressKey.includes(event.key)) {
    pressKey.push(event.key);
  }
});
window.addEventListener("keyup", (event) => {
  let poz = pressKey.indexOf(event.key);
  pressKey.splice(poz, 1);
});

window.addEventListener("resize", function () {
  canvas.width = window.innerWidth;
  canvas.height = window.innerHeight;
  location.reload(true);
});

function showCharacter() {
  c.clearRect(0, 0, window.innerWidth, window.innerHeight);
  c.beginPath();
  c.arc(character.x, character.y, character.size, 0, Math.PI * 2, true);
  c.stroke();
}

function characterMovement() {
  requestAnimationFrame(characterMovement);

  if (
    pressKey.includes("w") &&
    speed.y > -speed.maxSpeed &&
    pressKey.includes("a") &&
    speed.x > -speed.maxSpeed &&
    pressKey.includes("s") &&
    speed.y < speed.maxSpeed &&
    pressKey.includes("d") &&
    speed.x < speed.maxSpeed
  ) {
  } else if (
    pressKey.includes("w") &&
    speed.y > -speed.maxSpeed &&
    pressKey.includes("a") &&
    speed.x > -speed.maxSpeed &&
    pressKey.includes("s") &&
    speed.y < speed.maxSpeed
  ) {
    speed.x -= speed.acceleration;
  } else if (
    pressKey.includes("a") &&
    speed.x > -speed.maxSpeed &&
    pressKey.includes("s") &&
    speed.y < speed.maxSpeed &&
    pressKey.includes("d") &&
    speed.x < speed.maxSpeed
  ) {
    speed.y += speed.acceleration;
  } else if (
    pressKey.includes("s") &&
    speed.y < speed.maxSpeed &&
    pressKey.includes("d") &&
    speed.x < speed.maxSpeed &&
    pressKey.includes("w") &&
    speed.y > -speed.maxSpeed
  ) {
    speed.x += speed.acceleration;
  } else if (
    pressKey.includes("d") &&
    speed.x < speed.maxSpeed &&
    pressKey.includes("w") &&
    speed.y > -speed.maxSpeed &&
    pressKey.includes("a") &&
    speed.x > -speed.maxSpeed
  ) {
    speed.y -= speed.acceleration;
  } else if (
    pressKey.includes("w") &&
    speed.y > -speed.maxSpeed &&
    pressKey.includes("a") &&
    speed.x > -speed.maxSpeed
  ) {
    speed.y -= 0.6 * speed.acceleration;
    speed.x -= 0.6 * speed.acceleration;
  } else if (
    pressKey.includes("s") &&
    speed.y < speed.maxSpeed &&
    pressKey.includes("a") &&
    speed.x > -speed.maxSpeed
  ) {
    speed.y += 0.6 * speed.acceleration;
    speed.x -= 0.6 * speed.acceleration;
  } else if (
    pressKey.includes("s") &&
    speed.y < speed.maxSpeed &&
    pressKey.includes("d") &&
    speed.x < speed.maxSpeed
  ) {
    speed.y += 0.6 * speed.acceleration;
    speed.x += 0.6 * speed.acceleration;
  } else if (
    pressKey.includes("d") &&
    speed.x < speed.maxSpeed &&
    pressKey.includes("w") &&
    speed.y > -speed.maxSpeed
  ) {
    speed.y -= 0.6 * speed.acceleration;
    speed.x += 0.6 * speed.acceleration;
  } else if (pressKey.includes("w") && speed.y > -speed.maxSpeed) {
    speed.y -= speed.acceleration;
  } else if (pressKey.includes("a") && speed.x > -speed.maxSpeed) {
    speed.x -= speed.acceleration;
  } else if (pressKey.includes("s") && speed.y < speed.maxSpeed) {
    speed.y += speed.acceleration;
  } else if (pressKey.includes("d") && speed.x < speed.maxSpeed) {
    speed.x += speed.acceleration;
  }

  if (character.x < window.innerWidth - character.size && speed.x > 0)
    character.x += speed.x / 10;
  if (character.x > character.size && speed.x < 0) character.x += speed.x / 10;

  speed.x -= speed.x / 40;

  if (character.y < window.innerHeight - character.size && speed.y > 0)
    character.y += speed.y / 10;
  if (character.y > character.size && speed.y < 0) character.y += speed.y / 10;
  speed.y -= speed.y / 40;
  showCharacter();
}

showCharacter();
characterMovement();
