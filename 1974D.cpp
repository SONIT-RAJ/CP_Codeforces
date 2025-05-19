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
    string s;
    cin>>s;
    unordered_map<char,int>mpp;
    for(int i=0;i<n;i++){
        mpp[s[i]]++;
    }
    if((mpp['N']+mpp['S'])%2==1 || (mpp['W']+mpp['E'])%2==1){
        cout<<"NO";
        return;
    }
    bool up=true;
    bool down=true;
    bool right=true;
    bool left=true;
    int flag1=0;
    int flag2=0;
    string ans;
    for(int i=0;i<n;i++){
        if(s[i]=='N'){
            if(up){
                ans.push_back('R');
                flag1=1;
            }
            else{
                ans.push_back('H');
                flag2=1;
            }
            up=(!(up));
        }
        if(s[i]=='S'){
            if(down){
                ans.push_back('R');
                flag1=1;
            }
            else{
                ans.push_back('H');
                flag2=1;
            }
            down=(!(down));
        }
        if(s[i]=='E'){
            if(right){
                ans.push_back('R');
                flag1=1;
            }
            else{
                ans.push_back('H');
                flag2=1;
            }
            right=(!(right));
        }
        if(s[i]=='W'){
            if(left){
                ans.push_back('R');
                flag1=1;
            }
            else{
                ans.push_back('H');
                flag2=1;
            }
            left=(!(left));
        }
    }
    if(flag1==1 && flag2==1){
        cout<<ans;
    }
    else{
        cout<<"NO";
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