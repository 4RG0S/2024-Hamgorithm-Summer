#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;

    int resultQuarter[T];
    int resultDime[T];
    int resultNickel[T];
    int resultPenny[T];

    for (int i = 0; i < T; i++) {
        int quarter, dime, nickel, penny;

        int change;
        cin >> change;

        quarter = change / 25;
        change = change - quarter * 25;
        dime = change / 10;
        change = change - dime * 10;
        nickel = change / 5;
        change = change - nickel * 5;
        penny = change;

        resultQuarter[i] = quarter;
        resultDime[i] = dime;
        resultNickel[i] = nickel;
        resultPenny[i] = penny;
    }

    for (int i = 0; i < T; i++) {
        cout << resultQuarter[i] << " " << resultDime[i] << " "
             << resultNickel[i] << " " << resultPenny[i] << endl;
    }

    return 0;
}