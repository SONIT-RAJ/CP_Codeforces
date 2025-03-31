/*
   Author: SONIT RAJ
    created: 11:42:40 31-03-2025
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

    int n,r,b;
    cin>>n>>r>>b;
    int ans=(r%(b+1)==0)?r/(b+1):r/(b+1)+1;
    int countR=0;
    for(int i=0;i<n;i++){
        if(r<=0 && b<=0){
            break;
        }
        else if(r<=0){
            cout<<'B';
            b--;

        }
        else if(b<=0){
            cout<<'R';
            r--;

        }
        else if(countR>=ans){
            cout<<'B';
            b--;
            countR=0;
            int x=(r%(b+1)==0)?r/(b+1):r/(b+1)+1;
            if(ans>x){
            ans=x;
        }
        }
        else{
            cout<<'R';
            countR++;
            r--;
        }
    }






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