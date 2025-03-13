#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int x;
        cin>>x;
        int y=x;
        vector<int>ans;
        ans.push_back(y);
        for(int i=1;i<n;i++){
            cin>>x;
            if(x>=y){
                ans.push_back(x);
            }
            else{
                ans.push_back(x);
                ans.push_back(x);
            }
            y=x;
        }
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}