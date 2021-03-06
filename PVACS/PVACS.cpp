// PVACS.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"functions.h"
#include"ant.h"
#include<iostream>
#include<vector>
#include<fstream>
#include<random>
#include<time.h>
using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	srand((unsigned)time(NULL));
	vector<job> J;
	
	initJob(J);
	BFLPT(J);
	displayBatch();
	
	int info[100][100];//启发式信息
	int pos[100];//根据倾斜度算出的批的位置
	computeSIb();
	initPh();
	int t = Tmax;
	ant* Ant = new ant[antNum];
	while (t--)
	{
		cout << "第" << (100-t) << "次迭代：" << endl;
		for (int i = 0; i <antNum; i++)
		{
			Ant[i].id = i;
			Ant[i].generateV();
			Ant[i].createBatchSeq();
		}
		cout << "------------------------------------------" << endl;
	}
	
    return 0;
}

