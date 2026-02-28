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

    string s, t;
    cin>>s>>t;
    int n = s.length(), m = t.length();
    if(m > n) return cout<<"need tree", 0;

    int cnts[26] = {0}, cntt[26] = {0};
    for(const char& x : s)
        cnts[x - 'a']++;
    
    for(const char& x : t)
        cntt[x - 'a']++;

    int i = 0, j = 0;
    while(i < m && j < n){
        if(s[j] == t[i]) i++;
        j++;
    }
    if(i == m) return cout<<"automaton", 0;

    bool ok = 1, diff = 0;
    for(int i = 0; i < 26; i++)
        if(cnts[i] != cntt[i]){
            ok = 0;
            if(cnts[i] < cntt[i]) diff = 1;
        }

    if(ok && !diff) cout<<"array";
    else if(!ok && !diff) cout<<"both";
    else cout<<"need tree";
    return 0;
}