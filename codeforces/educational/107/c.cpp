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
    
    ll n, q; cin >> n >> q;
    ll a[n]; zep(i, 0, n){cin >> a[i]; a[i]--;}

    ll d[50]; memset(d, -1, sizeof(d));
    zep(i, 0, n)if(d[a[i]] == -1)d[a[i]] = i;

    zep(j, 0, q){
        ll t; cin >> t; t--;

        cout << d[t] + 1 << " ";
        zep(k, 0, 50)if(d[k] < d[t])d[k]++;
        d[t] = 0;
    }
    cout << endl;
    
    return 0;
}