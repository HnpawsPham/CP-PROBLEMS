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

int n;  

bool check(int fi, int se, vector<int> cnt){
    bool alice = 1;
    int step = 0;

    for(int i = 0; i < n; i++){
        if(!cnt[fi]) return !alice;
        cnt[fi]--;
        alice = !alice;
        if(step == 2) swap(fi, se);    
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

    cin>>n;
    vi a(n);
    for(int i = 0; i < n ;i++) cin>>a[i];

    vi cnt(3, 0);
    for(const int& x : a)
        cnt[x % 3]++;

    if(check(1, 2, cnt)) cout<<1;
    else if(check(2, 1, cnt)) cout<<1;
    else cout<<0;
    return 0;
}

// 2 
// 2 1

// 1 
// 2

// 5
// 5 1 2 4 3