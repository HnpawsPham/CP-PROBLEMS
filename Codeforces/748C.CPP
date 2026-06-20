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

int mp(char x){
    if(x == 'U') return 0;
    if(x == 'L') return 1;
    if(x == 'D') return 2;
    return 3;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin>>n>>s;

    bool check[4] = {0}; // U L D R
    int cnt = 1;
    for(const char& x : s){
        if(check[(mp(x) + 2) % 4]){
            cnt++;
            for(int i = 0; i < 4; i++)
                check[i] = 0;
        }
        check[mp(x)] = 1;
    }
    cout<<cnt;
    return 0;
}