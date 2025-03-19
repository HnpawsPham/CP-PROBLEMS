#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define el "\n"

int t;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>t;
	while(t--) {
		int n; cin>>n;
		int a[n], b[n];
		bool ok = 0;

		for(int i = 0; i <n; ++i) cin>>a[i];
		for(int i = 0; i < n; ++i) cin>>b[i];

		ll t = 1, m = 1;
		for(int i = 0; i < n; ++i){
			if(b[i] == 0){
				ok = 0;
				break;
			}
			t *= a[i];
			m *= b[i];

			ll gcd = __gcd(t, m);
			t /= gcd;
			m /= gcd;
		}

		while(m > 1 && m % 2 == 0) m /= 2;
		while(m > 1 && m % 5 == 0) m /= 5;
		ok = (m == 1);

		cout<<(ok ? "finite" : "repeating")<<el;
	}

	return 0;
}