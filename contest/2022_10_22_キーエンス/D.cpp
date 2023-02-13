#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, y;
    vector<int> move(1002);
    vector<bool> dp_x(20005, false),  dp_y(20005, false);  
    vector<vector<bool>> next(2, vector<bool>(20005, false));  


    cin >> n >> x >> y;

    for (int i = 0; i < n; i++) {
        cin >> move.at(i);
    }

    dp_x.at(move.at(0)+10002) = true;
    dp_y.at(10002) = true;

    for (int i = 1; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < 20005; j++) {
                if (dp_x.at(j)) {
                    dp_x.at(j) = false;
                    next.at(0).at(j+move.at(i)) = true;
                    next.at(0).at(j-move.at(i)) = true;
                }
            }
            dp_x.swap(next.at(0));
        } else {
            for (int j = 0; j < 20005; j++) {
                if (dp_y.at(j)) {
                    dp_y.at(j) = false;
                    next.at(1).at(j+move.at(i)) = true;
                    next.at(1).at(j-move.at(i)) = true;
                }
            }
            dp_y.swap(next.at(1));
        }
        //copy(next.begin(), next.end(), dp.begin());
        //dp.swap(next);
    }
  
    if (dp_x.at(x+10002) && dp_y.at(y+10002)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    
    return 0;
}