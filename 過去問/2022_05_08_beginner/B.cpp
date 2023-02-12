#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b;
    int flag = 0;

    cin >> n >> a >> b;
    int h = a*n;
    int w = b*n;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if ((((i/a)+(j/b))%2) == 0) cout <<'.';
            else cout << '#';
        }
        cout << endl;
    }

    return 0;
}