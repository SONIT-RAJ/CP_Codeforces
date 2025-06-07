/*
   Author: SONIT RAJ
    created: 10:05:45 07-06-2025
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
    sort(a.begin(),a.end(),greater<int>());
    if(a[0]==a[1]){
        cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3];
        return;
    }
    int j=-1;
    int sum=0;
    for(int i=0;i<n-1;i++){
        if(a[i]==a[i+1]){
            while(i<n-1 && a[i]==a[i+1]){
                j=i;
                sum=a[i]*2;
                i++;
            }
            break;
        }
    }
    if(j==-1){
        cout<<-1;
        return;
    }
    for(int i=n-1;i>0;i--){
        if(i==j+1 || i==j){
            continue;
        }
        if(i==j+2){
            if(j>=1 && a[i]+sum>a[j-1]){
                cout<<a[i]<<" "<<a[j]<<" "<<a[j+1]<<" "<<a[j-1];
                return;
            }
        }
        else if(a[i]+sum>a[i-1]){
            cout<<a[i]<<" "<<a[j]<<" "<<a[j+1]<<" "<<a[i-1];
            return;
        }
    }
    cout<<-1;




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