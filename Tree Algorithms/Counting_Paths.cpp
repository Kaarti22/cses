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
    void dfsDepth(vvi& adj, int node, int par, int dist, vi& depth, vi& parent){
        depth[node] = dist;
        parent[node] = par;
        for(auto it: adj[node]){
            if(it == par) continue;
            dfsDepth(adj, it, node, dist + 1, depth, parent);
        }
    }

    int findKthParent(int node, int k, vvi& sparseTable, int m){
        int ans = node;
        rep(i,0,m+1){
            if(k & (1 << i)){
                ans = sparseTable[i][ans];
                if(ans == -1) break;
            }
        }
        return ans;
    }

    int findLCA(int a, int b, vi& depth, vvi& sparseTable, int m){
        if(depth[a] < depth[b]) swap(a, b);
        int diff = depth[a] - depth[b];
        a = findKthParent(a, diff, sparseTable, m);
        if(a == b) return a;
        for(int i=m; i>=0; i--){
            if(sparseTable[i][a] != -1 && sparseTable[i][a] != sparseTable[i][b]){
                a = sparseTable[i][a];
                b = sparseTable[i][b];
            }
        }
        return sparseTable[0][a];
    }

    int dfs(vvi& adj, int node, vi& parent, vi& values){
        int sum = 0;
        for(auto it: adj[node]){
            if(it == parent[node]) continue;
            sum += dfs(adj, it, parent, values);
        }
        values[node] += sum;
        return values[node];
    }

public:
    void method(vvi& v, int n, vvi& q){
        vvi adj(n+1, vi());
        for(auto it: v){
            adj[it[0]].pb(it[1]);
            adj[it[1]].pb(it[0]);
        }
        vi depth(n+1, -1), parent(n+1, -1);
        dfsDepth(adj, 1, -1, 0, depth, parent);
        int m = 20;
        vvi sparseTable(m+1, vi(n+1, -1));
        rep(j,1,n+1){
            sparseTable[0][j] = parent[j];
        }
        rep(i,1,m+1){
            rep(j,1,n+1){
                int prev = sparseTable[i-1][j];
                if(prev != -1){
                    sparseTable[i][j] = sparseTable[i-1][prev];
                }
            }
        }
        vi values(n+1, 0);
        for(auto it: q){
            int a = it[0], b = it[1];
            int lca = findLCA(a, b, depth, sparseTable, m);
            values[a]++;
            values[b]++;
            values[lca]--;
            if(parent[lca] != -1) values[parent[lca]]--;
        }
        dfs(adj, 1, parent, values);
        rep(i,1,n+1){
            cout<<values[i]<<" ";
        }
        cout<<endl;
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin>>n>>q;
    vvi v(n-1, vi(2));
    rep(i,0,n-1) cin>>v[i][0]>>v[i][1];
    vvi queries(q, vi(2));
    rep(i,0,q) cin>>queries[i][0]>>queries[i][1];
    Kaarti ob;
    ob.method(v, n, queries);
    return 0;
}