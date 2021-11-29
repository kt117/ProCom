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

string a, b;
ll na, nb, cnta[10], cntb[10], mx;
bool rev = false;
vector<ll> va, vb;

void r(){
    rev = true;
    string tmp = a;
    a = b;
    b = tmp;
}

void init(){
    memset(cnta, 0, sizeof(cnta));
    memset(cntb, 0, sizeof(cntb));
    zep(i, 0, na)cnta[a[i] - '0']++;
    zep(i, 0, nb)cntb[b[i] - '0']++;
}

void solve(ll sa, ll sb){
    init();
    if(cnta[sa] * cntb[sb] == 0)return;

    ll k = 1;
    vector<ll> ansa, ansb;
    ansa.push_back(sa); cnta[sa]--;
    ansb.push_back(sb); cntb[sb]--;

    ll ia = 1, ib = 9;
    zep(i, 1, nb){
        while(cntb[ib] == 0)ib--;
        while(ia <= 9 && (cnta[ia] == 0 || ia + ib < 9))ia++;
        if(ia == 10)break;
        
        ansa.push_back(ia); cnta[ia]--;
        ansb.push_back(ib); cntb[ib]--;
        k++;
    }

    ia = 9, ib = 9;
    while(ia > 0){
        while(ia > 0 && cnta[ia] == 0)ia--;
        if(ia > 0){
            if(ia == 9 && ansb.size() == nb)k++;
            ansa.push_back(ia); cnta[ia]--;
        }
    }
    while(ib > 0){
        while(ib > 0 && cntb[ib] == 0)ib--;
        if(ib > 0){
            ansb.push_back(ib); cntb[ib]--;
        }
    }

    reverse(ansa.begin(), ansa.end());
    reverse(ansb.begin(), ansb.end());
    if(rev)ansa.swap(ansb);
    if(k > mx){
        mx = k;
        va.swap(ansa);
        vb.swap(ansb);
    }
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> a >> b;
    if(a.size() < b.size())r();
    
    na = a.size();
    nb = b.size();

    
    rep(sa, 1, 9){
        rep(sb, 10 - sa, 9){
            solve(sa, sb);
        }
    }

    if(mx == 0){
        if(rev)r();
        print(a)
        print(b)
    }else{
        zep(i, 0, va.size())cout << va[i]; cout << endl;
        zep(i, 0, vb.size())cout << vb[i]; cout << endl;
    }

    return 0;
}