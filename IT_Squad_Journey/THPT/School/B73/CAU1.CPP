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
#define taskname "CAU1"

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

    int a;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '?') a = i + 1;
        else sum += 1LL * (s[i] - '0') * (i + 1);
    }

    for(int i = 0; i < 10; i++){
        if(i == 0 && a == 1) continue;
        if((sum + 1LL * a * i) % 7 == 0) 
            return cout<<i, 0;
    }
    cout<<-1;
    return 0;
}