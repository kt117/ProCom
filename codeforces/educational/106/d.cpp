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

const ll MAX = 2e7;
ll cnt[MAX + 100];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);

    rep(i, 2, MAX){
        if(cnt[i] == 0){
            for(ll j = 1; i * j <= MAX; j++){
                cnt[i * j]++;
            }
        }
    }

    ll t; cin >> t;
    while(t--){
        ll c, d, x; cin >> c >> d >> x;

        ll ans = 0;
        for(ll i = 1; i * i <= x; i++){
            if(x % i == 0){
                ll a = i;
                if((a + d) % c == 0){
                    //cout << a << " " << (a + d) / c << endl;
                    ans += (1LL << cnt[(a + d) / c]);
                }

                if(i * i < x){
                    a = x / i;
                    if((a + d) % c == 0){
                        //cout << a << " " << (a + d) / c << endl;
                        ans += (1LL << cnt[(a + d) / c]);
                    }
                }
            }
        }
        print(ans)
    }
    
    return 0;
}