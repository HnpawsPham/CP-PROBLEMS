#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>

int t, n;

void sol(){
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int l[n];
    int front = n, back = n;
    priority_queue<int, vi, greater<int>> r;
    for(int i = n - 1; i >= 0; i--) {
        if(front == back || a[i] <= l[front])
            l[--front] = a[i];

        else r.push(a[i] + 1);

        while(front < back && !r.empty() && r.top() < l[back - 1])
            r.push(l[--back] + 1);
    }

    for(int i = front; i < back; i++) cout<<l[i]<<" ";

    while(!r.empty()){
        cout<<r.top()<<" ";
        r.pop();
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        sol();
        cout<<el;
    }

    return 0;
}