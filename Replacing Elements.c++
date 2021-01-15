#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() {
	ll t; cin >> t;
	while(t--){
		ll n, m; cin >> n >> m;
		vector<ll> a(n);
		ll flag = 0;
		for(ll i = 0; i < n; i++){
			cin >> a[i];
			if(a[i] <= m) flag++;
		}
		if(flag == n) cout<<"YES"<<"\n";
		else{
		    ll count = 0;
		    for(ll i = 0; i < n; i++){
		        for(ll j = i+1; j < n; j++) if(a[i]+a[j] <= m){ count = 1; break;}
		    }
		    if(count==1) cout<<"YES"<<"\n";
		    else cout<<"NO"<<"\n";
		}
	}
	// your code goes here
	return 0;
}