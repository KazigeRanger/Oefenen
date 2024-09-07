class NewtonianPhysicsObject {
    constructor(mass) {
        this._mass = mass; // Mass in kilograms
    }

    get mass() {
        return this._mass; // Mass in kilograms
    }

    calculateNettoForce(mass, acceleration) {
        return mass*acceleration;
    }

    calculateEarthGravitationalForce(mass) {
        const g = 9.81; // The gravitational acceleration on earth
        return g*mass;
    }

    calculateGravitationalForce(firstObjectMass, secondObjectMass, distance) {
        const gravitationalConstant = 6.67430e-11;
        return (gravitationalConstant*firstObjectMass*secondObjectMass)/Math.pow(distance, 2);
    }
}

module.exports = NewtonianPhysicsObject;
