#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define vi vector<int>

int n;
const int oo = 1e5;

int check(vi& a, vi& b){
    int freq[7] = {0};
    bool goods[7];
    int maxx = 0, num;

    for(int x : a) {
        freq[x]++;
        if(maxx < freq[x]){
            maxx = freq[x];
            num = x;
        }
    }

    for(int x : a)
        if(freq[x] == maxx) 
            goods[x] = 1;

    for(int x = 1; x <= 6; x++){
        if(!goods[x]) continue;
        int cnt = 0;
        for(int i = 0; i < n; i++)
            if(a[i] != x && b[i] == x) cnt++;

        if(cnt >= n - maxx) return n - maxx;
    }
    
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    vi a(n), b(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];

    // sol1
    // int res1 = check(a, b);
    // int res2 = check(b, a);

    // if(res1 == res2 && res1 == -1) cout<< -1;
    // else cout<<min(res1, res2);

    // sol2
    int res = oo;

    for(int x = 1; x <= 6; x++){
        int tswap = 0, bswap = 0;

        for(int i = 0; i < n; i++){
            if(a[i] != x && b[i] != x){
                tswap = bswap = oo;
                break;
            }

            if(b[i] != x) bswap++;
            else if(a[i] != x) tswap++;
        }
        res = min(res, min(tswap, bswap));
    }
    cout<<(res == oo) ? -1 : res;
    return 0;
}