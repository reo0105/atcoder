#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> s(8);
    for (int i = 0; i < 8; i++) cin >> s.at(i);

    int ok = 1;
    for (int i = 0; i < 7; i++) {
        if (s.at(i) > s.at(i+1)) ok = 0;
    }

    for (int i = 0; i <8; i++) {
        if (!(100 <= s.at(i) && s.at(i) <= 675)) ok = 0;
        if (s.at(i) % 25 != 0) ok = 0;
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;



    return 0; 
}