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

vector<int>dp(1e5+1,0);
void pre(){
    dp[1]=1;
    for(int i=2;i<=1e5;i++){
        dp[i]=(i*dp[i-1])%M;
    }
}

void solve(){

    int n;
    cin>>n;
    cout<<(dp[n]*n*(n-1))%M;




}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    pre();
    while(t--){
        solve();
        cout<<"\n";
    }
}