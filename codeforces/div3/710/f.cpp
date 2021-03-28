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
        vector<P> rc(n);
        zep(i, 0, n)cin >> rc[i].first;
        zep(i, 0, n)cin >> rc[i].second;
        sort(rc.begin(), rc.end());

        ll rat = 1, gat = 0, bgat = 0;

        ll ans = 0;
        zep(i, 0, n){
            //cout << rc[i].first << " " << rc[i].second << endl;
            if(rc[i].first == 1)continue;

            ll gnx = rc[i].first - rc[i].second;
            ll bgnx = gnx / 2;

            if(bgnx == bgat){
                if(gnx % 2 == 0){
                    ans += rc[i].first - rat;
                }
            }else{
                ans += bgnx - bgat;
            }

            rat = rc[i].first;
            gat = gnx;
            bgat = bgnx;
        }

        print(ans)
    }
    
    return 0;
}