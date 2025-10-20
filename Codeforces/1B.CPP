#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int tc = 1;

string sol(){
    string s;
    cin>>s;
    int n = s.length();

    string res = "";
    if(s[0] == 'R' && s.find('C') != string::npos && isdigit(s[1])){
        int i = 1;
        while(s[i] != 'C'){
            res.push_back(s[i]);
            i++;
        }

        int x = stoi(s.substr(i + 1));
        while(x > 0){
            x--;
            res = char(x % 26 + 'A') + res;
            x /= 26;
        }
    }
    else{
        int i = 0, x = 0;
        while(!isdigit(s[i])){
            x = x * 26 + (s[i] - 'A') + 1;
            i++;
        }
        res = 'R' + s.substr(i);
        res = res + 'C' + to_string(x);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}