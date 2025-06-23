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
    vector<int>b;
    b.reserve(n);
    b.push_back(a[0]);
    int pre;
    if(a[1]>a[0]){
        pre=1;
    }
    else{
        pre=0;
    }
    int current;
    for(int i=2;i<n;i++){
        if(a[i]>a[i-1]){
            current=1;
        }
        else{
            current=0;
        }
        if(pre!=current){
            b.push_back(a[i-1]);
            pre=current;

        }
    }
    b.push_back(a[n-1]);
    cout<<b.size()<<endl;
    for(int i=0;i<b.size();i++){
        cout<<b[i]<<" ";
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