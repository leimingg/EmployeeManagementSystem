#include "workerManager.h"
#include<iostream>
using namespace std;

/*#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"*/

/*WorkerManager::WorkerManager() {

}

WorkerManager::~WorkerManager() {
	if (this->m_EmpArray != NULL) {
		delete[] this->m_EmpArray;
	}
}
*/
/*void test() {
	Worker* worker = NULL;
	worker = new Employee(1, "����", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "����", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "����", 3);
	worker->showInfo();
	delete worker;
}*/

int main() {
	WorkerManager wm;
	int choice = 0;
	while (true) {
		wm.Show_Menu();

		cout << "Enter your choice:" << endl;
		cin >> choice;

		switch (choice) {
		case 0://�˳�ϵͳ
			wm.exitSystem();
			break;
		case 1://���ְ��
			wm.Add_Emp();
			break;
		case 2://��ʾְ��
			wm.Show_Emp();
			break;
		case 3://ɾ��ְ��
			wm.Del_Emp();
			break;
		case 4://�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5://����ְ��
			wm.Find_Emp();
			break;
		case 6://����ְ��
			wm.Sort_Emp();
			break;
		case 7://����ļ�
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}