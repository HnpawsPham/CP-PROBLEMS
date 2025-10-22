#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    n *= 2;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    bool check[n + 1] = {0};

    int cnt = 0, maxx = 0;
    for(int x : a){
        if(!check[x]) {
            check[x] = 1;
            cnt++;
        }
        else cnt--;
        maxx = max(maxx, cnt);
    }
    cout<<maxx;
    return 0;
}