#include <iostream>
#include <array>
#include <random>

//Функция рандома
int getRandomInt(int min, int max) {
	int range = max - min + 1;
	return rand() % range + min;
}


//Меняет объекты местами
template<typename T>void swap(T &a, typename T &b)
{
	T temp = b;
	b = a;
	a = temp;
}

//Сортировка пузырьком для массива
template<typename T>void bubleSort(T list[],int listLength) {
	while (listLength--)
	{
		bool swapped = false;
		for (int i = 0; i < listLength; i++)
		{
			if (list[i] > list[i + 1])
			{
				swap(list[i], list[i + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}

//Разделение по pivot элементу
template<typename T>int partition(T list[], int start, int pivot)
{
	int i = start;
	while (i < pivot)
	{
		if (list[i] > list[pivot] && i == pivot - 1)
		{
			swap(list[i], list[pivot]);
			pivot--;
		}

		else if (list[i] > list[pivot])
		{
			swap(list[pivot - 1], list[pivot]);
			swap(list[i], list[pivot]);
			pivot--;
		}

		else i++;
	}
	return pivot;
}

//"Быстрая сортирока" c случайным выбором pivot элемента
template<typename T>void quickSort(T list[], int start, int end)
{
	srand(3);
	if (start < end)
	{
		int pivot = getRandomInt(start, end);
		pivot = partition(list, start, end);

		quickSort(list, start, pivot - 1);
		quickSort(list, pivot + 1, end);
	}
}

//Сортировка вставкой
template<typename T>void insertionSort(T list[],int listLength){
	for (int i = 1; i < listLength; i++)
	{
		int j = i - 1;
		while (j >= 0 && list[j] > list[j + 1])
		{
			swap(list[j], list[j + 1]);
			j--;
		}
	}
}
//Рандомные элементы, сид чтобы каждый раз одни и те же были
template<typename T>void initArray(T list[], int listLength) {
	srand(3);
	std::cout << std::endl << "Изначальный массив" << std::endl;
	for (int i = 0; i < listLength; i++) {
		list[i] = getRandomInt(-30,30);
		std::cout << list[i] << " ";
	}
	std::cout << std::endl;
}
template<typename T>void showArray(T list[], int listLength) {;
	std::cout  << "Новый массив" << std::endl;
	for (int i = 0; i < listLength; i++) {
		std::cout << list[i] << " ";
	}
	std::cout << std::endl;
}


int main()
{
	//Вводные для проверки функций
	setlocale(LC_ALL,"Russian");
	int a[15];
	int listLength = 15; 
	//

	initArray(a, listLength);
	std::cout << "Сортировка пузырьком" << std::endl;
	bubleSort(a, listLength);
	showArray(a, listLength);

	
	initArray(a, listLength);
	std::cout << "Быстрая сортировка" << std::endl;
	quickSort(a, 0, listLength-1 );
	showArray(a, listLength);

	initArray(a, listLength);
	std::cout << "Сортировка вставкой" << std::endl;
	insertionSort(a, listLength);
	showArray(a, listLength);

}
