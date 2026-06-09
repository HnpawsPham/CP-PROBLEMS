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

int n, q;

void add(int i, int val, vi& t){
    while(i <= n){
        t[i] += val;
        i += (i & -i);
    }
    return;
}

int query(int i, const vi& t){
    int sum = 0;
    while(i > 0){
        sum += t[i];
        i -= (i & -i);
    }
    return sum;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    vi tx(n + 1, 0), ty(n + 1, 0);
    int cntx[n + 1] = {0}, cnty[n + 1] = {0};
    
    while(q--){
        int opt, x, y;
        cin>>opt>>x>>y;

        if(opt == 1){
            cntx[x]++;
            cnty[y]++;

            if(cntx[x] == 1) add(x, 1, tx);
            if(cnty[y] == 1) add(y, 1, ty);
        }
        else if(opt == 2){
            cntx[x]--;
            cnty[y]--;

            if(!cntx[x]) add(x, -1, tx);
            if(!cnty[y]) add(y, -1, ty);
        }
        else{
            int u, v;
            cin>>u>>v;

            if(query(u, tx) - query(x - 1, tx) >= u - x + 1
            || query(v, ty) - query(y - 1, ty) >= v - y + 1)
                cout<<"Yes"<<el;
            else cout<<"No"<<el;
        }
    }
    return 0;
}