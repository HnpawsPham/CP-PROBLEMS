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
    int cnt[10];

    for(int i = n + 1; i <= 1224444; i++){
        memset(cnt, 0, sizeof cnt);
        int x = i;
        while(x > 0){
            cnt[x % 10]++;
            x /= 10;
        }

        bool ok = 1;
        for(int j = 0; j <= 9; j++)
            if(cnt[j] && cnt[j] != j){
                ok = 0;
                break;
            }   
        if(ok) return cout<<i, 0;
    }
    return 0;
}