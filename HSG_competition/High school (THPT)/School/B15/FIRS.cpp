#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define pii pair<int, int>

int n;

int main(){
    freopen(".\\txt\\FIRS.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    bool check[n + 2] = {0};

    for(int i = 1;i <=n;i++){
        int x;
        cin>>x;
        pq.push({x, i});
    }

    int cnt = 0;
    while(!pq.empty()){
        pii cur = pq.top(); pq.pop();
        int pos = cur.second;
        
        if(!check[pos]){
            check[pos] = check[pos - 1] = check[pos + 1] = 1;
            cnt++;
        }
    }
    cout<<cnt<<el;

    return 0;
}