#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    stack<int> st;
    vector<int> dp(n, 1);

    for(int i = 0; i < n; i++){
        while(!st.empty() && a[st.top()] <= a[i]){
            if(a[st.top()] == a[i])
                dp[i] = dp[st.top()] + 1;

            st.pop();
        }
        st.push(i);
    }
    long long sum = 0;
    for(int x : dp) sum += x;
    cout<<sum;
    return 0;
}