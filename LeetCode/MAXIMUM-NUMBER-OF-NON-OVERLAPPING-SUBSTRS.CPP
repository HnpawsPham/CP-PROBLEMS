#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define vs vector<string>
#define fi first
#define se second
//#define taskname ""

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

    int n = s.length();
    int last[26], prev[26];
    memset(prev, -1, sizeof prev);
    memset(last, -1, sizeof last);

    for(int i = 0; i < n; i++){
        if(prev[s[i] - 'a'] == -1) 
            prev[s[i] - 'a'] = i;
        last[s[i] - 'a'] = i;
    }

    vector<pii> a;
    for(int i = 0; i < 26; i++){
        if(prev[i] == -1) continue;

        bool ok = 1;
        int l = prev[i], r = last[i];
        for(int j = l; j <= r && ok; j++){
            if(prev[s[j] - 'a'] < l) 
                ok = 0;
            r = max(r, last[s[j] - 'a']);
        }

        if(ok) a.push_back({r, l});
    }

    sort(a.begin(), a.end());
    vector<string> res;
    int rlast = -1;
    for(const auto& [r, l]: a){
        if(l > rlast){
            res.push_back(s.substr(l, r - l + 1));
            rlast = r;
        }
    }

    for(const string& x : res) 
        cout<<x<<" ";
    return 0;
}