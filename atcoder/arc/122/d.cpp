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


ll g(ll bit, vector<ll> u, vector<ll> v, ll d){
    if(u.size() == 0 || v.size() == 0)return INF;
    if(d < 0)return bit;

    vector<ll> uu[2], vv[2];
    
    zep(i, 0, u.size())uu[(u[i] >> d) & 1].push_back(u[i]);
    zep(i, 0, v.size())vv[(v[i] >> d) & 1].push_back(v[i]);

    if((uu[0].size() > 0 && vv[0].size() > 0) || (uu[1].size() > 0 && vv[1].size() > 0)){
        return min(g(bit, uu[0], vv[0], d - 1), g(bit, uu[1], vv[1], d - 1));
    }else{
        return min(
            g(bit | (1LL << d), uu[0], vv[1], d - 1), 
            g(bit | (1LL << d), uu[1], vv[0], d - 1)
        );
    }
}


ll f(vector<ll> v, ll d){
    if(v.size() == 0 || d < 0)return 0;

    vector<ll> u[2];
    zep(i, 0, v.size())u[(v[i] >> d) & 1].push_back(v[i]);

    if(u[0].size() % 2 == 0){
        return max(f(u[0], d - 1), f(u[1], d - 1));
    }else{
        return g((1LL << d), u[0], u[1], d - 1);
    }
}


int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n; cin >> n; n *= 2;
    ll a[n]; zep(i, 0, n)cin >> a[i];
    vector<ll> v;
    zep(i, 0, n)v.push_back(a[i]);

    print(f(v, 30));

    return 0;
}