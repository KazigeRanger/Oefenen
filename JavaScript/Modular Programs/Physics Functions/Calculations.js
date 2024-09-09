const constants = require("./Constants.js");
// const ClassicalMechanicsObject = require("./Functions.js");
const functions = require("./BinasFunctions.js");

const vibrationalObject = new functions.VibrationsWavesOptics.Vibrations();

console.log(vibrationalObject.calculatePeriod(5));

