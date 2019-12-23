#include <iostream>
#include <queue>
#include <string>

std::vector<std::string> map;
bool visited[10][10][10][10];

typedef struct
{
  int ry;
  int rx;
  int by;
  int bx;
  int cnt;
} BallInfo;

int bfs(BallInfo start)
{
  std::queue<BallInfo> q;
  q.push(start);
  visited[start.ry][start.rx][start.by][start.bx] = true;

  int dy[] = {-1, 1, 0, 0};
  int dx[] = {0, 0, -1, 1};

  while(!q.empty())
  {
    BallInfo info = q.front(); q.pop();
    if(info.cnt > 10) { return -1; }
    if(map[info.ry][info.rx] == 'O' && map[info.by][info.bx] != 'O') { return info.cnt; }

    for(int dir = 0; dir < 4; dir++)
    {
      int next_ry = info.ry;
      int next_rx = info.rx;
      int next_by = info.by;
      int next_bx = info.bx;

      // 빨간 구슬 이동
      while(1)
      {
        if(map[next_ry][next_rx] == '#')
        {
          next_ry -= dy[dir];
          next_rx -= dx[dir];
          break;
        }
        else if(map[next_ry][next_rx] == 'O')
        {
          break;
        }
        else
        {
          next_ry += dy[dir];
          next_rx += dx[dir];
        }
      }

      // 파란 구슬 이동
      while(1)
      {
        if(map[next_by][next_bx] == '#')
        {
          next_by -= dy[dir];
          next_bx -= dx[dir];
          break;
        }
        else if(map[next_by][next_bx] == 'O')
        {
          break;
        }
        else
        {
          next_by += dy[dir];
          next_bx += dx[dir];
        }
      }

      // 두 구슬이 같이 있으면 옮겨 주기
      if((next_ry == next_by && next_rx == next_bx) && (map[next_ry][next_rx] != 'O' && map[next_by][next_bx] != 'O'))
      {
        int diff_red = abs(next_ry - info.ry) + abs(next_rx - info.rx);
        int diff_blue = abs(next_by - info.by) + abs(next_bx - info.bx);
        if(diff_red > diff_blue)
        {
          next_ry -= dy[dir];
          next_rx -= dx[dir];
        }
        else
        {
          next_by -= dy[dir];
          next_bx -= dx[dir];
        }
      }

      if(visited[next_ry][next_rx][next_by][next_bx] == false)
      {
        visited[next_ry][next_rx][next_by][next_bx] = true;
        BallInfo next;
        next.ry = next_ry;
        next.rx = next_rx;
        next.by = next_by;
        next.bx = next_bx;
        next.cnt = info.cnt + 1;
        q.push(next);
      }
    }
  }

  return -1;
}

int main()
{
  int N, M;
  std::cin >> N >> M;
  map.resize(N);
  for (int i = 0; i < N; i++)
  {
    std::cin >> map[i];
  }

  BallInfo start;
  start.cnt = 0;
  for (int y = 0; y < N; y++)
  {
    for (int x = 0; x < M; x++)
    {
      if (map[y][x] == 'R')
      {
        start.ry = y;
        start.rx = x;
      }
      if (map[y][x] == 'B')
      {
        start.by = y;
        start.bx = x;
      }
    }
  }

  int ret = bfs(start);
  std::cout << ret << std::endl;
}