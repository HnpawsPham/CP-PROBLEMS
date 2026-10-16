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
const int maxn = 1e3 + 5;
int a[maxn];

void print(int type, int i, int j){
    cout<<type<<" "<<i + 1<<" "<<j + 1<<el;
}

void sol(){
    int n;
    cin>>n;
    memset(a, 0, sizeof a);
    for(int i = 0; i < n; i++) cin>>a[i];

    cout<<n / 2 * 6<<el;
    for(int i = 0; i < n; i+=2){
        print(1, i, i + 1);
        print(2, i, i + 1);
        print(1, i, i + 1);
        print(2, i, i + 1);
        print(1, i, i + 1);
        print(2, i, i + 1);
    }
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
    }
    return 0;
}