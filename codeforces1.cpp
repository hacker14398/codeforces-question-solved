#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
typedef long long ll;
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


ll ans(ll r, ll g, ll b, ll w){
    if((r%2 + g%2 + b%2 + w%2) > 1) return 0;
    else return 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    while(t--){
        ll r, g, b, w; cin >> r >> g >> b >> w;
        if(ans(r, g, b, w)) cout<<"Yes"<<"\n";
        else if((r > 0 and g > 0 and b > 0) and ans(r-1, g-1, b-1, w+3))
            cout<<"Yes"<<"\n";
        else cout<<"No"<<"\n";
    }    
    return 0;
}