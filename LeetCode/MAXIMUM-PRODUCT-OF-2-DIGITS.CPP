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
    int max1 = 0, max2 = 0;
    while(n > 0){
        if(max1 < (n % 10)){
            max2 = max1;
            max1 = n % 10;
        }
        else if(max2 < (n % 10))
            max2 = n % 10;
        n /= 10;
    }
    cout<<max1 * max2;
    return 0;
}