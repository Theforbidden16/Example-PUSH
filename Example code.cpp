#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_NAMES = 20;

int readNamesFromFile(const string& filename, string names[], int maxSize) {
    ifstream file(filename);
    string name;
    int count = 0;

    while (getline(file, name) && count < maxSize) {
        names[count] = name;
        count++;
    }
    file.close();
    return count;
}

bool linearSearch(string names[], int size, const string& word) {
    for (int i = 0; i < size; i++) {
        if (names[i] == word) {
            return true;
        }
    }
    return false;
}

int main()
{
    string filename = "names.txt";
    string names[MAX_NAMES];
    int numNames = readNamesFromFile(filename, names, MAX_NAMES);
    if (numNames == 0) {
        cout << "Error: The file is empty or couldn't be read." << endl;
        return 1;
    }
    string word;
    cout << "Enter a name to search: ";
    cin >> word;

    if (linearSearch(names, numNames, word)) {
        cout << "The name '" << word << "' was found!" << endl;
    }
    else {
        cout << "The name '" << word << "' was not found." << endl;
    }

    return 0;
}
