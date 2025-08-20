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

    int n, m;
    cin>>n>>m;
    for(int i = n + 1; ; i++){
        int cnt = 0;
        for(int j = 2; j <= sqrt(i); j++)
            if(i % j == 0) {
                cnt+=2;
                if(i / j == j) cnt--;
            }
        if(!cnt) return cout<<(m == i ? "YES" : "NO"), 0;
    }
    return 0;
}