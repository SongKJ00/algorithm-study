#include <iostream>
#include <vector>
#include <string.h>

int N;
int map[20][20];
int maxRet = 0;

void MoveMap(int cnt)
{
  if(cnt == 5)
  {
    for(int y = 0; y < N; y++)
    {
      for(int x = 0; x < N; x++)
      {
        maxRet = std::max(maxRet, map[y][x]);
      }
    }
    return;
  }

  int tempMap[20][20];
  memcpy(tempMap, map, sizeof(map));

  // 상, 하, 좌, 우
  for(int dir = 0; dir < 4; dir++)
  {
    for(int i = 0; i < N; i++)
    {
      std::vector<int> v;
      for(int j = 0; j < N; j++)
      {
        if(dir == 0 || dir == 1)
        {
          if(map[j][i] != 0)
            v.push_back(map[j][i]);
        }
        else
        {
          if(map[i][j] != 0)
            v.push_back(map[i][j]);
        }
      }

      // 상
      if(dir == 0)
      {
        int num = 0;
        for(int j = 0; j < v.size(); j++)
        {
          if(j < v.size()-1 && v[j] == v[j+1])
          {
            map[num++][i] = v[j]*2;
            j++;
          }
          else
          {
            map[num++][i] = v[j];
          }
        }
        while(num < N)
        {
          map[num++][i] = 0;
        }
      }
      // 하
      else if(dir == 1)
      {
        int num = N-1;
        for(int j = v.size()-1; j >= 0; j--)
        {
          if(j > 0 && v[j] == v[j-1])
          {
            map[num--][i] = v[j]*2;
            j--;
          }
          else
          {
            map[num--][i] = v[j];
          }
        }
        while(num >= 0)
        {
          map[num--][i] = 0;
        }
      }
      // 좌
      else if(dir == 2)
      {
        int num = 0;
        for(int j = 0; j < v.size(); j++)
        {
          if(j < v.size()-1 && v[j] == v[j+1])
          {
            map[i][num++] = v[j]*2;
            j++;
          }
          else
          {
            map[i][num++] = v[j];
          }
        }
        while(num < N)
        {
          map[i][num++] = 0;
        }
      }
      // 우
      else
      {
        int num = N-1;
        for(int j = v.size()-1; j >= 0; j--)
        {
          if(j > 0 && v[j] == v[j-1])
          {
            map[i][num--] = v[j]*2;
            j--;
          }
          else
          {
            map[i][num--] = v[j];
          }
        }
        while(num >= 0)
        {
          map[i][num--] = 0;
        }
      }
    }

    MoveMap(cnt+1);
    memcpy(map, tempMap, sizeof(map));
  }
}

int main()
{
  std::cin >> N;
  for(int y = 0; y < N; y++)
  {
    for(int x = 0; x < N; x++)
    {
      std::cin >> map[y][x];
    }
  }

  MoveMap(0);
  std::cout << maxRet << std::endl;

  return 0;
}