#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;

bool hamming(string &s, string &t){
    int n = s.size();
    if(n != t.size()) return 0;

    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] != t[i]) cnt++;
        if(cnt > 1) return 0;
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    string a[n];
    int b[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];

    int dp[n] = {0}, parent[n];
    memset(parent, -1, sizeof(parent));
    int last = 0;

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(hamming(a[i], a[j]) && dp[i] < dp[j] + 1 && b[i] != b[j]){
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        if(dp[i] > dp[last]) 
            last = i;
    }

    vector<string> res;
    for(int i = last; i >= 0; i = parent[i])
        res.push_back(a[i]);
    reverse(res.begin(), res.end());
    
    for(string x : res) cout<<x<<el;
    return 0;
}