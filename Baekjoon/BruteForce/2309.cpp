#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int sum = 0;
  vector<int> v(9);

  for(int i = 0; i < 9; i++)
  {
    std::cin >> v[i];
    sum += v[i];
  }

  for(int i = 0; i < v.size()-1; i++)
  {
    bool flag = false;
    for(int j = i+1; j < v.size(); j++)
    {
      if(sum - v[i] - v[j] == 100)
      {
        v[i] = -1;
        v[j] = -1;
        flag = true;
        break;
      }
    }
    if(flag)
    {
      break;
    }
  }

  sort(v.begin(), v.end());

  for(int i = 2; i < v.size(); i++)
  {
    cout << v[i] << endl;
  }

  return 0;
}