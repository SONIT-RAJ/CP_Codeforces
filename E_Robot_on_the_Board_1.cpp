/*
   Author: SONIT RAJ
    created: 01:01:46 12-05-2026
*/


#include<bits/stdc++.h>
using namespace std;

pair<int,int>check(int r,int c,int mid,string &s,int n){
    int l=0;
    int u=0;
    int ml=0;
    int mr=0;
    int md=0;
    int mu=0;
    for(int i=0;i<mid;i++){
        if(s[i]=='L'){
            l--;
        }
        else if(s[i]=='R'){
            l++;
        }
        else if(s[i]=='U'){
            u++;
        }
        else if(s[i]=='D'){
            u--;
        }
        ml=max(ml,l);
        mu=max(mu,u);

        md=min(md,u);
        mr=min(mr,l);
    }
    int x=1+abs(mr);
    int y=1+abs(mu);
    if(x+abs(ml)>c || y+abs(md)>r){
        return {-1,-1};
    }
    return {y,x};
}

// ╭──────────────────────────────╮
// │        SOLVER ZONE           │
// ╰──────────────────────────────╯
void solve(){

    int r,c;
    cin>>r>>c;
    string s;
    cin>>s;
    int n=s.size();
    int low=0;
    int high=n;
    pair<int,int>ans={r,c};
    pair<int,int>no={-1,-1};
    while(low<=high){
        int mid=low+(high-low)/2;
        pair<int,int>temp=check(r,c,mid,s,n);
        if(temp!=no){
            ans=temp;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<ans.first<<" "<<ans.second;




}
// ╭──────────────────────────────╮
// │             MAIN             │
// ╰──────────────────────────────╯
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // precomp_fact();  // Enable if using nCr or factorials
    int _=1;
    cin>>_;
    while(_--){
        solve();
        cout<<"\n";
    }
}