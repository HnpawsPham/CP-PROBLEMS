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

int tc = 1;
vi p;

void sieve(){
    for(int i = 2; i < 100; i++){
        bool ok = 1;
        for(int j = 2; j < i && ok; j++)
            if(i % j == 0) ok = 0;
        if(ok) p.push_back(i);
    }
    return;
}

void sol(){
    int n;
    string s;
    cin>>n>>s;

    sieve();
    for(int i = 0; i < n; i++)
        if(find(p.begin(), p.end(), s[i] - '0') == p.end()){
            cout<<1<<el<<s[i] - '0';
            return;
        }

    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++){
            int x = (s[i] - '0') * 10 + (s[j] - '0');
            if(find(p.begin(), p.end(), x) == p.end()){
                cout<<2<<el<<x;
                return;
            }
        }
    return;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        sol();
        cout<<el;
    }
    return 0;
}