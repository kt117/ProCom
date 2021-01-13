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
    ll a[(1LL << n)]; zep(i, 0, (1LL << n))cin >> a[i];
    
    vector<ll> v(1 << n);
    zep(i, 0, (1LL << n))v[i] = i;

    zep(i, 0, n - 1){
        vector<ll> u(v.size() / 2);

        zep(j, 0, v.size() / 2){
            if(a[v[2 * j]] > a[v[2 * j + 1]]){
                u[j] = (v[2 * j]);
            }else{
                u[j] = (v[2 * j + 1]);
            }
        }

        u.swap(v);
    }
    //printa(v, 0, v.size() - 1)

    if(a[v[0]] < a[v[1]]){
        print(v[0] + 1)
    }else{
        print(v[1] + 1)
    }

    return 0;
}