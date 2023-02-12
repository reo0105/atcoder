#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, sum = 0, even = 0, flag = 1, maxi = -1;
    priority_queue<int> data_even, data_odd;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x % 2 == 0) {
            data_even.push(x);
        } else {
            data_odd.push(x);
        }
    }

    if (!data_even.empty()) {
        sum += data_even.top();
        //cout << sum << endl;
        data_even.pop();
    } else {
        flag = 0;
    }

    if (!data_even.empty() && flag) {
        sum += data_even.top();
        //cout << sum << endl;
    } else {
        flag = 0;
    }

    if (!flag) maxi = -1;
    else maxi = sum;

    sum = 0;
    flag = 1;

    if (!data_odd.empty()) {
        sum += data_odd.top();
        data_odd.pop();
    } else {
        flag = 0;
    }

    if (!data_odd.empty() && flag) {
        sum += data_odd.top();
    } else {
        flag = 0;
    }

    if (sum > maxi && flag) maxi = sum;

    cout << maxi;

    return 0;
}