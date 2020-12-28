#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(ll i = 0; i < n; i++)
#define forrep(i, x, y) for(ll i = x; i <= y; i++)
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>

int main() {
	ll t; cin >> t;
	while(t--){
		ll n, m; cin >> n >> m;
		if(n%2 == 0){
			cout << n + 2*m << "\n";
			continue;
		}
		ll p;
		forrep(i, 2, n)
			if(n%i == 0){
				p = i;
				break;
			}
		cout << n + p + 2*(m-1) <<"\n";
	}
	return 0;
}
