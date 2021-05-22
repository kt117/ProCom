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

int n, m, a[2000000]; 

bool f(ll mid){
    vector<int> v(mid, 0);
    zep(i, 0, m){
        if(a[i] < mid)v[a[i]]++;
    }

    zep(i, 0, mid){
        if(v[i] == 0){
            return false;
        }
    }

    zep(i, m, n){
        if(a[i] < mid)v[a[i]]++;
        if(a[i - m] < mid){
            v[a[i - m]]--;
            if(v[a[i - m]] == 0){
                return false;
            }
        }
    }
    return true;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> m;
    zep(i, 0, n)cin >> a[i];

    ll ok = 0;
    ll ng = 2000000;

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