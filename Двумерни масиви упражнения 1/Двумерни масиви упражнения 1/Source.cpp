/* Провежда се едно модно състезание, в което N-манекена(мъже и жени) при N {10-1000} се
оценяват от M-членно жури (M {3-10}). 
Съставете програма, която представя информацията по подходящ начин за състезанието и определя 
номерата на победитела и победителката в конкурса. */

#include<iostream>
#define MaxN 1000
#define MaxM (10+1)
using namespace std;

int a[MaxN][MaxM], n, m;

// прототипи на функции
void ReadData();                // за въвеждане на данните
void PrintData();				// за отпечатване на данните
int Winner(unsigned);			// връща номера на победитела

int main() {
	system("chcp 1251");
	do {
		cout << "Въведете брой участници: "; cin >> n;
	} while (n<10 || n>MaxN);
	do {
		cout << "Въведете брой жури: "; cin >> m;
	} while (m<3 || m>MaxM);
	ReadData();
	PrintData();
	cout << "Победителят от мъжки пол е: " << Winner(0) << endl;
	cout << "Победителят от женски пол е: " << Winner(1) << endl;
	return 0;
}

void ReadData() {
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(j==0)
				do {
					cout << "Пол(0-мъж, 1-жена): "; cin >> a[i][j];
				} while (a[i][j] < 1 || a[i][j] > 10);
			else
				do {
					cout << "Оценка: " << j << " за участник номер: " << i;
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