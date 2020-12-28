#include<iostream>
using namespace std;

int main(){
	string s = "MEETMEAFTERTOGAPARTY";
	string key = "YCCDYCBEDCIDPKBGIDN";
	string res;
	for(int i = 0; i < s.length(); i++){
		res[i] = (s[i] + key[i])%26;
	}
	cout << res;
}