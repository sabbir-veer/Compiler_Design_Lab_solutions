#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream in("hello.txt");

    int lineCount = 0;
    string line;
    while (getline(in, line)) {
        lineCount++;
    }
    in.close();
    cout << lineCount << endl;

    return 0;
}