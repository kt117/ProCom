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
        string a, b; cin >> a >> b;

        ll n = a.size(), m = b.size();

        ll ans = n + m;

        zep(i, 0, n){
            zep(j, i, n){
                zep(k, 0, m){
                    if(k + j - i < m){
                        bool ok = true;

                        zep(l, 0, j - i + 1){
                            if(a[i + l] != b[k + l])ok = false;
                        }

                        if(ok){
                            ans = min(ans, n + m - 2 * (j - i + 1));
                        }
                    }
                }
            }
        }

        print(ans)
    }
    
    return 0;
}