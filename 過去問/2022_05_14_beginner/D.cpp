#include <bits/stdc++.h>
using namespace std;

int main()
{
    int w;
    cin >> w;
    
    cout << 297 << endl;
    int cnt = 100;
    for (int i = 1; i < 100; i++) cout << i << " ";
    for (int i = 1; i < 100; i++) cout << i*cnt << " ";
    for (int i = 1; i < 100; i++) cout << i * cnt*cnt << " ";

    return 0;
}
