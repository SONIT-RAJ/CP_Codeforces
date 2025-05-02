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

void ans(vector<int>& dp, int& n, string& s, vector<vector<int>>& next) {
    string r;
    cin >> r;
    int pos = 0;
    for (char c : r) {
        if (next[pos][c - 'a'] == n) {
            cout << 0;
            return;
        }
        pos = next[pos][c - 'a'] + 1;
    }
    cout << dp[pos - 1];
}

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<vector<int>>next(n+1,vector<int>(k,n));
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<k;j++){
            int mm=n;
            if(s[i]==j+'a'){
                mm=i;
            }
            next[i][j]=min(next[i+1][j],mm);
        }
    }
    vector<int>dp(n);
    for(int i=n-1;i>=0;i--){
        int mini=LLONG_MAX;
        for(int j=0;j<k;j++){
            if(next[i+1][j]==n){
                mini=min(mini,1LL*1);
                break;
            }
            else{
                mini=min(mini,1+dp[next[i+1][j]]);
            }
        }
        dp[i]=mini;
    }
    int q;
    cin>>q;
    while(q--){
        ans(dp,n,s,next);
        cout<<"\n";
    }

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}