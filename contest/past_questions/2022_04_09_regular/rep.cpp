#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;

int main()
{
    int n;
    deque<int> deq;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        deq.push_back(a);
    }

    int flip = 0;
    while (deq.size()) {
        if ((flip == 0 && deq.front() == 0) || (flip == 1 && deq.front() == 1)) {
            deq.pop_front();
            flip ^= 1;
        } else if ((flip == 0 && deq.back() == 0) || (flip == 1 && deq.back() == 1)) {
            deq.pop_back();
        } else break;
    }

    if (deq.size()) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}