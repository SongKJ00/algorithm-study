#include <iostream>

int N, M;
int map[50][50];

typedef struct
{
  int x;
  int y;
  int dir;
} RobotInfo;

int main(void)
{
  RobotInfo start;

  std::cin >> N >> M;
  std::cin >> start.y >> start.x >> start.dir;

  for(int y = 0; y < N; y++)
  {
    for(int x = 0; x < M; x++)
    {
      std::cin >> map[y][x];
    }
  }

  int dy[] = {-1, 0, 1, 0};
  int dx[] = { 0, 1, 0, -1};

  RobotInfo currInfo = start;
  RobotInfo leftInfo;
  int ret = 0;

  while(1)
  {
    // 현재 위치를 아직 청소 안 했다면 청소 수행
    if(map[currInfo.y][currInfo.x] == 0)
    {
      map[currInfo.y][currInfo.x] = 2;
      ret++;
    }

    // 네 방향 검사
    int aroundInvalidCnt = 0;
    for(int dir = 0; dir < 4; dir++)
    {
      int aroundY = currInfo.y + dy[dir];
      int aroundX = currInfo.x + dx[dir];
      if(map[aroundY][aroundX] == 1 || map[aroundY][aroundX] == 2)
      {
        aroundInvalidCnt++;
      }
    }
    if(aroundInvalidCnt == 4)
    {
      RobotInfo backInfo;
      backInfo.dir = (currInfo.dir + 2) % 4;
      backInfo.y = currInfo.y + dy[backInfo.dir];
      backInfo.x = currInfo.x + dx[backInfo.dir];
      if(map[backInfo.y][backInfo.x] == 1) { break; }
      else
      {
        currInfo.y += dy[backInfo.dir];
        currInfo.x += dx[backInfo.dir];
        continue;
      }
    }

    leftInfo.dir = currInfo.dir - 1 < 0 ? 3 : currInfo.dir - 1;
    leftInfo.y = currInfo.y + dy[leftInfo.dir];
    leftInfo.x = currInfo.x + dx[leftInfo.dir];
    if(map[leftInfo.y][leftInfo.x] == 0)
    {
      currInfo = leftInfo;
    }
    else
    {
      currInfo.dir = leftInfo.dir;
    }
  }

  std::cout << ret << std::endl;

  return 0;

}