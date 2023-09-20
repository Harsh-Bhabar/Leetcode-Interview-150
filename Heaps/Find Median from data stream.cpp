class MedianFinder
{
public:
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;

	MedianFinder()
	{
	}

	void balance()
	{
		if (maxHeap.size() > minHeap.size() + 1)
		{
			minHeap.push(maxHeap.top());
			maxHeap.pop();
		}
		if (maxHeap.size() + 1 < minHeap.size())
		{
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
	}

	void addNum(int num)
	{
		if (maxHeap.empty() or maxHeap.top() > num)
		{
			maxHeap.push(num);
		}
		else
		{
			minHeap.push(num);
		}
		balance();
	}

	double findMedian()
	{
		int maxHeapSize = maxHeap.size();
		int minHeapSize = minHeap.size();
		if (maxHeapSize > minHeapSize)
		{
			return maxHeap.top();
		}
		else if (minHeapSize > maxHeapSize)
		{
			return minHeap.top();
		}
		else
		{
			return double((minHeap.top() + maxHeap.top()) / 2.0);
		}
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */