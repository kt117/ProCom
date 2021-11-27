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

ll n, k, a[2 * 101 * 1001];

bool f(ll mid){
    ll cnt = 0;
    zep(i, 0, n){
        cnt += min(a[i], mid);
    }
    return cnt / k >= mid;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> k;
    zep(i, 0, n)cin >> a[i];

    ll ok = 0, ng = INF;
    while(ng - ok > 1){
        ll mid = (ok + ng) / 2;

        if(f(mid)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    print(ok)
    
    return 0;
}