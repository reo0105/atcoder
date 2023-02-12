#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> a(20);

    a.at(1).push_back(1);
    for (int i = 2; i <= n; i++) {
        int t = (int)a.at(i-1).size();
        for (int j = 0; j < t; j++) {
            a.at(i).push_back(a.at(i-1).at(j));
        }

        a.at(i).push_back(i);

        for (int j = 0; j < t; j++) {
            a.at(i).push_back(a.at(i-1).at(j));
        }
    }


    for (int i = 0; i < (int)a.at(n).size(); i++) cout << a.at(n).at(i) << " ";
    cout << endl; 

    return 0;
}