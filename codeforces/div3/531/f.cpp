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

ll n, m, a[20][10010]; 

bool f(ll x){
    bool u[n][n], d[n][n];
    memset(u, 1, sizeof(u));
    memset(d, 1, sizeof(d));
    zep(i, 0, n){
        zep(j, 0, n){
            zep(k, 0, m){
                if(k > 0 && abs(a[i][k - 1] - a[j][k]) < x)u[i][j] = false;
                if(abs(a[i][k] - a[j][k]) < x)d[i][j] = false;
            }
        }
    }

    zep(i, 0, n){
        ll dp[(1LL << n)]; memset(dp, 0, sizeof(dp));
        dp[(1LL << i)] = (1LL << i);
        bool use[(1LL << n)]; memset(use, 0, sizeof(use));
        use[(1LL << i)] = true;
        queue<ll> q;
        q.push((1LL << i));
        
        while(!q.empty()){
            ll x = q.front(); q.pop();
            zep(j, 0, n){
                if(x & (1LL << j)){
                    zep(k, 0, n){
                        if(!(x & (1LL << k)) && d[j][k]){
                            ll nx = (x | (1LL << k));
                            dp[nx] |= (1LL << k);
                            
                            if(!use[nx]){
                                use[nx] = true;
                                q.push(nx);
                            }
                        }
                    }
                }
            }
        }

        zep(j, 0, n){
            if((dp[(1LL << n) - 1] & (1LL << j)) && u[j][i]){
                return true;
            }
        }
    }
    return false;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> m;
    zep(i, 0, n)zep(j, 0, m)cin >> a[i][j];
    
    ll ok = 0;
    ll ng = 1e9;
    while(ng - ok > 1){
        ll mid = (ok + ng) / 2;
        if(f(mid)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    print(ok)
    
    return 0;
}