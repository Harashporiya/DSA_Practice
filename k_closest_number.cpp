#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> closest(vector<int>& a, int k, int x) {
    int n = a.size();
    priority_queue<pair<int, int>> maxheap;

    for (int i = 0; i < n; i++) {
        maxheap.push({abs(a[i] - x), i});
        if (maxheap.size() > k) {
            maxheap.pop();
        }
    }

    vector<int> indices;
    while (!maxheap.empty()) {
        indices.push_back(maxheap.top().second);
        maxheap.pop();
    }

    sort(indices.begin(), indices.end());

    vector<int> result;
    for (int index : indices) {
        result.push_back(a[index]);
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    int k, x;
    cin >> k >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> close = closest(a, k, x);
    for (int i = 0; i < close.size(); i++) {
        cout << close[i] << " ";
    }
    cout << endl;
    return 0;
}
