#include<iostream>
using namespace std;
#include "workerManager.h"
#include "employee.h"
#include "boss.h"
#include "manager.h"

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

void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0;i < this->m_EmpNum;i++) {
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}

void WorkerManager::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		Worker* worker = NULL;
		if (dId == 1) {
			worker = new Employee(id, name, dId);
		} else if (dId == 2) {
			worker = new Manager(id, name, dId);
		} else {
			worker = new Boss(id, name, dId);
		}

		this->m_EmpArray[index] = worker;
		index++;
	}
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
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect) {
			case 1:
				worker = new Employee(id,name,1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;
		}

		delete[] this->m_EmpArray;
		this->m_EmpArray = newSpace;
		this->m_EmpNum = newSize;
		this->m_FileIsEmpty = false;
		cout << "成功添加" << addNum << "名新职工！" << endl;
		this->save();
	} else {
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}

int WorkerManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId) {
		num++;
	}

	ifs.close();
	return num;
}
WorkerManager::WorkerManager() {
	/*this->m_EmpNum = 0;
	this->m_EmpArray = NULL;*/

	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//File not exist
	if (!ifs.is_open()) {
		cout << "File not exist!" << endl;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}
	//File exist, but is empty
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "File is empty!" << endl;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}

	int num = this->get_EmpNum();
	cout << "Number of Employee : "<< num << endl;
	this->m_EmpNum = num;

	this->m_EmpArray = new Worker * [this->m_EmpNum];
	init_Emp();
	/*for (int i = 0;i < m_EmpNum;i++) {
		cout << "Employee ID: " << this->m_EmpArray[i]->m_Id
			<< "Employee Name: " << this->m_EmpArray[i]->m_Name
			<< "Department Id: " << this->m_EmpArray[i]->m_DeptId << endl;
	}*/
}

void WorkerManager::Show_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "File not exist or file is empty!" << endl;
	} else {
		for (int i = 0;i < m_EmpNum;i++) {
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

int WorkerManager::IsExist(int id) {
	int index = -1;
	for (int i = 0;i < this->m_EmpNum;i++) {
		if (this->m_EmpArray[i]->m_Id == id) {
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::Del_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "Files not exist or empty!" << endl;
	} else {
		cout << "Enter Employee ID you want to delete: " << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1) {
			for (int i = index;i < this->m_EmpNum - 1;i++) {
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->save();
			cout << "Delete Successfully!" << endl;
		} else {
			cout << "Failed to delete. Unable to find this employee" << endl;
		}
	}
}

void WorkerManager::Mod_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "File not exist or empty!" << endl;
	} else {
		cout << "Enter employee Id you want to modify: " << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1) {
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "Found: " << id << " employee, please enter new employee ID: " << endl;
			cin >> newId;
			cout << "Enter new name: " << endl;
			cin >> newName;
			cout << "Enter new position: " << endl;
			cout << "1. Normal Employee" << endl;
			cout << "2. Manager" << endl;
			cout << "3. Boss" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect) {
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}
			this->m_EmpArray[ret] = worker;
			cout << "Modify Successfully!" << endl;
			this->save();
		} else {
			cout<<"Modify Failed, No this person!";
		}

		system("pause");
		system("cls");
	}
}

void WorkerManager::Find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "File not exist or empty!" << endl;
	} else {
	
		cout << "Enter the way you want to search:" << endl;
		cout << "1. search based on employee id" << endl;
		cout << "2.search based on name" << endl;
		int select = 0;
		cin >> select;

		if (select == 1) {
			int id;
			cout << "enter employee id: " << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1) {
				cout << "Searched Successfully! This employee information: " << endl;
				this->m_EmpArray[ret]->showInfo();
			} else {
				cout << "Search Failed. No this person" << endl;
			}
		} else if (select == 2) {
			string name;
			cout << "Enter name you want to search: " << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0;i < m_EmpNum;i++) {
				if (m_EmpArray[i]->m_Name == name) {
					cout << "Searched success, employee Id: "
						<< m_EmpArray[i]->m_Id
						<< " information: " << endl;
				
					flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false) {
				cout << "No this person" << endl;
			}
		} else {
			cout << "Entered wrong choice." << endl;
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::Sort_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "File not exist or empty!" << endl;
		system("pause");
		system("cls");
	} else {
		cout << "Enter sort method: " << endl;
		cout << "1. based on increasing employee Id" << endl;
		cout << "2. based on decreasing employee Id" << endl;

		int select = 0;
		cin >> select;
		for (int i = 0;i < m_EmpNum;i++) {
			int minOrMax = i;
			for (int j = i + 1;j < m_EmpNum;j++) {
				if (select == 1) {
					if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id) {
						minOrMax = j;
					}
				} else {
					if (m_EmpArray[minOrMax]->m_Id < m_EmpArray[j]->m_Id) {
						minOrMax = j;
					}
				}
				
			}

			if (i != minOrMax) {
				Worker* temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minOrMax];
				m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "Success, sorted result: " << endl;
		this->save();
		this->Show_Emp();
	}
}

void WorkerManager::Clean_File() {
	cout << "Confirm to delete?" << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;

	int select = 0;
	cin >> select;
	if (select == 1) {
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL) {
			for (int i = 0;i < this->m_EmpNum;i++) {
				if (this->m_EmpArray[i] != NULL) {
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "Delete Success" << endl;
	}
	system("pause");
	system("cls");
}
WorkerManager::~WorkerManager() {
	/*if (this->m_EmpArray != NULL) {
		delete[] this->m_EmpArray;
	}*/
}