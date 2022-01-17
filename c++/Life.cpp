#include <iostream>
#include <windows.h>
#include <math.h>

using namespace std;

HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

const int E = 0;
const int F = 1;
const int R = 20, C = 20;

void charge(int now[][C], int next[][C]) {
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) { 
			now[i][j] = E; 
			next[i][j] = E; 
		}
	now[3][13] = F;
	now[4][13] = F;
	now[5][13] = F;
	now[10][8] = F;
	now[11][8] = F;
	now[10][9] = F;
	now[11][9] = F;
	now[10][10] = F;
	now[11][10] = F;
	now[11][18] = F;
	now[12][18] = F;
	now[13][18] = F;
	now[11][19] = F;
	now[12][19] = F;
	now[13][19] = F;
	now[11][0] = F;
	now[12][0] = F;
	now[13][0] = F;
	now[18][8] = F;
	now[19][8] = F;
	now[0][8] = F;
	now[18][9] = F;
	now[19][9] = F;
	now[0][9] = F;
	now[18][10] = F;
	now[19][10] = F;
	now[0][0] = F;
	now[0][1] = F;
	now[1][0] = F;
	now[1][1] = F;
	now[0][19] = F;
	now[1][19] = F;
	now[19][19] = F;
	now[19][0] = F;
	now[19][1] = F;
	now[0][10] = F;
}

void print(int now[][C]) {
	char p[] = "L - I - F - E";
	int l = strlen(p);
	int pos = (int)((R * 2 - l) / 2);
	for (int i = 0; i < pos; i++)
		cout << " ";
	cout << p << endl;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (now[i][j]) {
				SetConsoleTextAttribute(color, 10);
				cout << now[i][j] << ' ';
			}
			else {
				SetConsoleTextAttribute(color, 7);
				cout << now[i][j] << ' ';
			}
		}
		SetConsoleTextAttribute(color, 7);
		cout << endl;
	}
}

void copy(int now[][C], int next[][C]) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			now[i][j] = next[i][j];
		}
	}
}

int outR(int k, int k1) {
	if (k == -1)
		k1 = k + C;
	else
		k1 = k - C;
	return k1;
}

int outC(int m, int m1) {
	if (m == -1)
		m1 = m + C;
	else
		m1 = m - C;
	return m1;
}

int cell(int i, int j, int now[][C]) {
	int q = 0, k, m, k1 = 0, m1 = 0, c = 0;
	for (k = i - 1; k <= i + 1; k++) {
		k1 = k;
		if (k < 0 || k >= R)
			k1 = outR(k, k1);
		for (m = j - 1; m <= j + 1; m++) {
			m1 = m;
			if (m < 0 || m >= C)
				m1 = outC(m, m1);
			if (now[k1][m1] == F)
				q++;
		}
	}
	if (now[i][j] == F)
		q--;
	if (q == 3 && now[i][j] == E)
		return F;
	if ((q == 3 || q == 2) && now[i][j] == F)
		return F;
	return E;
}

void evolution(int now[][C], int next[][C]) {
	for (int i = 0; i <= R; i++)
		for (int j = 0; j <= C; j++)
			next[i][j] = cell(i, j, now);
}

int main() {
	int now[R][C], next[R][C];
	char choice[100];
	charge(now, next);
	while (1) {
		print(now);
		cout << endl << "\"0\" per uscire, Invio per continuare: " << endl;
		cin.getline (choice, 100);
		if (choice[0] == '0')break;
		system("cls");
		evolution(now, next);
		copy(now, next);
	}
	system("Pause");
	return 0;
}