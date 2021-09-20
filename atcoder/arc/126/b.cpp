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

ll n, m, dp[2 * 101 * 1001];

ll f(ll x){
    ll ok = 0, ng = m;
    while(ng - ok > 1){
        ll mid = (ok + ng) / 2;

        if(dp[mid] < x){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    return ok;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> m;
    ll a[m], b[m]; zep(i, 0, m)cin >> a[i] >> b[i];

    vector<P> v;
    zep(i, 0, m)v.push_back(P(a[i], b[i]));
    sort(v.begin(), v.end());

    rep(i, 0, m + 1)dp[i] = INF;
    dp[0] = 0;

    ll ans = 0;
    vector<P> u;
    zep(i, 0, m){
        ll at = f(v[i].second);
        u.push_back(P(at + 1, v[i].second));
        ans = max(ans, at + 1);

        if(i == m - 1 || v[i].first != v[i + 1].first){
            while(!u.empty()){
                dp[u.back().first] = min(dp[u.back().first], u.back().second);
                u.pop_back();
            }
        }
    }

    print(ans)
    
    return 0;
}