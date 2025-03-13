#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>ans(n);
        int product=0;
        for(int i=0;i<n;i++){
            cin>>ans[i];
            if(ans[i]==2){
                product++;
            }
        }
        if(product%2==1){
            cout<<-1<<endl;
            continue;
        }
        product/=2;
        int present=0;
        for(int i=0;i<n;i++){
            if(ans[i]==2){
                present++;
            }
            if(present==product){
                cout<<i+1<<endl;
                break;
            }
        }
    }
    return 0;
}