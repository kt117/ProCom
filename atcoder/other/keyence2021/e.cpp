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

    ll ans[n + 1];
    zep(i, 0, n + 1){
        ll r = n - i;

        ll ans = 0;
        vector<ll> b;
        if(i <= r){
            zep(j, 0, i){
                ans += max(a[i - 1 - j], a[i + j]);
            }
            zep(j, 2 * i, n)b.push_back(a[j]);
        }else{
            zep(j, 0, r){
                ans += max(a[i - 1 - j], a[i + j]);
            }
            zep(j, 0, n - 2 * r)b.push_back(a[j]);
        }
        sort(b.begin(), b.end(), greater<>());
        zep(j, 0, (b.size() + 1) / 2){
            ans += b[j];
        }
        print(ans)
    }
    
    return 0;
}