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
    long long answer=0;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(n-i<=k && i+1<=k){
            int r=min(k,i+1);
            answer+=a[i]*r;
        }
        else if(i+1<=k){
            int r=min(k,i+1);
            answer+=a[i]*r;
        }
        else if(n-i<=k){
            int r=min(k,n-i);
            answer+=a[i]*r;
        }
    }
    double ans=(1.0*answer)/(n-k+1);
    cout << fixed << setprecision(6) << ans << endl;



}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
        cout<<"\n";
    }
}