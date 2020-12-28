#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		string p; cin >> p;
		bool check1 = p.find_first_not_of("abcdefghijklmnopqrstuvwxyz") != std::string::npos;
		int measure = 0;
		string hash; cin >> hash;
		bool check2 = hash.find_first_not_of("abcdefghijklmnopqrstuvwxyz") != std::string::npos;
		if(!check1 || !check2){
			cout << "NO" << "\n";
			break;
		}
		for(int i = 0; i < p.size(); i++){
			measure += (int)p[i];
		}
		bool flag = false;
		int len = hash.size() - p.size();
		for(int i = 0; i <= len; i++){
			int sum = 0;
			for(int  j = i; j < (p.size() + i); j++){
				sum += (int)hash[j];
			}
			if(sum == measure) {
				flag = true;
				break;
			}
		}
		if(flag) cout << "YES" << "\n";
		else{
			cout << "NO" << "\n";
		}
	}
	return 0;
}