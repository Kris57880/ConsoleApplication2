// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
typedef	struct Mahjong {
	int W[9] = { 0 };
	int B[9] = { 0 };
	int T[9] = { 0 };
	int EE = 0, SS = 0, WW = 0, NN = 0, RC = 0, GF = 0, WB = 0;
}mahjong;
int trans(char c) {
	return (int)c - 49;
}
bool checkNum(char c) {
	if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0')
		return true;
	else
		return false;
}
void check(mahjong &m, string &name) {
	int s = 0/*順子*/, k = 0/*刻子*/, j = 0/*將*/, i;
	//順子
	for (i = 0; i != 7; i++) {
		if (m.B[i] >= 1 && m.B[i + 1] >= 1 && m.B[i + 2] >= 1) {
			s++;
			m.B[i]--, m.B[i + 1]--, m.B[i + 2]--;
		}
		if (m.W[i] >= 1 && m.W[i + 1] >= 1 && m.W[i + 2] >= 1) {
			s++;
			m.W[i]--, m.W[i + 1]--, m.W[i + 2]--;
		}
		if (m.T[i] >= 1 && m.T[i + 1] >= 1 && m.T[i + 2] >= 1) {
			s++;
			m.T[i]--, m.T[i + 1]--, m.T[i + 2]--;
		}
	}
	//刻子 
	if (m.EE >= 3) { k++; m.EE -= 3; }
	if (m.SS >= 3) { k++; m.SS -= 3; }
	if (m.WW >= 3) { k++; m.WW -= 3; }
	if (m.NN >= 3) { k++; m.NN -= 3; }
	if (m.RC >= 3) { k++; m.RC -= 3; }
	if (m.GF >= 3) { k++; m.GF -= 3; }
	if (m.WB >= 3) { k++; m.WB -= 3; }

	for (i = 0; i != 9; i++) {
		if (m.B[i] >= 3) {
			k++;
			m.B[i] -= 3;
		}
		if (m.T[i] >= 3) {
			k++;
			m.T[i] -= 3;
		}
		if (m.W[i] >= 3) {
			k++;
			m.W[i] -= 3;
		}
	}
	//將 
	if (m.EE == 2 || m.SS == 2 || m.WW == 2 || m.NN == 2 || m.RC == 2 || m.GF == 2 || m.WB == 2)
		j++;
	for (i = 0; i != 9; i++) {
		if (m.B[i] >= 2 || m.T[i] >= 2 || m.W[i] >= 2)
			j++;
	}
	if (s + k == 5 && j == 1) {
		cout << name;
		printf(" can yell out Mahjong!");
	}
	else
		printf("Nothing happened.\n");
	cout << endl;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i != n; i++) {
		mahjong m;
		string name;
		cin >> name;
		for (int j = 0; j != 17; j++) {
			char c[2];
			for (int k = 0; k != 2; k++)
				cin >> c[k];
			if (checkNum(c[0])) {
				int num = trans(c[0]);
				if (c[1] == 'W')
					m.W[num]++;
				else if (c[1] == 'B')
					m.B[num]++;
				else if (c[1] == 'T')
					m.T[num]++;
			}
			else {
				if (c[0] == 'W') {
					if (c[1] == 'B')
						m.WB++;
					else
						m.WW++;
				}
				else if (c[0] == 'S')
					m.SS++;
				else if (c[0] == 'N')
					m.NN++;
				else if (c[0] == 'R')
					m.RC++;
				else if (c[0] == 'G')
					m.GF++;
				else if (c[0] == 'E')
					m.EE++;
			}
		}
		check(m, name);
	}

	return 0;
}

