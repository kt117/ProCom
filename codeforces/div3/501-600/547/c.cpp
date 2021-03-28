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
    ll q[n]; zep(i, 0, n - 1)cin >> q[i];
    
    ll p[n];
    p[0] = 0;
    ll mn = 0;
    zep(i, 1, n){
        p[i] = p[i - 1] + q[i - 1];
        mn = min(mn, p[i]);
    }

    zep(i, 0, n){
        p[i] -= mn - 1;
    }

    bool use[n]; memset(use, 0, sizeof(use));
    zep(i, 0, n){
        if(0 <= p[i] - 1 && p[i] - 1 < n)use[p[i] - 1] = true;
    }

    bool ok = true;
    zep(i, 0, n)if(!use[i])ok = false;

    if(ok){
        printa(p, 0, n - 1)
    }else{
        print(-1)
    }

    return 0;
}