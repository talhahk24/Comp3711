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
};


int main()
{
	std::cout << "Input 999 to end program!";
	int x {};
	MaxHeap MHeap {};
	while (!(x==999))
	{ 
		std::cout << "Write a numbers to insert it into the Max Heap: ";
		std::cin >> x;
		std::cout << std::endl;
		MHeap.insert(x);
		MHeap.print_heap();
		if (MHeap.is_valid())
		{
			std::cout<<"The Heap is valid!!"<<std::endl;
		}
		else
		{
			std::cout<<"HEAP NOT WOKING :("<<std::endl;
		}
	}
	
	std::cout<<"HeapSort Test:"<< std::endl;
	std::size_t ending_heap_size{MHeap.heap_arr.size()};
	int max_val {0};
	for (int i{0}; i < ending_heap_size; i++)
	{
		max_val = MHeap.pop_max();
		std::cout << max_val << " ";
	}
	
				

}



















