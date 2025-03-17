#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        if(n-k==1){
            cout<<"YES"<<endl;
            continue;
        }
        unordered_map<char,int>mpp;
        int count=0;
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
        }
        for(auto it=mpp.begin();it!=mpp.end();++it){
            if((it->second)%2==1){
                count++;
            }
        }
        if((n-k)%2==1){
            count--;
        }
        if(count==k){
            cout<<"YES"<<endl;
        }
        else if(count<k && (k-count)%2==0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }
    return 0;
}