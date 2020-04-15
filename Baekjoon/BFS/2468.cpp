/*
 * https://www.acmicpc.net/problem/2468
 * 안전 영역 문제
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int map[100][100];
bool visited[100][100];
int N;

void bfs(pair<int, int> start, int h)
{
  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, -1, 1};

  queue<pair<int, int>> q;
  q.push(start);

  while(!q.empty())
  {
    auto info = q.front(); q.pop();
    int currX = info.first;
    int currY = info.second;
    for(int dir = 0; dir < 4; dir++)
    {
      int nextX = currX + dx[dir];
      int nextY = currY + dy[dir];

      if(nextX < 0 || nextX >= N || nextY < 0 || nextY >= N) { continue; }
      if(map[nextX][nextY] <= h)
      {
        visited[nextX][nextY] = true;
        continue;
      }

      if(!visited[nextX][nextY])
      {
        visited[nextX][nextY] = true;
        auto newInfo = make_pair(nextX, nextY);
        q.push(newInfo);
      }
    }
  }
}

int main(void)
{
  cin >> N;

  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N; j++)
    {
      cin >> map[i][j];
    }
  }

  int answer = 0;
  for(int h = 0; h <= 100; h++)
  {
    int tempAnswer = 0;
    for(int i = 0; i < N; i++)
    {
      for(int j = 0; j < N; j++)
      {
        if(map[i][j] > h && !visited[i][j])
        {
          visited[i][j] = true;
          pair<int, int> start = make_pair(i, j);
          bfs(start, h);
          tempAnswer++;
        }
      }
    }

    for(int i = 0; i < N; i++)
    {
      for(int j = 0; j < N; j++)
      {
        visited[i][j] = false;
      }
    }

    answer = max(answer, tempAnswer);
  }

  cout << answer << endl;
}
