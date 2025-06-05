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

bool cmp(vector<int>&b,vector<int>&c){
    if(b[0]==c[0]){
        return b[1]>c[1];
    }
    else{
        return b[0]<c[0];
    }
}

void solve(){

    string s;
    cin>>s;
    int n=s.size();
    vector<vector<int>>a(n,vector<int>(2,0));
    a[0][1]=1;
    for(int i=1;i<n;i++){
        if(s[i-1]=='('){
            a[i][0]=a[i-1][0]+1;
            a[i][1]=i+1;
        }
        else{
            a[i][0]=a[i-1][0]-1;
            a[i][1]=i+1;
        }
    }
    sort(a.begin(),a.end(),cmp);
    for(int i=0;i<n;i++){
        cout<<s[a[i][1]-1];
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