#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    multiset<int> ms;
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        ms.insert(s[i] - '0');
    }

    ll lim = pow(10, n);
    for (ll i = 0; i*i < lim; i++) {
        ll sqrt = i * i;
        multiset<int> temp;

        int k = 0;
        while (sqrt != 0) {
            int rem = sqrt % 10;
            sqrt /= 10;
            temp.insert(rem);
            k++;
        }

        for (int j = k; j < n; j++) temp.insert(0);

        if (temp == ms) ans++;
    }

    cout << ans << endl;
    
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// int main()
// {
//     int n;
//     string s;
//     cin >> n >> s;

//     sort(s.begin(), s.end());
    
//     int ans = 0;
//     ll lim = pow(10, n);
//     for (ll i = 0; i*i < lim; i++) {
//         ll sqrt = i*i;
//         string temp = to_string(sqrt);

//         temp.resize(n, '0');
//         sort(temp.begin(), temp.end());
//         if (s == temp) ans++;
//     }

//     cout << ans << endl;
    
//     return 0;
// }