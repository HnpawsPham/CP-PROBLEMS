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
const int maxn = 3e5 + 5;
int parent[maxn];

void makeset(){
    for(int i = 1; i <= n; i++) 
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
    parent[b] = a;
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];
    makeset();

    for(int i = 1; i <= n; i++){
        int x = find(a[i]);
        cout<<x<<" ";
        parent[x] = find(x + 1 > n ? 1 : x + 1);
    }
    return 0;
}