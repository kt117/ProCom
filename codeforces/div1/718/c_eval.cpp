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

ll n, ans[500][500];

void dfs(ll i, ll j, ll x, ll res){
    if(res == 0)return;
    res--;

    if(i < n - 1 && ans[i + 1][j] == 0){
        ans[i + 1][j] = x;
        dfs(i + 1, j, x, res);
    }else{
        ans[i][j - 1] = x;
        dfs(i, j - 1, x, res);
    }
}

bool f(vector<ll> p){
    memset(ans, 0 ,sizeof(ans));
    zep(i, 0, n)ans[i][i] = p[i];

    rrep(i, n - 1, 0)dfs(i, i, p[i], p[i] - 1);

    zep(i, 0, n){
        zep(j, 0, i + 1){
            if(ans[i][j] == 0)return false;
        }
    }
    return true;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    n = 500;
    vector<ll> p(n); zep(i, 0, n)p[i] = i + 1;

    /*ll cnt = 0;
    do{
        if(!f(p))print("ng");
        //print(cnt++)
    }while(next_permutation(p.begin(), p.end()));*/

    zep(i, 0, 100000){
        mt19937 get_rand_mt;
        shuffle(p.begin(), p.end(), get_rand_mt);
        if(!f(p))print("ng");
    }

    return 0;
}