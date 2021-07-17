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
bool ng[1001 * 1001];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll L, R; cin >> L >> R;

    rep(i, 2, R){
        if(cnt[i] == 0){
            for(ll j = 1; j * i <= R; j++)cnt[j * i]++;
            for(ll j = 1; j * i * i <= R; j++)ng[j * i * i] = true;
        }
    }

    ll ans = 0;
    rep(i, 2, R){
        if(!ng[i]){
            ll a = R / i - (L - 1) / i;
            if(cnt[i] % 2 == 1){
                ans += a * (a - 1) / 2;
            }else{
                ans -= a * (a - 1) / 2;
            }
        }
        // cout << i << " " << ans << endl;
    }
    // print(ans)
    rep(i, max(2LL, L), R){
        ans -= R / i - 1;
    }
    print(2 * ans)
    
    return 0;
}