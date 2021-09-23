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

ll dp[5050];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    ll a[n]; zep(i, 0, n)cin >> a[i];
    ll b[n]; zep(i, 0, n)cin >> b[i];

    vector<P> ab; zep(i, 0, n)ab.push_back(P(a[i], b[i]));
    sort(ab.begin(), ab.end(), greater<>());

    zep(i, 0, n){
        rep(j, 0, 5000){
            if(j - ab[i].second >= 0){
                dp[j - ab[i].second] += dp[j];
                dp[j - ab[i].second] %= MOD;
            }
        }

        if(ab[i].first - ab[i].second >= 0){
            dp[ab[i].first - ab[i].second]++;
            dp[ab[i].first - ab[i].second] %= MOD;
        }
    }

    ll ans = 0;
    rep(i, 0, 5000){
        ans += dp[i];
        ans %= MOD;
    }
    print(ans)
    
    return 0;
}