#include <iostream>
#include <cstdlib>
#include <ctime>


int max_sum_subseq(int arr[], int left, int right)

{
	
	int mid { (left+right)/2 };
	
	// base case
	if (left == right) {
	return arr[left];
	}
	
	int max_left {0};
	int max_right {0};
	int max_crossing {0};
	max_left = max_sum_subseq(arr, left, mid);
	max_right = max_sum_subseq(arr, mid+1, right);
	
	int max_lcs {-10000};
	int running_sum {0};
	for (int i {mid}; i >= left; i--) {
		running_sum = running_sum+arr[i];
		if (running_sum > max_lcs){
			max_lcs = running_sum;
			}
		}
	
	int max_rcs{-10000};
	running_sum = 0;
	for (int i {mid+1}; i<=right; i++) {
		running_sum += arr[i];
		if (running_sum > max_rcs) {
			max_rcs = running_sum;
			}
		}

	max_crossing = max_lcs + max_rcs;
		
	
	return std::max(std::max(max_left, max_right), max_crossing);


}



int main()

{
	int aesthetic_var {0};
	std::cout<<"Press any key then Enter to start the program"<<std::endl;
	std::cin>>aesthetic_var;

	int arr[8];
	
	arr[0] = -12;
	arr[1] = 9;
	arr[2] = 14;
	arr[3] = 21;
	arr[4] = -16;
	arr[5] = 28;
	arr[6] = -12;
	arr[7] = 35;
	
	int max_sum {};
	max_sum = max_sum_subseq(arr, 0, 7);

	std::cout<< "Array: [-12,9,14,21,-16,28,-12,35]" << std::endl;
	std::cout<< "Maximum Sum: " << max_sum << std::endl;

	return 0;
}