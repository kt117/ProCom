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

ll n, x, sm, cntinv[40][2];
vector<ll> a;

void f(vector<ll> v, ll d){
    ll cnt[2] = {0, 0};
    vector<ll> u[2];
    //print(d)
    zep(i, 0, v.size()){
        int j = ((a[v[i]] & (1LL << d)) >> d);
        
        cnt[j]++;
        cntinv[d][j] += cnt[1 - j];
        u[j].push_back(v[i]);
    }

    if(d > 0){
        if(!u[0].empty())f(u[0], d - 1);
        if(!u[1].empty())f(u[1], d - 1);
    }
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n; a.resize(n);
    zep(i, 0, n)cin >> a[i];

    vector<ll> v(n);
    zep(i, 0, n)v[i] = i;
    f(v, 30);
    
    rrep(d, 30, 0){
        if(cntinv[d][0] <= cntinv[d][1]){
            sm += cntinv[d][0];
        }else{
            sm += cntinv[d][1];
            x += (1LL << d);
        }
    }
    cout << sm << " " << x << endl;
    
    return 0;
}