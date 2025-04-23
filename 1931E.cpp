/*
   Author: SONIT RAJ
    created: 22:22:44 23-04-2025
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

    int n,k;
    cin>>n>>k;
    vector<vector<int>>a(n,vector<int>(2));
    int size=0;
    int count=0;
    int flag=0;
    int s=0;
    int x;
    for(int i=0;i<n;i++){
            cin>>x;
            count=0;
            flag=0;
            s=0;
            while(x>0){
                s++;
                if(x%10==0 && flag==0){
                    count++;
                }
                else{
                    flag=1;
                }
                x/=10;
            }
            a[i][0]=count;
            a[i][1]=s;

    }
    sort(a.begin(), a.end(), [](const vector<long long>& c, const vector<long long>& b) {
        return c[0] > b[0];
    });

    for(int i=0;i<n;i++){
        if(i%2==0){
            size+=a[i][1]-a[i][0];
        }
        else{
            size+=a[i][1];
        }
    }
    if(k>=size){
        cout<<"Anna";
    }
    else{
        cout<<"Sasha";
    }





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