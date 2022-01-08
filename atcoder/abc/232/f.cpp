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

ll n, x, y, a[20], b[20];
vector<ll> dp((1LL << 20), INF);

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> x >> y;
    zep(i, 0, n)cin >> a[i];
    zep(i, 0, n)cin >> b[i];

    dp[0] = 0;
    zep(bit, 0, (1LL << n) - 1){
        ll bi = __builtin_popcount(bit);
        
        ll cnt = 0;
        zep(ai, 0, n){
            if(~bit & (1LL << ai)){
                dp[bit | (1LL << ai)] = min(dp[bit | (1LL << ai)], dp[bit] + x * abs(a[ai] - b[bi]) + y * cnt);
                cnt++;
            }
        }
    }

    print(dp[(1LL << n) - 1])

    return 0;
}