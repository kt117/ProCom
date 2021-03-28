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
    
    ll n, m; cin >> n >> m;
    ll a[n]; zep(i, 0, n)cin >> a[i];
    ll l[m], r[m]; zep(i, 0, m){cin >> l[i] >> r[i]; l[i]--; r[i]--;}

    ll ans = 0;
    vector<ll> v;
    zep(i, 0, n){
        zep(j, 0, n){
            ll res = a[i] - a[j];
            vector<ll> tmp;

            zep(k, 0, m){
                if((i < l[k] || r[k] < i) && l[k] <= j && j <= r[k]){
                    res++;
                    tmp.push_back(k);
                }
            }

            if(res > ans){
                ans = res;
                v.swap(tmp);
            }
        }
    }

    print(ans)
    print(v.size())
    zep(i, 0, v.size())cout << v[i] + 1 << " "; cout << endl;
    
    return 0;
}