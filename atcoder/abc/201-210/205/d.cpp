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

ll n, q, a[100010], k;
map<ll, ll> mp;

bool f(ll x){
    auto it = mp.upper_bound(x);
    ll cnt = 0;
    if(it == mp.end()){
        cnt = n;
    }else{
        cnt = (*it).second;
    }
    return cnt + k <= x;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> q;
    zep(i, 0, n)cin >> a[i];
    zep(i, 0, n)mp[a[i]] = i;

    zep(i, 0, q){
        cin >> k;

        ll ok = n + k;
        ll ng = 0;
        while(ok - ng > 1){
            ll mid = (ok + ng) / 2;

            if(f(mid)){
                ok = mid;
            }else{
                ng = mid;
            }
        }
        print(ok)
    }
    
    return 0;
}