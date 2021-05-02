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

long long powmod(long long a, long long x){
    if(x == 0)return 1;
    long long r = powmod(a, x / 2);
    return (x%2)? (r * r % MOD) * a % MOD : r * r % MOD;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll t; cin >> t;
    while(t--){
        ll n, m; cin >> n >> m;

        vector<vector<ll>> g(n);
        zep(j, 0, m){
            ll u, v; cin >> u >> v; u--; v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        bool use[n]; memset(use, 0, sizeof(use));
        ll col[n];
        ll ans = 1;
        zep(i, 0, n){
            if(!use[i]){
                ll cnt[2]; memset(cnt, 0, sizeof(cnt));

                queue<P> q;
                use[i] = true;
                col[i] = 0;
                cnt[0]++;
                q.push(P(i, 0));
                while(!q.empty()){
                    ll at = q.front().first, c = q.front().second; q.pop();

                    zep(j, 0, g[at].size()){
                        ll nx = g[at][j];
                        if(!use[nx]){
                            use[nx] = true;
                            col[nx] = 1 - c;
                            cnt[1 - c]++;
                            q.push(P(nx, 1 - c));
                        }else{
                            if(col[nx] != 1 - c)ans = 0;
                        }
                    }
                }

                ans *= (powmod(2, cnt[0]) + powmod(2, cnt[1])) % MOD; ans %= MOD;
            }
        }

        print(ans)
    }
    
    return 0;
}