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
    
    ll n, k; cin >> n >> k;
    ll t[n][n]; zep(i, 0, n)zep(j, 0, n)cin >> t[i][j];
    
    ll a[n - 1]; zep(i, 0, n - 1)a[i] = i + 1;

    ll ans = 0;
    do{ 
        ll sm = 0;
        sm += t[0][a[0]];
        zep(i, 0, n - 2){
            sm += t[a[i]][a[i + 1]];
        }
        sm += t[a[n - 2]][0];

        if(sm == k)ans++;
    }while(next_permutation(a, a + n - 1));

    print(ans)

    return 0;
}