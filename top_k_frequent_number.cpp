#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> frequent(vector<int>& a, int k){
    int n = a.size();
    priority_queue<pair<int,int >,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;

    unordered_map<int, int> mp;
    for(int i=0;i<n;i++){
         mp[a[i]]++;
    }

    for(auto i = mp.begin();i!=mp.end();i++){
        minHeap.push({i->second,i->first});
        if(minHeap.size()>k){
            minHeap.pop();
        }
    }

    vector<int> result;
    while(!minHeap.empty()){
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    sort(result.begin(),result.end());
  

    return result;

}
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<int> freq = frequent(a,k);

    for(int i=0;i<freq.size();i++){
        cout<<freq[i]<<" ";
    }
}