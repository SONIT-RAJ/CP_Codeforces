/*
   Author: SONIT RAJ
    created: 22:41:08 17-04-2025
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

    vector<int>a={4,8,16,15,23,42};
    vector<int>q(4);
    for(int i=0;i<4;i++){
        cout<<"? "<<i+1<<" "<<i+2<<endl;
        cin>>q[i];
    }
    vector<int>ans(6,0);
    for(int i=3;i<6;i++){
        int s=-1;
        int t=-1;
        for(int j=0;j<4;j++){
            if(q[j]%a[i]==0){
                if(s==-1){
                    s=j;
                }
                else{
                    t=j;
                }
            }
        }
        if(s==-1 && t==-1){
            ans[5]=a[i];
        }
        else if(t==-1){
            if(s==0){
                ans[0]=a[i];
                ans[1]=q[0]/ans[0];
            }
            else{
                ans[4]=a[i];
                ans[3]=q[3]/ans[4];
            }
        }
        else{
            ans[t]=a[i];
            ans[t-1]=q[t-1]/ans[t];
            ans[t+1]=q[t]/ans[t];
        }
    }
    for(int i=0;i<5;i++){
        if(ans[i]==0){
            continue;
        }
        if(i==0){
            ans[1]=q[0]/ans[0];
        }
        else if(i==4){
            ans[3]=q[3]/ans[4];
        }
        else{
            ans[i-1]=q[i-1]/ans[i];
            ans[i+1]=q[i]/ans[i];
        }
    }
    for(int i=0;i<5;i++){
        if(ans[i]==0){
            continue;
        }
        if(i==0){
            ans[1]=q[0]/ans[0];
        }
        else if(i==4){
            ans[3]=q[3]/ans[4];
        }
        else{
            ans[i-1]=q[i-1]/ans[i];
            ans[i+1]=q[i]/ans[i];
        }
    }
    if(ans[5]==0){
        int sum=0;
        for(int i=0;i<6;i++){
            sum+=ans[i];
        }
        ans[5]=108-sum;
    }

    cout<<"! ";
    for(int i=0;i<6;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;





}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}