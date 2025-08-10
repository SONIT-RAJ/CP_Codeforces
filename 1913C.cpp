/*
   Author: SONIT RAJ
    created: 14:00:52 09-08-2025
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

unordered_map<int,int>mpp;

void solve(){

    int q,x;
    cin>>q>>x;
    if(q==1){
        mpp[x]++;
        return;
    }
    else{
        int p=29;
        while(x>0 && p>=0){
            int val=1LL<<p;
            if(val<=x && mpp[p]>0){
                int take=min<int>(mpp[p],x/val);
                x -= take * val;
            }
            p--;
        }
        if(x==0){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
        cout<<"\n";
    }




}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}