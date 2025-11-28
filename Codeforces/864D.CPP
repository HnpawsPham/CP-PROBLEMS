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

    int f[n + 1] = {0}, left = 0;
    for(int x : a) f[x]++;
    for(int x : f) 
        if(x > 1) left += x;

    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(!f[i]) q.push(i);
        
    int i = 0, cnt = 0;
    while(!q.empty()){
        if(f[a[i]] <= 1) {
            i++;
            continue;
        }

        if(q.front() <= a[i] || left <= q.size()){
            f[a[i]]--;
            cnt++;

            a[i] = q.front();
            q.pop();
        }

        left--;
        i++;
    }

    cout<<cnt<<el;
    for(int x : a) cout<<x<<" ";
    return 0;
}