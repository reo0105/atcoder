#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    vector<int> a(100002); 

    cin >> n >> x;

    for (int i = 0; i < n; i++) cin >> a.at(i);

    int left = -1, right = n, mid;

    while (right - left > 1) {
        mid = (left + right) / 2;
        if (x == a.at(mid)) break;
        if (x < a.at(mid)) right = mid;
        else left = mid; 
    }

    cout << mid +1<< endl;
    return 0;
}