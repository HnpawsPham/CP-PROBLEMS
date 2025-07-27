#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 2e5 + 5;
bitset<200005> nprime;

void sieve(){
    nprime[0] = nprime[1] = 1;
    for(int i = 2; i < sqrt(maxn); i++)
        if(!nprime[i])
            for(int j = i * i; j < maxn; j += i)
                nprime[j] = 1;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    sieve();
    unordered_map<int, vi> prime;
    for(int i = 0; i < n; i++){
        int x = a[i];

        for(int j = 2; j * j <= x; j++){
            if(!nprime[j] && x % j == 0){
                prime[j].push_back(i);
                while(x % j == 0) x /= j;
            }
        }
        if(a[i] > 1 && !nprime[a[i]]) prime[x].push_back(i);
    }

    queue<int> q;
    vector<bool> check(maxn, 0);
    vi dis(n, -1);
    q.push(0);
    dis[0] = 0;

    int cnt = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v : {u - 1, u + 1}){
            if(v >= 0 && v < n && dis[v] == -1){
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }

        int x = a[u];
        if(x > 1 && !nprime[x] && !check[x]){ //teleport if x is prime
            for(int v : prime[x]){
                if(dis[v] == -1){
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
            check[x] = 1;
        }
    }
    cout<<dis[n - 1];
    return 0;
}