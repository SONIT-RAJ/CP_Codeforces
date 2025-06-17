/*
   Author: SONIT RAJ
    created: 08:59:55 17-06-2025
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

int check(int n,int m){
    while(m>n){
        m&=(m-1);
    }
    return m;
}

void solve(){

    int n,x;
    cin>>n>>x;
    int l=n;
    int h=5e18;
    int ans=-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        int a=check(n,mid);
        if(a==x){
            ans=mid;
            h=mid-1;
        }
        else if(a>x){
            l=mid+1;
        }
        else{
            h=mid-1;;
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