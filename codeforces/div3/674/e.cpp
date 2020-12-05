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
    ll a[3]; zep(i, 0, 3)cin >> a[i];
    ll b[3]; zep(i, 0, 3)cin >> b[i];

    ll mn = max(max(max(a[0] - (b[0] + b[2]), a[1] - (b[1] + b[0])), a[2] - (b[2] + b[1])), 0LL);
    ll mx = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);
    cout << mn << " " << mx << endl;

    return 0;
}