#include <bits/stdc++.h>
using namespace std;

int n, m;

int main(){
    cin >> n >> m;

    vector<vector<int>> a(n);
    int u, v;

    for (int i = 0; i < m; i++){
        cin >> u >> v;
        a[u - 1].push_back(v);
        a[v - 1].push_back(u);
    }

    for (int i = 0; i < n; i++){
        cout << i + 1 << " : ";

        for (auto x : a[i]) cout << x << " ";
        cout << endl;
    }
}