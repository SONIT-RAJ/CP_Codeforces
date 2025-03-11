#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        string ans;
        cin>>n;
        cin >>ans;
        int count=0;
        int k=0;
        for(int i=0;i<n;i++){
           if(ans[i]=='.'){
            k++;
            if(k==3){
                count=2;
                break;
            }
            count++;
           }
           else{
            k=0;
           }
        }
        cout<<count<<endl;
    }
    return 0;
}