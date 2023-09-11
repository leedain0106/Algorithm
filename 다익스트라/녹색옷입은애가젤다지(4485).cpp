// https://www.acmicpc.net/problem/4485
#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;
int mat[125][125];
int min_mat[125][125];
int visited[125][125];

// 위, 오, 아, 왼
int p[4][2] = {{-1,0}, {0,1},{1,0},{0,-1}};

struct rupee{
  int rp;
  int x,y;
};
struct compare{
  bool operator()(const rupee& r1, const rupee& r2){
    return r1.rp > r2.rp;
  }
};
int main(){
  int n = 1;
  int count = 1;
  while(n != 0){
    scanf("%d", &n);
    if(n == 0) break;

    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        scanf("%d", &mat[i][j]);
        visited[i][j] = 0; // visited 초기화
        min_mat[i][j] = 1000000; // 최소값 저장 배열 초기화
      }
    }

    priority_queue<rupee, vector<rupee>, compare> pq;

    min_mat[0][0] = mat[0][0];
    rupee r = {mat[0][0], 0, 0};
    pq.push(r);
    while(!pq.empty()){
      r = pq.top();
      pq.pop();
      visited[r.x][r.y] = 1;
      for(int i=0;i<4;i++){
        int x = r.x + p[i][0];
        int y = r.y + p[i][1];
        if(x >= 0 && y >= 0 && x < n && y < n && visited[x][y] == 0){
          if(r.rp + mat[x][y] < min_mat[x][y]){
            min_mat[x][y] = r.rp + mat[x][y];
            rupee update_rp = {min_mat[x][y], x, y};
            pq.push(update_rp);
          }
        }
      }
    }  
    printf("Problem %d: %d\n", count, min_mat[n-1][n-1]);
    count++;  
  }
}