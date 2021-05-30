#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 998244353;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(int i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    ll a[n]; zep(i, 0, n)cin >> a[i];

    P v[n]; zep(i, 0, n)v[i] = P(a[i], i);
    sort(v, v + n);

    ll ans = 1;
    bool use[n]; memset(use, 0, sizeof(use));
    zep(i, 0, n){
        ll at = v[i].second;
        use[at] = true;

        ll cnt = 0;
        if(at > 0 && use[at - 1])cnt++;
        if(at < n - 1 && use[at + 1])cnt++;

        ans *= v[i].first - cnt;
        ans %= MOD;
    }

    print(ans)

    return 0;
}