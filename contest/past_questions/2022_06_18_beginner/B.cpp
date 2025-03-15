#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, p = 0;
    bool one = 0, two = 0, three = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            p += (three) ? 1 : 0;
            three = (two) ? true : false;
            two = (one) ? true : false;
            one = true;
        } else if (a == 2) {
            p += (three) ? 1 : 0;
            p += (two) ? 1 : 0;
            three = (one) ? true : false;
            two = true;
            one = false;
        } else if (a == 3) {
            p += (three) ? 1 : 0;
            p += (two) ? 1 : 0;
            p += (one) ? 1 : 0;
            three = true;
            two = false;
            one = false;
        } else {
            p += (three) ? 1 : 0;
            p += (two) ? 1 : 0;
            p += (one) ? 1 : 0;
            p += 1;
            three = two = one = false;
        }
    }

    cout << p << endl;


    return 0;
}