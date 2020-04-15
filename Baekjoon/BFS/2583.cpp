/*
 * https://www.acmicpc.net/problem/2583
 * 영역 구하기 문제
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> map;

int main()
{
  int M, N, K;

  cin >> M >> N >> K;

  map.resize(M);
  for(int i = 0; i < map.size(); i++)
  {
    map[i].resize(N);
  }

  for(int i = 0; i < K; i++)
  {
    int leftX, leftY, rightX, rightY;
    cin >> leftX >> leftY >> rightX >> rightY;
    for(int y = leftY; y < rightY; y++)
    {
      for(int x = leftX; x < rightX; x++)
      {
        map[y][x] = 1;
      }
    }
  }
  
}