/*
   Author: SONIT RAJ
    created: 01:21:57 13-10-2025
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
    vector<int>a(60,0);
    int maxi=-1;
    int mini=-1;
    for(int i=0;i<30;i++){
        if((n&(1<<i))!=0){
            a[i]++;
            maxi=i;
            if(mini==-1){
                mini=i;
            }
        }
    }
    int i=maxi+mini;
    int j=0;
    while(i>=j){
        if(i==j){
            if(a[i]==1){
                cout<<"NO";
                return;
            }
            else{
                break;
            }
        }
        else if(a[i]!=a[j]){
            cout<<"NO";
            return;
        }
        i--;
        j++;
    }
    cout<<"YES";


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