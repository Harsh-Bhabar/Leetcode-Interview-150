class Solution
{
public:
	int findMin(vector<int> &nums)
	{
		int n = nums.size();
		int l = 0;
		int r = n - 1;

		if (n == 1)
		{
			return nums[l];
		}
		if (nums[l] < nums[r])
		{
			return nums[l];
		}

		while (l <= r)
		{
			int mid = l + (r - l) / 2;
			int prev = (mid - 1 + n) % n;
			int next = (mid + 1) % n;

			if (nums[mid] < nums[next] && nums[mid] < nums[prev])
			{
				return nums[mid];
			}
			if (nums[mid] < nums[r])
			{
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}

		return 0;
	}
};