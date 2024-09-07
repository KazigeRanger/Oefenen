const constants = require("./Constants.js");

class RectilinearMotion {
    calculateDisplacement(x1, x2) {
        return Math.max(x1, x2)-Math.min(x1, x2);
    }

    calculateDuration(t1, t2) {
        return Math.max(t1, t2)-Math.min(t1, t2);
    }

    calculateUniformMotionDisplacement(velocity, time) {
        return velocity*time;
    }

    calculateRandomMotionDisplacement(averageVelocity, time) {
        return averageVelocity*time;
    }

    calculateAverageSpeed(distance, time) {
        return distance/time;
    }

    calculateAverageAcceleration(deltaSpeed, time) {
        return deltaSpeed/time;
    }
}

class CircularMotion {
    calculateTraveledOrbit(angle, orbitRadius) {
        return angle*orbitRadius; // Note that the angle should be in radians.
    }

    calculateTraveledAngle(angularVelocity, time) {
        return angularVelocity*time;
    }

    calculateAngularVelocity(rectilinearVelocity, orbitRadius, orbitFrequency) {
        if (arguments.length === 2) {
            return rectilinearVelocity/orbitRadius;
        } else if (arguments.length === 1) {
            orbitFrequency = arguments[0];
            return 2*Math.PI*orbitFrequency;
        } else {
            console.log("Invalid arguments. Either the rectilinear velocity and the orbit radius of the orbit, or the frequency of the orbit need to be passed.")
            return;
        }
    }

    calculateOrbitSpeed(angularVelocity, orbitRadius) {
        return angularVelocity*orbitRadius;
    }

    calculateCentripetalAcceleration(angularVelocity, orbitRadius) {
        return Math.pow(angularVelocity, 2)*orbitRadius;
    }

    calculateCentripetalForce(mass, rectilinearVelocity, orbitRadius) {
        return (mass*Math.pow(rectilinearVelocity, 2))/orbitRadius;
    }
}

class ForceAndMomentum {
    calculateResultantForceWithSummation(forces) {
        return forces.reduce((accumulator, currentValue) => accumulator+currentValue, 0);
    }

    calculateResultantForceWithTheSecondLawOfNewton(mass, acceleration) {
        return mass*acceleration;
    }

    calculateGravitationalForceOnEarth(mass) {
        g = constants.gravitationalAcceleration;
        return mass*g;
    }

    calculateAirResistanceForce(airDensity, smoothnessCoefficient, area, velocity) {
        return 0.5*airDensity*smoothnessCoefficient*area*velocity;
    }

    calculateSpringForce(springCoefficient, displacement) {
        return springCoefficient*displacement;
    }

    calculateMomentum(mass, velocity) {
        return mass*velocity;
    }
}

const Mechanics = {RectilinearMotion, CircularMotion, ForceAndMomentum};
module.exports = Mechanics;
