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

void printAirportsInRange(const map<string, int>& traffic, int low, int high) {
    cout << "Airports with traffic in range [" << low << ", " << high << "]:" << endl;
    for (auto it = traffic.begin(); it != traffic.end(); ++it) {
        if (it->second >= low && it->second <= high) {
            cout << it->first << " " << it->second << endl;
        }
    }
    cout << endl;
}

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

int maxcount = 0;
for (auto it = traffic.begin(); it != traffic.end(); ++it) {
    if (it->second > maxcount) {
        maxcount = it->second;
    }
}

cout << "Busiest airport(s) with traffic count : " << maxcount << ":" << endl;
for (auto it = traffic.begin(); it != traffic.end(); ++it) {
    if (it->second == maxcount) {
        cout << it->first << endl;
    }
}
cout << endl;

printAirportsInRange(traffic, 5, 8);
printAirportsInRange(traffic, 9, 12);

return 0;
}
