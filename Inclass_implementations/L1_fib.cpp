# include <iostream>



unsigned int fib(int n)
{
	int arr[1001];
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i <= n; i++){
		arr[i] = arr[i-1]+arr[i-2];
		}	
	return arr[n];
}

int main() {
	int n {0};
	std::cout << "input a number (1-1000):" << std::endl;
	std::cin >> n;
	std::cout << fib(n) << std::endl;

	return 0;
}