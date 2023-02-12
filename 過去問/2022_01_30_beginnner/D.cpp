#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;

// int main()
// {
//     int n;
//     string s;

//     cin >> n >> s;

//     list<int> lst{0};
//     auto iter = lst.end();

//     for (int i = 0; i < n; i++) {
//         if (s.at(i) == 'L') iter--;
//         lst.insert(iter, i+1);
//     }
    
//     for (auto itr = lst.begin(); itr != lst.end(); itr++) {
//         cout << *itr << " ";
//     }
//     cout << endl;

//     return 0;
// }

int main()
{
    int n;
    string s;

    cin >> n >> s;

    deque<int> deq;
    deq.push_back(n);

    for (int i = n-1; i >= 0; i--) {
        if (s.at(i) == 'L') deq.push_back(i);
        else deq.push_front(i);
    }

    while (!deq.empty()) {
        cout << deq.front() << " ";
        deq.pop_front();
    }
    cout << endl;

    return 0;
}