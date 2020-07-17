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

ll n, m, dp[108][108];
map<ll, ll> mp[108];

ll memo(ll l, ll r){
    if(l > r)return 0;
    if(dp[l][r] != -1)return dp[l][r];

    ll k = 0;
    zep(i, 0, n){
        auto it = mp[i].lower_bound(l);
        if((*it).second <= r)k++;
    }

    ll res = -INF;
    rep(j, l, r){
        ll cnt = 0;
        zep(i, 0, n){
            auto it = mp[i].lower_bound(j);
            if(l <= (*it).second && (*it).first <= r)cnt++;
        }

        res = max(res, memo(l, j - 1) + cnt * cnt + memo(j + 1, r));
    }

    return dp[l][r] = res;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> m;

    zep(i, 0, n){
        ll k; cin >> k;
        
        zep(j, 0, k){
            ll l, r; cin >> l >> r;
            mp[i][r] = l;
        }
    }
    
    memset(dp, -1, sizeof(dp));
    print(memo(1, m))

    return 0;
}