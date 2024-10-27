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
    void method(string& s){
        unordered_map<char, int>m;
        for(auto it: s) m[it]++;
        int c = 0;
        for(auto it: m){
            if(it.second & 1) c++;
        }
        if(c > 1){
            cout<<"NO SOLUTION"<<endl;
            return;
        }
        string ans = "";
        string odd = "";
        int count = 0;
        for(auto it: m){
            if(it.second & 1){
                odd.pb(it.first);
                count = it.second;
                continue;
            }
            rep(j,0,it.second/2){
                ans.pb(it.first);
            }
        }
        string t = ans;
        reverse(all(t));
        while(count--){
            ans += odd;
        }
        ans += t;
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