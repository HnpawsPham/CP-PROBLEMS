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
//#define taskname "CAU5"

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a, a+ n);

    ll cntt = 0, cntn = 0, cntv = 0;
    for(int i = 0; i < n - 2; i++)
        for(int j = i + 1; j < n - 1; j++){
            int r = lower_bound(a + j + 1, a + n, a[i] + a[j]) - a;
            if(r <= j) continue;

            int sum = a[i] * a[i] + a[j] * a[j];
            int x = ceil(sqrt(sum));
            int pos1 = lower_bound(a + j + 1, a + r, x) - a;

            if(pos1 > r) continue;
            if(a[pos1] * a[pos1] == sum){
                cntv++;
                cntt += r - pos1 - 1;
            }
            else cntt += r - pos1;
       
            cntn += pos1 - j - 1;
        }
    
    cout<<cntn<<" "<<cntv<<" "<<cntt;
    return 0;
}