#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, m;
const int maxn = 1e6 + 5;
int parent[maxn];

void makeset(){
    for(int i = 1; i <= n + 1; i++)
        parent[i] = i;
    return;
}

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

bool unite(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return 0;
    parent[a] = b;
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    cin.ignore();
    makeset();

    string q;
    while(m--){
        getline(cin, q);
        int x = stoi(q.substr(2));

        if(q[0] == '-') unite(parent[x], parent[x + 1]);
        else{
            int tmp = find(parent[x]);
            if(tmp == n + 1) cout<<-1<<el;
            else cout<<tmp<<el;
        }
    }
    return 0;
}