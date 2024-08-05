#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> stockSpanProblem(vector<int> a, int n){
    vector<int> v;
    stack<pair<int,int>> s;
    vector<int> ans;
    for(int i=0;i<=n;i++){
        if(s.size() == 0){
            v.push_back(-1);
        }
        else if(s.size()>0 && s.top().first>a[i]){
            v.push_back(s.top().second);
        }else if(s.size()>0 && s.top().first<=a[i]){
            while(s.size()>0 && s.top().first<=a[i]){
                s.pop();
            }
            if(s.size()==0){
                v.push_back(-1);
            }else{
                v.push_back(s.top().second);
            }
        }
        s.push({a[i], i});
        ans.push_back(i-v[i]);
    }

    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> stock = stockSpanProblem(a,n);
    for(auto i:stock){
        cout<<i<<" ";
    }
}