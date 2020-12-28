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
typedef pair<int, int>  pii;
typedef pair<ll, ll>    pl;
typedef vector<int>     vi;
typedef vector<ll>      vl;
typedef vector<pii>     vpii;
typedef vector<pl>      vpl;
typedef vector<vi>      vvi;
typedef vector<vl>      vvl;

int main() {
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vl a(n);
        rep(i, n) cin >> a[i];
        vector<string> v;
        string s, s1;
        int var = 98;
        rep(i, a[0]){
            s += (char)var;
            var++;
        }
        v.push_back(s);
        s="";
        var = 98;
        rep(i, a[0]){
            s += (char)var;
            var++;
        }
        v.push_back(s);
        if(a[0] == 0){
            v.push_back("a");
            v.push_back("b");
        }
        repp(i, n){
            if(a[i] > a[i-1]){
                string s; s = a[i-1];
                
            }
        }
        for(auto i : v){
            cout<<i<<"\n";
        }
    }
    return 0;
}