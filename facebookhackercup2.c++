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
typedef vector<char>     vc;
typedef vector<ll>      vl;
typedef vector<pii>     vpii;
typedef vector<pl>      vpl;
//typedef vector<vi>      vvi;
typedef vector<vl>      vvl;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    while(t--){
        ll n, m; cin >> n;
        vl a(n+1, 0);
        ll count = 0;
        rep(i, n){
            cin >> m;
            count += m;
            a[m]++;
        }
        if(n == 1){
            cout<<0<<"\n";
            continue;
        }
        sort(a.begin(), a.end());
        ll x = a[n], y = a[n-1];
        if(count == (n*(n+1))/2) cout<<2<<"\n";
        else if(x == y) cout<<x<<"\n";
        else if((x/2) >= (y/2)) cout<<x/2<<"\n";
        else cout<<y/2<<"\n";
    }    
    return 0;
}