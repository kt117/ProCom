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

    vector<P> ans;
    zep(li, 0, n){
        zep(ri, li, n){
            ll x = 0;
            rep(i, li, ri)x += a[i];

            vector<P> v;
            v.push_back(P(li, ri));

            ll sm = 0;
            map<ll, ll> mp;
            mp[0] = ri;
            
            zep(i, ri + 1, n){
                sm += a[i];

                if(mp.find(sm - x) != mp.end()){
                    v.push_back(P(mp[sm - x] + 1, i));

                    sm = 0;
                    mp.clear();
                }
                mp[sm] = i;
            }

            if(v.size() > ans.size())ans.swap(v);
        }
    }

    print(ans.size())
    zep(i, 0, ans.size())cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    
    return 0;
}