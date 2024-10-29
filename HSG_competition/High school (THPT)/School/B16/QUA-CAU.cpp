#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, sum = 0;
const int maxn = 105;
priority_queue<int, vector<int>, greater<int>> des;
vector<int> pq;

void solve(){
    while(!pq.empty()){
        int maxx = 0;
        int sz = pq.size();

        for(int i = 0;i < min(2, sz);i++){
            int x = pq.back(); pq.pop_back();
            maxx = max(maxx, x);
            des.push(x);    
        }
        sum += maxx;

        int lt = des.top(); des.pop();
        sum += lt;
        if(!pq.empty()) pq.push_back(lt);
    }
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
        pq.push_back(x);
    }
    sort(pq.begin(), pq.end(), greater<int>());

    int maxx = 0;
    for(int i = 0; i < min(2, n); i++){
        int x = pq.back(); pq.pop_back();
        des.push(x);
        maxx = max(maxx, x);
    }
    sum += maxx;
    pq.push_back(des.top()); des.pop();

    sort(pq.begin(), pq.end());
    solve();
    cout<<sum<<el;

    return 0;
}