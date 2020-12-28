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


ll operation(ll Operand_1, ll Operand_2, char op) {
    if (op == '*') return Operand_1 * Operand_2;
    else if (op == '+') return Operand_1 + Operand_2;
    else if (op == '-') return Operand_1 - Operand_2;
}

ll ans(const string &s) {
    ll l = s.size();
    ll num = (l + 1)/2;
    ll low[num][num];
    ll high[num][num];
    memset(low, 0, sizeof(low));
    memset(high, 0, sizeof(high));
    for(ll i = 0; i < num; i++) {
        low[i][i] = stoll(s.substr(2 * i, 1));
        high[i][i] = stoll(s.substr(2 * i, 1));
    }
    for(ll j = 0; j < num - 1; j++){
        for (ll i = 0; i < num - j - 1; i++) {
            ll k = i + j + 1;
            ll MinValue = LLONG_MAX;
            ll MaxValue = LLONG_MIN;
            for (ll m = i; m < k; m++) {
                ll a = operation(low[i][m], low[m + 1][k], s[2 * m + 1]);
                ll b = operation(low[i][m], high[m + 1][k], s[2 * m + 1]);
                ll c = operation(high[i][m], low[m + 1][k], s[2 * m + 1]);
                ll d = operation(high[i][m], high[m + 1][k], s[2 * m + 1]);
                MinValue = min(MinValue, min(a, min(b, min(c, d))));
                MaxValue = max(MaxValue, max(a, max(b, max(c, d))));
            }
            low[i][k] = MinValue;
            high[i][k] = MaxValue;
        }
    }
    return high[0][num - 1];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s; cin >> s;
    cout<<ans(s)<<"\n";
}