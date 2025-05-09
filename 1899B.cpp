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
    vector<int>a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<int>p(n+1,0);
    p[0]=a[0];
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]+a[i];
    }
    long long answer=LLONG_MIN;

    for(int i=1;i<=n;i++){
        if(n%i==0){
            int maxi=LLONG_MIN;
        int mini=LLONG_MAX;
        for(int j=i;j<=n;j+=i){
            int present=p[j]-p[j-i];
            maxi=max(maxi,present);
            mini=min(mini,present);
        }
        answer=max(answer,abs(maxi-mini));
        }
    }
    cout<<answer;



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