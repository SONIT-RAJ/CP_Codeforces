/*

Problem link - https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/Q

Codeforces  - Q. Count Subarrays

Date- 07/03/2025

*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >>n;
        int count=1;
        int temp=1;
        int first;
        cin>>first;
        for(int i=1;i<n;i++){
            int present;
            cin>>present;
            if(first<=present){
                first=present;
                temp++;
                count+=temp;
            }
            else{
                first=present;
                temp=1;
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}