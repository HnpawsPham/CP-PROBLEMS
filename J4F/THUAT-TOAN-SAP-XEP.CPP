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
const int maxn = 1e5 + 5;
int bit[maxn] = {0};

void update(int i, int val){
    while(i <= n){
        bit[i] += val;
        i += (i & -i);
    }
    return;
}

int query(int i){
    int res = 0;
    while(i > 0){
        res += bit[i];
        i -= (i & -i); 
    }
    return res;
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
    int a[n], pos[n];
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        pos[a[i]] = i;
        update(i, 1);
    }

    int l = 1, r = n;
    for(int step = 1; step <= n; step++){
        if(step % 2){
            cout<<query(pos[l] - 1)<<el;
            update(pos[l], -1);
            l++;
        }
        else{
            cout<<query(n) - query(pos[r])<<el;
            update(pos[r], -1);
            r--;
        }
    }
    return 0;
}