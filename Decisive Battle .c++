#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;

    int east = 0, west = 0;

    for (char c : S) {
        if (c == 'E')
            east++;
        else
            west++;
    }

    if (east > west)
        cout << "East\n";
    else
        cout << "West\n";

    return 0;
}
