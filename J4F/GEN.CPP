#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, len;
    bool z = 0;
    cin>>n;
    string s;
    int maxx = 0;

    while(n--){
        cin>>s;
        len = s.length();

        if(s[0] != '0') z = 1;
        
        while(s[0] == '0')
            s.erase(0, 1);

        maxx = max(maxx, stoi(s));        
    }

    if(z) cout<<maxx<<el;
    else {
        cout<<'1';
        for(int i = 1; i < len; i++) cout<<'0';
        cout<<el;
    }
    
    for(int i = 0; i < len; i++) cout<<9;
    return 0;
}