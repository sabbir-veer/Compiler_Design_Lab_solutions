#include <bits/stdc++.h>
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

int main() {
    string inputLine;
    cout << "Enter an input line: ";
    getline(cin, inputLine);

    if (isComment(inputLine))
        cout << "The input line is a comment." << endl;
    else
        cout << "The input line is not a comment." << endl;

    return 0;
}
