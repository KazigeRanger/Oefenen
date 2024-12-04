interface APIRESPONSE {
    password: string;
}

async function generatePassword(passwordLength = 16): Promise<APIRESPONSE> {
    try {
        const response = fetch(`https://api.api-ninjas.com/v1/passwordgenerator?length=${passwordLength}`, {
            method: "GET", 
            headers: {
                "X-Api-Key": "DINwyGkOgjKTRPVMYDXDew==NhQn2RxfLgkRqr3G"
            }
        });
        const responseJSON = (await response).json();
        return responseJSON;
    } catch(err) {
        throw err;
    }
}

async function logPassword(passwordPromise: Promise<APIRESPONSE>): Promise<void> {
    const passwordJSON: APIRESPONSE = await passwordPromise;
    console.log(passwordJSON);
}

const password = generatePassword();
logPassword(password);