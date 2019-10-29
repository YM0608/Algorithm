// Subway Algorithm Including Bus Transit

#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;


#define MAX 5000
#define MLINE 10
#define MSTAT 50
ifstream fin("input.txt");

int **map;
int all_line;
int all_stat;
int *linenum;
int trannum;
int newtran;
int indexline;
int indexstat;
int *tran_stat1;
int *tran_stat2;
int *tran_stat3;
int *tran_stat4;
int *bustime;
int bus = 0;

int dat;
int *startstat;
int *deststat;
int *trantime;
int index_sline;
int index_sstat;
int index_dline;
int index_dstat;

void input() {
	int temp;
	fin >> all_line;

	linenum = new int[all_line+1];
	linenum[0] = 0;
	for (int i = 1; i <= all_line; i++) {
		fin >> linenum[i];
		fin >> linenum[i];
	}
	for (int i = 1; i <= all_line; i++)all_stat += linenum[i];
	map = new int *[all_stat + 1];
	for (int i = 0; i <= all_stat; i++)map[i] = new int[all_stat + 1];
	fin >> trannum;
	tran_stat1 = new int[trannum];
	tran_stat2 = new int[trannum];

	for (int i = 0; i < trannum; i++) {
		fin >> indexline;
		fin >> indexstat;
		for (int j = 0; j < indexline; j++) {
			temp = linenum[j];
			indexstat = temp + indexstat;
		}
		tran_stat1[i] = indexstat;
		fin >> indexline;
		fin >> indexstat;

		for (int k = 0; k < indexline; k++) {
			temp = linenum[k];
			indexstat = temp + indexstat;
		}
		tran_stat2[i] = indexstat;
	}
	fin >> newtran;
	bustime = new int[newtran];
	newtran += trannum;
	tran_stat3 = new int[newtran];
	tran_stat4 = new int[newtran];
	for (int l = 0; l < trannum; l++) {
		tran_stat3[l] = tran_stat1[l];
		tran_stat4[l] = tran_stat2[l];
	}
	for (int i = trannum; i < newtran; i++) {
		fin >> indexline;
		fin >> indexstat;
		for (int j = 0; j < indexline; j++) {
			temp = linenum[j];
			indexstat = temp + indexstat;
		}
		tran_stat3[i] = indexstat;
		fin >> indexline;
		fin >> indexstat;
		fin >> bustime[bus];
		bus++;
		for (int k = 0; k < indexline; k++) {
			temp = linenum[k];
			indexstat = temp + indexstat;
		}
		tran_stat4[i] = indexstat;
	}
	fin >> dat;
	trantime = new int[dat];
	startstat = new int[dat];
	deststat = new int[dat];

	for (int i = 0; i < dat; i++) {
		fin >> trantime[i];
		fin >> index_sline;
		fin >> index_sstat;
		startstat[i] = index_sstat;
		for (int j = 0; j < index_sline; j++) {
			temp = linenum[j];
			startstat[i] = temp + startstat[i];
		}
		fin >> index_dline;
		fin >> index_dstat;
		deststat[i] = index_dstat;
		for (int j = 0; j < index_dline; j++) {
			temp = linenum[j];
			deststat[i] = temp + deststat[i];
		}
	}
}

void make(int t) {
	int temp;
	int board = 0;

	for (int i = 0; i <= all_stat; i++)
		for (int j = 0; j <= all_stat; j++)
			map[i][j] = MAX;
	for (int i = 1; i <= all_stat; i++) {
		if ((i - 1) > 0)map[i][i - 1] = 1;
		map[i][i] = 0;
		if ((i + 1) <= all_stat)map[i][i + 1] = 1;
	}
	for (int i = 0; i < trannum; i++) {
		map[tran_stat3[i]][tran_stat4[i]] = t;
		map[tran_stat4[i]][tran_stat3[i]] = t;
	}
	for (int i = trannum,u=0; (i < newtran)&&(u<bus); i++,u++) {
		map[tran_stat3[i]][tran_stat4[i]] = bustime[u];
		map[tran_stat4[i]][tran_stat3[i]] = bustime[u];
	}
	for (int i = 1; i < all_line; i++) {
		temp = linenum[i];
		board = temp + board;
		map[board][board + 1] = MAX;
		map[board + 1][board] = MAX;
	}
}

int path(int num) {
	int *l;
	int *l2;

	l = new int[all_stat + 1];
	l2 = new int[all_stat + 1];

	int start, dest, finish;
	int min, i, near;
	int stat = 1;

	start = startstat[num];
	dest = deststat[num];
	for (i = 0; i <= all_stat; i++) {
		l[i] = map[start][i];
		l2[i] = map[start][i];
	}
	while (stat <= all_stat) {
		min = MAX;
		for (i = 0; i <= all_stat; i++) {
			if ((0 <= l[i]) && (l[i] < min) && (i != start)) {
				min = l[i];
				min = l2[i];
				near = i;
			}
		}
		for (i = 0; i <= all_stat; i++) {
			if (l[near] + map[near][i] < l[i]) {
				l[i] = l[near] + map[near][i];
				l2[i] = l2[near] + map[near][i];
			}
		}
		l[near] = -1;
		stat++;
	}
	finish = l2[dest];
	delete[] l;
	delete[] l2;
	return finish;
}

int main() {
	input();

	if (all_line > MLINE) {
		return 0;
	}
	for (int i = 1; i <= all_line; i++) {
		if (linenum[i] > MSTAT) {
			return 0;
		}
	}

	for (int i = 0; i < dat; i++) {
		make(trantime[i]);
		cout << path(i) << endl;
	}
	delete[] linenum;
	delete[] tran_stat1;
	delete[] tran_stat2;
	delete[] tran_stat3;
	delete[] tran_stat4;
	delete[] startstat;
	delete[] deststat;
	for (int i = 0; i < all_stat; i++)delete[] map[i];
	delete[] map;
	return 0;
}