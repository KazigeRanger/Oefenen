const constants = require("./Constants.js");
const NewtonianPhysicsObject = require("./Functions.js");

// console.log(constants);
// const newtonianBall = new NewtonianPhysicsObject(1); // Creates a new Newtonian physics object with a mass of 1kg

const earth = new NewtonianPhysicsObject(5.97219e24);
const moon = new NewtonianPhysicsObject(7.34767309e22);

const distanceEarthMoon = 384400000; // meters

const earthMoonGravitationalForce = earth.calculateGravitationalForce(earth.mass, moon.mass, distanceEarthMoon);
console.log(earthMoonGravitationalForce);