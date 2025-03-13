#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int x;
        cin>>x;
        int flag=0;
        if(x%2==0){
            flag=0;
        }
        else{
            flag=1;
        }
        int c=0;
        for(int i=1;i<n;i++){
            cin>>x;
            if(x%2==flag){
                c++;
            }
            else{
                flag=!(flag);
            }
        }
        cout<<c<<endl;
    }
    return 0;
}