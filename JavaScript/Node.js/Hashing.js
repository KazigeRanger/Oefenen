const {
    createHash,
  } = require('node:crypto');
const readline = require('node:readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
  });

const storedHash = "a570819e95aa4c43ad54fbb7ea3578726ee0eb1185348564908e5159822d653b";

rl.question('What is your password? ', (passwordInput) => {
    const passwordInputHash = createHash('sha256').update(passwordInput).digest('hex');

    console.log("The stored hash is: " + storedHash);
    console.log("The input hash is: " + passwordInputHash);

    if (storedHash === passwordInputHash) {
        console.log("The password is correct.");
        return rl.close();
    } else if (storedHash !== passwordInputHash) {
        console.log("The password is incorrect.");
        return rl.close();
    }
});