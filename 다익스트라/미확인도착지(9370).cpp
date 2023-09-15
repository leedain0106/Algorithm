// https://www.acmicpc.net/problem/9370
// 목적지 후보로 가는 최단 경로 중에 g, h를 지나는 경우를 찾는 것.
// 주의. 최단 경로가 여러개 인 경우가 여러개인 경우 있을 수 있음(g,h 지나는 경우 우선 선택하도록)
// 양방향 주의
// 기존 다익스트라에서 추가로 check 배열사용해서 g,h사이를 지나왔는지 체크함. 목적지 후보중에 check값이 1인 경우 지나온 것으로 판별.
// **결과 오름차순으로 출력하기!
#include <cstdio>
#include <vector>
#include <queue>
#define MAX 1000000000
using namespace std;
vector< pair<int, int> > adj[2001];
int dist[2001];
int check[2001];
int visited[2001];
int dest[20];

int main(){
  int testCase;
  scanf("%d", &testCase);
  for(int ts=1;ts<=testCase;ts++){

    int n, m, t;
    scanf("%d %d %d", &n, &m, &t);

    // init
    for(int i=0;i<=n;i++){
      adj[i].clear();
      dist[i] = MAX;
      check[i] = 0;
      visited[i] = 0;
    }

    int s, g, h;
    scanf("%d %d %d", &s, &g, &h);

    // adj
    for(int i=0;i<m;i++){
      int a, b, d;
      scanf("%d %d %d", &a, &b, &d);
      adj[a].push_back(make_pair(b, d));
      adj[b].push_back(make_pair(a, d));
    }

    priority_queue< pair<int, int> > pq; // -가중치, node 번호

    dist[s] = 0;
    pq.push(make_pair(0, s));
    while(!pq.empty()){
      pair<int, int> cur = pq.top();
      pq.pop();
      visited[cur.second] = 1;
      for(int i=0;i<adj[cur.second].size();i++){
        int node = adj[cur.second][i].first;
        int w = adj[cur.second][i].second;
        if(visited[node] == 0){
          if(dist[cur.second] + w <= dist[node]){
            // 가중치가 같은 경우. g, h 포함된 경우가 선택되어야 함.
            if(dist[cur.second] + w == dist[node]){
              if(check[node] == 1) continue;
            }
            dist[node] = dist[cur.second] + w;
            pq.push(make_pair(-dist[node], node));
            
            if(check[cur.second] == 1) {
              check[node] = 1;
            }else{
              if((cur.second == g && node == h) ||(cur.second == h && node == g)) check[node] = 1;
              else check[node] = 0;
            }

          }
        }
      }
    }

    for(int i=0;i<t;i++){
      scanf("%d", &dest[i]);
    }
    sort(dest, dest+t); // 오름차순 정렬
    for(int i=0;i<t;i++){
      if(check[dest[i]] == 1){
        printf("%d ", dest[i]);
      }
    }
    printf("\n");
  }

}