#include <iostream>

using namespace std;

bool visited[11][11][11][11];

int solution(string dirs) {
  int answer = 0;
  int currX = 5, currY = 5;
  for(auto dir: dirs)
  {
    int nextX = currX, nextY = currY;
    switch(dir)
    {
      case 'U':
        nextY++;
        break;
      case 'D':
        nextY--;
        break;
      case 'R':
        nextX++;
        break;
      case 'L':
        nextX--;
        break;
    }
    if(nextX < 0 || nextX > 10 || nextY < 0 || nextY > 10)
    {
      continue;
    }
    if(!visited[currX][currY][nextX][nextY])
    {
      visited[currX][currY][nextX][nextY] = true;
      visited[nextX][nextY][currX][currY] = true;
      answer++;
    }
    currX = nextX;
    currY = nextY;
  }
  return answer;
}

int main()
{
  cout << solution("LULLLLLLU") << endl;
  return 0;
}