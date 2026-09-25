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

set<string> sol(int& i, const string& s){
    int n = s.length();
    set<string> res;
    vector<set<string>> a;
    a.push_back({""});

    while(i < n && s[i] != '}'){
        if(s[i] == ','){
            a.push_back({""});
            i++;
        }
        else{
            set<string> tmp;
            if(s[i] == '{'){
                tmp = sol(++i, s);
                i++;
            }
            else{
                string cur = "";
                while(i < n && 'a' <= s[i] && s[i] <= 'z')
                    cur.push_back(s[i++]);
                tmp.insert(cur);
            }

            set<string> con;
            for(const string& x : a.back())
                for(const string& y: tmp)
                    con.insert(x + y);
            a.back() = con;
        }
    }

    for(const auto& v : a)
        for(const string& x : v)
            res.insert(x);
    return res;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    int i = 0;
    set<string> res = sol(i, s);
    for(const string& x : res) 
        cout<<x<<" ";
    return 0;
}