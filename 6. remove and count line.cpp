#include <fstream>
#include <iostream>
#include <string>
using namespace std;
bool isComment(const string& line) {
    // Check for single-line comment
    if (line.find("//") == 0)
        return true;

    // Check for multi-line comment
    if (line.find("/*") == 0 && line.find("*/") != string::npos)
        return true;

    return false;
}

void removeComments(const string& inputFile, const string& outputFile, int& deletionCount) {
    ifstream input(inputFile);
    ofstream output(outputFile);

    if (!input || !output) {
        cerr << "Error opening files." << endl;
        return;
    }

    string line;
    while (getline(input, line)) {
        if (!isComment(line)) {
            output << line << endl;
        } else {
            deletionCount++;
        }
    }

    input.close();
    output.close();
}

int main() {
    string inputFilename = "hello.txt", outputFilename = "output.txt";

    int deletionCount = 0;
    removeComments(inputFilename, outputFilename, deletionCount);

    cout << "Number of comment deletions: " << deletionCount << std::endl;

    return 0;
}
