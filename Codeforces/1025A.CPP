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

int n;
string s;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>s;
    int cnt[26] = {0};
    for(const char& x : s)
        cnt[x - 'a']++;

    int d = 0, gr = 0;
    for(int i = 0; i < 26; i++){
        if(!cnt[i]) continue;
        if(cnt[i] == 1) d++;
        gr++;
    }
    cout<<(n > 1 && d == gr ? "No" : "Yes");
    return 0;
}