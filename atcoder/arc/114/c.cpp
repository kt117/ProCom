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

ll n, m;
ll dp[5050][5050];
bool use[5050][5050];

ll memo(ll w, ll h){
    if(use[w][h]){
        return dp[w][h];
    }

    use[w][h] = true;
    
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> m;

    rep(j, 1, m){
        dp[1][j] = 1;
        use[1][j] = true;
    }
    
    ll ans = 0;
    zep(j, 1, m){
        ans += memo(n, j);
        ans %= MOD;
    }
    print(ans)

    return 0;
}