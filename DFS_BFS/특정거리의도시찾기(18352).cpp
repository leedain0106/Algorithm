// https://www.acmicpc.net/problem/18352
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> bfs(vector<int> graph[],vector<int> dst, int x ) {
    deque<int> queue;
    queue.push_back(x);
    dst[x] = 0;
    
    while (queue.size() > 0) {
        int node = queue.front();
        queue.pop_front();
        int count = dst[node] + 1;
        
        for (int i=0;i<graph[node].size();i++){
            int n = graph[node][i];
            if (dst[n] == 0 && n != x) {
                queue.push_back(n);
                dst[n] = count;
            }
        }
    }
    return dst;
}

int main() {
    
    int n, l, k, x;
    cin >> n >> l >> k >> x;

    vector<int> graph[n+1];
    vector<int> dst(n+1);
    
    for(int i=0;i<l;i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    
    vector<int> result_dst = bfs(graph, dst, x);

    int count = 0;
    for (int i=1;i<n+1;i++) {
        if(result_dst[i] == k){
            count = count + 1;
            cout << i << endl;;
        }
    }

    if (count == 0) {
         cout << -1 << endl;
    }
}
