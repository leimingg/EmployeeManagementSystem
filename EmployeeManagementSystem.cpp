#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

WorkerManager::WorkerManager() {

}

WorkerManager::~WorkerManager() {
			  
}

void test() {
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
}

int main() {
	WorkerManager wm;
	wm.Show_Menu();
	int choice = 0;
	cout << "Enter your choice:" << endl;
	cin >> choice;

	switch (choice) {
	case 0://�˳�ϵͳ
		wm.exitSystem();
		break;
	case 1://���ְ��
		break;
	case 2://��ʾְ��
		break;
	case 3://ɾ��ְ��
		break;
	case 4://�޸�ְ��
		break;
	case 5://����ְ��
		break;
	case 6://����ְ��
		break;
	case 7://����ļ�
		break;
	default:
		system("cls");
		break;
	}
	system("pause");
	return 0;
}