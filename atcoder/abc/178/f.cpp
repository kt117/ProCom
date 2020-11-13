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
    ll a[n]; zep(i, 0, n)cin >> a[i];
    ll b[n]; zep(i, 0, n)cin >> b[i];

    ll cnt[n + 1]; memset(cnt, 0, sizeof(cnt));
    zep(i, 0, n){
        cnt[a[i]]++;
        cnt[b[i]]++;
    }
    rep(i, 1, n){
        if(cnt[i] > n){
            print("No")
            return 0;
        }
    }
    print("Yes")

    reverse(b, b + n);
    vector<ll> u, v;
    ll x = -1;
    zep(i, 0, n){
        if(a[i] == b[i]){
            u.push_back(i);
            x = b[i];
        }
    }
    zep(i, 0, n)if(a[i] != x && b[i] != x)v.push_back(i);

    zep(i, 0, u.size()){
        ll tmp = b[u[i]];
        b[u[i]] = b[v[i]];
        b[v[i]] = tmp;
    }
    printa(b, 0, n - 1)

    return 0;
}