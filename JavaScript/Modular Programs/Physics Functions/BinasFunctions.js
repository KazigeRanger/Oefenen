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

class WorkAndEnergy {
    calculateWork(force, distance) {
        return force*distance;
    }

    calculateKineticEnergy(mass, velocity) {
        return 0.5*mass*Math.pow(velocity, 2);
    }

    calculateGravitationalEnergyOnEarth(mass, height) {
        const g = constants.gravitationalAcceleration;
        return mass*g*height;
    }

    calculateSpringEnergy(springConstant, displacement) {
        return 0.5*springConstant*Math.pow(displacement, 2);
    }

    calculatePower(work, time) {
        return work/time; // Note that work is interchangeable with energy
    }

    calculateEfficiency(usefulEnergy, inputEnergy) {
        return usefulEnergy/inputEnergy; // Note that energy is interchangeable with power
    }

    calculateWindPower(airDensity, area, velocity) {
        return 0.5*airDensity*area*Math.pow(velocity, 3);
    }
}

class Gravitation {
    calculateGravitationalForce(firstObjectMass, secondObjectMass, distance) {
        const G = constants.gravitationalConstant;
        return (G*firstObjectMass*secondObjectMass)/Math.pow(distance, 2);
    }

    calculateGravitationalEnergy(firstObjectMass, secondObjectMass, distance) {
        const G = constants.gravitationalConstant;
        return -(G*firstObjectMass*secondObjectMass)/distance
    }
}

class Deformation {
    calculatePressure(force, area) {
        return force/area;
    }

    calculateStrain(deltaLength, initialLength) {
        return deltaLength/initialLength;
    }

    calculateModulusOfElasticity(tensileStress, strain) {
        return tensileStress/strain;
    }

    calculateTensileStress(force, area) {
        return force/area;
    }

    calculateSpringConstant(force, displacement) {
        return force/displacement;
    }
}

class StaticsAndRotation {
    calculateGeneralMomentOfInertiaBySummation(masses, radiuses) {
        if (masses.length !== radiuses.length) {
            console.log("ERROR  The lengths of the datasets that are input need to be the same.");
        } else if(masses.length === radiuses.length) {
            let terms = [];
            for (let i = 0; i < masses.length; i++) {
                terms[i] = masses[i]*Math.pow(radiuses[i], 2)
            }
            return terms.reduce((accumulator, currentValue) => accumulator+currentValue, 0);
        }
    }

    calculateHollowCilinderMomentOfInertia(mass, radius) {
        return mass*Math.pow(radius, 2);
    }

    calculateSolidCilinderMomentOfInertia(mass, radius) {
        return 0.5*mass*Math.pow(radius, 2);
    }

    calculateHollowSphereMomentOfInertia(mass, radius) {
        return (2/3)*mass*Math.pow(radius, 2);
    }

    calculateSolidSphereMomentOfInertia(mass, radius) {
        return 0.4*mass*Math.pow(radius, 2);
    }

    calculateDiscMomentOfInertia(mass, radius) {
        return 0.25*mass*Math.pow(radius, 2);
    }

    calculateObjectAngularMomentum(momentOfInertia, angularVelocity) {
        return momentOfInertia*angularVelocity;
    }

    calculateRotationalEnergy(momentOfInertia, angularVelocity) {
        return 0.5*momentOfInertia*Math.pow(angularVelocity, 2);
    }
}

class Vibrations {
    calculatePeriod(frequency) {
        return 1/frequency; // Note that this exact function can also be used to calculate the frequency
    }

    calculatePhaseDifference(deltaTime, period) {
        return deltaTime/period;
    }

    calculateDisplacementOfHarmonicVibration(amplitude, period, time) {
        return amplitude*Math.sin((2*Math.PI*time)/period);
    }

    calculateMaxSpeedOfHarmonicVibration(amplitude, period) {
        return (2*Math.PI*amplitude)/period;
    }

    calculatePeriodOfMassSpringSystem(mass, springConstant) {
        return 2*Math.PI*Math.sqrt(mass/springConstant);
    }

    calculatePeriodOfMathematicalPendulum(pendulumLength) {
        const g = constants.gravitationalAcceleration;
        return 2*Math.PI*Math.sqrt(pendulumLength/g);
    }

    calculatePeriodOfPhysicalPendulum(momentOfInertia, mass, pivotPointToCenterOfMassDistance) {
        const g = constants.gravitationalAcceleration;
        return 2*Math.PI*Math.sqrt(momentOfInertia/(mass*g*pivotPointToCenterOfMassDistance));
    }

    calculatePeriodOfTorsionalPendulum(momentOfInertia, torsionalConstant) {
        return 2*Math.PI*Math.sqrt(momentOfInertia/torsionalConstant);
    }
}

class Waves {
    calculateWaveSpeed(period, waveLength) {
        return waveLength/period;
    }

    calculatePhaseLag(distanceTraveled, waveLength) {
        return distanceTraveled/waveLength;
    }

    calculatePropagationSpeedTransversalWaveThroughString(tensileForceString, stringLength, stringMass) {
        return Math.sqrt((tensileForceString*stringLength)/stringMass);
    }

    calculatePropagationSpeedTransversalWaveTroughLiquidSurface(liquidDepth) {
        const g = constants.gravitationalAcceleration;
        return Math.sqrt(g*liquidDepth); // Note that this formula can only be used if the depth of the liquid is smaller than the wavelength
    }

    calculatePropagationSpeedLongitudinalWaveThroughSolid(modulusOfElasticity, density) {
        return Math.sqrt(modulusOfElasticity/density);
    }

    calculatePropagationSpeedLongitudinalWaveThroughLiquid(bulkModulus, density) {
        return Math.sqrt(bulkModulus, density);
    }

    calculatePropagationSpeedLongitudinalWaveThroughGas(heatCapacityAtConstantPressure, heatCapacityAtConstantVolume, kelvinTemperature, molarMass) {
        const R = constants.universalGasConstant;
        if (arguments.length === 4) {
            return Math.sqrt((heatCapacityAtConstantPressure*R*kelvinTemperature)/(heatCapacityAtConstantVolume*molarMass));
        } else if (arguments.length === 3) {
            const gamma = arguments[0];
            const kelvinTemperature = arguments[1];
            const molarMass = arguments[2];
            return Math.sqrt((gamma*R*kelvinTemperature)/molarMass);
        }
    }

    
}

const Mechanics = {RectilinearMotion, CircularMotion, ForceAndMomentum, WorkAndEnergy, Gravitation, Deformation, StaticsAndRotation};
const VibrationsWavesOptics = {Vibrations, Waves};
module.exports = {Mechanics, VibrationsWavesOptics};
