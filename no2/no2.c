#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

void place(vector<vector<bool> > &map, int i, int j, const int W, const int H, int &cnt, int &res)
{
	bool up = (i-2>=0 && j>=0 && i-2<W && j<H && map[i-2][j]);//上边放了
	bool down = (i+2>=0 && j>=0 && i+2<W && j<H && map[i+2][j]);//下边放了
	bool left = (i>=0 && j-2>=0 && i<W && j-2<H && map[i][j-2]);//左边放了
	bool right = (i>=0 && j+2>=0 && i<W && j+2<H && map[i][j+2]);//右边放了
	if (up || down || left || right)//任意一个方向放了就不能放
	{
		printf("can not place in (%d, %d)\n", i, j);
		if (i == W-1 && j == H-1)//放到最后一个结束了
		{
			printf("\n#end here, cnt = %d, res = %d\n\n", cnt, res);
			return;
		}
		else if (i != W-1 && j == H-1)//换行
			place(map, i+1, 0, W, H, cnt, res);
		else if (j != H-1)
			place(map, i, j+1, W, H, cnt, res);
		else
			;	
	}
	else//可以选择放也可以选择不放
	{
		for (int p = 0; p < 2; p++)
		{
			printf("choose to place %d in (%d, %d)\n", p, i, j);
			map[i][j] = bool(p);
			cnt += p;
			res = max(res, cnt);
			if (i == W-1 && j == H-1)//放到最后一个结束了
			{
				printf("\n#end here, cnt = %d, res = %d\n\n", cnt, res);
				return;
			}
			else if (i != W-1 && j == H-1)//换行
				place(map, i+1, 0, W, H, cnt, res);
			else if (j != H-1)
				place(map, i, j+1, W, H, cnt, res);
			else
				;
			//回溯
			cnt -= p;
			map[i][j] = bool(1-p);
		}
	}

}

int main()
{
	int W, H;
	while(cin >> W >> H)
	{
		vector<vector<bool> > map(W, vector<bool>(H, false));
		int cnt = 0;
		int res = 0;
		place(map, 0, 0, W, H, cnt, res);
		cout << res << endl;	
	}
	return 0;
}
