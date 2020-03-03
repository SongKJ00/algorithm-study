/*
 * https://www.acmicpc.net/problem/6603
 * 로또 문제
 */
#include <iostream>
#include <vector>
using namespace std;

void dfs(int k, vector<int>& elems, vector<int>& result, int start, int depth)
{
  if(depth == 6)
  {
    for(int i = 0; i < result.size(); i++)
    {
      cout << result[i] << " ";
    }
    cout << endl;
    return;
  }

  for(int i = start; i < k; i++)
  {
    result[depth] = elems[i];
    dfs(k, elems, result, i+1, depth+1);
  }
}

int main()
{
  while(1)
  {
    vector<int> v;
    vector<int> result(6);
    int k;
    cin >> k;
    if(k == 0)
    {
      break;
    }
    v.resize(k);
    for(int i = 0; i < k; i++)
    {
      cin >> v[i];
    }

    dfs(k, v, result, 0, 0);
    cout << endl;
  }
  return 0;
}