#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int sum_a = 0, sum_b = 0;

    for (int i = 0; i < 9; i++) {
        int a;
        cin >> a;
        sum_a += a;
    }
    for (int i = 0; i < 8; i++) {
        int b;
        cin >> b;
        sum_b += b;
    }

    cout << sum_a - sum_b + 1 << endl;

    return 0;
}