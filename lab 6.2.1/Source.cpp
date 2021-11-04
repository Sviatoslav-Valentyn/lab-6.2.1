// Варіант 6(Ітераційний спосіб)
#define NOMINMAX
#include <iostream>
#include <Windows.h>
using namespace std;

void Init(int* b, const int size)
{
	for (size_t i = 0; i < size; i++)
		b[i] = -10 + rand() % 21;
}

void Print(const int* const b, const int size)
{
	cout << "{";
	for (size_t i = 0; i < size; i++)
	{
		cout << b[i];
		if (i != size - 1)
			cout << ", ";
	}
	cout << "}" << endl;
}
int FirsIndex(const int b[], const int size)
{
	int index = -1;
	for (int i = 0; i < size; i++)
	{
		if (b[i] % 2 == 0) 
		{
			index = i;
			break;
		}
	}
	return index;
}

int IndexMin(int b[], const int size)
{
	int index = FirsIndex(b, size);
	if (index == -1)
		return index;
	int min = b[index];
	for (int i = 0; i < size; i++)
		if (b[i] < min && b[i] % 2 == 0) 
		{
			index = i;
			min = b[i];
		}
	return index;
}

bool Modify(int b[], const int size)
{
	int index = IndexMin(b, size);
	if (index != -1)
	{
		int tmp = b[0];
		b[0] = b[index];
		b[index] = tmp;
		return true;
	}
	else return false;
}

int main()
{
	SetConsoleOutputCP(1251);

	srand(time(0));
	int n;
	cout << "n = "; cin >> n;

	int* b = new int[n];

	Init(b, n);
	Print(b, n);
	if (!Modify(b, n))
		cout << "Немає елемента, який підходить умові" << endl;
	Print(b, n);

	delete[] b;
	b = nullptr;

	return 0;
}