#include <iostream>
#include <string>
using namespace std;

// an array to record the status of people
// a[0]    [1] [2] [3]         [4]     [5] [6]  [7]
// police dad mom daughterA daughterB sonA sonB criminal 
// for example 
// left[0] = true : police is on the left side of the river


class Solution
{
public:
	bool left[8];// on the left side of the river
	bool right[8];// on the right side of the river
	bool mid[8];// on the boat
	string map[8];// the mapping array
	void solveone()
	{
		if (finish())
		{
			cout << "finally finish" << endl;
			return;
		}
		for (int i = 0; i < 3; i++)// police or dad or mom get on the boat
		{
			if (left[i] == 0)// not here, choose next one
				continue;
			left[i] = 0;
			mid[i] = 1;
			if (true)// at least 2 people get on the boat, otherwise meaningless
			{
				//cout << m[i] << " go to boat" << endl;
				for (int j = 0; j < 8; j++)
				{
					if (left[j] == 0)// not here, choose next one
						continue;
					left[j] = 0;
					mid[j] = 1;
					if (allok())
					{
						cout << map[i] << ", " << map[j] << " go to boat and drive to right" << endl;
						// get off the boat
						mid[i] = mid[j] = 0;
						right[i] = right[j] = 1;
						if (allok())
						{
							for (int m = 0; m < 3; m++)// police or dad or mon get on the boat						
							{
								if (right[i] == 0)
									continue;
								right[m] = 0;
								mid[m] = 1;
								for (int n = 0; n < 8; n++)
								{
									if (right[n] == 0 && n != m)// m and n can be the same person, go to left alone
										continue;
									right[n] = 0;
									mid[n] = 1;
									if (allok())
									{
										cout << map[m] << ", " << map[n] << " go to boat and drive to left" << endl;
										left[m] = left[n] = 1;
										mid[m] = mid[n] = 0;
										if (allok())
										{
											solve();
										}
										// backtrace
										cout << "backtrace " << map[m] << ", " << map[n] << " go to boat and drive to left" << endl;
										left[m] = left[n] = 0;
										mid[m] = mid[n] = 1;
									}
								}
							}
						}

						// backtrace
						mid[i] = mid[j] = 1;
						right[i] = right[j] = 0;


					}
					
					// backtrace	
					left[j] = 1;
					mid[j] = 0;
					
				}

			}
			// backtrace
			left[i] = 1;
			mid[i] = 0;
		}
	}
	
	Solution()// initialize: all people on the left 
	{
		m[0] = "police";
		m[1] = "dad";
		m[2] = "mom";
		m[3] = "dauA";
		m[4] = "dauB";
		m[5] = "sonA";
		m[6] = "sonB";
		m[7] = "climinal";

		for (int i = 0; i < 8; i++)
		{
			left[i] = 1;
			mid[i] = 0;
			right[i] = 0;
		}
	}
	bool ok(bool arr[])
	{
		if (arr[7] == 1 && arr[0] == 0)// criminal is not with police
		{
			for (int i = 1; i < 7; i++)
			{
				if (arr[i] == 1)// and there is other people. this is not ok.
					return false;
			}
		}
		if (arr[1] == 1 && arr[2] == 0)// dad is here but mom is not
		{
			if (arr[3] == 1 || arr[4] == 1)// daughter is here, this is not ok.
				return false;
		}
		if (arr[1] == 0 && arr[2] == 1)// mom is here but dad is not
		{
			if (arr[5] == 1 || arr[6] == 1)// son is here, this is not ok.
				return false;
		}
		return true;
	}

	bool allok()
	{
		return (ok(left) && ok(mid) && ok(right));
	}

	bool finish()// all people on the right
	{
		for (int i = 0; i < 8; i++)
			if (right[i] == false)
				return false;
		return true;
	}


	
};


int main()
{
	Solution sol;
	cout << sol.allok() << endl;
	sol.solveone();
	return 0;
}
