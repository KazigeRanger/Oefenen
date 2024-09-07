const constants = require("./Constants.js");
const ClassicalMechanicsObject = require("./Functions.js");

const Mechanics = require("./BinasFunctions.js");

// Example use
const mechanicsObject = new Mechanics.ForceAndMomentum();
console.log(mechanicsObject.calculateResultantForceWithSummation([50, 2,-5,10,-35]));

// Example use: calculating the gravitational force between the earth and the moon.
const earthMass = 5.97219e24;
const moonMass = 7.34767309e22;

const earth = new ClassicalMechanicsObject();

const distanceEarthMoon = 384400000; // meters

const earthMoonGravitationalForce = earth.calculateGravitationalForce(earthMass, moonMass, distanceEarthMoon);
// console.log(earthMoonGravitationalForce);