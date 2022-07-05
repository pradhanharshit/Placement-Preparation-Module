// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
#define ll long long
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        // code here
        ll m = 1e9+7;
        vector<vector<ll>> r(n);
        for(int i = 0; i < n; i++){
            r[i].resize(i+1);
            r[i][0] = r[i][i] = 1;
            
            for(int j = 1; j < i; j++){
                r[i][j] = (r[i-1][j-1] + r[i-1][j])%m;
            }
        }
        return r[n-1];
    }
};


// { Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}
  // } Driver Code Ends