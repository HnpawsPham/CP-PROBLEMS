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

    int n = s.length();
    int d[n + 1] = {0};
    int cnt = 0;
    for(const char& x : s){
        if(x == '7'){
            cnt++;
            d[1]++;
            d[cnt + 1]--;     
        }
        else cnt = 0;
    }

    for(int i = 1; i <= n; i++)
        d[i] += d[i - 1];

    for(int i = 1; i <= n; i++)
        if(d[i]) cout<<i<<" "<<d[i]<<el;
    return 0;
}