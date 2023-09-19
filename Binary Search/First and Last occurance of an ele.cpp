class Solution
{
public:
	int firstPosition(vector<int> &nums, int l, int r, int target)
	{
		int ans = -1;
		while (l <= r)
		{
			int mid = l + (r - l) / 2;
			if (nums[mid] == target)
			{
				ans = mid;
				r = mid - 1;
			}
			else
			{
				if (nums[mid] < target)
				{
					l = mid + 1;
				}
				else
				{
					r = mid - 1;
				}
			}
		}
		return ans;
	}

	int lastPosition(vector<int> &nums, int l, int r, int target)
	{
		int ans = -1;
		while (l <= r)
		{
			int mid = l + (r - l) / 2;
			if (nums[mid] == target)
			{
				ans = mid;
				l = mid + 1;
			}
			else
			{
				if (nums[mid] < target)
				{
					l = mid + 1;
				}
				else
				{
					r = mid - 1;
				}
			}
		}
		return ans;
	}

	vector<int> searchRange(vector<int> &nums, int target)
	{
		int n = nums.size();
		if (n == 0)
		{
			return {-1, -1};
		}
		int l = firstPosition(nums, 0, n - 1, target);
		int r = lastPosition(nums, 0, n - 1, target);
		return {l, r};
	}
};
