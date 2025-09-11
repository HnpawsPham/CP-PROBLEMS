#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;
int parent[maxn];
int f[maxn], l[maxn];
int n;

void makeset(){
    for(int i = 1; i <= n + 1; i++)
        parent[i] = i;
    return;
}

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> f[i];
    for (int i = 1; i <= n; i++) cin >> l[i];
    makeset();

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin>>y>>x;

        int cur = find(y);

        while (x > 0 && cur <= n) {
            int left = l[cur] - f[cur];
            int need = min(x, left);

            f[cur] += need;
            x -= need;


            if (f[cur] == l[cur]) 
                parent[cur] = find(cur + 1);
            
            cur = find(cur);
        }
    }

    for (int i = 1; i <= n; i++) cout<<f[i]<<" ";
    return 0;
}