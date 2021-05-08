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

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    ll a[n]; zep(i, 0, n)cin >> a[i];

    vector<vector<ll>> u(200);
     vector<vector<ll>> v(200);
    v[0].push_back(-1);
    u[0].push_back(-1);

    zep(i, 0, n){
        zep(j, 0, 200){
            if(u[j].size() > 0 && u[j].back() != i){
                if(u[(j + a[i]) % 200].size() > 0){
                    while(!v[(j + a[i]) % 200].empty()){
                        v[(j + a[i]) % 200].pop_back();
                    }
                    zep(k, 0, u[j].size()){
                        v[(j + a[i]) % 200].push_back(u[j][k]);
                    }
                    v[(j + a[i]) % 200].push_back(i);
                }else{
                    while(!u[(j + a[i]) % 200].empty()){
                        u[(j + a[i]) % 200].pop_back();
                    }
                    zep(k, 0, u[j].size()){
                        u[(j + a[i]) % 200].push_back(u[j][k]);
                    }
                    u[(j + a[i]) % 200].push_back(i);
                }
            }
            if(v[j].size() > 0 && v[j].back() != i){
                while(!v[(j + a[i]) % 200].empty()){
                    v[(j + a[i]) % 200].pop_back();
                }
                zep(k, 0, u[j].size()){
                    v[(j + a[i]) % 200].push_back(u[j][k]);
                }
                v[(j + a[i]) % 200].push_back(i);
            }
        }
    }

   
    // zep(i, 0, n){
    //     zep(j, 0, 200){
    //         if(v[j].size() > 0 && v[j].back() != i){
    //             if(v[(j + a[i]) % 200].size() <= v[j].size() + 1){
    //                 while(!v[(j + a[i]) % 200].empty()){
    //                     v[(j + a[i]) % 200].pop_back();
    //                 }
    //                 zep(k, 0, v[j].size()){
    //                     v[(j + a[i]) % 200].push_back(v[j][k]);
    //                 }
    //                 v[(j + a[i]) % 200].push_back(i);
    //             }
    //         }
    //     }
    // }

    //zep(i, 0, 200)reverse(u[i].begin(), u[i].end());

    // zep(i, 0, 200){
    //     if(u[i].size() > 0){
    //         zep(j, 0, u[i].size())cout << u[i][j] << " "; cout << endl;
    //     }
    //     // if(v[i].size() > 0){
    //     //     zep(j, 0, v[i].size())cout << v[i][j] << " "; cout << endl;
    //     //     //printa(v[i], 0, v[i].size() - 1)
    //     // }
    // }
    // zep(i, 0, u[180].size())cout << u[180][i] << " "; cout << endl;
    // zep(i, 0, v[180].size())cout << v[180][i] << " "; cout << endl;

    zep(i, 0, 200){
        if(v[i].size() > 1 && u[i].size() > 1){
            if(u[i].size() != v[i].size()){
                print("Yes")
                cout << u[i].size() - 1 << " ";
                zep(j, 1, u[i].size())cout << u[i][j] + 1 << " "; cout << endl;
                cout << v[i].size() - 1 << " ";
                zep(j, 1, v[i].size())cout << v[i][j] + 1 << " "; cout << endl;
                return 0;
            }else{
                bool ok = false;
                zep(j, 0, v[i].size()){
                    if(u[i][j] != v[i][j])ok = true;
                }
                if(ok){
                    print("Yes")
                    cout << u[i].size() - 1 << " ";
                    zep(j, 1, u[i].size())cout << u[i][j] + 1 << " "; cout << endl;
                    cout << v[i].size() - 1 << " ";
                    zep(j, 1, v[i].size())cout << v[i][j] + 1 << " "; cout << endl;
                    return 0;
                }
            }
        }
    }

    print("No")

    return 0;
}