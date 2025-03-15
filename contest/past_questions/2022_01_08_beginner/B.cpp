#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    double maxi = -1;
    vector<int> x(105), y(105);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> x.at(i) >> y.at(i);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double tmp = sqrt((x.at(i) - x.at(j)) * (x.at(i) - x.at(j)) + (y.at(i) - y.at(j)) * (y.at(i) - y.at(j)));
            if (tmp > maxi) maxi = tmp;
        }
    }

    cout << fixed << setprecision(12) << maxi << endl;

    return 0;
}