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
    
    ll t; cin >> t;
    while(t--){
        ll n, m; cin >> n >> m;
        ll a[n]; zep(i, 0, n)cin >> a[i];
        ll x[m]; zep(j, 0, m)cin >> x[j];

        ll sm = 0; zep(i, 0, n)sm += a[i];

        zep(i, 1, n)a[i] += a[i - 1];
        ll mx = a[0]; zep(i, 1, n)mx = max(mx, a[i]);

        zep(i, 1, n)a[i] = max(a[i], a[i - 1]);
        map<ll, ll> mp; rrep(i, n - 1, 0)mp[a[i]] = i;

        ll ans[m]; memset(ans, 0, sizeof(ans));
        zep(j, 0, m){
            if(sm <= 0 && x[j] > mx){
                ans[j] = -1;
            }else{
                if(x[j] > mx){
                    ll l = (x[j] - mx + sm - 1) / sm;
                    ans[j] += n * l;
                    x[j] -= sm * l;
                }
                ans[j] += (*(mp.lower_bound(x[j]))).second;
            }
        }
        printa(ans, 0, m - 1)
    }
    
    return 0;
}