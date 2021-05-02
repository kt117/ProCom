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
    ll h[n]; zep(i, 0, n)cin >> h[i];

    ll mn = INF;
    zep(i, 0, n)mn = min(mn, h[i]);

    ll MAX = 2e5;
    ll cnt[MAX + 10]; memset(cnt, 0, sizeof(cnt));

    zep(i, 0, n)cnt[h[i]]++;
    rrep(i, MAX - 1, 1)cnt[i] += cnt[i + 1];

    ll buf = 0, ans = 0;
    rrep(i, MAX, mn + 1){
        if(buf + cnt[i] > k){
            ans++;
            buf = 0;
        }

        buf += cnt[i];
    }
    if(buf > 0)ans++;
    
    print(ans)
    
    return 0;
}