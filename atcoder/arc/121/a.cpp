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

P nm(P a){
    if(a.second < a.first){
        a = P(a.second, a.first);
    }
    return a;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    ll x[n], y[n]; zep(i, 0, n)cin >> x[i] >> y[i];

    P xx[n]; zep(i, 0, n)xx[i] = P(x[i], i);
    P yy[n]; zep(i, 0, n)yy[i] = P(y[i], i);

    sort(xx, xx + n);
    sort(yy, yy + n);

    vector<pair<ll, P>> v;
    v.push_back(make_pair(abs(xx[0].first - xx[n - 1].first), nm(P(xx[0].second, xx[n - 1].second))));
    v.push_back(make_pair(abs(xx[0].first - xx[n - 2].first), nm(P(xx[0].second, xx[n - 2].second))));
    v.push_back(make_pair(abs(xx[1].first - xx[n - 1].first), nm(P(xx[1].second, xx[n - 1].second))));
    v.push_back(make_pair(abs(yy[0].first - yy[n - 1].first), nm(P(yy[0].second, yy[n - 1].second))));
    v.push_back(make_pair(abs(yy[0].first - yy[n - 2].first), nm(P(yy[0].second, yy[n - 2].second))));
    v.push_back(make_pair(abs(yy[1].first - yy[n - 1].first), nm(P(yy[1].second, yy[n - 1].second))));
    sort(v.begin(), v.end(), greater<>());

    if(v[1].second == v[0].second){
        print(v[2].first)
    }else{
        print(v[1].first)
    }
    
    return 0;
}