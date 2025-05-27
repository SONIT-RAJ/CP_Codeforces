/*
   Author: SONIT RAJ
    created: 00:59:03 27-05-2025
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

    int n,q;
    cin>>n>>q;
    vector<int>a(n);
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    int last=-1;
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int i,x;
            cin>>i>>x;
            if(last==-1){
                sum+=x-a[i-1];
                cout<<sum<<endl;
                a[i-1]=x;
            }
            else{
                sum+=x-last;
                cout<<sum<<endl;
                a[i-1]=x;
            }
        }
        else{
            cin>>last;
            sum=last*n;
            cout<<sum<<endl;
        }
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