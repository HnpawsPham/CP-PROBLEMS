#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define vi vector<int>

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    
    vector<vi> a(n), b(m);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        b[i] = {x, y};
    }

    vector<vi> res;
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (a[i][0] == b[j][0]) {
            res.push_back({a[i][0], a[i][1] + b[j][1]});
            i++, j++;
        } else if (a[i][0] < b[j][0]) {
            res.push_back(a[i]);
            i++;
        } else {
            res.push_back(b[j]);
            j++;
        }
    }

    while (i < n) res.push_back(a[i++]);
    while (j < m) res.push_back(b[j++]);

    bool first = 1;
    cout<<"[";
    for (vi x : res){
        if(!first) cout<<",";
        first = 0;
        cout<<"["<<x[0]<<","<<x[1]<<"]";
    }
    cout<<"]";
    return 0;
}
