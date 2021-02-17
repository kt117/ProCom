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

ll a[108], ans[108];

void f(ll l, ll r, ll d){
    if(l >= r)return;

    ll mxi = -1;
    ll mx = -1;
    zep(i, l, r){
        if(a[i] > mx){
            mx = a[i];
            mxi = i;
        }
    }

    ans[mxi] = d;
    f(l, mxi, d + 1);
    f(mxi + 1, r, d + 1);
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        zep(i, 0, n)cin >> a[i];
        f(0, n, 0);
        printa(ans, 0, n - 1)
    }

    return 0;
}