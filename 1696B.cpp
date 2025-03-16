#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        int together=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if((i==0 && a[i]!=0) || (i!=0 && a[i-1]==0 && a[i]!=0)){
                together++;
            }
        }
        if(together<=1){
            cout<<together<<endl;
        }
        else{
            cout<<2<<endl;
        }

    }
    return 0;
}