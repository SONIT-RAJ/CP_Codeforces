#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]==1){
                a[i]++;
            }
            if(i!=0 && a[i]%a[i-1]==0){
                a[i]++;
            }
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}