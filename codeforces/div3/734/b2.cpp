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
        ll n, k; cin >> n >> k;
        ll a[n]; zep(i, 0, n){cin >> a[i]; a[i]--;}

        ll cnt[n]; memset(cnt, 0, sizeof(cnt));
        zep(i, 0, n)cnt[a[i]]++;

        ll x = 0;
        vector<vector<ll>> v(n);
        vector<ll> u;
        zep(i, 0, n){
            if(cnt[i] < k){
                zep(j, 0, cnt[i]){
                    v[i].push_back(x % k + 1);
                    u.push_back(i);
                    x++;
                }
            }else{
                zep(j, 0, k){
                    v[i].push_back(j + 1);
                }
            }
        }

        while(u.size() % k != 0){
            v[u.back()].pop_back();
            u.pop_back();
        }

        ll c[n]; memset(c, 0, sizeof(c));
        
        zep(i, 0, n){
            if(v[a[i]].size() > 0){
                c[i] = v[a[i]].back();
                v[a[i]].pop_back();
            }
        }

        printa(c, 0, n - 1)
    }
    
    return 0;
}