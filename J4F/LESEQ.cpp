#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;
const int maxn = (int)1e6 + 5;
const int maxa = 2 * maxn;
int a[maxn], p[maxa];
bool check[maxa];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int cnt0 = 0;
    memset(check, 0, sizeof(check));
    memset(p, 0, sizeof(p));

    for(int i = 1; i <=n; ++i){
        cin>>a[i];
        check[a[i] + (int)1e6] = 1;
        cnt0 += (a[i] == 0);
    }

    for(int i = 1; i< maxa; ++i)
        p[i] = p[i - 1] + check[a[i]];
    
    int len = 0;
    for(int i = 0; i <maxa; ++i){
        if(!check[i]) continue;

        int l = 0, r = i;
        while(l <= r){
            int mid = (l + r)/2;
            int need = (i - mid + 1) - p[i + 1] - p[mid];

            if(need <= cnt0){
                len = max(len, i - mid + 1);
                r = mid - 1;
            }
            else l = mid + 1;
        }
    }
    cout<<len;
    return 0;
}
// 7
// 1 0 3 8 5 9 0