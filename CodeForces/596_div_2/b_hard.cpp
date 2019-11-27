#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <map>

int main(void)
{
  //freopen("596_div_2/b.txt", "r", stdin);

  int t;
  int n, k, d;
  std::vector<std::vector<int> > a;
  std::vector<int> maxSub;
  std::vector<int> result;

  std::cin >> t;
  a.resize(t);
  result.resize(t);
  for(int i = 0; i < t; i++)
  {
    std::cin >> n >> k >> d;
    maxSub.push_back(d);
    for(int j = 0; j < n; j++)
    {
      int show;
      std::cin >> show;
      a[i].push_back(show);
    }
  }

  for(int i = 0; i < a.size(); i++)
  {
    int minBuy = 0;
    std::map<int, int> m;
    for(int j = 0; j < maxSub[i]; j++)
    {
      m[a[i][j]]++;
    }
    minBuy = m.size();

    for(int j = maxSub[i]; j < a[i].size(); j++)
    {
      std::map<int, int>::iterator popKey = m.find(a[i][j-maxSub[i]]);
      int& popValue = m[a[i][j-maxSub[i]]];
      popValue--;
      if(popValue == 0)
      {
        m.erase(popKey);
      }
      m[a[i][j]]++;
      if(minBuy > m.size())
      {
        minBuy = m.size();
      }
    }
    result[i] = minBuy;
  }

  for(int i = 0; i < result.size(); i++)
  {
    std::cout << result[i] << std::endl;
  }

  return 0;
}