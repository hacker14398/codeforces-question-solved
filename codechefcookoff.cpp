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
//typedef vector<vi> vvi;
typedef vector<vl>   vvl;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        string s; cin >> s;
        ll count1 = 0, count0 = 0;
        ll block = n/k;
        for(auto x : s) {
            if(x == '0') {
                count0++;
            } 
            else {
                count1++;
            }
        }
        if(count0%block or count1%block) {
            cout << "IMPOSSIBLE\n";
        }
        else{
            string res;
            for(int i = 0; i < k; ++i) {
                if(count0) {
                    res += '0';
                    count0 -= block;
                } 
                else {
                    res += '1';
                    count1 -= block;
                }
            }
            string ans, rres = res;
            reverse(rres.begin(), rres.end());
            for(int i = 0; i < block; ++i) {
                if(i&1) {
                    ans += rres;
                } 
                else {
                    ans += res;
                }
            }
            cout << ans << "\n";
        }
    }    
    return 0;
}