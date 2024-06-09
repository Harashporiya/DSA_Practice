#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> sortedArray(vector<int>& a,int k){
    int n = a.size();

    vector<int> sortArray;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i=0;i<=k && i<n;i++){
      minHeap.push(a[i]);
    }

    for(int i=k+1;i<n;i++){
        sortArray.push_back(minHeap.top());
        minHeap.pop();
        minHeap.push(a[i]);
    }
    
    while(!minHeap.empty()){
        sortArray.push_back(minHeap.top());
        minHeap.pop();
    }
    return sortArray;
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
   vector<int> sort = sortedArray(a,k);
   
   for(int i=0;i<sort.size();i++){
    cout<< sort[i] <<" ";
   }
}