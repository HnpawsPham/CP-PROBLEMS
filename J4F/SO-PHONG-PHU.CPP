#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 1e5 + 5;
int d[maxn] = {0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int l, r;
    cin>>l>>r;
    for(int i = 1; i < maxn; i++)
        for(int j = i + i; j < maxn; j += i)
            d[j] += i;

    int cnt = 0;
    for(int i = l; i <= r; i++)
        if(d[i] > i) cnt++;
    cout<<cnt;
    return 0;
}