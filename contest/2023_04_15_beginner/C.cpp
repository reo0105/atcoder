#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;

    vector<map<int, int>> nums(200005);
    vector<map<int, int>> boxes(200005);

    cin >> n >> q;
    for (int i = 0; i < q; i++) {
        int x, qi, qj;
        cin >> x;
        if (x == 1) {
            cin >> qi >> qj;
            nums.at(qj)[qi]++;
            boxes.at(qi)[qj] = 1;
        } else if (x == 2) {
            cin >> qi;
            for (auto x : nums.at(qi)) {
                for (int j = 0; j < x.second; j++) cout << x.first << " "; 
            }
            cout << endl;
        } else {
            cin >> qi;
            // set<int> done;
            for (auto x : boxes.at(qi)) {
                // if (!done.count(x)) {
                    cout << x.first << " ";
                    // done.insert(x);
                
            }
            cout << endl;
        }
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;

    vector<vector<int>> nums(200005);
    vector<set<int>> box(200005);
    vector<vector<int>> boxes(200005);

    cin >> n >> q;
    for (int i = 0; i < q; i++) {
        int x, qi, qj;
        cin >> x;
        if (x == 1) {
            cin >> qi >> qj;
            nums.at(qj).push_back(qi);
            if (!box.at(qi).count(qj)) {
                boxes.at(qi).push_back(qj);
                box.at(qi).insert(qj);
            }
        } else if (x == 2) {
            cin >> qi;
            sort(nums.at(qi).begin(), nums.at(qi).end());
            for (int x : nums.at(qi)) {
                cout << x << " "; 
            }
            cout << endl;
        } else {
            int pre = -1;
            cin >> qi;
            sort(boxes.at(qi).begin(), boxes.at(qi).end());
            for (int x : boxes.at(qi)) {
                if (pre != x) cout << x << " ";
                pre = x;
            }
            cout << endl;
        }
    }

    return 0;
}