/* �� ����� ��� �� ����� �������� �� �������� ���������� �� �������, ��������� � 0, 6, 12, 18 ����.
�������� ��������, ����� �������� �������� ��������:
 �) ������� ������� �� ������;
 �) ��������� ������� �� ������;
 �) ��������� �������� �������� �������� ���� ������;
 �) ����� � ���- ����� ������� ��������;
 �) ���- ������� ��� ���� ������� �����������.
   �������� ������ main �������, � ����� ���� ���� �� ������� ������� �������� � �������
 */

#include<iostream>
#include<iomanip>
using namespace std;

int a[31][4], n;

void InputData() {
	do {
		cout << "\n���� ���: "; 
		cin >> n;
	} while (n < 1 || n>31);
	for (int i = 1; i <= n; i++) {
			cout << "�������� ����� �� 0:00, 06:00, 12:00, 18:00 �� " << i << " ��� " <<endl;
			for (int j = 0; j < 4; j++)
			cin >> a[i][j];
		}
	return;
}

void PrintData() {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 4; j++)
			cout << left << setw(4) << a[i][j] << " ";
		cout << endl;
	}
	return;
}

float Func_c() {                       //returns average morning hum
	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum += a[i][1];
	return sum / (1.0 * n);
}

void Func_d() {													//days with most low night hum
	int min = 101;
	for (int i = 1; i <= n; i++)
		if (a[i][3] < min)
			min = a[i][3];
	for (int i = 1; i <= n; i++)
		if (a[i][3] == min)
			cout << "\n���-����� ������� ��������: " << i << endl;
	return;
}

float average(int k) {
	return (float)(a[k][0] + a[k][1] + a[k][2] + a[k][3]) / 4;
}

void Func_e() {
	float max = -1;
	//search of most high hum of sec 10 days
	if (n <= 10){
		cout << "\n������ ����� ���! " << endl;
	return;
	}
	for (int i = 11;(i<=n && n<=20)||(i<=20 && n>20); i++) 
		if (average(i) > max)
				max = average(i);
	for (int i = 11; (i <= n && n <= 20) || (i <= 20 && n > 20); i++)
		if (average(i) == max)
			cout << "\n��� � ���-������ ��������: " << i<<endl;
}

int main() {
	system("chcp 1251");
	int ch;
	do {
		cout << "\n1- �������� ������� �� ������\n2- ��������� ������� �� ������.\n3- ��������� �������� �������� �������� ���� ������.\n4- ����� � ��� - ����� ��������.\n5- ��� - ������� ��� ���� ������� �����������.\n0- �����\n";
		cout << "\n�������� ����� �� ������: "; cin >> ch;
		switch (ch) {
		case 1: {InputData(); break; }
		case 2: {PrintData(); break; }
		case 3: {cout<<Func_c(); break; }
		case 4: {Func_d(); break; }
		case 5: {Func_e(); break; }
		  defaut: {cout << "Try again: "; break; }
		}
	} while (ch);
	return 0;
}