#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define ll long long int
#define rep(i,n) for(ll i = 0; i < n; i++)
#define repp(i,x,y) for(ll i = x; i <= y; i++)
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
        ll count = 0;
        if(n == 1){
            cout<<"First"<<"\n";
            continue;
        }
        rep(i, n){
            if((i != 0 and a[i] > 1) and n%(i+1) == 0) count++;
            else if(a[i] > 1) count+=2;
            else count++;
        }
        if(count%2 == 0) cout<<"Second"<<"\n";
        else cout<<"First"<<"\n";
    }
    return 0;
}