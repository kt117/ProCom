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
    
    ll n, l, w; cin >> n >> l >> w;
    ll a[n + 1]; zep(i, 0, n)cin >> a[i];
    a[n] = l;

    ll c = 0, ans = 0;
    rep(i, 0, n){
        if(a[i] > c){
            ans += (a[i] - c + w - 1) / w;
            // c += (a[i] - c + w - 1) / w * w;
        }
        c = a[i] + w;
    }
    print(ans)

    return 0;
}