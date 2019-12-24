#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

int N, M;
int map[8][8];
int tempMap[8][8];
int mapSpreaded[8][8];
int maxRet = 0;

typedef struct
{
  int x;
  int y;
} VirusInfo;

std::vector<VirusInfo> viruses;

void SetMaxRet()
{
  int ret = 0;

  for(int y = 0; y < N; y++)
  {
    for(int x = 0; x < M; x++)
    {
      if(mapSpreaded[y][x] == 0)
      {
        ret++;
      }
    }
  }

  if(ret > maxRet)
  {
    maxRet = ret;
  }
}

void bfs()
{
  memcpy(mapSpreaded, tempMap, sizeof(tempMap));

  int dy[] = {-1, 1, 0, 0};
  int dx[] = {0, 0, -1, 1};

  for(auto v: viruses)
  {
    std::queue<VirusInfo> q;
    q.push(v);
    while(!q.empty())
    {
      VirusInfo info = q.front(); q.pop();

      for(int dir = 0; dir < 4; dir++)
      {
        int next_y = info.y + dy[dir];
        int next_x = info.x + dx[dir];

        if(next_y >= N || next_y < 0) { continue; }
        if(next_x >= M || next_x < 0) { continue; }

        if(mapSpreaded[next_y][next_x] == 0)
        {
          mapSpreaded[next_y][next_x] = 2;
          VirusInfo next;
          next.y = next_y;
          next.x = next_x;
          q.push(next);
        }
      }
    }
  }
}

void MakeRestWall(int numWallToMake)
{
  if(numWallToMake == 0)
  {
    bfs();
    SetMaxRet();
    return;
  }

  for(int y = 0; y < N; y++)
  {
    for(int x = 0; x < M; x++)
    {
      if(tempMap[y][x] == 0)
      {
        tempMap[y][x] = 1;
        MakeRestWall(numWallToMake - 1);
        tempMap[y][x] = 0;
      }
    }
  }
}

int main(void)
{
  std::cin >> N >> M;

  for(int y = 0; y < N; y++)
  {
    for(int x = 0; x < M; x++)
    {
      std::cin >> map[y][x];
      if(map[y][x] == 2)
      {
        VirusInfo v;
        v.y = y;
        v.x = x;
        viruses.push_back(v);
      }
    }
  }

  for(int y = 0; y < N; y++)
  {
    for(int x = 0; x < M; x++)
    {
      if(map[y][x] == 0)
      {
        memcpy(tempMap, map, sizeof(map));
        tempMap[y][x] = 1;
        MakeRestWall(2);
      }
    }
  }

  std::cout << maxRet << std::endl;

  return 0;
}