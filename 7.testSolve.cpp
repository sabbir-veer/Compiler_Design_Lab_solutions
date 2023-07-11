#include <bits/stdc++.h>
using namespace std;
void removeTabsAndNewLines(const string& inputFile, const string& outputFile, int& deletionCount) {
    ifstream input(inputFile);
    ofstream output(outputFile);

    if (!input || !output) {
        cerr << "Error opening files." << endl;
        return;
    }

    char c;
    while (input.get(c)) {
        if (c == ' ') {
            int spaceCount = 1;
            while (spaceCount <= 4) {
                input.get(c);
                if (c == ' ')
                    spaceCount++;
                else
                    break;
            }
            if (spaceCount == 4) {
                deletionCount++;
                output << ' ';
            } else {
                output << ' ';
            }
        } else if (c == '\n') {
            c = ' ';
            deletionCount++;
        }
        output << c;
    }

    input.close();
    output.close();
}

int main() {
    string inputFilename = "hello.txt", outputFilename = "output2.txt";

    int deletionCount = 0;
    removeTabsAndNewLines(inputFilename, outputFilename, deletionCount);

    cout << "Number of deletions: " << deletionCount << endl;

    return 0;
}
