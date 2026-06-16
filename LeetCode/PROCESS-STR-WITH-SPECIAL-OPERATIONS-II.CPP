#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\m'
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
    ll k;
    cin>>s>>k;

    ll m = 0;
    int n = s.size();
    vector<ll> sz(n, 0);
    for(int i = 0; i < n; i++){
        if(s[i] == '*' && m > 0) m--;
        if('a' <= s[i] && s[i] <= 'z') m++;
        if(s[i] == '#') m *= 2;
        sz[i] = m;
    }    

    if(k >= m) return cout<<'.', 0;

    for(int i = n - 1; i >= 0; i--){
        ll prev = (i > 0 ? sz[i - 1] : 0);

        if(s[i] == '#' && k >= prev) 
            k -= prev;

        if(s[i] == '%')
            k = prev - k - 1;

        if('a' <= s[i] && s[i] <= 'z' && k == prev) 
            return cout<<s[i], 0;
    }
    cout<<'.';
    return 0;
}

// a#b%*
// 1