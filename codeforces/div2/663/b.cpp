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
    
    ll T; cin >> T;
    while(T--){
        ll n, m; cin >> n >> m;

        string a[n]; zep(i, 0, n)cin >> a[i];

        ll ans = 0;
        zep(i, 0, n - 1){
            if(a[i][m - 1] != 'D')ans++;
        }

        zep(j, 0, m - 1){
            if(a[n - 1][j] != 'R')ans++;
        }

        print(ans)
    }
    
    return 0;
}