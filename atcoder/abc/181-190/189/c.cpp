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

    ll l[n];
    vector<ll> v;
    zep(i, 0, n){
        while(!v.empty() && a[v.back()] >= a[i])v.pop_back();

        if(v.empty()){
            l[i] = 0;
        }else{
            l[i] = v.back() + 1;
        }
        v.push_back(i);
    }

    ll r[n];
    vector<ll> u;
    rrep(i, n - 1, 0){
        while(!u.empty() && a[u.back()] >= a[i])u.pop_back();

        if(u.empty()){
            r[i] = n;
        }else{
            r[i] = u.back();
        }
        u.push_back(i);
    }
    
    ll ans = 0;
    zep(i, 0, n){
        ans = max(ans, a[i] * (r[i] - l[i]));
    }
    print(ans)

    return 0;
}