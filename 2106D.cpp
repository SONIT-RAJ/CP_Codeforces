/*
   Author: SONIT RAJ
    created: 21:19:46 26-04-2025
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
    vector<int>b(m);
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    int x=0;
    int y=0;
    while(x<n){
        if(b[y]<=a[x]){
            y++;
            x++;
        }
        else{
            x++;
        }
        if(y>=m){
            cout<<0;
            return;
        }
    }
    vector<int>s(m);
    int k=0;
    for(int i=0;i<n;i++){
        if(b[k]<=a[i]){
            s[k]=i;
            k++;
            if(k>=m){
                break;
            }
        }
    }
    for(int i=k;i<m;i++){
        s[i]=LLONG_MAX;
    }
    k=m-1;
    vector<int>p(m);
    for(int i=n-1;i>=0;i--){
        if(b[k]<=a[i]){
            p[k]=i;
            k--;
            if(k<0){
                break;
            }
        }
    }
    for(int i=k;i>=0;i--){
        p[i]=LLONG_MIN;
    }
    int answer=LLONG_MAX;
    int flag=0;
    for(int i=0;i<m;i++){
        if(i==0 && p[i+1]>=0){
            flag=1;
            answer=min(answer,b[i]);
        }
        else if(i==m-1 && s[i-1]<n){
            flag=1;
            answer=min(answer,b[i]);
        }
        else if(s[i-1]<p[i+1]){
            flag=1;
            answer=min(answer,b[i]);
        }
    }
    if(flag){
        cout<<answer;
    }
    else{
        cout<<-1;
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