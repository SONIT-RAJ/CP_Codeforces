/*
   Author: SONIT RAJ
    created: 02:02:29 28-03-2025
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
    unordered_map<int,int>mpp1;
    int maximum=0;
    int count=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i==0){
            count++;
        }
        else{
            if(a[i]==a[i-1]){
                count++;
            }
            else{
                count=1;
            }
        }
        mpp1[a[i]]=max(mpp1[a[i]],count);
        maximum=max(maximum,mpp1[a[i]]);
    }
    vector<int>b(n);
    unordered_map<int,int>mpp2;
    count=0;
    for(int i=0;i<n;i++){
        cin>>b[i];
        if(i==0){
            count++;
        }
        else{
            if(b[i]==b[i-1]){
                count++;
            }
            else{
                count=1;
            }
        }
        mpp2[b[i]]=max(mpp2[b[i]],count);
        maximum=max(maximum,mpp1[b[i]]+mpp2[b[i]]);
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