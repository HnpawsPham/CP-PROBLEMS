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
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    int cnt = 0;
    vi d(n, 0);

    for(int i = 0; i < n; i++){
        if(a[i]) continue;
        for(int dir : {1, -1}){
            int j = i + dir;

            while(0 <= j && j < n){
                if(a[j] - d[j]){
                    d[j]++;
                    dir = -dir;
                }
                j += dir;
            }

            bool ok = 1;
            for(int j = 0; j < n; j++){
                if(a[j] - d[j]) ok = 0;
                d[j] = 0;
            }
            cnt += ok; 
        }
    }
    cout<<cnt;
    return 0;
}

// 5
// 1 0 2 0 3

// 7
// 2 3 4 0 4 1 0