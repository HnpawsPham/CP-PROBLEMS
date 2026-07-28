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
// #define taskname "CAU3"

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

    int p[n + 1] = {0};
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + (s[i - 1] - '0');

    ll cnt = (p[n] % 3 == 0);
    int mod[3] = {0};
    mod[0] = 1;

    for(int i = 1; i <= n; i++){
       cnt += mod[(p[i] - (p[n] % 3) + 3) % 3];
       mod[p[i] % 3]++;
    }
    cout<<cnt - 1;
    return 0;
}