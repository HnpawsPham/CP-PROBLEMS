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
    int cnt[26];
    memset(cnt, 0, sizeof cnt);
    for(const char& x : s)
        cnt[x - 'A']++;

    int res = 0, odd = 0;
    for(int i = 0; i < 26; i++){
        if(cnt[i] == n) return cout<<-1, 0;
        if(cnt[i] % 2) odd++;
        res += cnt[i] / 2;
    }
    if(odd == 0) cout<<res - 1;
    else cout<<res - (odd == 1) + 1;
    return 0;
}