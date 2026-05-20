/*
   Author: SONIT RAJ
    created: 21:43:19 20-05-2026
*/


#include<bits/stdc++.h>
using namespace std;



#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
vector<int>seg1,seg2;


void build1(int i,int low,int high,vector<int>&a){
    if(low>=high){
        seg1[i]=a[low];
        return;
    }
    int mid=low+((high-low)>>1);
    build1(2*i+1,low,mid,a);
    build1(2*i+2,mid+1,high,a);
    seg1[i]=max(seg1[2*i+1],seg1[2*i+2]);
}

void build2(int i,int low,int high,vector<int>&a){
    if(low>=high){
        seg2[i]=a[low];
        return;
    }
    int mid=low+((high-low)>>1);
    build2(2*i+1,low,mid,a);
    build2(2*i+2,mid+1,high,a);
    seg2[i]=min(seg2[2*i+1],seg2[2*i+2]);
}

int q1(int i,int low,int high,int start,int end){
    if(low>end || high<start){
        return -2e9;
    }
    if(start<=low && high<=end){
        return seg1[i];
    }
    int mid=low+((high-low)>>1);
    return max(q1(2*i+1,low,mid,start,end),q1(2*i+2,mid+1,high,start,end));
}

int q2(int i,int low,int high,int start,int end){
    if(low>end || high<start){
        return 2e9;
    }
    if(start<=low && high<=end){
        return seg2[i];
    }
    int mid=low+((high-low)>>1);
    return min(q2(2*i+1,low,mid,start,end),q2(2*i+2,mid+1,high,start,end));
}

// ╭──────────────────────────────╮
// │        SOLVER ZONE           │
// ╰──────────────────────────────╯
void solve(){

    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>b(n);
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    seg1.resize(4*n);
    seg2.resize(4*n);
    build1(0,0,n-1,a);
    build2(0,0,n-1,b);
    long long ans=0;
    for(int i=0;i<n;i++){
        int low=i;
        int high=n-1;
        int right=high+1;
        while(low<=high){
            int mid=low+((high-low)>>1);
            int up=q1(0,0,n-1,i,mid);
            int down=q2(0,0,n-1,i,mid);
            if(up>down){
                right=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        low=i;
        high=n-1;
        int left=i-1;
        while(low<=high){
            int mid=low+((high-low)>>1);
            int up=q1(0,0,n-1,i,mid);
            int down=q2(0,0,n-1,i,mid);
            if(up<down){
                left=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        ans+=max(0,right-left-1);
    }

    cout<<ans;


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