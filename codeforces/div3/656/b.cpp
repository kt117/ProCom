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
        ll n; cin >> n;
        ll a[2 * n]; zep(i, 0, 2 * n)cin >> a[i];

        vector<ll> p;
        bool use[n + 1]; memset(use, 0, sizeof(use));

        zep(i, 0, 2 * n){
            if(!use[a[i]]){
                use[a[i]] = true;
                p.push_back(a[i]);
            }
        }

        printa(p, 0, n - 1)
    }
    
    return 0;
}