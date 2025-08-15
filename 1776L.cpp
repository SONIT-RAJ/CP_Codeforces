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

void solvee(int plus,int minus){
    int a,b;
    cin>>a>>b;
    if(a>b){
        swap(a,b);
    }
    int l=(a*b)/__gcd(a,b);
    int l1=l/a;
    int l2=l/b;
    int t=l1-l2;
    int fine=plus-minus;
    if(fine==0){
        cout<<"YES";
        return;
    }
    if(t==0){
        if(fine==0){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
        return;
    }
    if(fine%t==0 && abs((fine/t)*(l1+l2))<=plus+minus){//needs modification
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }

}

void solve(){

    int n;
    cin>>n;
    string s;
    cin>>s;
    int plus=0;
    int minus=0;
    for(int i=0;i<n;i++){
        if(s[i]=='+')plus++;
        else minus++;
    }
    int q;
    cin>>q;
    while(q--){
        solvee(plus,minus);
        cout<<"\n";
    }




}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}