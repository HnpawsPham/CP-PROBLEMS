#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, sum = 0;
const int maxn = 105;
priority_queue<int, vector<int>, greater<int>> pq, des;
vector<int> t;

void solve(){
    while(!pq.empty()){
        if(pq.size() == 2) sum += des.top();
        int maxx = 0;

        for(int i = 0;i<2;i++){
            int x = pq.top();
            maxx = max(maxx, x);
            pq.pop();
            des.push(x);
            cout<<x<<" ";
        }
        sum += maxx;

        int lt = des.top(); des.pop();
        t.push_back(lt);
    }
    for(int x : t) sum += x;
    return;
}

int main(){
    freopen(".\\txt\\QUA-CAU.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 0; i <n;i++) {
        int x;
        cin>>x;
        pq.push(x);
    }

    solve();
    cout<<sum<<el;

    return 0;
}