#include <iostream>

typedef struct
{
  int x;
  int y;
  int val;
} Block;

const int specialBlockDirs[4][3] = {
        {0, 1, 3},
        {0, 1, 2},
        {0, 2, 3},
        {1, 2, 3}};
int N, M;
int map[500][500];
bool visited[500][500];
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
Block block[4];
int maxRet = 0;

void solve(int cnt)
{
  if(cnt == 3)
  {
    int ret = 0;
    for(int i = 0; i < 4; i++)
    {
      ret += block[i].val;
    }
    maxRet = std::max(ret, maxRet);
    return;
  }

  int currX = block[cnt].x;
  int currY = block[cnt].y;
  visited[currY][currX] = true;
  for(int dir = 0; dir < 4; dir++)
  {
    int nextX = block[cnt].x + dx[dir];
    int nextY = block[cnt].y + dy[dir];
    if(nextX < 0 || nextX >= M) { continue; }
    if(nextY < 0 || nextY >= N) { continue; }

    if(visited[nextY][nextX] == false)
    {
      block[cnt + 1].x = nextX;
      block[cnt + 1].y = nextY;
      block[cnt + 1].val = map[nextY][nextX];
      solve(cnt + 1);
    }
  }
  visited[currY][currX] = false;
}

void CalcSpecialBlock()
{
  for(int i = 0; i < 4; i++)
  {
    int sum = block[0].val;
    bool isValidBlock = true;

    for(int j = 0; j < 3; j++)
    {
      int nextX = block[0].x + dx[specialBlockDirs[i][j]];
      int nextY = block[0].y + dy[specialBlockDirs[i][j]];
      if(nextX < 0 || nextX >= M)
      {
        isValidBlock = false;
        break;
      }
      if(nextY < 0 || nextY >= N)
      {
        isValidBlock = false;
        break;
      }

      sum += map[nextY][nextX];
    }

    if(isValidBlock)
    {
      maxRet = std::max(maxRet, sum);
    }
  }
}

int main(void)
{
  std::cin >> N >> M;
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < M; j++)
    {
      std::cin >> map[i][j];
    }
  }

  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < M; j++)
    {
      block[0].y = i;
      block[0].x = j;
      block[0].val = map[i][j];
      solve(0);
      CalcSpecialBlock();
    }
  }

  std::cout << maxRet << std::endl;

  return 0;
}