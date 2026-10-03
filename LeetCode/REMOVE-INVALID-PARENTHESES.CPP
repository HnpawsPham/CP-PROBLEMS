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

int n, minn = 25;
unordered_set<string> res;

void sol(int i, int d, int cnt, string& s){
    if(cnt > minn) return;
    if(i == n){
        if(d == 0){
            if(cnt < minn){
                res.clear();
                minn = cnt;
            }
            if(cnt == minn){
                string t = "";
                for(const char& x : s)
                    if(x != '_')
                        t.push_back(x);
                res.insert(t);
            }
        }
        return;
    }

    int val;
    if(s[i] == '(') val = 1;
    else if(s[i] == ')') val = -1;
    else val = 0;

    if(d + val >= 0)
        sol(i + 1, d + val, cnt, s);

    if('a' <= s[i] && s[i] <= 'z')
        return;
    char tmp = s[i];
    s[i] = '_';
    sol(i + 1, d + 0, cnt + 1, s);
    s[i] = tmp;
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

    n = s.length();
    sol(0, 0, 0, s);
    for(const string& x : res)
        cout<<x<<" ";
    return 0;
}