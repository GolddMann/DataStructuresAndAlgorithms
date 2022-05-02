#include <iostream>
using namespace std;

class FenwickTree
{
private:
	int *array;
	int size;

public:
	FenwickTree(int *array, int size)
	{
		this->size = size;
		this->array = new int[size];
		for (int i = 0; i < size; i++)
		{
			this->array[i] = 0;
		}

		for (int i = 0; i < size; i++)
		{
			int j = i + 1;
			while (j - 1 < size)
			{
				this->array[j - 1] += array[i];

				j += (1 << (j & (j - 1));
				j--;
			}
		}
	}

	FenwickTree(int size)
	{
		this->size = size;
		this->array = new int[size];
		for (int i = 0; i < size; i++)
		{
			this->array[i] = 0;
		}
	}

	int prefix(int i)
	{
		int sum = 0;
		i++;
		while (i - 1 >= 0)
		{
			sum += array[i - 1];
			if (i == (1 << (i & -i)))
				i--;
			else
				i -= (1 << (i & -i));
		}
		return sum;
	}
};

int main()
{
	int arr[4] = {1, 2, 3, 4};
	int size = 4;
	FenwickTree tree(arr, size);
	cout << tree.prefix(3) << endl;
	return 0;
}
