/*
   Author: SONIT RAJ
    created: 10:04:35 04-06-2025
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

int countSetBits(long long n) {
    int count = 0;
    while (n) {
        n &= (n - 1); // clear the least significant bit set
        count++;
    }
    return count;
}

int find(vector<int>&f,int n,int i){
    if(i>=16){
        return countSetBits(n);
    }
    int ans=LLONG_MAX;
    if(n>=f[i]){
        int sub=1+find(f,n-f[i],i+1);
        ans=sub;
    }
    return min(ans,find(f,n,i+1));
}


void solve(){

    vector<int>f(16,1);
    for(int i=1;i<16;i++){
        f[i]=f[i-1]*i;
    }
    int n;
    cin>>n;
    int s=countSetBits(n);
    if(s==1){
        cout<<1;
        return;
    }
    int ans=find(f,n,1);
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