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
    void method(vvi& v, int n, vvi& q){
        vvi dist(n+1, vi(n+1, LLONG_MAX));
        for(auto it: v){
            dist[it[0]][it[1]] = min(dist[it[0]][it[1]], it[2]);
            dist[it[1]][it[0]] = min(dist[it[1]][it[0]], it[2]);
        }
        rep(i,1,n+1){
            dist[i][i] = 0;
        }
        rep(k,1,n+1){
            rep(i,1,n+1){
                rep(j,1,n+1){
                    if(dist[i][k] == LLONG_MAX || dist[k][j] == LLONG_MAX) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        rep(i,1,n+1){
            rep(j,1,n+1){
                if(dist[i][j] == LLONG_MAX) dist[i][j] = -1;
            }
        }
        for(auto it: q){
            cout<<dist[it[0]][it[1]]<<endl;
        }
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin>>n>>m>>q;
    vvi v(m, vi(3));
    rep(i,0,m) cin>>v[i][0]>>v[i][1]>>v[i][2];
    vvi queries(q, vi(2));
    rep(i,0,q) cin>>queries[i][0]>>queries[i][1];
    Kaarti ob;
    ob.method(v, n, queries);
    return 0;
}