const {
    createHash,
  } = require('node:crypto');

const storedHash = "a570819e95aa4c43ad54fbb7ea3578726ee0eb1185348564908e5159822d653b";

const passwordInput = "Broodje ham";

const passwordInputHash = createHash('sha256').update(passwordInput).digest('hex');

console.log("The stored hash is: " + storedHash);
console.log("The input hash is: " + passwordInputHash);

if (storedHash === passwordInputHash) {
    return console.log("The password is correct.");
} else if (storedHash !== passwordInputHash) {
    return console.log("The password is incorrect.");
}