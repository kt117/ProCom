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
    ll a[n + 1]; rep(i, 1, n)cin >> a[i];

    ll b[n + 1], c[n + 1];
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));

    rep(i, 1, n){
        if(i % 2 == 0){
            b[i] = a[i];
        }else{
            c[i] = a[i];
        }
    }

    rep(i, 1, n){
        b[i] += b[i - 1];
        c[i] += c[i - 1];
    }

    ll ans = 0;
    rep(i, 1, n){
        if(b[i - 1] - b[0] + c[n] - c[i] == c[i - 1] - c[0] + b[n] - b[i])ans++;
    }
    print(ans)
    
    return 0;
}