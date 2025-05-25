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

class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        rep(i,0,n+1){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Kaarti{
public:
    void method(vvi& v, int n, int m){
        DisjointSet ds(n);
        for(auto it: v){
            ds.unionBySize(it[0], it[1]);
        }
        int ans = 0;
        vvi edges;
        rep(i,2,n+1){
            int ulp = ds.findUPar(1);
            int ulp_node = ds.findUPar(i);
            if(ulp == ulp_node) continue;
            ans++;
            edges.pb({1, i});
            ds.unionBySize(1, i);
        }
        cout<<ans<<endl;
        for(auto it: edges){
            cout<<it[0]<<" "<<it[1]<<endl;
        }
    }
};

int32_t main(){
    int n, m;
    cin>>n>>m;
    vvi v(m, vi(2));
    rep(i,0,m) cin>>v[i][0]>>v[i][1];
    Kaarti ob;
    ob.method(v, n, m);
    return 0;
}