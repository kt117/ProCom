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

ll n, m, w[10], l[100008], v[100008], dp[10][10]; 
bool ok[10][10];

ll memo(ll li, ll ri){
    if(ok[li][ri])return dp[li][ri];
    ok[li][ri] = true;

    rep(k, li + 1, ri - 1){
        dp[li][ri] = max(dp[li][ri], memo(li, k) + dp[k][ri]);
    }
    
    return dp[li][ri];
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> m;
    zep(i, 0, n)cin >> w[i];
    zep(j, 0, m)cin >> l[j] >> v[j];

    ll mx = 0; zep(i, 0, n)mx = max(mx, w[i]);
    zep(j, 0, m)if(mx > v[j]){print(-1) return 0;}

    ll ans = INF;
    ll p[n]; zep(i, 0, n)p[i] = i;
    
    vector<P> vl;
    zep(j, 0, m)vl.push_back(P(v[j], l[j]));
    sort(vl.begin(), vl.end());
    
    map<ll, ll> mp; mp[0] = 0;
    ll nl = 0;
    zep(j, 0, m){
        if(vl[j].second > nl){
            nl = vl[j].second;
            mp[-vl[j].first] = nl;
        }
    }

    do{
        memset(dp, 0, sizeof(dp));
        zep(li, 0, n){
            zep(ri, li + 1, n){
                ll sm = 0; rep(k, li, ri)sm += w[p[k]];

                auto it = mp.upper_bound(-sm);
                dp[li][ri] = (*it).second;
            }
        }

        memset(ok, 0, sizeof(ok));
        zep(i, 0, n)ok[i][i] = true;

        ans = min(ans, memo(0, n - 1));
    }while(next_permutation(p, p + n));
    
    print(ans)

    return 0;
}