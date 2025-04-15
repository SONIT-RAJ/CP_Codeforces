/*
   Author: SONIT RAJ
    created: 19:23:26 15-04-2025
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
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int i=1;
    int j=n;
    int left=a[i];
    int right=a[j];
    int count=0;
    while(i<j){
        if(left>right){
            j--;
            if(i>=j){
                break;
            }
            right+=a[j];
        }
        else if(left<right){
            i++;
            if(i>=j){
                break;
            }
            left+=a[i];
        }
        else{
            count=i+n-j+1;
            i++;
            if(i>=j){
                break;
            }
            left+=a[i];
        }
    }
    cout<<count;



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