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

ll cnt[1001 * 1001];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll L, R; cin >> L >> R;

    rep(i, 2, R)cnt[i] = R / i - (L - 1) / i;
    rep(i, 2, R)cnt[i] *= cnt[i];
    // printa(cnt, 1, R)
    vector<vector<ll>> v(R + 1);
    rep(i, 2, R){
        for(ll j = 2; j * i <= R; j++){
            v[j * i].push_back(i);
        }
    }

    rrep(i, R, 2){
        zep(j, 0, v[i].size()){
            cnt[v[i][j]] -= cnt[i];
        }
    }
    // printa(cnt, 1, R)
    ll ans = 0;
    rep(i, 2, R)ans += cnt[i];
    rep(i, max(2LL, L), R)ans -= 2 * (R / i - (L - 1) / i) - 1;
    print(ans)
    
    return 0;
}