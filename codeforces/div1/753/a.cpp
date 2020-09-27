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
        ll n; cin >> n;
        ll a[n];
        zep(i, 0, n){
            cin >> a[i]; a[i]--;
        }

        vector<vector<ll>> v(n);
        zep(i, 0, n)v[a[i]].push_back(i);

        vector<ll> sp(n, -1);
        zep(i, 0, n){
            if(v[i].size() > 0){
                zep(j, 1, v[i].size()){
                    sp[i] = max(sp[i], v[i][j] - v[i][j - 1]);
                }

                sp[i] = max(sp[i], v[i][0] + 1);
                sp[i] = max(sp[i], n - v[i].back());
            }
        }

        vector<ll> ans(n + 1, -1);
        ll at = n;
        zep(i, 0, n){
            if(sp[i] != -1 && sp[i] <= at){
                rep(j, sp[i], at)ans[j] = i + 1;
                at = sp[i] - 1;
            }
        }

        printa(ans, 1, n)
    }
    
    return 0;
}