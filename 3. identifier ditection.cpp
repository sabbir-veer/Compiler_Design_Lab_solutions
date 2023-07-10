#include <bits/stdc++.h>
using namespace std;
bool isValidIdentifier(const string& identifier) {
    // Check if the identifier is empty
    if (identifier.empty())
        return false;

    // Check if the first character is a letter or underscore
    if (!isalpha(identifier[0]) && identifier[0] != '_')
        return false;

    // Check the remaining characters
    for (size_t i = 1; i < identifier.length(); ++i) {
        // Check if the character is alphanumeric or underscore
        if (!isalnum(identifier[i]) && identifier[i] != '_')
            return false;
    }

    // All checks passed, the identifier is valid
    return true;
}

int main() {
    string identifier;
    cout << "Enter an identifier: ";
    cin >> identifier;

    if (isValidIdentifier(identifier))
        cout << "The identifier is valid." << endl;
    else
        cout << "The identifier is not valid." << endl;

    return 0;
}
