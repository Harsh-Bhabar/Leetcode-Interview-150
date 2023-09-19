class Solution
{
public:
	int kadanes(vector<int> &nums)
	{
		int ans = nums[0];
		int curr = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			curr = max(nums[i], nums[i] + curr);
			ans = max(ans, curr);
		}
		return ans;
	}

	int maxSubarraySumCircular(vector<int> &nums)
	{
		if (nums.size() == 1)
		{
			return nums[0];
		}

		int maxSumSub = kadanes(nums);

		int total = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			total += nums[i];
			nums[i] *= -1;
		}

		int negMaxSumSub = kadanes(nums);

		int circular = total - (-1 * negMaxSumSub);
		if (circular == 0)
		{
			return maxSumSub;
		}

		return max(maxSumSub, circular);
	}
};