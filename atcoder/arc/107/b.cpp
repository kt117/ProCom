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

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, k; cin >> n >> k;

    ll cnt[2 * n + 100]; memset(cnt, 0, sizeof(cnt));
    rep(i, 0, n - 1){
        cnt[i + n] = n - i;
    }

    zep(i, -(n - 1), 0){
        cnt[i + n] = n + i;
    }

    ll ans = 0;
    rep(i, -(n - 1), n - 1){
        if(-(n - 1) <= k - i && k - i <= n - 1){
            ans += cnt[i + n] * cnt[k - i + n];
        }
    }
    print(ans)

    return 0;
}