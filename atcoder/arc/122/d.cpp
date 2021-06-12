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

ll n, ans, cnt, p[200020][30];
vector<ll> a;

void f(vector<ll> v, ll d, ll pp){
    if(d < 0 || v.size() == 0)return;
    
    printa(v, 0, v.size() - 1)
    vector<ll> u[2];
    
    zep(i, 0, v.size()){
        u[v[i] >> d].push_back(v[i]);
    }
    zep(i, 0, u[0].size())cout << u[0][i] << " "; cout << endl;
    zep(i, 0, u[1].size())cout << u[1][i] << " "; cout << endl;
    print("------")
    if(pp != -1){
        if(u[0].size() % 2 == 1){
            if(p[pp][d] == -1){
                p[pp][d] = 0;
            }else if(p[pp][d] == 1){
                ans += (1LL << d);
            }

            f(u[0], d - 1, pp);
            f(u[1], d - 1, -1);
        }else{
            if(p[pp][d] == -1){
                p[pp][d] = 1;
            }else if(p[pp][d] == 0){
                ans += (1LL << d);
            }

            f(u[0], d - 1, -1);
            f(u[1], d - 1, pp);
        }
    }else{
        if(u[0].size() % 2 == 1){
            pp = cnt; cnt++;
            ans += (1LL << d);

            f(u[0], d - 1, pp);
            f(u[1], d - 1, pp);
        }else{
            f(u[0], d - 1, -1);
            f(u[1], d - 1, -1);
        }
    }
}


int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n; n *= 2;
    ll a[n]; zep(i, 0, n)cin >> a[i];
    vector<ll> v;
    zep(i, 0, n)v.push_back(a[i]);

    memset(p, -1, sizeof(p));
    
    // f(v, 30, -1);
    f(v, 2, -1);
    print(ans)

    return 0;
}