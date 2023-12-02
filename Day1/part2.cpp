
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include<bits/stdc++.h>
using namespace std;

map<char,vector<string>>mp={
    {'o',{"one"}},{'t',{"two","three"}},{'f',{"four","five"}},{'s',{"six","seven"}},{'e',{"eight"}},{'n',{"nine"}}
};
map<string, char> num={
    {"one",'1'},
    {"two",'2'},
    {"three",'3'},
    {"four",'4'},
    {"five",'5'},
    {"six",'6'},
    {"seven",'7'},
    {"eight",'8'},
    {"nine",'9'}
};

int main() {
    // Open the file
    ifstream inputFile("data.txt");
    int ans=0;

    // Check if the file is open
    if (!inputFile.is_open()) {
        cerr << "Error opening the file." <<endl;
        return 1;
    }
    

    string line;
    while (getline(inputFile, line)) {
        // Check if the line is empty (blank line)
        string s=line;
        string temp="";
        bool flag1=false,flag2=false;

        for(int i=0;i<s.size();i++){
            if(flag1)break;
            if(s[i]-'0'>=0 && s[i]-'0'<=9){
                temp+=s[i];
                flag1=true;
            }
            else{
                for(auto it:mp[s[i]]){
                    if(flag1) break;
                    if(s.size()-i>=it.size()){
                        if(num.find(s.substr(i,it.size()))!=num.end()){
                            temp+=num[s.substr(i,it.size())];
                            flag1=true;
                        }
                    }
                }
            }
        }
        for(int i=s.size()-1;i>=0;i--){
            if(flag2) break;
            if(s[i]-'0'>=0 && s[i]-'0'<=9){
                temp+=s[i];
                flag2=true;
            }
            else{
                for(auto it:mp[s[i]]){
                    if(flag2) break;
                    if(s.size()-i>=it.size()){
                        if(num.find(s.substr(i,it.size()))!=num.end()){
                            temp+=num[s.substr(i,it.size())];
                            flag2=true;
                        }
                    }
                }
            }
            
        }
        cout<<temp<<endl;
        ans+=(((temp[0]-'0')*10)+(temp[1]-'0'));
       
    }

    // Close the file
    inputFile.close();
    cout<<ans<<endl;


    return 0;
}

