#include <bits/stdc++.h>
using namespace std;
#define el '\n'

const int maxn = 4e4 + 1;
int cnt = 0;
bool en[maxn] = {0};
int child[maxn][27];

void add(const string &s){
    int n = s.length();
    int u = 0;

    for(int i = 0; i < n; i++){
        int k = (s[i] == '/' ? 26 : s[i] - 'a');  
        if(!child[u][k]) child[u][k] = ++cnt;
        u = child[u][k];
    }
    en[u] = 1;
    return;
}

bool query(const string& s){
    int n = s.length();
    int u = 0;

    for(int i = 0; i < n; i++){
        int k = (s[i] == '/' ? 26 : s[i] - 'a');  
        u = child[u][k];
        if(!u) return 0;

        if(en[u] && i < n - 1 && s[i + 1] == '/') return 1;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<string> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a.begin(), a.end());

    vector<string> res;
    for(const string& s : a)
        if(!query(s)) {
            add(s);
            res.push_back(s);
        }
    
    for(string& x : res) cout<<x<<el;
    return 0;
}

// 5
// /a
// /a/b
// /c/d
// /c/d/e
// /c/f