#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

string normalize(const string& s){
    string res = "";
    int n = s.length();

    for(int i = 1; i < n; i++){
        if(s[i] == ' '){
            if(s[i - 1] == '*' || s[i - 1] == ' ') continue;
            res += ' ';
        }
        else if('0' <= s[i] && s[i] <= '9') 
            res += s[i];
    
        else{
            char c = tolower(s[i]);
            if('a' <= c && c <= 'z') res += c;
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    int i = 0;
    unordered_map<string, int> mp;
    while(getline(cin, s)){
        if(s.empty()) break;
        if(s[0] != '*') continue;
        string tmp = normalize(s);
        mp[tmp]++;
    }

    int maxx = 0;
    for(auto x : mp)
        maxx = max(maxx, x.se);

    vector<string> res;
    for(auto x : mp)
        if(x.se == maxx) res.push_back(x.fi);
    sort(res.begin(), res.end());

    for(const string& x : res) cout<<x<<el;
    return 0;
}