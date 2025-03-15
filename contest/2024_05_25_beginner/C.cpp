#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;

    vector<int> row(2005), col(2005);
    int s0 = 0, s1 = 0;

    int ok = -1;

    for (int i = 0; i < t; i++) {
        int x;
        cin >> x;

        int ci = (x-1) % n;
        int ri = (x-1) / n;
        col[ci]++;
        row[ri]++;

        if (ci == ri) {
            s0++;
        } 
        if (ci + ri == n-1) {
            s1++;
        }

        if (col[ci] == n || row[ri] == n || s0 == n || s1 == n) {
            ok = i+1;
            break;
        }
    }

    cout << ok << endl;    


}