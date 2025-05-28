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
    void method(vi& v, int n, vvi& q){
        int m = 30;
        vvi sparseTable(m+1, vi(n+1, -1));
        rep(i,0,n){
            sparseTable[0][i+1] = v[i];
        }
        rep(i,1,m+1){
            rep(j,1,n+1){
                sparseTable[i][j] = sparseTable[i-1][sparseTable[i-1][j]];
            }
        }
        for(auto it: q){
            int x = it[0], k = it[1];
            int ans = x;
            rep(i,0,m+1){
                if(k & (1 << i)){
                    ans = sparseTable[i][ans];
                }
            }
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
    rep(i,0,q) cin>>queries[i][0]>>queries[i][1];
    Kaarti ob;
    ob.method(v, n, queries);
    return 0;
}