#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>ans;
        int flag=0;
        int x;
        cin>>x;
        ans.push_back(x);
        int check=x;
        for(int i=1;i<n;i++){
            cin>>x;
            ans.push_back(x);
            if(check!=x){
                flag=1;
            }
            check=x;
        }
        if(flag==0){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            sort(ans.begin(),ans.end(),greater<int>());
            if(ans[0]==ans[1]){
                swap(ans[0],ans[n-1]);
            }
            for(int i=0;i<n;i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}