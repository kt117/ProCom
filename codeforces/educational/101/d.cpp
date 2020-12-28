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
        ll x = n;

        vector<P> ans;
        rrep(i, n - 1, 3){
            if(i * i <= x){
                x = (x + i - 1) / i;
                ans.push_back(P(n, i));
                ans.push_back(P(i, n));
            }else{
                ans.push_back(P(i, n));
            }
        }

        while(x > 1){
            x = (x + 1) / 2;
            ans.push_back(P(n, 2));
        }

        print(ans.size())
        zep(i, 0, ans.size())cout << ans[i].first << " " << ans[i].second << endl;
    }
    
    return 0;
}