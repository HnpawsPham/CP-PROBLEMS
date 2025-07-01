#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string str;

bool checkSum (string s, int n){
    int sum = 0, d = 1, pos;
    string ss = "";

    for(int i = 0; i < n;i++){
        if(!isdigit(s[i])){
            if(!ss.empty()) sum += stoi(ss) * d;
            ss = "";

            if(s[i] == '-') d = -1;
            else if(s[i] == '+') d = 1;
            else {
                if(!ss.empty()) sum += stoi(ss) * d;
                pos = i + 1;
                break;
            }
        } else ss += s[i];
    }
    for(int i = pos; i < n; i++){
        ss += s[i];
    }
    return sum == stoi(ss);
}

int solve(string s, int n){
    if(!checkSum(s, n)) {
        solve(s, n + 1);
    }

    return 0;
}

int main(){
    freopen(".\\txt\\ADDITIVE-NUMBER.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>str;
    
    if(str.length() < 3){
        cout<<"false"<<el;
        return 0;
    }

    cout<<checkSum("11+22=34233", 11)<<el;


    return 0;
}