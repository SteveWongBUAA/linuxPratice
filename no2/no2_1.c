#include <iostream>
using namespace std;

int main()
{
	int W, H, i, j, cnt = 0;
	cin >> W >> H;
	if (W % 4 == 0 || H % 4 == 0)
		cnt = W * H / 2;
	else if (W % 2 == 0 && H % 2 == 0)
		cnt = (W * H / 4 / 2 + 1) * 4;
	else
		cnt = W * H / 2 + 1;
	cout << cnt << endl;
	return 0;

}
