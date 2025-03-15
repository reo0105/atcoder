#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {

    int n;
    cin >> n;

    int sum = 0;
    vector<string> s(n);

    for (int i = 0; i < n; i++) {
        int c;
        cin >> s[i] >> c;
        sum += c;
    }

    sort(s.begin(), s.end());
    cout << s[sum%n] << endl;

    return 0;
}