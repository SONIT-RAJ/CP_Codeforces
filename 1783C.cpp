/*
   Author: SONIT RAJ
    created: 10:04:22 25-05-2025
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

    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>b=a;
    sort(a.begin(),a.end());
    int sum=0;
    int score=-1;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum>m){
            score=i;
            break;
        }
    }
    if(score==0){
        cout<<n+1;
        return;
    }
    if(score==-1){
        cout<<1;
        return;
    }
    if(b[score]>m){
        cout<<n-score+1;
        return;
    }
    m-=b[score];
    int c=1;
    sum=0;
    int flag=1;
    for(int i=0;i<n;i++){
        if(a[i]==b[score] && flag==1){
            flag=0;
            continue;
        }
        sum+=a[i];
        if(sum<=m){
            c++;
        }
        else{
            break;
        }
    }
    if(c>=score){
        cout<<n-score;
    }
    else{
        cout<<n-score+1;
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