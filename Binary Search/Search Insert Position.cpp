class Solution
{
public:
	int searchInsert(vector<int> &nums, int target)
	{
		int n = nums.size();
		if (nums[0] > target)
		{
			return 0;
		}
		if (nums[n - 1] < target)
		{
			return n;
		}

		int l = 0;
		int r = n - 1;
		int ans = -1;
		while (l <= r)
		{
			int mid = l + (r - l) / 2;
			if (nums[mid] == target)
			{
				return mid;
			}
			else if (nums[mid] < target)
			{
				ans = mid + 1;
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}

		return ans;
	}
};