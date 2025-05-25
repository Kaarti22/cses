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
    vector<pair<pair<int, int>, string>> dir = {
        {{-1, 0}, "U"},
        {{1, 0}, "D"},
        {{0, -1}, "L"},
        {{0, 1}, "R"}
    };

public:
    void method(vector<string>& v, int n, int m){
        pair<int, int> src, dst;
        rep(i,0,n){
            rep(j,0,m){
                if(v[i][j] == 'A') src = {i, j};
                if(v[i][j] == 'B'){
                    dst = {i, j};
                    v[i][j] = '.';
                }
            }
        }
        vvi vis(n, vi(m, 0));
        vis[src.first][src.second] = 1;
        vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(m, {-1, -1}));
        queue<pair<int, int>> q;
        q.push(src);
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            pair<int, int> pos = it;
            if(pos == dst) break;
            for(auto d: dir){
                int x = pos.first + d.first.first, y = pos.second + d.first.second;
                if(x >= 0 && x < n && y >= 0 && y < m && v[x][y] == '.' && vis[x][y] == 0){
                    vis[x][y] = 1;
                    par[x][y] = {pos.first, pos.second};
                    q.push({x, y});
                }
            }
        }
        if(vis[dst.first][dst.second] == 0){
            cout<<"NO"<<endl;
            return;
        }
        string path = "";
        pair<int, int> curr = dst;
        while(curr != src){
            auto p = par[curr.first][curr.second];
            int px = p.first, py = p.second;
            for(auto it: dir){
                if(px + it.first.first == curr.first && py + it.first.second == curr.second){
                    path += it.second;
                    break;
                }
            }
            curr = p;
        }
        reverse(all(path));
        cout<<"YES"<<endl;
        cout<<path.size()<<endl;
        cout<<path<<endl;
    }
};

int32_t main(){
    int n, m;
    cin>>n>>m;
    vector<string> v(n);
    rep(i,0,n) cin>>v[i];
    Kaarti ob;
    ob.method(v, n, m);
    return 0;
}