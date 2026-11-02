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

    vi pos[26];
    int n = s.length();
    for(int i = 0; i < n; i++)
        pos[s[i] - 'a'].push_back(i);
    
    int cnt = 1, cur = -1;
    for(const char& x : t){
        int i = x - 'a';
        if(pos[i].empty()) 
            return cout<<-1, 0;

        auto it = upper_bound(pos[i].begin(), pos[i].end(), cur);
        if(it == pos[i].end()){
            cnt++;
            cur = pos[i][0];
        }
        else cur = *it;
    }
    cout<<cnt;
    return 0;
}