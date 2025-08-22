#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n;
const int maxn = 1e4 + 5;
int a[maxn], t[maxn];

bool check(int x){
    int l[n] = {0}, r[n] = {0};
    for(int i = 0; i < n; i++){
        l[max(1, a[i] - x / t[i])]++;
        r[min(n, a[i] + x / t[i])]++;
    }
   
    for(int i = 1; i < n; i++){
        l[i] += l[i - 1];
        r[i] += r[i - 1];
        if(l[i] < i || r[i] > i) return 0; 
    }
    return 1;
}   

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 0; i < n; i++) cin>>a[i]>>t[i];

    int l = 0, r = 2e8;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout<<l;
    return 0;
}