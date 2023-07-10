#include <fstream>
#include <iostream>
#include <string>

using namespace std;
int main() {
    string data;
    ifstream in("hello.txt");

    int charCount = 0;
    char ch;
    while (in.get(ch)) {
        charCount++;
    }
    in.close();
    cout << charCount << endl;

    return 0;
}