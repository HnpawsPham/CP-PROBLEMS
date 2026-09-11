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
    cin>>n;
    string s, t;

    cin.ignore();
    getline(cin, s);
    stringstream ss(s);

    int maxx = 0;
    while(ss >> t){
        int cnt = 0;
        for(const char& x: t)
            cnt += ('A' <= x && x <= 'Z');
        maxx = max(maxx, cnt);
    }
    cout<<maxx;
    return 0;
}