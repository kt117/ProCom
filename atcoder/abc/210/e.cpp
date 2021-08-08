#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(int i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

long long gcd(long long a, long long b){return (b == 0)? a : gcd(b, a % b);}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;
    ll a[m], c[m]; zep(i, 0, m)cin >> a[i] >> c[i];

    vector<P> ac(m); zep(i, 0, m)ac[i] = P(c[i], a[i]);
    sort(ac.begin(), ac.end());

    ll ans = 0;
    zep(i, 0, m){
        ll g = gcd(n, ac[i].second);
        if(g < n){
            ans += ac[i].first * (n - g);
            n = g;
        }

        if(n == 1)break;
    }

    print((n == 1)? ans : -1)

    return 0;
}