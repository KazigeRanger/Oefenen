interface APIRESPONSE {
    quote: string;
    author: string;
    category: string;
}

async function getQuote(): Promise<APIRESPONSE> {
    try {
        const response = await fetch("https://api.api-ninjas.com/v1/quotes", {
            method: "GET",
            headers: {
                "X-Api-Key": "DINwyGkOgjKTRPVMYDXDew==NhQn2RxfLgkRqr3G"
            }
        });
        const responseJSON = await response.json();
        return responseJSON;
    } catch(err) {
        throw err;
    }
}

async function logQuote(quotePromise: Promise<APIRESPONSE>): Promise<void> {
    const quoteJSON: APIRESPONSE = await quotePromise;
    const quote: string = quoteJSON[0].quote;
    const author: string = quoteJSON[0].author;
    const category: string = quoteJSON[0].category;

    console.log(`"${quote}"\n - ${author}`);
}

logQuote(getQuote());