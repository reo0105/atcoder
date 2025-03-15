#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> where(n+1);
    unordered_map<int, int> move;
    unordered_map<int, int> to;
    unordered_map<int, int> trace;
    
    for (int i = 1; i <= n; i++) {
        where[i] = i;
        move[i] = i;
        to[i] = i;
        trace[i] = i;
    }

    for (int i = 0; i < q; i++)
    {
        int qi, a, b;
        cin >> qi;
        if (qi == 1) {
            cin >> a >> b;
            where[a] = b;
            trace[a] = move[b];
        } else if (qi == 2) {
            cin >> a >> b;
            swap(move[a], move[b]);
            to[move[a]] = a;
            to[move[b]] = b;

        } else {
            cin >> a;
            // cout << where[a] << " " << trace[where[a]] << endl;  
            cout << to[trace[a]] << endl;
        }
    }
    // for (int i = 1; i <= n; i++) cout << move[i] << " ";
    // cout << endl;
    // for (int i = 1; i <= n; i++) cout << to[i] << " ";
    // cout << endl;


    return 0;
}