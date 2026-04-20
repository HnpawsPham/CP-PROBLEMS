#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define hexcode pair<int, pii>
#define fi first
#define se second
//#define taskname ""

const int MOD = 256;

int convert(const char& x){
    if('0' <= x && x <= '9') return x - '0';
   
}

hexcode comp(const string& s, const string& t){
    int r, b, g, r1, g1, b1;
    r = convert(s[1]) * 16 + convert(s[2]);
    g = convert(s[3]) * 16 + convert(s[4]);
    b = convert(s[5]) * 16 + convert(s[6]);

    r1 = convert(t[1]) * 16 + convert(t[2]);
    g1 = convert(t[3]) * 16 + convert(t[4]);
    b1 = convert(t[5]) * 16 + convert(t[6]);
    return hexcode({abs(r - r1 + MOD) % MOD, {abs(g - g1 + MOD) % MOD, abs(b - b1 + MOD) % MOD}});
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    string a[n], b[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];

    map<hexcode, int> mp;
    int cnt = 0;
    for(int i = 0; i < n ;i++){
        hexcode x = comp(a[i], b[i]);
        mp[x]++;
        cnt = max(cnt, mp[x]);
    }
    
    cout<<fixed<<setprecision(2)<<(db)cnt / (db)n * 100<<"%";
    return 0;
}