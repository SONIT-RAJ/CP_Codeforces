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

vector<int>x,y;

bool cmpx(int &i,int &j){
    return x[i]<x[j];
}
bool cmpy(int &i,int &j){
    return y[i]<y[j];
}

void solve(){

    int n;
    cin>>n;
    x.resize(n);
    y.resize(n);
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    vector<int>a(n);
    for(int i=0;i<n;i++){
        a[i]=i;
    }
    sort(a.begin(),a.end(),cmpx);
    sort(a.begin(),a.begin()+n/2,cmpy);
    sort(a.begin()+n/2,a.end(),cmpy);
    for(int i=0;i<n/2;i++){
        cout<<a[i]+1<<" "<<a[n-1-i]+1<<"\n";
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