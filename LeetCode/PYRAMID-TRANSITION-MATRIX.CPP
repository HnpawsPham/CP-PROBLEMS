#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
//#define taskname ""

int n;
string s;
unordered_map<string, vector<char>> mp;
unordered_map<string, bool> memo;

bool sol(string& bot, const vector<string>& a);

bool gen(string& bot, string& cur, int i, const vector<string>& a){
    if(i + 1 == bot.size()){
        if(sol(cur, a)) return 1;
        return 0;
    }

    string tmp = bot.substr(i, 2);
    if(!mp.count(tmp)) return 0;

    for(char x : mp[tmp]){
        cur.push_back(x);
        if(gen(bot, cur, i + 1, a)) return 1;
        cur.pop_back();
    }
    return 0;
}

bool sol(string& bot, const vector<string>& a){
    if(bot.length() == 1) return 1;
    if(memo.count(bot)) return memo[bot];

    string cur;
    return memo[bot] = gen(bot, cur, 0, a);
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s>>n;
    vector<string> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    for(const string& x : a)
        mp[x.substr(0, 2)].push_back(x[2]);
    cout<<sol(s, a);
    return 0;
}

// BCD 4
// BCC CDE CEA FFF

// AAAA 5
// AAB AAC BCD BBE DEF