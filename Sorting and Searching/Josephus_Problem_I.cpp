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
    void method(int n){
        if(n == 1){
            cout<<n<<endl;
            return;
        }
        set<int>s;
        rep(i,1,n+1) s.insert(i);
        auto it = s.begin();
        it++;
        while(!s.empty()){
            cout<<(*it)<<" ";
            it = s.erase(it);
            if(s.empty()) break;
            if(it == s.end()) it = s.begin();
            it++;
            if(it == s.end()) it = s.begin();
        }
        cout<<endl;
    }
};

int32_t main(){
    
        int n;
        cin>>n;
        
        Kaarti *ob = new Kaarti;
        ob->method(n);
    return 0;
}