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

ll n, c[10], m, mxsm;
vector<vector<ll>> v(10), u(10);
set<vector<ll>> ban;
vector<ll> state, ans;

void f(ll at, ll sm){
    if(at == n){
        if(ban.find(state) == ban.end() && sm > mxsm){
            mxsm = sm;
            while(ans.size())ans.pop_back();
            zep(i, 0, n)ans.push_back(state[i]);
        }
    }else{
        zep(i, 0, u[at].size()){
            state.push_back(c[at] - i);
            f(at + 1, sm + u[at][i]);
            state.pop_back();
        }
    }
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    zep(i, 0, n){
        cin >> c[i];
        zep(j, 0, c[i]){
            ll a; cin >> a;
            v[i].push_back(a);
        }
    }

    cin >> m;
    zep(i, 0, m){
        vector<ll> tmp;
        zep(j, 0, n){
            ll b; cin >> b;
            tmp.push_back(b);
        }
        ban.insert(tmp);
    }

    zep(i, 0, n){
        u[i].push_back(v[i].back());
        v[i].pop_back();
    }

    ll cnt = 1;
    while(cnt <= ban.size()){
        ll mi = -1, mn = INF;
        zep(i, 0, n){
            if(v[i].size() > 0 && u[i].front() - v[i].back() < mn){
                mn = u[i].back() - v[i].back();
                mi = i;
            }
        }

        cnt = cnt / u[mi].size() * (u[mi].size() + 1);
        u[mi].push_back(v[mi].back());
        v[mi].pop_back();
    }

    zep(i, 0, n){
        if(v[i].size() > 0){
            u[i].push_back(v[i].back());
            v[i].pop_back();
        }
    }
    
    f(0, 0);
    printa(ans, 0, n - 1)

    return 0;
}