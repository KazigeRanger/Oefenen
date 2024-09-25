// Get the echo-input element and save it in a variable
const echoInput = document.getElementById("echo-input");
const echos = document.getElementsByClassName("echos");

for (let i = 0; i < echos.length; i++) {
    echos[i].style.opacity = 1-(i+1)/echos.length;
}

// Add an "input" eventlistener to the echoInput and print the value of the echoInput whenever it changes
echoInput.addEventListener("input", () => {
    let echoText = echoInput.value;
    for (let i = 0; i < echos.length; i++) {
        setTimeout(() => {
            if (echoText !== "") {
                echos[i].innerHTML = `${echoText}`;
                echos[i].style.visibility = "visible";
                echos[i].style.opacity = 1-(i+1)/echos.length;
                // echos[i].style.color = "black";
            } else if (echoText === "") {
                echos[i].innerHTML = `.`;
                echos[i].style.opacity = 0;
                // echos[i].style.color = "white";
                console.log(`LEEGTE GEDETECTEERD ${echos[i].style.visibility}`);
            }
        }, 100*(i+1));
    }
    console.log(echoText);
    // console.log(echos);
})