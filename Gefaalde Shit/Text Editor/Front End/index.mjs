import sqlite3 from "sqlite3";

const titleInput = document.getElementById("title-input");
const textarea = document.getElementById("textarea");
const saveButton = document.getElementById("save-button");

const db = new sqlite3.Database("./../Back End/texts.db");

saveButton.addEventListener("click", () => {
    console.log("TEST TEST");
    const title = titleInput.value;
    const text = textarea.value;

    let sql = `INSERT INTO texts VALUES (${title}, ${text})`;

    db.exec(sql);

    db.all("SELECT * FROM texts;", [], (err, rows) => {
        if (err) {
            throw err;
        }

        console.log(rows);
    });
});