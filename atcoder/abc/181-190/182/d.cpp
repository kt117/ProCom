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
    ll a[n]; zep(i, 0, n)cin >> a[i];
    ll ca[n];
    zep(i, 0, n)ca[i] = a[i];
    zep(i, 1, n)ca[i] += ca[i - 1];

    ll mx[n][2];
    zep(j, 0, 2)zep(i, 0, n)mx[i][j] = ca[i];

    zep(i, 1, n)mx[i][0] = max(mx[i][0], mx[i - 1][0]);
    zep(i, 1, n)mx[i][1] = min(mx[i][1], mx[i - 1][1]);

    ll ans = 0, sm = 0;
    zep(i, 0, n){
        ans = max(ans, sm + mx[i][0]);
        //ans = max(ans, abs(sm + mx[i][1]));

        sm += ca[i];
        //print(ans)
    }
    print(ans)

    return 0;
}