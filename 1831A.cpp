#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            cin>>ans[i];
            cout<<n-ans[i]+1<<" ";
        }
        cout<<endl;

    }
    return 0;
}