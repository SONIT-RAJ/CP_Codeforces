/*
   Author: SONIT RAJ
    created: 21:52:34 15-04-2025
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
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n<3){
        cout<<"YES";
        return;
    }
    int i=0;
    int j=n-1;
    int removed=0;
    int flag1=1;
    int flag2=1;
    while(i<j){
        if(a[i]==a[j]){
            i++;
            j--;
        }
        else{
            if(removed==0){
                removed=a[j];
                j--;
            }
            else if(removed==a[j]){
                j--;
            }
            else if(removed==a[i]){
                i++;
            }
            else{
                flag1=0;
                break;
            }

        }
    }
    i=0;
    j=n-1;
    removed=0;
    while(i<j){
        if(a[i]==a[j]){
            i++;
            j--;
        }
        else{
            if(removed==0){
                removed=a[i];
                i++;
            }
            else if(removed==a[i]){
                i++;
            }
            else if(removed==a[j]){
                j--;
            }
            else{
                flag2=0;
                break;
            }

        }
    }
    if(flag1 || flag2){
        cout<<"YES";
    }
    else{
        cout<<"NO";
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