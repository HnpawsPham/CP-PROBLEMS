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

bool f[9] = {0};

bool check(int x){
    while(x > 0){
        if(f[x % 10]) return 1;
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

    int x;
    cin>>x;

    int tmp = x;
    while(tmp > 0){
        f[tmp % 10] = 1;
        tmp /= 10;
    }

    int cnt = 0;
    for(int i = 1; 1LL * i * i <= x; i++){
        if(x % i) continue;
        if(check(i)) cnt++;
        if(i != x / i && check(x / i)) cnt++;
    }
    cout<<cnt;
    return 0;
}