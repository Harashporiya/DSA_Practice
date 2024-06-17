#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> frequency(vector<int>& a){
   int n = a.size();
   priority_queue<pair<int,int>> maxHeap;
   unordered_map<int,int> mp;

   for(int i=0;i<n;i++){
    mp[a[i]]++;
   }
   vector<int> result;
   for(auto i = mp.begin();i!=mp.end();i++){
      maxHeap.push({i->second,i->first});
    
   }
   while(!maxHeap.empty()){
     int fre = maxHeap.top().first;
     int ele = maxHeap.top().second;
     for(int i=0;i<fre;i++){
       result.push_back(ele);
     }
     maxHeap.pop();
   }
 return result;
  
} 
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<int> fre = frequency(a);

    for(int i=0;i<fre.size();i++){
        cout<<fre[i]<<" ";
    }
}