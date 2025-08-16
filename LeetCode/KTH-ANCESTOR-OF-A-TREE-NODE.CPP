#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n;

class TreeAncestor {
public:
    int LOG = 16;
    vector<vi> p;

    TreeAncestor(int n, vector<int>& parent) {
        p.assign(n + 1, vi(LOG, -1));
        for(int i = 0; i < n; i++) p[i][0] = parent[i];

        for(int j = 1; j < LOG; j++)
            for(int i = 0; i < n; i++)
                p[i][j] = p[p[i][j - 1]][j - 1];
    }
    
    int getKthAncestor(int u, int k) {
        for(int i = 0; i < LOG && u != -1; i++)
            if(k & (1 << i)) u = p[u][i];
        return u;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    TreeAncestor tree(n);
    cout<<tree.getKthAncestor(2, 1);
    return 0;
}