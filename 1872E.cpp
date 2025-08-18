/*
   Author: SONIT RAJ
    created: 20:11:27 18-08-2025
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
    for(int i=0;i<n;i++)cin>>a[i];
    string s;
    cin>>s;
    int zero=0;
    int one=0;
    vector<int>pre(n);
    for(int i=0;i<n;i++){
        int last=(i-1>=0)?pre[i-1]:0;
        pre[i]=last^a[i];
        if(s[i]=='0'){
            zero^=a[i];
        }
        else{
            one^=a[i];
        }
    }
    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type==2){
            int q2;
            cin>>q2;
            if(q2==0){
                cout<<zero<<" ";
            }
            else{
                cout<<one<<" ";
            }
        }
        else{
            int l,r;
            cin>>l>>r;
            l--;
            r--;
            int last2=(l-1>=0)?pre[l-1]:0;
            int required=pre[r]^last2;
            one^=required;
            zero^=required;

        }
    }




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