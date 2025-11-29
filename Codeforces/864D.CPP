#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int f[n + 1] = {0};
    for(int x : a) f[x]++;

    queue<int> q;
    unordered_set<int> s;

    for(int i = 1; i <= n; i++){
        if(f[i] == 0) q.push(i);
        s.insert(i);
    }
    cout<<q.size()<<el;

    for(int i = 0; i < n && !q.empty(); i++){
        if(f[a[i]] <= 1){
            s.erase(a[i]);
            continue;
        }

        if(q.front() < a[i] || s.count(a[i]) == 0){
            f[a[i]]--;

            a[i] = q.front();
            q.pop();
        }
        s.erase(a[i]);
    }

    for(int x : a) cout<<x<<" ";
    return 0;
}