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

	//������� 1
	cout << "������� 1" << endl;
	int n;
	cout << "������� ���-�� ����� � �������: " << endl;
	cin >> n;
	int* arr = new int[n];

	for (int i = 0; i < n; ++i) {
		arr[i] = rand() % 21;
	}
	cout << endl;

	for (int i = 0; i < n; i++) cout << arr[i] << " ";

	int x1,c1 = 0;
	cout << "������� ����� ��� ������: " << endl;
	cin >> x1;
	cout << "���� ����� ���� ������� �� ��������: ";
	for (int i = 0; i < n; i++) {
		if (arr[i] == x1) {
			c1++;
			cout << i << " ";
		}
	}
	cout << endl << "����� �������: " << c1 << endl;

	//������� 2 - ����������� ���������� (Bubble sort)
	cout << endl << "������� 2: ���������� ���������" << endl;
	int* bubble_sorted = bubble_sort(arr, n);
	for (int i = 0; i < n; i++) cout << bubble_sorted[i] << " ";

	//������� 3 - ������ ���������� (Gnome sort)
	cout << endl <<"������� 3: ������ ����������" << endl;
	int* gnome_sorted = gnome_sort(arr, n);
	for (int i = 0; i < n; i++) cout << gnome_sorted[i] << " ";

	//������� 4 - ���������� ���������
	cout << endl << "������� 3: ������ ����������" << endl;
	int* count_sorted = count_sort(arr, n);
	for (int i = 0; i < n; i++) cout << count_sorted[i] << " ";

	//�������5
	cout <<endl<< "������� 5" << endl;
	int x;
	cout << "������� x: ";
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
		cout << "�� ������� ����� ���������";
		return 0;
	}
	cout << "������� " << count << " ��������� x �� ��������:" << endl;
	for (int p : pos) cout << p << " ";
}