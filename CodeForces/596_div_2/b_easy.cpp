#include <iostream>
#include <set>
#include <vector>
#include <list>

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
    std::list<int> group;
    std::set<int> s;
    for(int j = 0; j < maxSub[i]; j++)
    {
      s.insert(a[i][j]);
      group.push_back(a[i][j]);
      minBuy = s.size();
    }

    for(int j = maxSub[i]; j < a[i].size(); j++)
    {
      group.pop_front();
      group.push_back(a[i][j]);
      std::set<int> s(group.begin(), group.end());
      if(minBuy > s.size())
      {
        minBuy = s.size();
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