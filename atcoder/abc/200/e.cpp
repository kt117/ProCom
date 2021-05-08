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

ll v[3 * 1000000 + 1];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, k; cin >> n >> k;

    rep(i, 3, 3 * n){
        v[i] += v[i - 1];
        v[i] += (i - 1) * (i - 2) / 2;
        if(i >= n + 3)v[i] -= 3 * (i - n - 1) * (i - n - 2) / 2;
        if(i >= 2 * n + 3)v[i] += 3 * (i - 2 * n - 1) * (i - 2 * n - 2) / 2;
    }

    ll ok = 3 * n;
    ll ng = 2;    
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;

        if(k <= v[mid]){
            ok = mid;
        }else{
            ng = mid;
        }
    }

    k -= v[ok - 1];
    
    ll okk = n;
    ll ngg = 0;    
    while(okk - ngg > 1){
        ll mid = (okk + ngg) / 2;

        ll sm = 0;
        rep(i, 1, mid){
            if(ok - i <= 2 * n && ok - i >= 2){
                sm += min(n, ok - i - 1) - max(1LL, ok - i - n) + 1;
            }
        }

        if(k <= sm){
            okk = mid;
        }else{
            ngg = mid;
        }
    }

    zep(i, 1, okk){
        if(ok - i <= 2 * n && ok - i >= 2){
            k -= min(n, ok - i - 1) - max(1LL, ok - i - n) + 1;
        }
    }

    k--;

    ll a = okk;
    ll c = min(n, ok - a - 1);
    ll b = ok - a - c;

    zep(i, 0, k){
        b++;
        c--;
    }
    cout << a << " " << b << " " << c << endl;

    return 0;
}