/*
   Author: SONIT RAJ
    created: 11:44:17 07-10-2025
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
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    stack<int>s;
    s.push(-1);
    for(int i=0;i<n;i++){
        int num=(s.top()==-1)?0:a[s.top()];
        while(num>=a[i]){
            s.pop();
            num=(s.top()==-1)?0:a[s.top()];
        }
        if(s.top()==-1){
            cout<<0<<" ";
        }
        else{
            cout<<s.top()+1<<" ";
        }
        s.push(i);
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