#include<iostream>
using namespace std;
#include "workerManager.h"

void WorkerManager::Show_Menu() {
	cout << "*****************************************************************" << endl;
	cout << "**************Welcome to Employee Management System**************" << endl;
	cout << "**************************0.退出管理系统**************************" << endl;
	cout << "**************************1.增加职工信息**************************" << endl;
	cout << "**************************2.显示职工信息**************************" << endl;
	cout << "**************************3.删除离职职工**************************" << endl;
	cout << "**************************4.修改职工信息**************************" << endl;
	cout << "**************************5.查找职工信息**************************" << endl;
	cout << "**************************6.按照编号排序**************************" << endl;
	cout << "**************************7.清空所有文档**************************" << endl;
	cout << "*****************************************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem() {
	cout << "Hope to see you next time!" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp() {
	cout << "请输入增加职工数量:" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0) {
		int newSize = this->m_EmpNum + addNum;
		Worker** newSpace = new Worker * [newSize];
		if (this->m_EmpArray != NULL) {
			for (int i = 0;i < this->m_EmpNum;i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		for (int i = 0;i < addNum;i++) {
			int id;
			string name;
			int dSelect;

			cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;

			cout << "请选择该职工的岗位：" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin
		}
	}
}
WorkerManager::WorkerManager() {
	this->m_EmpNum = 0;
	this->m_EmpArray = NULL;
}