async function getQuote(): Promise<void> {
    try {
        const response = await fetch("https://api.api-ninjas.com/v1/quotes", {
            method: "GET",
            headers: {
                "X-Api-Key": "DINwyGkOgjKTRPVMYDXDew==NhQn2RxfLgkRqr3G"
            }
        });
        const responseJSON = await response.json();
        console.log(responseJSON);
    } catch(err) {
        throw err;
    }
}

getQuote();