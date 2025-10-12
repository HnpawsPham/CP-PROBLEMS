#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, m;
const int maxn = 1005;

bool check(const string& s, const string& t){
    int n = s.length(), m = t.length();
    int i = 0, j = 0;
    while(i < n && j < m){
        if(tolower(s[i]) == tolower(t[j])) j++;
        i++;
    }
    return (j == m);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    string a[n], b[m];
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++) cin>>b[i];

    int cnt[n] = {0};
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(check(a[i], b[j])) cnt[i]++;

    for(int x: cnt) cout<<x<<el;
    return 0;
}