#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, k;
ll f[21];

void build_factorial(){
    f[0] = 1;
    for(int i = 1; i <= 20; i++)
        f[i] = f[i - 1] * i;
    return;
}

void build_permutation(){
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);

    vector<int> res;

    for(int i = n; i > 0; i--){
        ll factor = (i - 1 < 20) ? f[i - 1] : f[20];
        int index = k / factor;

        res.push_back(a[index]);
        a.erase(a.begin() + index);
        k %= factor;
    }

    for(int x : res) cout<<x<<" ";
    return;
}

int main(){
    freopen("HVK.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    k--;

    build_factorial();
    build_permutation();

    return 0;
}