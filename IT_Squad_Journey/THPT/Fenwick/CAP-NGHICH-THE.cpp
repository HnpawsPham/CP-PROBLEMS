#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<int> t(1e5 + 1, 0);

void update(int i, int del){
    while (i > 0){
        t[i] += del;
        i -= (i & -i);
    }
    return;
}

int sum(int i){
    int res = 0;

    while (i <= n){
        res += t[i];
        i += (i & -i);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    ll ans = 0;

    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;

        update(x, 1);
        ans += sum(x + 1);
    }
    cout<<ans<<endl;
    return 0;
}