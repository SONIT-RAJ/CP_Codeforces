/*
   Author: SONIT RAJ
    created: 12:13:38 03-04-2025
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
    unordered_map<int,int>mpp1;
    unordered_map<int,int>mpp2;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        mpp1[s[i]]++;
    }
    int m=mpp1.size();
    int maximum=m;
    int count=m;
    for(int i=0;i<n-1;i++){
        if(mpp2[s[i]]==0){
            count++;
        }
        mpp2[s[i]]++;
        mpp1[s[i]]--;
        if(mpp1[s[i]]==0){
            count--;
        }
        maximum=max(maximum,count);
    }
    cout<<maximum;



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