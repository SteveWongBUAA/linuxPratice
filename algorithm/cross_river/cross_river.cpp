#include <iostream>
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
	bool mid[8];//on the boat
	bool boat;//boat==false means the boat is on the left side.
			//	boat==true means the boat is on the right side.
	Solution()// initialize: all people on the left and boat is on the left
	{
		for (int i = 0; i < 8; i++)
		{
			left[i] = 1;
			mid[i] = 0;
			right[i] = 0;
			boat = false;
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
				cout << i << " go to boat" << endl;
				for (int j = 0; j < 8; j++)
				{
					if (left[i] == 0)// not here, choose next one
						continue;
					left[j] = 0;
					mid[j] = 1;
					if (allok())
					{
						cout << j << " go to boat" << endl;
						if (j < 3)// j can drive back to left too, try j
						{
							right[i] = 1;
							mid[i] = 0;
							if (allok())
							{
								cout << i << "go to right and " << j << " go to left" << endl;
								mid[j] = 0;
								left[j] = 1;
								solveone();
								// backtrace
								mid[j] = 1;
								left[j] = 0;
							}

							// backtrace
							right[i] = 0;
							mid[i] = 1;
						}
						// i < 3, can drive back to left
						right[j] = 1;
						mid[j] = 0;
						if (allok())
						{
							cout << j << "go to right and " << i << " go to left" << endl;
							mid[i] = 0;
							left[i] = 1;
							solveone(); // next try
							// backtrace
							mid[i] = 1;
							left[i] = 0;
						}

						//backtrace
						right[j] = 0;
						mid[j] = 1;

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
};


int main()
{
	Solution sol;
	cout << sol.allok() << endl;
	sol.solveone();
	return 0;
}
