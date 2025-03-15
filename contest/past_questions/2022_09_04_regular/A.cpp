#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> a;
    deque<int> deq;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        deq.push_back(a.at(i));
    }

    int ans = 0;
    while (deq.size()) {
        int mini = deq.front();
        int maxi = deq.back();
        deq.pop_back();
        ans++;
        
        int rem = maxi % mini;
        if (rem == 0) continue;

        deq.push_front(rem);
    }

    cout << ans-1 << endl;

    return 0;
}

// int main()
// {
//     int n;
//     // vector<int> a;
//     multiset<int> ms;

//     int mini = 1e9+5, id;
    
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         int x;
//         cin >> x;
//         ms.insert(x);
//         if (mini > x) {
//             mini = x;
//             id = i;
//         }
//     }

//     int ans = 0;
//     while (ms.size()) {
//         int maxi = *rbegin(ms);
//         ms.erase(ms.find(maxi));
        
//         ans++;
//         int rem = maxi % mini;
//         if (rem == 0) continue;

//         ms.insert(rem);
//         mini = rem;
//     }

//     cout << ans-1 << endl;

//     return 0;
// }