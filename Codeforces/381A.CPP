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
    deque<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    int sum1 = 0, sum2 = 0, i = 0;
    while(!a.empty()){
        int cur;
        if(a.front() > a.back()){
            cur = a.front();
            a.pop_front();
        }
        else{
            cur = a.back();
            a.pop_back();
        }
        
        if(i % 2) sum2 += cur;
        else sum1 += cur;
        i++;
    }
    cout<<sum1<<" "<<sum2;
    return 0;
}