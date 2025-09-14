#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

string tolow(string s) {
    for (char &x : s) x = tolower(x);
    return s;
}

bool isvow(char x){
    x = tolower(x);
    if(x == 'a' || x == 'u' || x == 'o' || x == 'i' || x == 'e') return 1;
    return 0;
}

string convert(const string& s){
    string t = s;
    for(char& x : t) 
        if(isvow(x)) x = '.';
    return tolow(t);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<string> a, que;
    int n, m;
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        string s;
        cin>>s;
        a.push_back(s);
    }
    for(int i = 0; i < m; i++){
        string s;
        cin>>s;
        que.push_back(s);
    }

    vector<string> res; 
    unordered_set<string> mp(a.begin(), a.end());
    unordered_map<string, string> low, vow;

    for(const string& x : a){
        string tl = tolow(x);
        string con = convert(x);
        if(!low.count(tl)) low[tl] = x;
        if(!vow.count(con)) vow[con] = x;
    }

    for(const string& x : que){
        if(mp.count(x))
            res.push_back(x);
        else{
            string tl = tolow(x);
            string con = convert(x);
            if(low.count(tl)) res.push_back(low[tl]);
            else if(vow.count(con)) res.push_back(vow[con]);
            else res.push_back("");
        }
    }

    for(const string& x : res) cout<<x<<" ";
    return 0;
}