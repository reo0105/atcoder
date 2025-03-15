#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b;
    vector<int> c(2005);
    cin >> n >> a >> b;

    for (int i = 1; i <= n; i++) cin >> c.at(i);

    int sum = a + b;
    for (int i = 1; i <= n; i++) {
        if (sum == c.at(i)) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}