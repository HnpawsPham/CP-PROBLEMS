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

int tc = 1;
int cnts[26], cntt[26];

string sol(){
    int n, k;
    string s, t;
    cin>>n>>k>>s>>t;

    memset(cnts, 0, sizeof cnts);
    memset(cntt, 0, sizeof cntt);
    for(int i = 0; i < n; i++){
        cnts[s[i] - 'a']++;
        cntt[t[i] - 'a']++;
    }
    if(memcmp(cnts, cntt, sizeof cnts) != 0) return "NO";

    for(int i = 0; i < n; i++){
        if((i < k && i + k >= n) && s[i] != t[i]) 
            return "NO";
    }
    return "YES";
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}