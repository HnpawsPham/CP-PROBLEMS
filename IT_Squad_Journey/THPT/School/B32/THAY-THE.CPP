#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
using ll = long long;
#define el "\n"
#define pii pair<int, int>
#define fi first
#define se second

ll n, a, b, r;
int p;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("THAY-THE.INP", "r", stdin);

    cin>>n>>p>>a>>b>>r;

    if(n == r) return cout<<0, 0;

    unordered_map<ll, bool> check;
    queue<pair<int, int>> q;
    q.push({n, 0});
    check[n] = true;

    while (!q.empty()) {
        auto [cur, dis] = q.front();
        q.pop();

        for (int next : {(cur + a) % p, (cur + b) % p, (cur + a + b) % p}) {
            if (!check[next]) {
                if (next == r) 
                    return cout << dis + 1, 0;
                
                check[next] = 1;
                q.push({next, dis + 1});
            }
        }
    }

    cout<<-1;
    return 0;
}