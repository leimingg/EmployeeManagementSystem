#pragma once
#include<iostream>
#include "worker.h"
using namespace std;

class WorkerManager {
public:
	//constructor
	WorkerManager();
	//display menu
	void Show_Menu();
	//exit system
	void exitSystem();
	//deconstructor
	~WorkerManager();
	//add employee
	void Add_Emp();


	int m_EmpNum;
	Worker** m_EmpArray;
};