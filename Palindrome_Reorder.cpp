/*
   Author: SONIT RAJ
    created: 12:24:19 19-10-2025
*/


#include<bits/stdc++.h>
using namespace std;
void solve(){

    string s;
    cin>>s;
    int n=s.size();
    unordered_map<char,int>mpp;
    for(int i=0;i<n;i++){
        mpp[s[i]]++;
    }
    bool flag=true;
    vector<char>a(n);
    int i=0;
    int j=n-1;
    for(auto &x:mpp){
        char key = x.first;
        int v = x.second;
        if(v%2==1){
            if(flag){
                flag=false;
                for(int k=1;k<=v/2;k++){
                    a[i++]=key;
                    a[j--]=key;
                }
                a[n/2]=key;
            }
            else{
                cout<<"NO SOLUTION";
                return;
            }
        }
        else{
            for(int k=1;k<=v/2;k++){
                a[i++]=key;
                a[j--]=key;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i];
    }




}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}