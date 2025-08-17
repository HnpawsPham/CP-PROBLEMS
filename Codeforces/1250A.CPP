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
const int maxn = 1e5 + 5;
int front[maxn], back[maxn];

void balance(int post, int pos){
    front[post] = min(front[post], pos);
    back[post] = max(back[post], pos);
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;

    int id[n + 1], post[n + 1];
    for(int i = 1; i <= n; i++) front[i] = back[i] = id[i] = post[i] = i;

    for(int i = 0; i < m; i++){
        int curpost;
        cin>>curpost;

        if(id[curpost] == 1) continue;

        int prevpost = post[id[curpost] - 1];
        swap(post[id[curpost]], post[id[prevpost]]);

        id[curpost]--;
        id[prevpost]++; 

        balance(curpost, id[curpost]);
        balance(prevpost, id[prevpost]);
    }
    for(int i = 1; i <= n; i++) cout<<front[i]<<" "<<back[i]<<el;
    return 0;
}