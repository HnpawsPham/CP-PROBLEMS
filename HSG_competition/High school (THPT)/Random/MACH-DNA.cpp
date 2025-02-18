#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string str;
unordered_map<char, char> mp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>str;
    int n = str.length();
    string res = "";
    string t = "";

    mp.insert({'A', 'T'});
    mp.insert({'T', 'A'});
    mp.insert({'G', 'C'});
    mp.insert({'C', 'G'});

    for(int i = 0; i<n; i++){
        if('0' <= str[i] && str[i] <= '9') t += str[i];
        else {
            int num = stoi(t);
            for(int j = 0; j < num; j++) res += mp[str[i]]; 
            t = ""; 
        }
    }

    cout<<res;

    return 0;
}