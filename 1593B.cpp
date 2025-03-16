#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        string str = to_string(n);
        int count=0;
        bool flag0=false;
        bool flag5=false;

        for(int i=str.size()-1;i>=0;i--){
            if(flag5 && (str[i]=='7' || str[i]=='2')){
                if(flag0){
                    cout<<++count<<endl;
                    break;
                }
                cout<<count<<endl;
                break;
            }
            else if(flag0 && (str[i]=='0' || str[i]=='5')){
                if(flag5){
                    cout<<++count<<endl;
                    break;
                }
                cout<<count<<endl;
                break;
            }
            else if(str[i]!='0' && str[i]!='5'){
                count++;
            }
            else{
                if(str[i]=='0'){
                    flag0=true;
                }
                else if(flag5){
                    count++;
                }
                else{
                    flag5=true;
                }
            }
        }
    }
    return 0;
}