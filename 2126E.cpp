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

int lcm(int a,int b){
    return (a*b)/(__gcd(a,b));
}

void solve(){

    int n;
    cin>>n;
    vector<int>p(n);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    vector<int>s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=1;i<n;i++){
        if(p[i]>p[i-1] || s[i]<s[i-1]){
            cout<<"NO";
            return;
        }
        if(p[i]!=__gcd(p[i],p[i-1]) || s[i-1]!=__gcd(s[i],s[i-1])){
            cout<<"NO";
            return;
        }
    }
    if(p[n-1]!=s[0] || __gcd(p[0],p[n-1])!=p[n-1] || __gcd(s[n-1],s[0])!=s[0] || s[0]>__gcd(p[0],s[n-1])){
        cout<<"NO";
    }
    else{
        int g=__gcd(p[0],s[0]);
        for(int i=1;i<n;i++){
            if(g!=__gcd(p[i],s[i])){
                cout<<"NO";
                return;
            }
        }
        for(int i=0;i<n-1;i++){
            if(g!=__gcd(p[i],s[i+1])){
                cout<<"NO";
                return;
            }
        }
        cout<<"YES";

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