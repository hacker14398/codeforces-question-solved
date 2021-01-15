#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define ll long long int
#define rep(i,n) for(ll i = 0; i < n; i++)
#define repp(i, x) for(ll i = 1; i < x; i++)
#define si(x)   scanf("%d",&x)
#define sl(x)   scanf("%lld",&x)
#define ss(s)   scanf("%s",s)
#define pi(x)   printf("%d\n",x)
#define pl(x)   printf("%lld\n",x)
#define ps(s)   printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<char> vc;
typedef vector<ll>   vl;
typedef vector<pii>  vpii;
typedef vector<pl>   vpl;

string solution(string str, ll n) {
    ll itr = n-1;
    ll itr1 = 0;
    while(itr >= 0 and itr1 < 3) {
        if(str[itr] == '1') {
            itr1++;
        }
        itr--;
    }
    itr ++;
    itr += (itr1 == 3 ? 1 : 0);
    if(itr1 >= 2) reverse(str.begin()+itr, str.end());
    return str;
}

string makeString(string str, ll n) {
    if(n == 1 or n == 2) return str;
    else {
        string s = makeString(str.substr(0, n-1), n-1);
        str = s + str[n-1];
        if(str[n-1] == '1') {
            str = solution(str, n);
        }
        return str;
    }
}

void solve() {
    string s; cin >> s;
    ll n = s.size();
    set<string> ans;
    rep(i, n){
        for(ll j = 1; j <= n-i; j++) {
            ans.insert(makeString(s.substr(i, j), j));
        }
    }
    cout<<ans.size()<<"\n";
    return;
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    while(t--){
        solve();
    }
}