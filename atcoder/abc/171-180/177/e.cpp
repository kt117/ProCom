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

const ll MAX = 1e6 + 10;
ll n, a[MAX];
bool use[MAX], pr[MAX];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    zep(i, 0, n)cin >> a[i];
    
    bool p = true;
    ll uq = n;

    zep(i, 0, n){
        if(use[a[i]]){
            if(a[i] != 1)p = false;
            uq--;
        }
        use[a[i]] = true;
    }

    bool s = true;
    memset(pr, true, sizeof(pr));

    for(ll i = 2; i <= 1e6; i++){
        if(pr[i]){
            ll cnt = 0;

            for(ll j = 1; j * i <= 1e6; j++){
                if(j > 1)pr[i * j] = false;
                if(use[i * j])cnt++;
            }

            if(cnt > 1)p = false;
            if(cnt == uq)s = false;
        }
    }
    
    if(p){print("pairwise coprime") return 0;}
    if(s){print("setwise coprime") return 0;}
    print("not coprime")

    return 0;
}