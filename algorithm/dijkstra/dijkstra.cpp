#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int inf = 0x7fffffff;


void pvec(const vector< vector<int> > v)
{
	for (auto i : v)
	{
		for (auto j : i)
		{
			cout << j << " ";
		}
	cout << endl;
	}
}

bool allVisited(const vector<bool> visited)
{
	for (auto i : visited)
		if (i == false)
			return false;
	return true;
}

int dijkstra(const vector< vector<int> > v, int start, int end)
{
	const int len = v.size();
	//priority_queue< pair<int, int> > pq(len);// store the 
	vector<int> res(len);// store the result, res[i] means the shortest path of start -> i
	vector<bool> visited(len);

	// initialize
	for (int i = 0; i < len; i++)
	{
		res[i] = v[start][i];
		visited[i] = false;
	}

	while (!allVisited(visited))
	{
		// every time we use the min value 
		// get the min index and the min value of the res array
		int minIndex = -1;
		int minVal = inf;
		bool findFirstUnvisit = false;
		for (int i = 0; i < len; i++)
		{
			if (!visited[i])
			{
				if (!findFirstUnvisit)
				{
					findFirstUnvisit = true;
					minIndex = i;
					minVal = res[i];
				}
				else
				{
					if (res[i] < minVal)
					{
						minIndex = i;
						minVal = res[i];
					}
				}
			}
		}

		if (minIndex == end)
			return minVal;

		// start from the node[minIndex], update the res array
		// if we pass through node[minIndex], the path is shorter, then update
		for (int i = 0; i < len; i++)
		{
			if (!visited[i] && v[minIndex][i] != inf && res[i] > minVal + v[minIndex][i])
				res[i] = minVal + v[minIndex][i];
		}

		// node[minIndex] is visited
		visited[minIndex] = true;
	
	}
	return -1;

}

int main()
{
	vector< vector<int> > map = {{0, 10, inf, 5, inf}, 
								{inf, 0, 1, 2, inf},
								{inf, inf, 0, inf, 4}, 
								{inf, 3, 9, 0 ,2}, 
								{7, inf, 6, inf, 0}};
	pvec(map);
	for (int i = 0; i < 5; i++)
	{
		int res = dijkstra(map, 0, i);
		cout << i << " res: " << res << endl;
	}
	return 0;
}
