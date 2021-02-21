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

string x;
ll m, n;

bool f(ll mid){
    ll y = 0;
    zep(i, 0, n){
        if(y > m / mid){
            return false;
        }
        y *= mid;
        y += x[i] - '0';
        if(y > m)return false;
    }
    return true;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> x >> m;
    n = x.size();

    ll mx = 0;
    zep(i, 0, n){
        mx = max(mx, ll(x[i] - '0'));
    }

    if(n == 1){
        if(x[0] - '0' <= m){
            print(1)
        }else{
            print(0)
        }
        return 0;
    }
    
    ll y = 0;
    zep(i, 0, n){
        if(y > m / (mx + 1)){
            print(0)
            return 0;
        }
        y *= mx + 1;
        y += x[i] - '0';
        if(y > m){
            print(0)
            return 0;
        }
    }
    //print(f(4))
    ll ok = mx + 1;
    ll ng = m + 1;
    while(ng - ok > 1){
        ll mid = (ok + ng) / 2;
        if(f(mid)){
            ok = mid;
        }else{
            ng = mid;
        }
    }

    print(ok - (mx + 1) + 1)

    return 0;
}