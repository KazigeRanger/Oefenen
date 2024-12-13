var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
function generatePassword() {
    return __awaiter(this, arguments, void 0, function* (passwordLength = 16) {
        try {
            const response = fetch(`https://api.api-ninjas.com/v1/passwordgenerator?length=${passwordLength}`, {
                method: "GET",
                headers: {
                    "X-Api-Key": "DINwyGkOgjKTRPVMYDXDew==NhQn2RxfLgkRqr3G"
                }
            });
            const responseJSON = (yield response).json();
            return responseJSON;
        }
        catch (err) {
            throw err;
        }
    });
}
function logPassword(passwordPromise) {
    return __awaiter(this, void 0, void 0, function* () {
        const passwordJSON = yield passwordPromise;
        console.log(passwordJSON);
    });
}
const password = generatePassword();
logPassword(password);
