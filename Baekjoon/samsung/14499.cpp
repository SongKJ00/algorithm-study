#include <iostream>
#include <vector>
#include <string.h>

int dice[7] = {0, };
int tempDice[7] = {0, };
int map[20][20];
int currR = 0, currC = 0;

int dr[5] = {0, 0, 0, -1, 1};
int dc[5] = {0, 1, -1, 0, 0};

int main(void)
{
  int N, M;
  int K;
  std::vector<int> cmd;
  std::vector<int> ret;

  std::cin >> N >> M >> currR >> currC >> K;
  cmd.resize(K);
  for(int r = 0; r < N; r++)
  {
    for(int c = 0; c < M; c++)
    {
      std::cin >> map[r][c];
    }
  }
  for(int i = 0; i < K; i++)
  {
    std::cin >> cmd[i];
  }

  for(int i = 0; i < cmd.size(); i++)
  {
    int currCmd = cmd[i];
    int nextR = currR + dr[currCmd];
    int nextC = currC + dc[currCmd];
    if(nextR < 0 || nextR >= N) { continue; }
    if(nextC < 0 || nextC >= M) { continue; }

    memcpy(tempDice, dice, sizeof(dice));
    switch(currCmd)
    {
      // 동
      case 1:
        dice[1] = tempDice[4];
        dice[4] = tempDice[6];
        dice[6] = tempDice[3];
        dice[3] = tempDice[1];
        break;
      // 서
      case 2:
        dice[1] = tempDice[3];
        dice[3] = tempDice[6];
        dice[6] = tempDice[4];
        dice[4] = tempDice[1];
        break;
      // 북
      case 3:
        dice[1] = tempDice[5];
        dice[5] = tempDice[6];
        dice[6] = tempDice[2];
        dice[2] = tempDice[1];
        break;
      // 남
      case 4:
        dice[1] = tempDice[2];
        dice[2] = tempDice[6];
        dice[6] = tempDice[5];
        dice[5] = tempDice[1];
        break;
    }

    if(map[nextR][nextC] == 0)
    {
      map[nextR][nextC] = dice[6];
    }
    else
    {
      dice[6] = map[nextR][nextC];
      map[nextR][nextC] = 0;
    }

    currR = nextR;
    currC = nextC;
    ret.push_back(dice[1]);
  }

  for(int i = 0; i < ret.size(); i++)
  {
    std::cout << ret[i] << std::endl;
  }
}