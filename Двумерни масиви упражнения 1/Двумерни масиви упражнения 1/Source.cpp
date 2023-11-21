/* �������� �� ���� ����� ����������, � ����� N-��������(���� � ����) ��� N {10-1000} ��
�������� �� M-������ ���� (M {3-10}). 
��������� ��������, ����� ��������� ������������ �� �������� ����� �� ������������ � �������� 
�������� �� ���������� � ������������� � ��������. */

#include<iostream>
#define MaxN 1000
#define MaxM (10+1)
using namespace std;

int a[MaxN][MaxM], n, m;

// ��������� �� �������
void ReadData();                // �� ��������� �� �������
void PrintData();				// �� ����������� �� �������
int Winner(unsigned);			// ����� ������ �� ����������

int main() {
	system("chcp 1251");
	do {
		cout << "�������� ���� ���������: "; cin >> n;
	} while (n<10 || n>MaxN);
	do {
		cout << "�������� ���� ����: "; cin >> m;
	} while (m<3 || m>MaxM);
	ReadData();
	PrintData();
	cout << "����������� �� ����� ��� �: " << Winner(0) << endl;
	cout << "����������� �� ������ ��� �: " << Winner(1) << endl;
	return 0;
}

void ReadData() {
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(j==0)
				do {
					cout << "���(0-���, 1-����): "; cin >> a[i][j];
				} while (a[i][j] < 1 || a[i][j] > 10);
			else
				do {
					cout << "������: " << j << " �� �������� �����: " << i;
					cin >> a[i][j];
				} while (a[i][j] < 1 || a[i][j] > 10);
}

void PrintData() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cout << a[i][j] << '\t';
			cout << endl;
}

int Winner(unsigned flag_pol) {
	int max = 0, brT = 0, index = 0;
	for (int i = 0; i < n; i++) {
		brT = 0;
		if (a[i][0] == flag_pol)
			for (int j = 1; j < m; j++)
				brT += a[i][j];
		if (brT > max) {
			max = brT;
			index = i;
		}
	}
	return index;
}