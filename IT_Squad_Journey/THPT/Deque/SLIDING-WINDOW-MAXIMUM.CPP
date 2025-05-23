#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);;

    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    deque<int> dq;
    vector<int> res;

    for(int i = 0; i < n; i++){
        if(!dq.empty() && dq.front() == i - k)
            dq.pop_front();
        
        while(!dq.empty() && a[dq.back()] < a[i])
            dq.pop_back();
        
        dq.push_back(i);

        if(i >= k - 1) 
            res.push_back(a[dq.front()]);
    }
    for(int x : res) cout<<x<<" ";
    return 0;
}