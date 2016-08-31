// can not finish this program, hang up
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
	void solveone(int pre1, int pre2)
	{
		cout << endl << "one round!" << endl << endl;
		if (finish())
		{
			cout << "\n#### finally finish ####" << endl << endl;
			return;
		}
		for (int i = 0; i < 3; i++)// police or dad or mom get on the boat
		{
			if (left[i] == 0)// not here, choose next one
				continue;
			//left[i] = 0;
			//mid[i] = 1;
			if (true)// at least 2 people get on the boat, otherwise meaningless
			{
				//cout << m[i] << " go to boat" << endl;
				for (int j = 0; j < 8; j++)
				{
					if (left[j] == 0)// not here, choose next one
						continue;
					if ((pre1 == i && pre2 == j) || (pre1 == j && pre2 == i)) // we should avoid that the same person go to right and loop forever.
						continue;
					left[i] = left[j] = 0;
					mid[i] = mid[j] = 1;
					if (allok())
					{
						cout << map[i] << ", " << map[j] << " go to boat and drive to right" << endl;
						// get off the boat
						mid[i] = mid[j] = 0;
						right[i] = right[j] = 1;
						if (allok())
						{
							cout << map[i] << ", " << map[j] << " get off and be on the right" << endl;
							for (int m = 0; m < 3; m++)// police or dad or mon get on the boat						
							{
								if (right[m] == 0)
									continue;
								//right[m] = 0;
								//mid[m] = 1;
								for (int n = 0; n < 8; n++)// choose n to go to left
								{
									if (right[n] == 0 && m != n)// m and n can be the same person, go to left alone. 
										continue;
									if ((m == i && n == j) || (m == j && n == i))// but we should avoid that two same person go to right and go to left and loop forerver
										continue;
									right[m] = right[n] = 0;
									mid[m] = mid[n] = 1;
									if (allok())
									{
										cout << map[m] << ", " << map[n] << " go to boat and drive to left" << endl;
										left[m] = left[n] = 1;
										mid[m] = mid[n] = 0;
										if (allok())
										{
											cout <<  map[m] << ", " << map[n] << " get off be on the left" << endl;
											solveone(m, n);
										}
										// backtrace
										cout << "# backtrace! should not " << map[m] << ", " << map[n] << " get off be on the left" << endl;
										left[m] = left[n] = 0;
										mid[m] = mid[n] = 1;
									}
									// backtrace
									cout << "# backtrace! should not " << map[m] <<  ", " << map[n] << " go to boat and drive to left" << endl;
									right[m] = right[n] = 1;
									mid[m] = mid[n] = 0;
								}
								// backtrace
								//cout << "# backtrace! should not " << map[m] << " go to boat and drive to left" << endl;
								//right[m] = 1;
								//mid[m] = 0;
							}
						}

						// backtrace
						cout << "# backtrace! should not " << map[i] << ", " << map[j] << " get off and be on the right" << endl;
						mid[i] = mid[j] = 1;
						right[i] = right[j] = 0;


					}
					
					// backtrace	
					cout << "# backtrace! should not " << map[i] << ", " << map[j]  << " go to boat and drive to right" << endl;
					left[i] = left[j] = 1;
					mid[i] = mid[j] = 0;
					
				}

			}
			// backtrace
			//cout << "# backtrace! should not " << map[i]  << " go to boat and drive to right" << endl;
			//left[i] = 1;
			//mid[i] = 0;
		}
	}
	
	Solution()// initialize: all people on the left 
	{
		map[0] = "police";
		map[1] = "dad";
		map[2] = "mom";
		map[3] = "dauA";
		map[4] = "dauB";
		map[5] = "sonA";
		map[6] = "sonB";
		map[7] = "criminal";

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
	sol.solveone(-1, -1);
	return 0;
}
