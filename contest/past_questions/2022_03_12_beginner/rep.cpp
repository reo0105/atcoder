#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n, x;
    string s;

    cin >> n >> x;
    cin >> s;

    deque<char> deq;

    for (int i = 0; i < n; i++) {
        if (deq.empty()) deq.push_back(s.at(i));
        else {
            if (s.at(i) == 'U' && deq.back() != 'U') {
                deq.pop_back();
            } else {
                deq.push_back(s.at(i));
            }
        }
    }

    while (deq.size()) {
        char dir = deq.front();
        deq.pop_front();

        if (dir == 'U') x >>= 1;
        else if (dir == 'L') x <<= 1;
        else {
            x <<= 1;
            x++;
        }
    }

    cout << x << endl;

    return 0;
}