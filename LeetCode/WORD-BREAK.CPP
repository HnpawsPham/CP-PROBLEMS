#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string s;
int m, id = 0;
const int maxn = 305;
int child[maxn * 20][26] = {{0}};
bool check[maxn * 20] = {0},
     dp[maxn] = {0};

void add(string& s){
    int n = s.length();
    int u = 0;

    for(int i = 0; i < n; i++){
        int k = s[i] - 'a';
        if(!child[u][k]) child[u][k] = ++id;
        u = child[u][k];
    }
    check[u] = 1;
    return;
}

bool sol(string& s){
    int n = s.length();

    for(int i = 0; i < n; i++){
        if(!dp[i]) continue;
        int u = 0;

        for(int j = i; j < n; j++){
            u = child[u][s[j] - 'a'];
            if(!u) break;

            if(check[u]) dp[j + 1] = 1;
        }
    }
    return dp[n];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s>>m;
    vector<string> a(m);
    for(int i = 0; i < m; i++) cin>>a[i];

    for(string x : a) add(x);

    // unordered_set<string> dict(a.begin(), a.end());

    // int n = s.length();
    // vector<bool> dp(n + 1, 0);
    // dp[0] = 1;

    // for(int i = 1; i <= n; i++){
    //     for(int j = 0; j < i; j++){
    //         if(dp[j] && dict.count(s.substr(j, i - j))) {
    //             dp[i] = 1;
    //             break;
    //         }
    //     }
    // }

    dp[0] = 1;
    cout<<sol(s);
    return 0;
}