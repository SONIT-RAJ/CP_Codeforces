/*
   Author: SONIT RAJ
    created: 09:46:23 27-05-2025
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
    if(a[n-2]>a[n-1]){
        cout<<-1<<endl;
        return;
    }
    if(a[n-3]>a[n-2] && a[n-2]<a[n-2]-a[n-1]){
        cout<<-1<<endl;
        return;
    }
    int positive=a[n-1];
    int j=n;
    vector<vector<int>>b;
    b.reserve(n);
    for(int i=n-3;i>=0;i--){
        if(a[i]>a[i+1]){
            if(positive<0){
                cout<<-1<<endl;
                return;
            }
            a[i]=a[i+1]-positive;
            b.push_back({i+1,i+2,j});
        }
        if(a[i+1]>=0){
            positive=a[i+1];
            j=i+2;
        }

    }
    if(b.size()>n){
        cout<<-1<<endl;
        return;
    }
    cout<<b.size()<<endl;
    for(int i=0;i<b.size();i++){
        cout<<b[i][0]<<" "<<b[i][1]<<" "<<b[i][2]<<endl;
    }



}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}