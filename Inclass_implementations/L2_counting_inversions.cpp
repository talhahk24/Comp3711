


#include <iostream>
#include <limits> 



int merge_sort(int arr[], int left, int right)
{
	int mid { (left+right)/2 };

	if (left == right)
	{
		return 0;
	}
	
	int left_inv_count {0};
	int right_inv_count {0};

	left_inv_count += merge_sort(arr, left, mid);
	right_inv_count += merge_sort(arr, mid+1, right);
	
	int left_array[100];
	int right_array[100];
	int l {0};
	int r {0};
	for (int i = left; i <= mid; i++)
	{
		left_array[l] = arr[i];
		l += 1;
	}
	for (int i = mid+1; i <= right; i++)
	{
		right_array[r] = arr[i];
		r += 1;
	}
	
	
	int counter_left = 0;
	int counter_right = 0;
	int cross_inv_count {0};
	
	for (int i {left}; i <= right; i++)
	{
		if (counter_right <= r-1 && counter_left <= l-1)
		{
			if (right_array[counter_right]<left_array[counter_left])
			{
				cross_inv_count += l - counter_left;
				counter_right += 1;
			}
			else
			{
				counter_left += 1;
			}
		}
	}
	

	counter_left = 0;
	counter_right = 0;
	for (int i {left}; i <= right; i++)
	{	
		if (left_array[counter_left] < right_array[counter_right])
		{
			arr[i] =left_array[counter_left];
			left_array[counter_left] = std::numeric_limits<int>::max();
			if (counter_left < l-1)
			{
				counter_left += 1;
			}
		}
			
		else
		{
			arr[i] = right_array[counter_right];
			right_array[counter_right] = std::numeric_limits<int>::max();
			if (counter_right < r-1)
			{
				counter_right += 1;
			}
		}
	}
	
	
	return left_inv_count + right_inv_count + cross_inv_count;
		
	
}


int main()
{
	int array_size {0};
	std::cout << "Please input a integer:";
	std::cin >> array_size;

	int arr[100];
	int n {array_size};
	
	for (int i {0}; i <= array_size-1; i++)
	{
		arr[i] = n;
		n -= 1;
	}

	std::cout << "[";
	for (int i {0}; i<=array_size-1; i++)
	{
		std::cout << arr[i];
		if (i<array_size-1)
		{
			std::cout << ",";
		}
	}
	std::cout << "]" << std::endl;
	
	int num_inversions {0};
	num_inversions = merge_sort(arr, 0, array_size-1);
	
	std::cout << "[";
	for (int i {0}; i<=array_size-1; i++)
	{
		std::cout << arr[i];
		if (i<array_size-1)
		{
			std::cout << ",";
		}
	}
	std::cout << "]" << std::endl;
	
	std::cout << "Number of Inversions: " << num_inversions << std::endl;
	
	
	

}
	