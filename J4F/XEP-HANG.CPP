#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, q, node = 1;
const int maxn = 50002;
int t_min[4 * maxn], t_max[4 * maxn];

void build(){
    for(int i = node - 1; i > 0; i--){
        t_min[i] = min(t_min[2 * i], t_min[2 * i + 1]);
        t_max[i] = max(t_max[2 * i], t_max[2 * i + 1]);
    }
    return;
}

int get_max(int l, int r){
    int res = 0;

    l += node;
    r += node;

    while(l <= r){
        if(l % 2 == 1){
            res = max(res, t_max[l]);
            l++;
        }
        if(r % 2 == 0){
            res = max(res, t_max[r]);
            r--;
        }
        r /= 2;
        l /= 2;
    }

    return res;
}

int get_min(int l, int r){
    int res = 1e6 + 5;

    l += node;
    r += node;

    while(l <= r){
        if(l % 2 == 1){
            res = min(res, t_min[l]);
            l++;
        }
        if(r % 2 == 0){
            res = min(res, t_min[r]);
            r--;
        }
        r /= 2;
        l /= 2;
    }

    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    while(node < n) node *= 2;

    for(int i = 0; i < n; i++){
        int x; cin>>x;
        t_min[i + node] = t_max[i + node] = x;
    }

    build();

    while(q--){
        int l, r;
        cin>>l>>r;
        l--; r--;

        cout<<get_max(l, r) - get_min(l, r)<<el;
    }

    return 0;
}