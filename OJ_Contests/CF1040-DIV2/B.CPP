#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'
#define pii pair<int, int>
#define vi vector<int>
#define fi first
#define se second

int t, n, s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while (t--) {
        cin >> n >> s;
        int a[n];
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
            if (a[i] == 0) cnt0++;
            else if (a[i] == 1) cnt1++;
            else if (a[i] == 2) cnt2++;
        }

        if (s < sum) {
            sort(a, a + n);

            for (int i = 0; i < n; ++i) 
                cout<<a[i]<<" ";
        } 
        else if (s == sum) cout<< -1;
        else {
            int d = s - sum;
            if (d == 1) {
                vi res;
                while(cnt0--) res.push_back(0);
                while(cnt2--) res.push_back(2);
                while(cnt1--) res.push_back(1);

                for (int i = 0; i < n; ++i) 
                    cout<<res[i]<<" ";
            } 
            else cout<<-1;
        }
        cout<<el;
    }

    return 0;
}