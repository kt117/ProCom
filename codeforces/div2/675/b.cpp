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
        ll n, m; cin >> n >> m;
        ll a[n][m];
        zep(i, 0, n)zep(j, 0, m)cin >> a[i][j];

        ll ans = 0;
        zep(i, 0, n / 2){
            zep(j, 0, m / 2){
                vector<ll> v;
                v.push_back(a[i][j]);
                v.push_back(a[n - 1 - i][j]);
                v.push_back(a[i][m - 1 - j]);
                v.push_back(a[n - 1 - i][m - 1 - j]);
                sort(v.begin(), v.end());

                ans += v[1] - v[0];
                ans += v[2] - v[1];
                ans += v[3] - v[1];
            }
        }

        if(n % 2 == 1){
            zep(j, 0, m / 2){
                ans += abs(a[n / 2][j] - a[n / 2][m - 1 - j]);
            }
        }

        if(m % 2 == 1){
            zep(i, 0, n / 2){
                ans += abs(a[i][m / 2] - a[n - 1 - i][m / 2]);
            }
        }

        print(ans)
    }
    
    return 0;
}