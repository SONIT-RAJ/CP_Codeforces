/*
   Author: SONIT RAJ
    created: 19:08:53 12-06-2025
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

int N = 1e5;
vector<vector<int>> divisors(N+1);

bool isP(int n){
    if(divisors[n].size()==2){
        return true;
    }
    return false;
}


void solve(){

    int n;
    cin>>n;
    if(isP(n)){
        cout<<"NO";
        return;
    }
    for(int i=1;i<divisors[n].size();i++){
        if(divisors[n][i]*divisors[n][i]>n){
            break;
        }
        int f1=divisors[n][i];
        int f2=n/divisors[n][i];
        if(isP(f1) && isP(f2)){
            break;
        }
        if(isP(f1)){
            if(divisors[f2].size()>4 || f2%f1!=0){
                cout<<"YES";
                return;
            }
        }
        if(isP(f2)){
            if(divisors[f1].size()>4 || f1%f2!=0){
                cout<<"YES";
                return;
            }
        }
        if(isP(f1)==false && isP(f2)==false){
            cout<<"YES";
            return;
        }



    }
    cout<<"NO";




}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            divisors[j].push_back(i);
        }
    }
    int t=1;
    cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
}