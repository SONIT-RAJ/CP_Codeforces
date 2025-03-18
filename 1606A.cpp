#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        long long countAB=0;
        long long countBA=0;
        bool ab=false;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='a' && s[i+1]=='b'){
                countAB++;
            }
            else if(s[i]=='b' && s[i+1]=='a'){
                countBA++;
            }
        }
        if(countAB-countBA==0){
            cout<<s<<endl;
        }
        else{
            if(countAB>countBA){
                ab=true;
            }
            for(int i=0;i<s.size()-1;i++){
                if(s[i]=='a' && s[i+1]=='b'){
                    s[i]
                }
                else if(s[i]=='b' && s[i+1]=='a'){
                    countBA++;
                }
            }
        }
    }
    return 0;
}