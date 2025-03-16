#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        int flag=1;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(i>=2){
                if(a[i-2]<a[i-1] && a[i-1]>a[i] && flag==1){
                    flag=0;
                    cout<<"YES"<<endl;
                    cout<<i-1<<" "<<i<<" "<<i+1<<endl;
                }
            }
        }
        if(flag){
            cout<<"NO"<<endl;
        }

    }
    return 0;
}