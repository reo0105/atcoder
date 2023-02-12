#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int h, w, flag = 0, count = 0;
    cin >> h >> w;
    vector<string> s(h), t(h);
    
  	for (int i = 0; i < h; i++) {
        cin >> s.at(i);
    }
 
    for (int i = 0; i < h; i++) {
        cin >> t.at(i);
    }
  
  vector<vector<char>> Ts(w, vector<char>(h)), Tt(w, vector<char>(h));
  
  for (int i = 0; i < h; i++) {
	for (int j = 0; j < w; j++) {
		Ts.at(j).at(i) = s.at(i).at(j);
      	Tt.at(j).at(i) = t.at(i).at(j);
    }
  }
  
  sort(Ts.begin(), Ts.end());
  sort(Tt.begin(), Tt.end());
  
  if (Ts == Tt) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  
    return 0;
}