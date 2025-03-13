#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>ans(n);
        cin>>ans[0];
        for(int i=1;i<n;i++){
            cin>>ans[i];
            if(ans[i]<ans[i-1]){
                swap(ans[i],ans[i-1]);
            }
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;

    }
    return 0;
}