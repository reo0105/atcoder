#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, tmp, cnt = 0;;
    vector<int> data(200002);
    // vector<int> num(200002);
    map<int, int> num;
    set<int> nums;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> data.at(i);
        if (num.count(data.at(i))) {
            num[data.at(i)] += 1;
        } else {
            num[data.at(i)] = 1;
        }
        nums.insert(data.at(i));
    }


    for (int k = 0; k < n; k++) {
        if (!nums.empty()) {
            int max = *rbegin(nums);
            cout << num[max] << endl;
            nums.erase(max);
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}