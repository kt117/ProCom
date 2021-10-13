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

ll n, k, a[101 * 1001];

ll f(ll mid){
    ll cnt = 0;
    zep(i, 0, n){
        if(a[i] > mid){
            cnt += a[i] - mid;
        }
    }
    return cnt;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> k;
    zep(i, 0, n)cin >> a[i];

    ll ok = 2e9 + 1, ng = -1;
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;

        if(f(mid) <= k){
            ok = mid;
        }else{
            ng = mid;
        }
    }

    ll ans = 0;
    zep(i, 0, n){
        if(a[i] > ok){
            ans += (a[i] + ok + 1) * (a[i] - ok) / 2;
            k -= a[i] - ok;
        }
    }
    ans += k * ok;
    print(ans)
    
    return 0;
}