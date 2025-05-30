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
private:
    void dfs(vvi& adj, int node, int par, int dist, vi& depth){
        depth[node] = dist;
        for(auto it: adj[node]){
            if(it == par) continue;
            dfs(adj, it, node, dist + 1, depth);
        }
    }

    int findKthParent(int node, int k, vvi& sparseTable, int m){
        int ans = node;
        rep(i,0,m+1){
            if(k & (1 << i)){
                ans = sparseTable[i][ans];
            }
        }
        return ans;
    }

public:
    void method(vi& v, int n, vvi& q){
        vvi adj(n+1, vi());
        rep(i,2,n+1){
            adj[i].pb(v[i-2]);
            adj[v[i-2]].pb(i);
        }
        vi depth(n+1, -1);
        dfs(adj, 1, 0, 0, depth);
        int m = 20;
        vvi sparseTable(m+1, vi(n+1, -1));
        rep(j,2,n+1){
            sparseTable[0][j] = v[j-2];
        }
        rep(i,1,m+1){
            rep(j,1,n+1){
                int prev = sparseTable[i-1][j];
                if(prev != -1) sparseTable[i][j] = sparseTable[i-1][sparseTable[i-1][j]];
            }
        }
        for(auto it: q){
            int a = it[0], b = it[1];
            if(depth[a] < depth[b]) swap(a, b);
            int diff = depth[a] - depth[b];
            a = findKthParent(a, diff, sparseTable, m);
            if(a == b){
                cout<<a<<endl;
                continue;
            }
            for(int i=m; i>=0; i--){
                if(sparseTable[i][a] != -1 && sparseTable[i][a] != sparseTable[i][b]){
                    a = sparseTable[i][a];
                    b = sparseTable[i][b];
                }
            }
            cout<<sparseTable[0][a]<<endl;
        }
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin>>n>>q;
    vi v(n-1);
    inpvec(v, n-1);
    vvi queries(q, vi(2));
    rep(i,0,q) cin>>queries[i][0]>>queries[i][1];
    Kaarti ob;
    ob.method(v, n, queries);
    return 0;
}