#include <bits/stdc++.h>
using namespace std;
#define el '\n'

string s;
int n;
vector<string> res;
unordered_set<string> st;

void sol(int l, int r, string ss, int len){
    if(r == n){
        if(len == n)
            res.push_back(ss);
        return;
    }

    int m = r - l + 1;
    string tmp = s.substr(l, m);
    if(st.count(tmp))
        sol(r + 1, r + 1, ss + tmp + ' ', len + m);

    sol(l, r + 1, ss, len);
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m;
    cin>>s>>m;
    n = s.length();

    string t[m];
    for(int i = 0; i < m; i++) cin>>t[i];

    for(const string& x : t) st.insert(x);

    sol(0, 0, "", 0);
    for(string x : res) cout<<x<<el;
    return 0;
}

// catsanddog
// 5
// cat
// cats
// and
// sand
// dog