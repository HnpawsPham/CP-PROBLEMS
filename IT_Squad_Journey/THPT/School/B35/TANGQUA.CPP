#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'

const int maxn = 1e6 + 1;

int main(){
    freopen("TANGQUA.INP", "r", stdin);
    freopen("TANGQUA.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 1; i < maxn; i++) pq.push(i);

    bitset<maxn> used;
    int minn = 1;
    while(n--){
        int x;
        cin>>x;
        used[x] = 1;

        if(x == minn){
            while(!pq.empty() && used[pq.top()])
                pq.pop();
            
            minn = pq.top();
            pq.pop();

            used[minn] = 1;
        }
        cout<<minn<<" ";
    }
    return 0;
}

// 5
// 1 2 3 5 7

// 5
// 2 1 5 4 3