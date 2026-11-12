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

    int k, w, n;
    cin>>k>>w>>n;
    int a[n], need[n];
    for(int i =0; i < n; i++)
        cin>>a[i];
    for(int i = 0; i < n; i++)
        cin>>need[i];

    pii proj[n];
    for(int i = 0; i < n; i++)
        proj[i] = {need[i], a[i]};
    sort(proj, proj + n);

    priority_queue<int> pq;
    int j = 0;
    for(int i = 0; i < k; i++){
        while(j < n && proj[j].fi <= w){
            pq.push(proj[j].se);
            j++;
        }

        if(pq.empty()) break;
        w += pq.top();
        pq.pop();
    }
    cout<<w;
    return 0;
}