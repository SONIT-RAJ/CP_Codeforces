/*
   Author: SONIT RAJ
    created: 01:34:24 14-04-2025
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
    int total=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        total+=a[i];
    }
    int sum=0;
    int start=0;
    int maxsum=LLONG_MIN;
    for(int i=0;i<n;i++){
        if(sum==0){
            start=i;
        }
        sum+=a[i];
        if(maxsum<sum){
            maxsum=sum;
        }
        if(sum<=0){
            sum=0;
        }
        if(i==n-1 && start==0){
            if(maxsum>=total){
                cout<<"YES";
                return;
            }
        }
        else{
            if(maxsum>=total){
                cout<<"NO";
                return;
            }
        }
    }
    if(maxsum<total){
        cout<<"YES";
    }
    else{
        cout<<"NO";
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