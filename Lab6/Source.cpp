#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int* bubble_sort(int* arr,int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i; j < n; j++) {
			if (arr[i] > arr[j]) {
				int t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}
	}
	return arr;
}

int* gnome_sort(int* arr, int n) {
	int i = 1;
	while (i < n) {
		if (arr[i] >= arr[i - 1]) ++i;
		else {
			swap(arr[i], arr[i - 1]);
			--i;
		}
	}
	return arr;
}

int* count_sort(int* arr, int n) {
	int m = arr[0];
	for (int i = 0; i<n;i++) if (arr[i] > m) m = arr[i];

	int* count = new int[n+1];
	for (int i = 0; i < n; i++) count[i] = 0;

	for (int i = 0; i < n; i++) {
		count[arr[i]]++;
	}

	int j = 0;
	for (int i = 0; i < n; i++) {
		while (count[i] > 0) {
			arr[j++] = i;
			count[i]--;
		}
	}
	return arr;
}

int main() {
	setlocale(LC_ALL, "Russian");
	srand(static_cast<unsigned>(time(nullptr)));

	//Задание 1
	cout << "Задание 1" << endl;
	int n;
	cout << "Введите кол-во чисел в массиве: " << endl;
	cin >> n;
	int* arr = new int[n];

	for (int i = 0; i < n; ++i) {
		arr[i] = rand() % 21;
	}
	cout << endl;

	for (int i = 0; i < n; i++) cout << arr[i] << " ";

	int x1,c1 = 0;
	cout << "Введите число для поиска: " << endl;
	cin >> x1;
	cout << "Ваше число было найдено на позициях: ";
	for (int i = 0; i < n; i++) {
		if (arr[i] == x1) {
			c1++;
			cout << i << " ";
		}
	}
	cout << endl << "Всего найдено: " << c1 << endl;

	//Задание 2 - пузырьковая сортировка (Bubble sort)
	cout << endl << "Задание 2: Сортировка пузырьком" << endl;
	int* bubble_sorted = bubble_sort(arr, n);
	for (int i = 0; i < n; i++) cout << bubble_sorted[i] << " ";

	//Задание 3 - гномья сортировка (Gnome sort)
	cout << endl <<"Задание 3: Гномья сортировка" << endl;
	int* gnome_sorted = gnome_sort(arr, n);
	for (int i = 0; i < n; i++) cout << gnome_sorted[i] << " ";

	//Задание 4 - сортировка подсчетом
	cout << endl << "Задание 3: Гномья сортировка" << endl;
	int* count_sorted = count_sort(arr, n);
	for (int i = 0; i < n; i++) cout << count_sorted[i] << " ";

	//Задание5
	cout <<endl<< "Задание 5" << endl;
	int x;
	cout << "Введите x: ";
	cin >> x;

	int count = 0;
	vector<int> pos;

	for (int i = 0; i < n; i++) {
		if (bubble_sorted[i] == x) {
			count++;
			pos.push_back(i);
		}
		else if (bubble_sorted[i] > x) {
			break;
		}
	}
	if (!count) {
		cout << "Не найдено таких эелментов";
		return 0;
	}
	cout << "Найдено " << count << " элементов x на позициях:" << endl;
	for (int p : pos) cout << p << " ";
}