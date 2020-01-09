#include <iostream>
#include <vector>
#include <queue>

int R, C;
std::vector<std::vector<char> > map;
std::vector<std::vector<bool> > visited;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void bfs(std::pair<int, int> start)
{
  std::vector<std::pair<int, int> > section;
  std::queue<std::pair<int, int> > q;
  q.push(start);
  section.push_back(start);

  while(!q.empty())
  {
    std::pair<int, int> info = q.front(); q.pop();
    int currY = info.first;
    int currX = info.second;

    for(int dir = 0; dir < 4; dir++)
    {
      int nextY = currY + dy[dir];
      int nextX = currX + dx[dir];

      if(nextY < 0 || nextY >= R || nextX < 0 || nextX >= C) { continue; }
      if(map[nextY][nextX] == '#') { continue; }

      if(visited[nextY][nextX] != true)
      {
        visited[nextY][nextX] = true;
        std::pair<int, int> newInfo = std::make_pair(nextY, nextX);
        q.push(newInfo);
        section.push_back(newInfo);
      }
    }
  }

  int numDrone = 0, numBird = 0;
  std::vector<std::pair<int, int> > dronePos, birdPos;

  for(int i = 0; i < section.size(); i++)
  {
    int y = section[i].first;
    int x = section[i].second;
    if(map[y][x] == 'v')
    {
      numBird++;
      birdPos.push_back(section[i]);
    }
    else if(map[y][x] == 'o')
    {
      numDrone++;
      dronePos.push_back(section[i]);
    }
  }

  if(numBird >= numDrone)
  {
    for(int i = 0; i < dronePos.size(); i++)
    {
      int y = dronePos[i].first;
      int x = dronePos[i].second;
      map[y][x] = '.';
    }
  }
  else
  {
    for(int i = 0; i < birdPos.size(); i++)
    {
      int y = birdPos[i].first;
      int x = birdPos[i].second;
      map[y][x] = '.';
    }
  }
}

int main(void)
{
  std::cin >> R >> C;
  map.resize(R);
  visited.resize(R);
  for(int y = 0; y < R; y++)
  {
    map[y].resize(C);
    visited[y].resize(C);
  }

  for(int y = 0; y < R; y++)
  {
    for(int x = 0; x < C; x++)
    {
      std::cin >> map[y][x];
    }
  }

  for(int y = 0; y < R; y++)
  {
    for(int x = 0; x < C; x++)
    {
      if(visited[y][x] != true)
      {
        visited[y][x] = true;
        std::pair<int, int> start = std::make_pair(y, x);
        bfs(start);
      }
    }
  }

  int numDrone = 0, numBird = 0;
  for(int y = 0; y < R; y++)
  {
    for(int x = 0; x < C; x++)
    {
      if(map[y][x] == 'o')
      {
        numDrone++;
      }
      else if(map[y][x] == 'v')
      {
        numBird++;
      }
    }
  }

  std::cout << numDrone << " " << numBird << std::endl;

  return 0;
}