#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

bool check(int n, int k){
    return ((n - k) >= 1 && (n % 2 == k % 2));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;

    int cnt = 0;
    queue<int> q;
    q.push(n);

    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        if(!check(x, k)) cnt++;
        else{
            q.push((x + k) / 2);
            q.push((x - k) / 2);
        }
    }
    cout<<cnt;
    return 0;
}