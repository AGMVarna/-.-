/* Провежда се едно модно състезание, в което N-манекена(мъже и жени) при N {10-1000} се
оценяват от M-членно жури (M {3-10}). 
Съставете програма, която представя информацията по подходящ начин за състезанието и определя 
номерата на победитела и победителката в конкурса. */

#include<iostream>
#define MaxN 1000
#define MaxM (10+1)
using namespace std;

int a[MaxN][MaxM], n, m;

// ïðîòîòèïè íà ôóíêöèè
void ReadData();                // çà âúâåæäàíå íà äàííèòå
void PrintData();				// çà îòïå÷àòâàíå íà äàííèòå
int Winner(unsigned);			// âðúùà íîìåðà íà ïîáåäèòåëà

int main() {
	system("chcp 1251");
	do {
		cout << "Âúâåäåòå áðîé ó÷àñòíèöè: "; cin >> n;
	} while (n<10 || n>MaxN);
	do {
		cout << "Âúâåäåòå áðîé æóðè: "; cin >> m;
	} while (m<3 || m>MaxM);
	ReadData();
	PrintData();
	cout << "Ïîáåäèòåëÿò îò ìúæêè ïîë å: " << Winner(0) << endl;
	cout << "Ïîáåäèòåëÿò îò æåíñêè ïîë å: " << Winner(1) << endl;
	return 0;
}

void ReadData() {
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(j==0)
				do {
					cout << "Ïîë(0-ìúæ, 1-æåíà): "; cin >> a[i][j];
				} while (a[i][j] < 1 || a[i][j] > 10);
			else
				do {
					cout << "Îöåíêà: " << j << " çà ó÷àñòíèê íîìåð: " << i;
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
