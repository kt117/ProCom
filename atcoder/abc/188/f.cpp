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

ll f(ll x){
    ll res = 0;
    ll cnt = 0;
    while(x){
        if(x % 2 == 1){
            cnt++;
        }else{
            res += min(cnt, 2LL);
            cnt = 0;
        }

        x /= 2;
    }
    res += min(cnt, 2LL);

    return res;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll x, y; cin >> x >> y;

    if(x >= y){
        print(x - y) return 0;
    }

    ll n = 0;
    ll p = 1;
    while(2 * p * x < y){
        p *= 2;
        n++;
    }

    ll lz = ((1LL << (n + 1)) - 1) & (y - p * x);
    ll rlz = ((y - p * x) - lz) >> n;
    ll l = n + f(lz) + rlz;
    //cout << n << " " << lz << " " << y - p * x << endl;

    ll rz = ((1LL << (n + 2)) - 1) & (2 * p * x - y);
    ll rrz = ((2 * p * x - y) - rz) >> (n + 1);
    ll r = n + 1 + f(rz) + rrz;
    //cout << l << " " << r << endl;
    print(min(l, r))

    return 0;
}