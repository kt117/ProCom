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
        ll a[n]; zep(i, 0, n)cin >> a[i];

        sort(a, a + n);
        queue<ll> q;

        ll ans = 0;
        zep(i, 0, n){
            q.push(a[i]);
            while(q.front() < a[i] - 2)q.pop();

            ll m = q.size();
            if(m >= 3){
                ans += (m - 1) * (m - 2) / 2;
            }
        }

        print(ans)
    }
    
    return 0;
}