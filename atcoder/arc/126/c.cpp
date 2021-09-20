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

const ll MAX = 2 * 3 * 100000;
ll n, k, a[MAX + 10], cnt[MAX + 10];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> k;
    rep(i, 1, n)cin >> a[i];
    sort(a, a + n);

    ll mx = 0; rep(i, 1, n)mx = max(mx, a[i]);
    ll sm = 0; rep(i, 1, n)sm += a[i];

    if(mx * n - sm <= k){
        print((sm + k) / n) return 0;
    }

    rep(i, 1, n)cnt[a[i]]++;
    rep(i, 1, 2 * n)a[i] += a[i - 1];
    rep(i, 1, 2 * mx)cnt[i] += cnt[i - 1];

    rrep(i, mx, 1){
        ll c = 0;
        rep(j, 1, (mx + i - 1) / i){
            c += (cnt[j * i] - cnt[(j - 1) * i]) * j * i - (a[cnt[j * i]] - a[cnt[(j - 1) * i]]);
        }

        if(c <= k){
            print(i)
            return 0;
        }
    }

    return 0;
}