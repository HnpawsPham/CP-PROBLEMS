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

int n;
const int maxn = 1e5 + 5;
int a[maxn];

bool unsorted(){
    bool dec = 1, inc = 1;
    for(int i = 1; i < n; i++){
        if(a[i] < a[i - 1]) inc = 0;
        if(a[i] > a[i - 1]) dec = 0;
    }
    return !(dec || inc);
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>a[i];

    if(n < 3) return cout<<-1, 0;
    bool ok = 0;
    for(int i = 1; i < n && !ok; i++)
        if(a[i] != a[0]) ok = 1;
    if(!ok) return cout<<-1, 0;

    for(int i = 1; i < n; i++)
        if(a[i] != a[0]){
            swap(a[i], a[0]);
            if(unsorted()) 
                return cout<<"1 "<<i + 1, 0;
            swap(a[i], a[0]);
        }

    for(int i = 2; i < n; i++)
        if(a[i] != a[i - 1]){
            swap(a[i], a[i - 1]);
            if(unsorted()) 
                return cout<<i<<" "<<i + 1, 0;
            swap(a[i], a[i - 1]);
        }

    for(int i = 0; i < n - 1; i++)
        if(a[i] != a[n - 1]){
            swap(a[i], a[n - 1]);
            if(unsorted()) 
                return cout<<i+ 1<<" "<<n, 0;
            swap(a[i], a[n - 1]);
        }
    cout<<-1;
    return 0;
}