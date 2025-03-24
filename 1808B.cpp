/*
   Author: SONIT RAJ
    created: 22:00:28 23-03-2025
*/


#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#define ll long long
#define int long long
#define rep(i,a,b) for(int i = a; i<b; i++)
#define rew(x) for(int i = 0; i<x; i++)
#define all(x) x.begin(), x.end()
#ifdef ONLINE_JUDGE
    #define de(...)
    #define de2(...)
#endif
const ll inf = 2e18 + 5;
const ll M = 1e9 + 7;
#define PI 3.141592653589

void solve(){

    int n,m;
    cin>>n>>m;
    vector<vector<int>>a(m,vector<int>(n,0));
    vector<vector<int>>b(m,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[j][i];
        }
    }
    for (auto &row : a) {
        sort(row.begin(), row.end());
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            b[i][j]=a[i][j];
            if(j!=0){
                b[i][j]+=b[i][j-1];
            }
        }
    }
    int sum = 0;
    for (int j = 0; j < m; j++) {
        int prefix_sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[j][i] * i - prefix_sum;  // Difference sum calculation
            prefix_sum += a[j][i];  // Update prefix sum
        }
    }

    cout << sum;





}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
}