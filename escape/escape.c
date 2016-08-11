// problem: http://www.nowcoder.com/questionTerminal/0385945b7d834a99bc0010e67f892e38
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int inf = 9999;

void vprint(vector<vector<int> > map)
{
	for (auto i : map)
	{
		for (auto j : i)
		{
			cout << j << ' ';
		}
		cout << endl;
	}
}

void vprint(vector<vector<char> > map)
{
	for (auto i : map)
	{
		for (auto j : i)
		{
			cout << j << ' ';
		}
		cout << endl;
	}
}

void solve(vector<vector<char> > map, const int n, const int m, vector<vector<int> > d, 
		:vector<vector<int> > &res, queue<pair<int, int> > &q)
{
	while (!q.empty())
	{
		pair<int, int> nowp = q.front();
		q.pop();
		for (auto onestep : d)
		{
			int i = nowp.first;
			int j = nowp.second;
			int nexti = i + onestep[0];
			int nextj = j + onestep[1];
			if (nexti>=0 && nexti<n && nextj>=0 && nextj<m && map[nexti][nextj] == '.')
			{
				if (res[nexti][nextj] > res[i][j] + 1)//只有新的走法比原来小的时候才更新
				{
					res[nexti][nextj] = res[i][j] + 1;
					q.push(pair<int, int>(nexti, nextj));
					//printf("(%d, %d) -> (%d, %d), res = %d \n", i, j, nexti, nextj, res[nexti][nextj]);
				}
			}

		}
	}
}

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<vector<char> > map;
		for (int i = 0; i < n; i++)
		{
			vector<char> line;
			for (int j = 0; j < m; j++)
			{
				char tmp;
				cin >> tmp;
				line.push_back(tmp);
			}
			map.push_back(line);
		}
		int x0, y0, k, dx, dy;
		cin >> x0 >> y0;
		cin >> k;
		vector<vector<int> > d;
		for (int i = 0; i < k; i++)
		{
			cin >> dx >> dy;
			vector<int> tmp = {dx, dy};
			d.push_back(tmp);
		}
		//printf("n = %d, m = %d\n", n, m);
		//vprint(map);
		//printf("x0 = %d, y0 = %d, k = %d\n", x0, y0, k);
		//vprint(d);

		vector<vector<int> > res(n, vector<int>(m, inf));//存储结果的数组
		res[x0][y0] = 0;
		queue<pair<int, int> > q;//BFS的队列
		q.push(pair<int, int>(x0, y0));
		solve(map, n, m, d, res, q);
		//cout << "res\n" << endl;
		//vprint(res);
		int ret = -1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (res[i][j] == inf && map[i][j] == '.')//原来是'.'但是走不到那里去，返回-1
				{
					cout << -1 << endl;
					break;
				}
				if (res[i][j] != inf)
					ret = max(res[i][j], ret);
			}
		}
		cout << ret << endl;

	}

	return 0;

}
