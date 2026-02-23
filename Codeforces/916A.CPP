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

bool check(int x){
    while(x > 0){
        if(x % 10 == 7) return 1;
        x /= 10;
    }
    return 0;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x, h, m;
    string hh, mm;
    cin>>x>>hh>>mm;

    h = stoi(hh);
    m = stoi(mm);

    int cnt = 0;
    while(!check(m) && !check(h)){
        if(m - x < 0)
            h = (h + 23) % 24;
        m = (m - x + 60) % 60;
        cnt++;
    }
    cout<<cnt;
    return 0;
}

// 26
// 04 58