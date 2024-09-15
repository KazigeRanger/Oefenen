let database = [{id: "Jeroen Tilburg", vak: "Natuurkunde", aardigheid: 8},
    {id: "Wouter Koning", vak: "Natuurkunde", aardigheid: 9}
];

/**
 * The addToDatabase function adds an object with the specified properties to the specified database.
 * @param id 
 * @param vak 
 * @param aardigheid 
 */
function addToDatabase(database, id: string, vak: string, aardigheid: number):void {
    const addedObject = {id: id, vak: vak, aardigheid: aardigheid};
    database.push(addedObject);
}

/**
 * The formatDatabaseObjectProperty function first loops over all the objects in the specified database
 * and when it finds the right object by matching the id properties it returns the specified property
 * of that object.
 * @param database 
 * @param object 
 * @param property 
 * @returns The formatDatabaseObjectProperty function returns a clean string that contains the specified 
 * property of the specified object from a specified database. Or, if the specified object cannot be 
 * found it returns an error.
 */
function formatDatabaseObjectProperty(database, object: string, property: string):string {
    for (let i = 0; i < database.length; i++) {
        let databaseObject = database[i];
        let id = databaseObject.id;

        if (id === object) {
            let objectProperty = databaseObject[property];
            return objectProperty;
        } else {
            continue;
        }
    }

    throw new Error(`The specified object with id: ${object} could not be found.`);
}

// addToDatabase(database, "Rosa Veenstra", "Engels", 10);
// const vakWouterKoning = formatDatabaseObjectProperty(database, "Woutr Koning", "vak");
// const vakRosaVeenstra = formatDatabaseObjectProperty(database, "Rosa Veenstra", "vak");

// console.log(vakWouterKoning);
// console.log(vakRosaVeenstra);

console.log("Database.ts called");
