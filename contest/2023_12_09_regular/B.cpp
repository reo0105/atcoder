#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll minSubsequences(vector<int>& arr, int S) {
    int n = arr.size();
    ll result = 0;
    int sum = 0;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        sum += arr[right];
        
        while (sum > S) {
            sum -= arr[left];
            left++;
        }

        result += (right - left + 1);
    }

    return result;
}

int main() {
    ll n, s;

    cin >> n >> s;

    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];


    ll result = minSubsequences(A, s);
    cout << result << endl;

    return 0;
}
