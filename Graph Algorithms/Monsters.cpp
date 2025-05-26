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
    vector<pair<pair<int, int>, string>> dir = {
        {{-1, 0}, "U"},
        {{1, 0}, "D"},
        {{0, -1}, "L"},
        {{0, 1}, "R"},
    };

    void bfsMonsters(vector<string>& v, vvi& dist){
        int n = v.size(), m = v[0].size();
        queue<pair<int, int>> q;
        rep(i,0,n){
            rep(j,0,m){
                if(v[i][j] == 'M'){
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x = it.first, y = it.second;
            for(auto d: dir){
                int newX = x + d.first.first, newY = y + d.first.second;
                if(newX >= 0 && newX < n && newY >= 0 && newY < m && v[newX][newY] == '.' && dist[x][y] + 1 < dist[newX][newY]){
                    dist[newX][newY] = dist[x][y] + 1;
                    q.push({newX, newY});
                }
            }
        }
    }

    void bfs(pair<int, int>& st, vector<string>& v, map<pair<int, int>, pair<int, int>>& par, vvi& dist, pair<int, int>& end){
        int n = v.size(), m = v[0].size();
        queue<pair<pair<int, int>, int>> q;
        q.push({st, 0});
        vvi vis(n, vi(m, 0));
        vis[st.first][st.second] = 1;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x = it.first.first, y = it.first.second, steps = it.second;
            if(x == 0 || x == n-1 || y == 0 || y == m-1){
                end = {x, y};
                return;
            }
            for(auto d: dir){
                int newX = x + d.first.first, newY = y + d.first.second;
                if(newX >= 0 && newX < n && newY >= 0 && newY < m && v[newX][newY] == '.' && vis[newX][newY] == 0 && steps + 1 < dist[newX][newY]){
                    vis[newX][newY] = 1;
                    par[{newX, newY}] = {x, y};
                    q.push({{newX, newY}, steps + 1});
                }
            }
        }
    }

public:
    void method(vector<string>& v, int n, int m){
        vvi dist(n, vi(m, INT_MAX));
        pair<int, int> st;
        rep(i,0,n){
            rep(j,0,m){
                if(v[i][j] == 'A'){
                    v[i][j] = '.';
                    st = {i, j};
                    break;
                }
            }
        }
        bfsMonsters(v, dist);
        map<pair<int, int>, pair<int, int>> par;
        pair<int, int> end = {-1, -1};
        bfs(st, v, par, dist, end);
        if(end.first == -1){
            cout<<"NO"<<endl;
            return;
        }
        string path = "";
        pair<int, int> curr = end;
        while(curr != st){
            pair<int, int> parent = par[curr];
            for(auto d: dir){
                if(parent.first + d.first.first == curr.first && parent.second + d.first.second == curr.second){
                    path += d.second;
                    break;
                }
            }
            curr = parent;
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