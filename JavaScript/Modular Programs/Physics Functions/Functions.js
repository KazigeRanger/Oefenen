const constants = require("./Constants.js");
class ClassicalMechanicsObject {
    calculateNettoForce(mass, acceleration) {
        return mass*acceleration;
    }

    calculateEarthGravitationalForce(mass) {
        const g = constants.gravitationalAcceleration; // The gravitational acceleration on earth
        return g*mass;
    }

    calculateGravitationalForce(firstObjectMass, secondObjectMass, distance) {
        const G = constants.gravitationalConstant;
        return (G*firstObjectMass*secondObjectMass)/Math.pow(distance, 2);
    }

    calculateSpeed(deltaDistance, deltaTime) {
        return deltaDistance/deltaTime;
    }

    calculateWork(force, distance) {
        return force*distance;
    }

    calculateKineticEnergy(mass, velocity) {
        return 0.5*mass*Math.pow(velocity, 2);
    }

    calculateEarthGravitationalEnergy(mass, height) {
        const g = constants.gravitationalAcceleration;
        return mass*g*height;
    }

    
}

module.exports = ClassicalMechanicsObject;
