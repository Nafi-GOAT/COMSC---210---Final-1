//
//
// Mehraj Hasan Nafi | COMSC 210 | Final 1
//IDE used: VSCode 
//
//
#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;

int main() {
    map<string, int > traffic;
    
    ifstream infile("210-final-1-FA25.txt");
    if(!infile){
        cout << "Error opening file." << endl;
        return 1;
    }

    string origin, destination;

    while (infile >> origin >> destination) {
    traffic[origin]++;
    traffic[destination]++;
}

cout << "All airports and their traffic counts: "<< endl;
for (auto it = traffic.begin(); it != traffic.end(); ++it) {
    cout << it->first << " " << " Traffic Count: " << it->second << endl;
}
cout << endl;

return 0;
}
