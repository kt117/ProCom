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

const ll MAX = 101 * 1001;
ll n, p[MAX], cs[MAX], ga[MAX][2];
vector<vector<ll>> g;

void dfs(ll at){
    zep(i, 0, g[at].size())dfs(g[at][i]);
    
    cs[at] = 1;
    zep(i, 0, g[at].size())cs[at] += cs[g[at][i]];


    ga[at][0] = 1;
    ga[at][1] = 0;
    if(g[at].size() == 0){    
        return;
    }
    
    vector<vector<ll>> vo, ve;
    zep(i, 0, g[at].size()){
        ll nx = g[at][i];
        if(cs[nx] % 2 == 0){
            ve.push_back({ga[nx][0] - ga[nx][1], nx});
        }else{
            vo.push_back({ga[nx][0] - ga[nx][1], nx});
        }
    }
    sort(ve.begin(), ve.end());
    sort(vo.begin(), vo.end());

    ll flag = 0;

    zep(i, 0, ve.size()){
        if(ve[i][0] <= 0){
            ga[at][flag] += ga[ve[i][1]][0];
            ga[at][1 - flag] += ga[ve[i][1]][1];
        }
    }

    zep(i, 0, vo.size()){
        ga[at][flag] += ga[vo[i][1]][0];
        ga[at][1 - flag] += ga[vo[i][1]][1];
        flag = 1 - flag;
    }

    zep(i, 0, ve.size()){
        if(ve[i][0] > 0){
            ga[at][flag] += ga[ve[i][1]][0];
            ga[at][1 - flag] += ga[ve[i][1]][1];
        }
    }
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    zep(i, 1, n){cin >> p[i]; p[i]--;}
    g.resize(n);
    zep(i, 1, n)g[p[i]].push_back(i);

    dfs(0);
    print(ga[0][0])
    //print(ga[0][1])

    return 0;
}