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
            if(ab){
                for(int i=0;i<s.size();i++){
                    if(i==0 && s[i]=='a' && s[i+1]=='b'){
                        s[i]='b';
                        countAB--;
                    }
                    else if(i==0 && s[i]=='a' && s[i+1]=='a'){
                        s[i]='b';
                        countBA++;
                    }
                    else if(i==s.size()-1 && s[i]=='b' && s[i-1]=='a'){
                        s[i]='a';
                        countAB--;
                    }
                    else if(i==s.size()-1 && s[i]=='b' && s[i-1]=='b'){
                        s[i]='a';
                        countBA++;
                    }

                    if(countAB==countBA){
                        cout<<s<<endl;
                        break;
                    }
                }
            }
            else{
                for(int i=0;i<s.size();i++){
                    if(i==0 && s[i]=='b' && s[i+1]=='b'){
                        s[i]='a';
                        countAB++;
                    }
                    else if(i==0 && s[i]=='b' && s[i+1]=='a'){
                        s[i]='a';
                        countBA--;
                    }
                    else if(i==s.size()-1 && s[i]=='a' && s[i-1]=='a'){
                        s[i]='b';
                        countAB++;
                    }
                    else if(i==s.size()-1 && s[i]=='a' && s[i-1]=='b'){
                        s[i]='b';
                        countBA--;
                    }

                    if(countAB==countBA){
                        cout<<s<<endl;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}