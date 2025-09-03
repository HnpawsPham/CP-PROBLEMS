#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    freopen("THUGON.INP", "r", stdin);
    freopen("THUGON.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    while(1){
        getline(cin, s);
        if(s.empty()) break;

        int cnt = 0, n = s.length();
        string res = "";

        for(int i = 1; i < n; i++){
            if(s[i] == s[i - 1]) cnt = cnt + 1 + (i == 1);
     
            else {
                if(cnt > 1) res += to_string(cnt);
                res += s[i - 1];
                cnt = 1;
            }
        }
        if(cnt > 1) res += to_string(cnt);
        res += s[n - 1];
        cout<<res<<el;
    }

    return 0;
}