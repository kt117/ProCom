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

template<typename T> class BIT {
private:
    int n,sz;
    vector<T> node;

public:
    BIT(int sz) : n(1), sz(sz){
        while(n < sz) n *= 2;
        node.resize(n, 0);
    }
    
    void add(int i, T x){
        i++;
        while(i <= n){
            node[i] += x;
            i += i & -i;
        }
    }
    
    T sum(int i){
        if(i < 0)return 0;

        T s = 0;
        i++;
        while(i){
            s += node[i];
            i -= i & -i; 
        }
        return s;
    }
};

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, q; cin >> n >> q;
    ll a[n]; zep(i, 0, n)cin >> a[i];

    vector<BIT<int>> bit(30, BIT<int>(n));
    zep(i, 0, n){
        zep(j, 0, 30){
            if(a[i] & (1LL << j))bit[j].add(i, 1);
        }
    }

    while(q--){
        ll t, x, y; cin >> t >> x >> y;
        x--;
        if(t == 1){
            zep(j, 0, 30){
                if(y & (1LL << j))bit[j].add(x, 1);
            }
        }else{
            ll res = 0;
            zep(j, 0, 30){
                if((bit[j].sum(y - 1) - bit[j].sum(x - 1)) % 2 == 1){
                    res += (1LL << j);
                }
            }
            print(res)
        }
    }

    return 0;
}