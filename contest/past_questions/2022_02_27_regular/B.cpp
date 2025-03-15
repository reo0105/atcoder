#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, flag = 0;
    vector<int> a(5005), b(5005);
    multiset<int> msa, msb;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
        if (msa.count(a.at(i))) flag = 1;
        msa.insert(a.at(i));
    }

    for (int i = 0; i < n; i++) {
        cin >> b.at(i);
        msb.insert(b.at(i));
    }

    int num_a = 0, num_b = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (a.at(i) > a.at(j)) num_a++;
            if (b.at(i) > b.at(j)) num_b++;            
        }
    }

    if (msa != msb) flag = 0;
    else if (num_a%2 == num_b%2) flag = 1;

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}