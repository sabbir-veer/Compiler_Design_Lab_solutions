#include <fstream>
#include <iostream>
using namespace std;

int main() {
    string st = "Hello from the server";
    string st2;

    // opening file using constructor and writing it
    // ofstream out("hello.txt");
    // out << st;

    // opening files using constructor and reading it
    ifstream in("hello.txt");
    getline(in, st2);
    cout << st2 << endl;
}