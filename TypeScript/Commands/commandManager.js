const { exec } = require("child_process");
const { stdout, stderr } = require("process");
//const chalk = require("chalk");

console.log("commandManager.js called");

// Function that returns a Promise for exec
function execPromise(command) {
    return new Promise((resolve, reject) => {
        exec(command, (error, stdout, stderr) => {
            if (error) {
            reject(`Error: ${error.message}`);
            return;
        }
        if (stderr) {
            reject(`Stderr: ${stderr}`);
            return;
        }
        resolve(stdout);
        });
    });
}
  
execPromise('tsc').then(() => {
    var calledFile = process.argv[2];
    var commandFile = calledFile.replace(".ts", ".js");
    console.log(`file being called: ${commandFile}`);
    var command = `node ${commandFile}`;
        
    exec(command, (error, stdout, stderr) => {
        if (error) {
            console.error(`Error executing command: ${error.message}`);
            return;
        }
            
        if (stderr) {
            console.error(`stderr: ${stderr}`);
            return;
        }
            
        console.log(`\nstdout:\n    ${stdout}`);
    });
}).catch((error) => {
      console.error('Command failed with error:', error);
});
