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
typedef vector<char>    vc;
typedef vector<ll>      vl;
typedef vector<pii>     vpii;
typedef vector<pl>      vpl;
//typedef vector<vi>      vvi;

void solve() {
    ll n; cin >> n;
    string income, out; cin >> income >> out;
    vector<vector<bool>> ans(n, vector<bool> (n, true));
    rep(i, n){
        for(int j = i+1; j < n; ++j) {
            ans[i][j] = (ans[i][j-1] and (income[j] == 'Y' ? true : false) and (out[j-1] == 'Y' ? true : false)); 
        }
    } 
    rep(i, n) {
        for(ll j = i-1; j >= 0; --j) {
            ans[i][j] = (ans[i][j+1] and (income[j] == 'Y' ? true : false) and (out[j+1] == 'Y' ? true : false)); 
        }
    } 

    rep(i, n){
        rep(j, n){
            cout << (ans[i][j] ? 'Y' : 'N');
        }
        cout << "\n";
    }
    return;
}

int main(int argc, char const *argv[]){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    ll x = 1;
    while(t--){
        cout<<"Case #"<<x<<":"<<"\n";
        solve();
        x++;
    }
    return 0;
}