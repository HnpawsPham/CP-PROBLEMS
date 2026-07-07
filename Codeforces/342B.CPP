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

int n, m, st, en;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>st>>en;
    char pass = 'R';
    int dir = 1;
    if(en < st){
        dir = -1;
        pass = 'L';
    }

    string res = "";
    int time = 1, pos = st;
    while(m--){
        int t, l, r;
        cin>>t>>l>>r;

        while(time < t && pos != en){
            res.push_back(pass);
            pos += dir;
            time++;
        }
        if(pos == en) continue;

        if((l <= pos && pos <= r) || (l <= pos + dir && pos + dir <= r))
            res.push_back('X');
        else{
            res.push_back(pass);
            pos += dir;
        }
        time++;
    }

    while(pos != en){
        pos += dir;
        res.push_back(pass);
    }
    cout<<res;
    return 0;
}