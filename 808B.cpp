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
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int required=min(k,n-k+1);
    for(int i=1;i<=n;i++){
        if(i<k && n-i<k){
            answer+=1LL*a[i]*required;
        }
        else if(i<=required){
            answer+=1LL*a[i]*min(required,i);
        }
        else{
            answer+=1LL*a[i]*min(required,n-i+1);
        }

    }
    double ans=(1.000000*answer)/(n-k+1);
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