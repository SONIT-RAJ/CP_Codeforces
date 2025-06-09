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

    int n;
    cin>>n;
    vector<vector<char>>a(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int a1=0;
            int a2=0;
            if(a[i][j]=='0'){
                a1++;
            }
            else{
                a2++;
            }
            if(a[j][n-1-i]=='0'){
                a1++;
            }
            else{
                a2++;
            }
            if(a[n-1-i][n-1-j]=='0'){
                a1++;
            }
            else{
                a2++;
            }
            if(a[n-1-j][i]=='0'){
                a1++;
            }
            else{
                a2++;
            }
            int maxi=max(a1,a2);
            ans+=4-maxi;
        }
    }
    cout<<ans/4;




}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
}