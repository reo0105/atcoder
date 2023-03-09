#include <bits/stdc++.h>
using namespace std;

int main()
{
    double a, b, d;
    cin >> a >> b >> d;


    double nx = a*cos(d*M_PI/180) - b*sin(d*M_PI/180); 
    double ny = a*sin(d*M_PI/180) + b*cos(d*M_PI/180);

    cout << fixed << setprecision(12) << nx << " " << ny << endl;

    return 0;
}