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
    
    ll n; cin >> n;

    ll t[n], k[n];
    vector<vector<ll>> a(n);
    zep(i, 0, n){
        cin >> t[i] >> k[i];
        a[i].resize(k[i]);
        zep(j, 0, k[i]){cin >> a[i][j]; a[i][j]--;}
    }

    ll ans = 0;
    bool use[n]; memset(use, 0, sizeof(use));
    use[n - 1] = true;
    rrep(i, n - 1, 0){
        if(use[i]){
            ans += t[i];
            zep(j, 0, k[i])use[a[i][j]] = true;
        }
    }
    print(ans)

    return 0;
}