#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n+1);
    vector<int> back(n+1);

    int s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != -1) back[a[i]] = i;
        else s = i;
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        cout << s << " ";
        s = back[s];
    }
    cout << endl;


    return 0;
}