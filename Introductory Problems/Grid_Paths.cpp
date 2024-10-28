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
    void generate(vector<string>& v, string& s, int ind){
        int n = s.size();
        if(ind >= n){
            v.pb(s);
            return;
        }
        if(s[ind] != '?'){
            generate(v, s, ind+1);
            return;
        }
        s[ind] = 'D';
        generate(v, s, ind+1);
        s[ind] = 'U';
        generate(v, s, ind+1);
        s[ind] = 'L';
        generate(v, s, ind+1);
        s[ind] = 'R';
        generate(v, s, ind+1);
    }

public:
    void method(string& s){
        vector<string>v;
        generate(v, s, 0);
        vvi grid(7, vi(7));
        int ans = 0;
        for(auto it: v){
            int x = 0, y = 0;
            bool f = 1;
            for(auto dir: it){
                if(dir == 'D') x++;
                else if(dir == 'U') x--;
                else if(dir == 'R') y++;
                else y--;
                if(x < 0 || x > 6 || y < 0 || y > 6){
                    f = 0;
                    break;
                }
            }
            if(f && x == 6 && y == 0) ans++;
        }
        cout<<ans<<endl;
    }
};

int32_t main(){
    string s;
    cin>>s;
    Kaarti *ob = new Kaarti;
    ob->method(s);
    return 0;
}