#include <bits/stdc++.h>
using namespace std;
bool isSyntaxValid(const string& input) {
    // Regular expressions to match the syntax patterns
    regex whileRegex(R"(^\s*while\s*\(\s*.*\s*\)\s*$)");
    regex endRegex(R"(^\s*end\s*)");
    regex beginRegex(R"(^\s*begin\s*$)");
    regex statement(R"(^\s*(?:\w+\s+)*\w+\s*;\s*$)");

    // Check if input matches the while-loop pattern
    if (regex_match(input, whileRegex))
        return true;

    // check if input matches the begin keyword pattern
    if (regex_match(input, beginRegex))
        return true;

    // Check if input matches the end keyword pattern
    if (regex_match(input, endRegex))
        return true;

    // check if a statement is valid or not
    if (regex_match(input, statement))
        return true;

    return false;
}

bool verifySyntax(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening the file." << endl;
        return false;
    }

    string line;
    bool insideWhileLoop = false;
    bool insideBegin = false;
    bool whileHappened = false;
    bool beginHappened = false;
    while (getline(file, line)) {
        if (line.find("end") != string::npos) {
            insideWhileLoop = false;
            insideBegin = false;
            if (!isSyntaxValid(line)) {
                return false;
            }
        } else if (line.find("while") != string::npos) {
            whileHappened = true;
            insideWhileLoop = true;
            if (!isSyntaxValid(line)) {
                return false;
            }
        } else if (line.find("begin") != string::npos) {
            beginHappened = true;
            insideBegin = true;
            if (!isSyntaxValid(line)) {
                return false;
            }

        } else if (insideBegin) {
            if (!isSyntaxValid(line)) {
                return false;
            }
        }
    }
    file.close();

    if (whileHappened and beginHappened)
        return !insideWhileLoop;  // Verify that the while-loop is closed
    else
        return false;
}
int main() {
    string filename = "syntax.txt";

    bool isSyntaxCorrect = verifySyntax(filename);

    if (isSyntaxCorrect) {
        cout << "The syntax of the while-loop construct is valid." << endl;
    } else {
        cout << "The syntax of the while-loop construct is not valid." << endl;
    }

    return 0;
}
