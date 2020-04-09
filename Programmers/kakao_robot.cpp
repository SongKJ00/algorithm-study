#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct
{
  int firstX;
  int firstY;
  int secondX;
  int secondY;
  int sec;
} RobotInfo;

bool visited[110][110][110][110];

vector<RobotInfo> move(RobotInfo info, vector<vector<int>>& board)
{
  int currFirstX = info.firstX;
  int currFirstY = info.firstY;
  int currSecondX = info.secondX;
  int currSecondY = info.secondY;
  int nextSec = info.sec + 1;

  vector<RobotInfo> ret;
  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, -1, 1};
  for(int dir = 0; dir < 4; dir++)
  {
    int nextFirstX = currFirstX + dx[dir];
    int nextFirstY = currFirstY + dy[dir];
    int nextSecondX = currSecondX + dx[dir];
    int nextSecondY = currSecondY + dy[dir];

    if(board[nextFirstX][nextFirstY] == 0 && board[nextSecondX][nextSecondY] == 0)
    {
      RobotInfo newInfo = {nextFirstX, nextFirstY, nextSecondX, nextSecondY, nextSec};
      ret.push_back(newInfo);
    }
  }

  bool isHorizontalAlligned = currFirstX == currSecondX;
  int nextFirstX = currFirstX;
  int nextFirstY = currFirstY;
  int nextSecondX = currSecondX;
  int nextSecondY = currSecondY;
  int rotate[] = {1, -1};
  if(isHorizontalAlligned)
  {
    for(auto r: rotate)
    {
      if(board[currFirstX+r][currFirstY] == 0 && board[currSecondX+r][currSecondY] == 0)
      {
        RobotInfo newInfo1 = {currFirstX+r, currFirstY, currFirstX, currFirstY, nextSec};
        RobotInfo newInfo2 = {currSecondX+r, currSecondY, currSecondX, currSecondY, nextSec};
        ret.push_back(newInfo1);
        ret.push_back(newInfo2);
      }
    }
  }
  else
  {
    for(auto r: rotate)
    {
      if(board[currFirstX][currFirstY+r] == 0 && board[currSecondX][currSecondY+r] == 0)
      {
        RobotInfo newInfo1 = {currFirstX, currFirstY+r, currFirstX, currFirstY, nextSec};
        RobotInfo newInfo2 = {currSecondX, currSecondY+r, currSecondX, currSecondY, nextSec};
        ret.push_back(newInfo1);
        ret.push_back(newInfo2);
      }
    }
  }

  return ret;
}

int solution(vector<vector<int>> board) {
  vector<vector<int>> newBoard(board.size()+2);
  for(int i = 0; i < newBoard.size(); i++)
  {
    for(int j = 0; j < newBoard.size(); j++)
    {
      newBoard[i].push_back(1);
    }
  }

  for(int i = 0; i < board.size(); i++)
  {
    for(int j = 0; j < board.size(); j++)
    {
      newBoard[i+1][j+1] = board[i][j];
    }
  }

  int answer = 0;
  RobotInfo start = {1, 1, 1, 2, 0};
  queue<RobotInfo> q;
  q.push(start);

  while(!q.empty())
  {
    RobotInfo info = q.front(); q.pop();
    if((info.firstX == board.size() && info.firstY == board.size()) ||
      (info.secondX == board.size() && info.secondY == board.size()))
    {
      answer = info.sec;
      break;
    }
    auto ret = move(info, newBoard);
    for(auto elem: ret)
    {
      if(!visited[elem.firstX][elem.firstY][elem.secondX][elem.secondY])
      {
        visited[elem.firstX][elem.firstY][elem.secondX][elem.secondY] = true;
        q.push(elem);
      }
    }
  }

  return answer;
}

int main()
{
  return 0;
}