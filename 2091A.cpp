/*
   Author: SONIT RAJ
    created: 00:28:43 06-04-2025
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
    vector<int>a(n);
    int ans=0;
    int count0=0;
    int count1=0;
    int count3=0;
    int count2=0;
    int count5=0;
    int flag=0;

    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==0){
            count0++;
        }
        else if(a[i]==3){
            count3++;
        }
        else if(a[i]==1){
            count1++;
        }
        else if(a[i]==2){
            count2++;
        }
        else if(a[i]==5){
            count5++;
        }
        if(count0>=3 && count1>=1 && count2>=2 && count3>=1 && count5>=1 && flag==0){
            ans=i+1;
            flag=1;
        }
    }
    cout<<ans;



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