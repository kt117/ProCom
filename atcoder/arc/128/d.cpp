#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 998244353;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(int i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

ll n, a[2 * 101 * 1001], dp[2 * 101 * 1001];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    zep(i, 0, n)cin >> a[i];

    bool ok = false;
    zep(i, 0, n)if(a[i] != a[0])ok = true;
    if(!ok){print(1) return 0;}
    
    dp[0] = 1;
    zep(i, 1, n){
        ll sm = 0;
        for(ll j = i - 1; j >= 0; j--){
            dp[i] += dp[j];
            dp[i] %= MOD;
            if(a[i] == a[j])break;
        }
    }
    print(dp[n - 1])

    return 0;
}