#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e9;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(int i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    ll a[n], t[n]; zep(i, 0, n)cin >> a[i] >> t[i];
    ll q; cin >> q;
    ll x[q]; zep(j, 0, q)cin >> x[j];

    ll mx = INF, mn = -INF, sm = 0;
    zep(i, 0, n){
        if(t[i] == 1){
            mx += a[i];
            mn += a[i];
            sm += a[i];
        }else if(t[i] == 2){
            mx = max(mx, a[i]);
            mn = max(mn, a[i]);
        }else{
            mx = min(mx, a[i]);
            mn = min(mn, a[i]);
        }
    }

    zep(j, 0, q){
        print(min(max(mn, x[j] + sm), mx))
    }

    return 0;
}