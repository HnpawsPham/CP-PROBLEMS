#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int sum = 0;
    int cnt[105] = {0};

    for(int i = 0; i < n; i++){
        sum += a[i];

        if(sum <= m) cout<<0<<" ";
        else{
            int target = sum - m;
            int del = 0;

            for(int j = 100; j > 0 && target > 0; j--){
                if(!cnt[j]) continue;
                int tmp = min(cnt[j], (target + j - 1) / j);
                target -= tmp * j;
                del += tmp;
            }
            cout<<del<<" ";
        }
        cnt[a[i]]++;
    }
    return 0;
}