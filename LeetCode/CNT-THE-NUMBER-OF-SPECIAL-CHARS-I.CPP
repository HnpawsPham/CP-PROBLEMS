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
    vector<bool> checkl(26, 0), checku(26, 0);
    for(const char& x : s){
        if('a' <= x && x <= 'z') checkl[x - 'a'] = 1;
        else checku[x - 'A'] = 1;
    }

    int cnt = 0;
    for(int i = 0; i < 26; i++)
        cnt += checkl[i] && checku[i];
    cout<<cnt;
    return 0;
}