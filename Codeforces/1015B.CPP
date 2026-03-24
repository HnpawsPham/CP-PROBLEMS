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

    int n;
    string s, t;
    cin>>n>>s>>t;
    vi cnts(26, 0), cntt(26, 0);
    for(const char& x : s) cnts[x - 'a']++;
    for(const char& x : t) cntt[x - 'a']++;

    if(cnts != cntt) return cout<<-1, 0;

    vi res;
    for(int i = 0; i < n; i++){
        if(s[i] == t[i]) continue;
        int j = i + 1;
        while(j < n && s[j] != t[i]) j++;
        while(j > i){
            swap(s[j], s[j - 1]);
            res.push_back(j--);
        }
    }    

    cout<<res.size()<<el;
    for(int x : res) cout<<x<<" ";
    return 0;
}