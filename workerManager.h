#pragma once
#include<iostream>
#include "worker.h"
#include<fstream>
#define FILENAME "empFile.txt"

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
	//save data to file
	void save();
	//display employee
	void Show_Emp();
	//check file is empty
	bool m_FileIsEmpty;
	//delete employee
	void Del_Emp();
	//modify employee
	void Mod_Emp();
	//search employee
	void Find_Emp();
	//sort employee
	void Sort_Emp();
	//clean file
	void Clean_File();
	int IsExist(int id);
	int get_EmpNum();
	int m_EmpNum;

	//initial employee
	void init_Emp();
	Worker** m_EmpArray;
};