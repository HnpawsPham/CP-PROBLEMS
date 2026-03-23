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
//#define taskname ""

int tc = 1;

int sol(){
    int n, x;
    cin>>n;
    int cnt[3] = {0};
    for(int i = 0; i < n; i++){
        cin>>x;
        cnt[x % 3]++;
    }
    
    int res = 0;
    if(cnt[2] < n / 3){
        for(int i = 1; i >= 0; i--)
            while(cnt[i] > n / 3 && cnt[2] < n / 3){
                res += 2 - i;
                cnt[i]--;
                cnt[2]++;
            }
    }
    for(int i = 0; i < 2; i++)
        if(cnt[i] < n / 3)
            for(int j = 1; j < 3; j++)
                while(cnt[(i + j) % 3] > n / 3 && cnt[i] < n / 3){
                    res += (i - ((i + j) % 3) + 3) % 3;
                    cnt[(i + j) % 3]--;
                    cnt[i]++;
                }
    return res;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}