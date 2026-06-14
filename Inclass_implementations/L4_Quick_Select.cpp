#include <iostream>
#include <vector>

void swap(std::vector<int>& arr, int index1, int index2)
{
	int x {arr[index1]};
	arr[index1] = arr[index2];
	arr[index2] = x;

	return;

}

void sort(std::vector<int>& arr, int start, int end)
{
	int min_i {start};
	for (int i {start}; i <= end; i++)
	{
		min_i = i;
		for (int k {i}; k <= end; k++)
		{
			if (arr[k] <= arr[min_i])
			{
				min_i = k;
			}
		} 
		swap(arr, i, min_i);
	}

	return;
}


int find_median_of_medians(std::vector<int>& arr, int l, int r)
{
    int sub_size = 5;
    int median_count = 0;

    // base case
    if (r - l + 1 <= sub_size)
    {
        sort(arr, l, r);
	swap(arr, l, l + (r - l)/2);
        return arr[l];
    }

    for (int i = l; i <= r; i += sub_size)
    {
        if (i + sub_size - 1 <= r)
        {
            sort(arr, i, i + sub_size - 1);

            int mid = i + sub_size/2;   // i+2
            swap(arr, l+median_count, mid);

            median_count++;
        }
    }

    return find_median_of_medians(arr, l, l+median_count - 1);
}

int quick_select(std::vector<int>& arr, int l, int r, int kth)
{
	// base case
	if (r == l)
	{	
		return arr[l];
	}
	
	int k_ind {0};
	int k {0};
	// k_ind = find_median_of_medians(arr, l, r);
	k = find_median_of_medians(arr, l, r);
	if (arr[l] == k) {std::cout << "k is at l"<< std::endl;}
	else {std::cout << "k is NOT at l" << std::endl;}
	

	// move median to end
	swap(arr, l, r);
	
	int finger_l {l};
	int finger_r {r-1};

	while (finger_l<finger_r)
	{
		while (arr[finger_l] < k && finger_l < finger_r)
		{
			++finger_l;
		}
		while (arr[finger_r] >= k && finger_l < finger_r)
		{
			--finger_r;
		}
		swap(arr, finger_l, finger_r);
	}
	
	if (k <= arr[finger_l])
	{
		swap(arr, r, finger_l);
		k_ind = finger_l;
	}
	else
	{
		swap(arr, r, finger_l+1);
		k_ind = finger_l+1;
	}
	
	if (r-k_ind == kth-1) {return k;}
	
	int kth_largest_num {};
	if (r-k_ind > kth-1) 
	{
		 kth_largest_num = quick_select(arr, k_ind+1, r, kth);
		
	}
	else
	{
		kth_largest_num = quick_select(arr, l, k_ind-1, kth-(r-k_ind+1));
	}
	
	return kth_largest_num;

}
	

int main()
{
	std::cout << "Input the last number 999! ";
	
	std::vector<int> arr {};
	int i {};
	int x {};
	
	std::cout << "Write a list of numbers for Quick Select:";
	while (!(x==999))
	{
		std::cin >> x;
		arr.push_back(x);
		i += 1;
	}
	std::cout << std::endl;
	std::cout << "What is the rank of largest element you would like?: ";
	int kth {};
	std::cin >> kth;
	std::cout << std::endl;
	std::cout << "The " << kth << "th largest element is: ";
	
	int e {};
	e = quick_select(arr, 0, arr.size()-1, kth);
	
	std::cout << e << " ";
	
	std::cout << std::endl;
	
	return 0;

}

















		