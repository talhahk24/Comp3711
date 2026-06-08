#include <iostream>
#include <vector>

struct MaxHeap
{

	std::vector<int> heap_arr{};
	
	void _swap(int indice1, int indice2)
	{
		int temp{heap_arr[indice1]};
		heap_arr[indice1] = heap_arr[indice2];
		heap_arr[indice2] = temp;
	}
	
	void _bubbleDown(int indice)
	{
		if ((indice * 2)+1 > heap_arr.size()-1)
		{
			return;		
		}
		
		if (indice*2+2 > heap_arr.size()-1)
		{
			if (heap_arr[indice] < heap_arr[indice*2+1]) {_swap(indice, indice*2+1);}
			return;
		}

		if (heap_arr[indice] < heap_arr[indice*2+1] || heap_arr[indice] < heap_arr[indice*2+2])
		{
			if (heap_arr[indice*2+1] >= heap_arr[indice*2+2])
			{
				_swap(indice, indice*2+1);
				_bubbleDown(indice*2+1);
			}
			else
			{
				_swap(indice, indice*2+2);
				_bubbleDown(indice*2+2);
			}
		}
		return;
	}
	
	void _bubbleUp(int indice)
	{
		if (indice == 0)
		{
			return;
		}
		else
		{
			if (heap_arr[indice] > heap_arr[(indice - 1)/2])
			{
			_swap(indice, (indice - 1)/2);
			_bubbleUp((indice - 1)/2);
			}
		}
		return;
	}

	void insert(int element)
	{
		heap_arr.push_back(element);
		_bubbleUp(heap_arr.size()-1);
		return;
	}
	
	int pop_max()
	{
		if (!heap_arr.empty())
		{
			int max {heap_arr[0]};
			heap_arr[0] = heap_arr[heap_arr.size()-1];
			heap_arr.pop_back();
			_bubbleDown(0);
			return max;
		}
		else
		{
			std::cout << "Heap is Empty" << std::endl;
		}
		return 0;
	}
	
	int get_max()
	{
		if (!heap_arr.empty())
		{
			return heap_arr[0];
		}
		else
		{
			std::cout << "Heap is Empty!" << std::endl;
		}
		return 0;
	}
	
	void print_heap()
	{
		for (int i {}; i<heap_arr.size(); i++)
		{
			std::cout << heap_arr.at(i) << " ";
		}
		std::cout << std::endl;
	}
	bool is_valid()
	{
		for (int i {0}; i < heap_arr.size(); i++)
		{
			int left_child {i*2+1};
			int right_child {i*2+2};
			if (left_child < heap_arr.size() && heap_arr[left_child] > heap_arr[i])
			{
				return false;
			}

			if (right_child < heap_arr.size() && heap_arr[right_child] > heap_arr[i])
			{
				return false;
			}
	
			
		}
		return true;
		
	}
	
	void sort_array(std::vector<int>& arr)
	{
		for (int i{0}; i < arr.size(); i++)
		{
			heap_arr.push_back(arr[i]);
		}
		
		for (int i{0}; i < arr.size(); i++)
		{
			_bubbleDown(heap_arr.size()-1-i);
		}
		
		int max {};
		for (int i{0}; i < arr.size(); i++)
		{
			max = pop_max();
			std::cout << max << " ";
		}
		std::cout << std::endl;
		
		return;
	}
};


int main()
{
	std::cout << "Input the last number 999! ";
	
	std::vector<int> arr {};
	int i {};
	int x {};
	
	std::cout << "Write a list of numbers for HeapSort to sort:";
	while (!(x==999))
	{ 
		std::cin >> x;
		arr.push_back(x);
		i += 1;
	}
	std::cout << std::endl << "The sorted sequence is: ";
	MaxHeap MHeap{};
	MHeap.sort_array(arr);
				

}



















