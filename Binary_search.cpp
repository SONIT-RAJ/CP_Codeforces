/*

Problem link - https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/Z

Codeforces  - Z. Binary Search

Date- 07/03/2025

*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n;
    cin>>q;
    vector<int>ans(n,0);
    for(int i=0;i<n;i++){
        cin >>ans[i];
    }
    sort(ans.begin(),ans.end());
    while(q--){
        int target;
        cin >>target;
        int low=0;
        int high=n-1;
        int flag=0;
        while(low<=high){
            int mid=low+((high-low)/2);
            if(ans[mid]==target){
                cout <<"found"<<endl;
                flag=1;
                break;
            }
            else if(ans[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        if(flag==0){
            cout<<"not found"<<endl;
        }
    }
    return 0;
}