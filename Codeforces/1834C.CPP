#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int tc, n;
string s, t;

int sol(){
    int cnts = 0, cntrs = 0;
    string rs = s;
    reverse(rs.begin(), rs.end());

    for(int i = 0; i < n; i++){
        if(s[i] != t[i]) cnts++;
        if(rs[i] != t[i]) cntrs++;
    }
    
    cnts = 2 * cnts - (cnts % 2);
    cntrs = max(2, 2 * cntrs - (1 - cntrs % 2));
    return min(cnts, cntrs);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cin>>n>>s>>t;
        cout<<sol()<<el;
    }

    return 0;
}

// 1
// 6
// yoyoyo
// oyoyoy