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

bool u[10][10], v[10][10];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;
    ll a[m], b[m]; zep(i, 0, m){cin >> a[i] >> b[i]; a[i]--; b[i]--;}
    ll c[m], d[m]; zep(i, 0, m){cin >> c[i] >> d[i]; c[i]--; d[i]--;}
    
    zep(i, 0, m){
        u[a[i]][b[i]] = true;
        u[b[i]][a[i]] = true;
    }
    zep(i, 0, m){
        v[c[i]][d[i]] = true;
        v[d[i]][c[i]] = true;
    }

    vector<ll> p;
    zep(i, 0, n)p.push_back(i);
    // print(u.same(0, 1))
    // print(v.same(0, 1))
    bool ans = false;
    do {
        ans = true;
        zep(i, 0, n){
            zep(j, 0, n){
                // if(true != true)ans = false;
                if(u[i][j] != v[p[i]][p[j]])ans = false;
            }
        }
        
        if(ans){
            // printa(p, 0, n - 1);
            print("Yes") return 0;
        }
    } while (std::next_permutation(p.begin(), p.end()));

    print("No")

    return 0;
}