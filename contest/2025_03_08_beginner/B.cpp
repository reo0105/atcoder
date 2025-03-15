#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main()
{
    int q;
    cin >> q;

    stack<int> stk;
    for (int i = 0; i < 105; i++) stk.push(0);

    for (int i = 0; i < q; i++)
    {
        int qi;
        cin >> qi;

        if (qi == 1)
        {
            int x;
            cin >> x;
            stk.push(x);
        }
        else
        {
            cout << stk.top() << endl;
            stk.pop();
        }
    }

    return 0;
}