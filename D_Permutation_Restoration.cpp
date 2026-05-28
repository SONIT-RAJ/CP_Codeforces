/*
   Author: SONIT RAJ
    created: 22:44:58 27-05-2026
*/


#include<bits/stdc++.h>
using namespace std;


bool cmp(vector<int>&a,vector<int>&b){
    if(a[0]!=b[0]){
        return a[0]<b[0];
    }
    return a[1]<b[1];
}


vector<int>seg1;

void build1(int i,int low,int high,vector<vector<int>>&a){
    if(low>=high){
        seg1[i]=low;
        return;
    }
    int mid=low+((high-low)>>1);
    build1(2*i+1,low,mid,a);
    build1(2*i+2,mid+1,high,a);
    int left=seg1[2*i+1];
    int right=seg1[2*i+2];
    if(a[left][1]<=a[right][1]){
        seg1[i]=left;
    }
    else{
        seg1[i]=right;
    }
}

int q2(int i,int low,int high,int start,int end,int &n,vector<vector<int>>&a){
    if(low>end || high<start){
        return 2e9;
    }
    if(start<=low && high<=end){
        return seg1[i];
    }
    int mid=low+((high-low)>>1);
    int left=q2(2*i+1,low,mid,start,end,n,a);
    int right=q2(2*i+2,mid+1,high,start,end,n,a);
    if(left>n){
        return right;
    }
    else if(right>n){
        return left;
    }
    else{
        if(a[left][1]<=a[right][1]){
            return left;
        }
        else{
            return right;
        }
    }
}

void upd(int i,int low,int high,int idx,int val,vector<vector<int>>&a){
    if(low>=high){
        a[low][1]=val;
        return;
    }
    int mid=low+((high-low)>>1);
    if(idx<=mid){
        upd(2*i+1,low,mid,idx,val,a);
    }
    else{
        upd(2*i+2,mid+1,high,idx,val,a);
    }
    int left=seg1[2*i+1];
    int right=seg1[2*i+2];
    if(a[left][1]<=a[right][1]){
        seg1[i]=left;
    }
    else{
        seg1[i]=right;
    }
}

// ╭──────────────────────────────╮
// │        SOLVER ZONE           │
// ╰──────────────────────────────╯
void solve(){

    int n;
    cin>>n;
    vector<int>a(n);
    vector<vector<int>>b(n,vector<int>(3));
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]!=0){
            int big=(i+1)/a[i];
            int small=(i+1)/(a[i]+1);
            b[i]={small+1,big,i+1};
        }
        else{
            b[i]={i+2,n,i+1};
        }
    }
    seg1.resize(4*n);
    sort(b.begin(),b.end(),cmp);
    build1(0,0,n-1,b);
    vector<int>ans(n+1,0);
    for(int i=1;i<=n;i++){
        auto it=upper_bound(b.begin(),b.end(),vector<int>{i,INT_MAX,INT_MAX});
        int idx=it-b.begin();
        int mini_idx=q2(0,0,n-1,0,idx-1,n,b);
        ans[b[mini_idx][2]]=i;
        upd(0,0,n-1,mini_idx,1e9,b);
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }




}
// ╭──────────────────────────────╮
// │             MAIN             │
// ╰──────────────────────────────╯
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--){
        solve();
        cout<<"\n";
    }
}