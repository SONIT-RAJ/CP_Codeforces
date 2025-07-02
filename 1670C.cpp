/*
   Author: SONIT RAJ
    created: 17:27:19 02-07-2025
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

    int n;
    cin>>n;
    vector<int>a(n+1);
    vector<int>ai(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ai[a[i]]=i;
    }
    vector<int>b(n+1);
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    vector<int>c(n+1);
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    unordered_map<int,bool>mpp;
    int ans=1;
    for(int i=1;i<=n;i++){
        bool flag=false;
        bool flag2=false;
        int idx=i;
        while(!(mpp[a[idx]]==true && mpp[b[idx]]==true)){
            flag2=true;
            mpp[a[idx]]=true;
            mpp[b[idx]]=true;
            if(c[idx]!=0 || a[idx]==b[idx]){
                flag=true;
            }
            idx=ai[b[idx]];
            if(c[idx]!=0 || a[idx]==b[idx]){
                flag=true;
            }

        }
        if(flag==false && flag2==true){
            ans=(ans*2)%M;
        }
    }
    cout<<ans;




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