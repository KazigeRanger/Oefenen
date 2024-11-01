#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

string databaseLookup(const char query[50]) {
    string db[] = {"Anwar Rahmoun", "Bibi Schwartz", "Chris Mijnarends", "Derek den Otter",
                   "Eveline van Loon", "Fadi Laraj", "Gerard Joling", "Hannah Plomp", 
                   "Iris Lohuis", "Jan van Rhee", "Koen Lohuis", "Loïs van Wijk", "Manouk Corver"};

    const int dbSize = sizeof(db) / sizeof(db[0]);
    int matches[dbSize] = {0};  // Initialize matches array to 0

    // Calculate the match score for each name
    for (int i = 0; i < dbSize; i++) {
        for (int j = 0; j < db[i].length() && j < strlen(query); j++) {
            if (query[j] == db[i][j]) {
                matches[i]++;
            } else {
                break;  // Stop counting if characters don't match
            }
        }
    }

    // Find the index of the maximum match score
    int maxIndex = max_element(matches, matches + dbSize) - matches;
    cout << "Match: " << matches << endl;
    cout << "dbSize: " << dbSize << endl;
    cout << "max: " << max_element(matches, matches + dbSize) << endl;
    cout << "maxIndex: " << maxIndex << endl;
    
    // If the best match score is zero, it means no match was found
    if (matches[maxIndex] == 0) {
        cout << "Lookup failed" << endl;
        return "";
    }

    return db[maxIndex];
}

int main(int argc, char *argv[]) {
    string password = "TheCanvasOfBabel";

    if (argc == 1) {
        cout << "The password must be passed as an argument in the command line.";
        return 0;
    } else if (argv[1] == password) {
        cout << "Access granted" << endl << endl;
    } else {
        cout << "Access denied\n";
        return 0;
    }

    cout << "Database:" << endl;
    const int maxQueryLength = 50;
    char userQuery[maxQueryLength];
    std::cin.getline(userQuery, maxQueryLength);

    cout << "Query: " << userQuery << endl;

    string dbout = databaseLookup(userQuery);

    if (!dbout.empty()) {
        cout << "Best match: " << dbout << endl;
    }

    return 0;
}
