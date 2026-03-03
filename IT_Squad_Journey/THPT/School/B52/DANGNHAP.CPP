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
#define taskname "DANGNHAP"

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s, t = "login";
    cin>>n;

    vi res;
    for(int i = 1; i <= n; i++){
        cin>>s;
        int cnt = 0;
        for(const char& x : s){
            if(x == t[cnt]) cnt++;
            if(cnt == 5) break;
        }
        if(cnt == 5) res.push_back(i);
    }

    cout<<res.size()<<el;
    for(int x : res) cout<<x<<" ";
    return 0;
}