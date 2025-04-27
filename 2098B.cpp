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

    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int flag=0;
    int first=0;
    int last=0;
    for(int i=0;i<n;i++){
        if(abs(i-n+1+i)<=k+1){
            if(flag==0){
                flag=1;
                first=a[i];
                last=a[i];
            }
            else{
                last=a[i];
            }
        }
    }
    cout<<last-first+1;



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