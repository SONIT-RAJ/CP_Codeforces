/*
   Author: SONIT RAJ
    created: 00:23:53 12-05-2026
*/


#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin>>n;
    vector<int>a(n);
    string b;
    vector<int>mpp(3,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        b.push_back('0');
        mpp[a[i]%3]++;
    }
    if(mpp[0]<=n/2){
        cout<<0<<endl;
        for(int i=0;i<n;i++){
            if(a[i]%3==0){
                b[i]='1';
            }
        }
        int req=n/2-mpp[0];
        for(int i=0;i<n;i++){
            if(b[i]=='1')continue;
            if(req>0){
                req--;
                b[i]='1';
            }
        }
        cout<<b;
    }
    else{
        cout<<2<<endl;
        for(int i=0;i<n;i++){
            if(a[i]%3!=0){
                b[i]='1';
            }
        }
        int req=n/2-mpp[1]-mpp[2];
        for(int i=0;i<n;i++){
            if(b[i]=='1')continue;
            if(req>0){
                req--;
                b[i]='1';
            }
        }
        cout<<b;
    }



}
// ╭──────────────────────────────╮
// │             MAIN             │
// ╰──────────────────────────────╯
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--){
        solve();
    }
}