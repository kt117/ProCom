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
    
    ll n, m; cin >> n >> m;
    ll h[n]; zep(i, 0, n)cin >> h[i];
    ll w[m]; zep(j, 0, m)cin >> w[j];
    sort(h, h + n);
    set<ll> s;
    zep(j, 0, m)s.insert(w[j]);

    ll l[n]; memset(l, 0, sizeof(l));
    zep(i, 0, n)if(i % 2 == 1)l[i] = h[i] - h[i - 1];
    zep(i, 1, n)l[i] += l[i - 1];

    ll r[n]; memset(r, 0, sizeof(r));
    rrep(i, n - 1, 0)if(i % 2 == 1)r[i] = h[i + 1] - h[i];
    rrep(i, n - 1, 1)r[i - 1] += r[i];

    ll ans = INF;
    zep(i, 0, n){
        if(i % 2 == 0){
            auto it = s.lower_bound(h[i]);
            ll buf = INF;
            if(it != s.end())buf = abs(h[i] - *it);
            if(it != s.begin()){
                it--;
                buf = min(buf, abs(h[i] - *it));
            }

            if(i - 1 >= 0)buf += l[i - 1];
            if(i + 1 < n)buf += r[i + 1];
            ans = min(ans, buf);
        }
    }
    print(ans)

    return 0;
}