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

    ll b[32];
    for(int i = 0; i < 32; i++)
        b[i] = (1 << i);

    sort(a, a + n);

    bool check[n] = {0};
    for(int i = 0; i < n; i++){        
        if(check[i]) continue;
        
        for(int x : b){
            int l = 0, r = n - 1;
            while(l <= r){
                int mid = (l + r) / 2;
                if(a[mid] == x - a[i] && mid != i){
                    check[i] = check[mid] = 1;
                    break;
                }

                if(a[mid] > x - a[i]) 
                    r = mid - 1;
                else l = mid + 1;
            }
        }
    }
    
    int sum = 0;
    for(bool x : check) sum += x;
    cout<<n - sum;
    return 0;
}