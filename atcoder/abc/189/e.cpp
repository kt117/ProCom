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

template<typename T> struct Matrix {
    vector<vector<T>> A;

    Matrix(int n, int m, T x) : A(n, vector<T> (n, x)) {}
    Matrix(vector<vector<T>> a) {
        A.resize(a.size());
        for (int i = 0; i < a.size(); i++) {
            A[i].resize(a[i].size());
            for (int j = 0; j < a[i].size(); j++)
                A[i][j] = a[i][j];
        }
    }
    
    size_t size() const {return A.size();}
    vector<T>& operator [] (int i) {return A[i];}
    const vector<T>& operator [] (int i) const {return A[i];}

    Matrix operator * (const Matrix &B) {
        Matrix<T> R(A.size(), B[0].size(), 0);
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < B[0].size(); j++)
                for (int k = 0; k < B.size(); k++)
                    R[i][j] += A[i][k] * B[k][j];
        return R;
    }

    Matrix operator + (const Matrix &B) {
        Matrix<T> R(A.size(), A[0].size(), 0);
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < A[0].size(); j++)
                R[i][j] = A[i][j] + B[i][j];
        return R;
    }
};

template<typename T> Matrix<T> identity(int n) {
    Matrix<T> R(n, n, 0);
    for (int i = 0; i < n; i++) R[i][i] = 1;
    return R;
}

template<typename T> Matrix<T> pow(const Matrix<T> &A, long long x) {
    if (x == 0)return identity<T>(A.size());
    Matrix<T> R = pow(A, x / 2);
    return (x % 2)? R * R * A : R * R;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    ll x[n], y[n]; zep(i, 0, n)cin >> x[i] >> y[i];
    
    ll m; cin >> m;
    ll o[m], p[m];
    zep(i, 0, m){
        cin >> o[i];
        if(o[i] >= 3)cin >> p[i];
    }
    
    ll q; cin >> q;
    ll a[q], b[q]; zep(i, 0, q){cin >> a[i] >> b[i]; b[i]--;}
    ll ans[q][2];
    vector<vector<ll>> v(m + 1);
    zep(i, 0, q)v[a[i]].push_back(i);

    zep(j, 0, v[0].size()){
        //print(x[b[v[0][j]]])
        ans[v[0][j]][0] = x[b[v[0][j]]];
        ans[v[0][j]][1] = y[b[v[0][j]]];
    }
    Matrix<ll> A = identity<ll>(2);
    Matrix<ll> P(2, 2, 0);
    Matrix<ll> B(2, 2, 0); B[0][1] = 1; B[1][0] = -1;
    Matrix<ll> C(2, 2, 0); C[0][1] = -1; C[1][0] = 1;
    Matrix<ll> D(2, 2, 0); D[0][0] = -1; D[1][1] = 1;
    Matrix<ll> E(2, 2, 0); E[0][0] = 1; E[1][1] = -1;    
    zep(i, 0, m){
        if(o[i] == 1){
            A = B * A;
            P = B * P;
        }
        if(o[i] == 2){
            A = C * A;
            P = C * P;
        }
        if(o[i] == 3){
            A = D * A;
            P = D * P;
            P[0][0] = P[0][0] + 2 * p[i];
        }
        if(o[i] == 4){
            A = E * A;
            P = E * P;
            P[1][0] = P[1][0] + 2 * p[i];
        }

        zep(j, 0, v[i + 1].size()){
            Matrix<ll> Q(2, 2, 0);
            Q[0][0] = x[b[v[i + 1][j]]];
            Q[1][0] = y[b[v[i + 1][j]]];

            Q = P + A * Q;
            ll xx = Q[0][0];
            ll yy = Q[1][0];
            ans[v[i + 1][j]][0] = xx;
            ans[v[i + 1][j]][1] = yy;
        }
    }

    zep(i, 0, q){
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    
    return 0;
}