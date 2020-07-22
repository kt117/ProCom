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

ll cnt[2][30][30];

ll g(ll r, ll d, ll c){
    ll res = 0;
    rep(i, 0, c)res += cnt[r][d][i];
    return res;
}

ll h(ll d, ll c){
    ll res = 0;
    rep(j, 1, d)rep(i, 0, c)res += cnt[1][j][i];
    return res;
}

ll f(ll x, ll c){
    if(x == 0 || c == 0)return 0;

    ll t = 1, cnt = 0;
    while(t <= 1e17 && 10 * t <= x){
        t *= 10;
        cnt++;
    }
    //print(t)
    /*print(x / t)
    //print(cnt)
    print(g(cnt, c - 1))
    print(h(cnt, c - 1))
    print(g(cnt, c))
    print(f(x % t, c - 1))*/
    return (x / t - 1) * (g(0, cnt, c - 1) + g(1, cnt, c - 1)) + h(cnt, c) + 1 + f(x % t, c - 1);
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cnt[0][0][0] = 1;
    rep(i, 1, 20){
        rep(j, 0, 3){
            cnt[0][i][j] += cnt[0][i - 1][j] + cnt[1][i - 1][j];
            cnt[1][i][j + 1] += 9 * (cnt[0][i - 1][j] + cnt[1][i - 1][j]);
        }
    }

    //printa(cnt[0][3], 0, 3)
    /*rep(i, 1, 20){
        rep(j, 0, 3){
            cnt[0][i][j] += cnt[0][i - 1][j];
            cnt[1][i][j] += cnt[1][i - 1][j];
        }
    }*/
    //print(f(2000, 3))
    //return 0;
    ll t; cin >> t;
    while(t--){
        ll l, r; cin >> l >> r;

        //print(f(r, 3))
        //print(f(l - 1, 3))

        print(f(r, 3) - f(l - 1, 3))
    }
    
    return 0;
}