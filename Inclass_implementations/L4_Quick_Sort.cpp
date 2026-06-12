#include <iostream>
#include <vector>

void swap(std::vector<int>& arr, int index1, int index2)
{
	int x {};
	x = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = x;
	return;	
}

void quick_sort(std::vector<int>& arr, int l, int r)
{
	
	if (l == r)
	{
		return;
	}

	int k_val {};
	int k_index {(l+r)/2};
	int l_f {l};
	int r_f {r-1};

	k_val = arr[k_index];
	swap(arr, k_index, r);
	k_index = r;
	
	while (l_f<r_f)
	{
		while (arr[l_f] <= k_val && l_f<r_f)
		{
			++l_f;
		}
		while (arr[r_f] > k_val && l_f<r_f)
		{
			--r_f;
		}
		swap(arr, l_f, r_f);
		
	}

	if (k_val < arr[l_f])
	{
		swap(arr, k_index, l_f);
	}
	else
	{
		swap(arr, k_index, l_f+1);
	}
	
	quick_sort(arr, l, l_f);
	quick_sort(arr, l_f+1, r);
	return;

}



int main()
{
	std::cout << "Input the last number 999! ";
	
	std::vector<int> arr {};
	int i {};
	int x {};
	
	std::cout << "Write a list of numbers for Quick Sort to sort:";
	while (!(x==999))
	{
		std::cin >> x;
		arr.push_back(x);
		i += 1;
	}
	std::cout << std::endl << "The sorted sequence is: ";
	
	quick_sort(arr, 0, arr.size()-1);
	
	for (int i {0}; i<arr.size(); i++)
	{
		std::cout << arr[i] << " ";
	}
	
	std::cout << std::endl;
	

}


















