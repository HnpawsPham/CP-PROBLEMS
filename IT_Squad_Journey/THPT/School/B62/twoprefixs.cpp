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
#define taskname "twoprefixs"

string s, t;

int main(){
    #ifdef taskname
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s>>t;
    int n = s.length();
    int m = t.length();

    string a;
    unordered_set<string> cnt;

    for(int i = 0; i < n; i++){
        a.push_back(s[i]);
        string b;
        for(int j = 0; j < m; j++){
            b.push_back(t[j]);
            cnt.insert(a + b);
        }
    }
    cout<<cnt.size();
    return 0;
}