#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define MOD 1000000007
#define pb push_back
#define popb pop_back
#define rep(i,a,b) for(int i=a; i<b; i++)
#define all(v) v.begin(),v.end()

void inparr(int arr[], int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}

void disarr(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

void inpvec(vi &v, int n){
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
}

void disvec(vi v, int n){
    for(int i=0;i<n;i++){
        cout<<v[i]<<' ';
    }
    cout<<endl;
}

int madd(int a,int b) {
    return (a+b)%MOD;
}

int msub(int a,int b){
    return (((a-b)%MOD)+MOD)%MOD;
}

int mmul(int a,int b){
    return ((a%MOD)*(b%MOD))%MOD;
}

class Kaarti{
public:
    void method(vi& v, vvi& q, int n){
        int m = log2l(n);
        vvi sparseTable(m+1, vi(n));
        rep(i,0,n){
            sparseTable[0][i] = v[i];
        }
        rep(i,1,m+1){
            for(int j=0; j + (1 << i) <= n; j++){
                sparseTable[i][j] = min(sparseTable[i-1][j], sparseTable[i-1][j + (1 << (i - 1))]);
            }
        }
        for(auto it: q){
            int l = it[0] - 1, r = it[1] - 1;
            int len = r - l + 1;
            int k = log2l(len);
            int ans = min(sparseTable[k][l], sparseTable[k][r - (1 << k) + 1]);
            cout<<ans<<endl;
        }
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin>>n>>q;
    vi v(n);
    inpvec(v, n);
    vvi queries(q, vi(2));
    rep(i,0,q){
        cin>>queries[i][0]>>queries[i][1];
    }
    Kaarti ob;
    ob.method(v, queries, n);
    return 0;
}