#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    string s;
    cin >> s;

    deque<char> deq;

    int sz = (int)s.size();

    int cnt = 0;
    for (int i = 0; i < sz; i++) {
        char now = s[i];
        deq.push_back(now);

        if (now == 'A') cnt = 1;
        else if (cnt == 1 && now == 'B') cnt = 2;
        else if (cnt == 2 && now == 'C') {
            deq.pop_back();
            deq.pop_back();
            deq.pop_back();
            if (deq.size() && deq.back() == 'A') cnt = 1;
            else if (deq.size() && deq.back() == 'B') {
                deq.pop_back();
                if (deq.size() && deq.back() == 'A') cnt = 2;
                else cnt = 0;
                deq.push_back('B');
            }
            else cnt = 0;
        } else cnt = 0;
    }

    while (deq.size()) {
        char now = deq.front();
        deq.pop_front();
        cout << now;
    }

    cout << endl;

    return 0;
}