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

int cnt[26], n, mid;

bool sol(int i, bool ok, const string& t, string& res){
    if(i > mid){
        string rs = res;
        if(n % 2) rs.pop_back();

        reverse(rs.begin(), rs.end());
        string tmp = res + rs;

        if(tmp > t){
            res += rs;
            return 1;
        }
        return 0;
    }

    //center
    int d = 2 - (i == mid && (n % 2));

    for(char x = (ok ? 'a' : t[i]); x <= 'z'; x++){
        if(cnt[x - 'a'] < d) continue;
        cnt[x - 'a'] -= d;
        res.push_back(x);

        if(sol(i + 1, ok || x > t[i], t, res))
            return 1;

        res.pop_back();
        cnt[x - 'a'] += d;

        if(ok) break;
    }
    return 0;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, t;
    cin>>s>>t;

    n = s.length();
    mid = (n - 1) / 2;

    memset(cnt, 0, sizeof cnt);
    for(const char& x : s)
        cnt[x - 'a']++;

    string res = "";
    if(sol(0, 0, t, res))
        return cout<<res, 0;
    cout<<"";
    return 0;
}

// baba abba
// baba bbaa