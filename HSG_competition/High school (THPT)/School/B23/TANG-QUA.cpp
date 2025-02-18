#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;
const int maxn = (int)1e6 + 5;
bool check[maxn];
int b[maxn];

int main(){
    freopen(".\\txt\\TANG-QUA.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    b[0] = 1;

    for(int i = 1; i <= n; i++) {
        int x;
        cin>>x;
        check[x] = 1;

        int r = b[i - 1];

        while(check[r]) r++;
        b[i] = r;
    }

    for(int i = 1; i <= n; i++) cout<<b[i]<<" ";

    return 0;
}