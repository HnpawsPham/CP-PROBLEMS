#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el endl
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define ask(x) cout<<x<<el; cout.flush();
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
    int a[n + 1] = {0};
    int res, tmp;
    
    ask("? 1 2");
    cin>>tmp;
    ask("? 1 3");
    cin>>res;
    a[3] = res - tmp;

    ask("? 2 3");
    cin>>res;
    a[2] = res - a[3];
    a[1] = tmp - a[2];

    for(int i = 4; i <= n; i++){
        cout<<"? "<<i - 1<<' '<<i<<el;
        cout.flush();

        cin>>res;
        a[i] = res - a[i - 1];
    }

    cout<<"! ";
    for(int i = 1; i <= n; i++)
        cout<<a[i]<<" ";

    cout<<el;
    cout.flush();
    return 0;
}

// 6
// 5
// 9
// 8
// 10
// 13
// 15