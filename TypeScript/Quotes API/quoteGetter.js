var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
function getQuote() {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            const response = yield fetch("https://api.api-ninjas.com/v1/quotes", {
                method: "GET",
                headers: {
                    "X-Api-Key": "DINwyGkOgjKTRPVMYDXDew==NhQn2RxfLgkRqr3G"
                }
            });
            const responseJSON = yield response.json();
            return responseJSON;
        }
        catch (err) {
            throw err;
        }
    });
}
function logQuote(quotePromise) {
    return __awaiter(this, void 0, void 0, function* () {
        const quoteJSON = yield quotePromise;
        const quote = quoteJSON[0].quote;
        const author = quoteJSON[0].author;
        const category = quoteJSON[0].category;
        console.log(`"${quote}"\n - ${author}`);
    });
}
logQuote(getQuote());
