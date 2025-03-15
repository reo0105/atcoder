#include <iostream>
using namespace std;

int main()
{
    int n, m, l;
    cin >> m >> l;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string ni;
        int pi, li;
        cin >> ni >> pi >> li;

        if (m >= pi && l >= li) {
            cout << ni << " " << pi << endl;
        }
    }

    // string s;
    // cin >> s;
    // cout << s << endl;

    return 0;
}