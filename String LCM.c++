
#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() {
	ll t; cin >> t;
	while(t--){
		string a, b; cin >> a >> b;
		ll lena = a.length(), lenb = b.length();
		string res1, res2;
		ll lcmfind = lcm(lena, lenb);
		for(ll i = 1; i <= (lcmfind/lena); i++){
		    res1 += a;
		}
		for(ll i = 1; i <= (lcmfind/lenb); i++){
		    res2 += b;
		}
		if(res1 == res2) cout<<res1<<"\n";
		else cout<<"-1"<<"\n";
	}
	// your code goes here
	return 0;
}