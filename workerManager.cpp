#include<iostream>
using namespace std;
#include "workerManager.h"

void WorkerManager::Show_Menu() {
	cout << "*****************************************************************" << endl;
	cout << "**************Welcome to Employee Management System**************" << endl;
	cout << "**************************0.�˳�����ϵͳ**************************" << endl;
	cout << "**************************1.����ְ����Ϣ**************************" << endl;
	cout << "**************************2.��ʾְ����Ϣ**************************" << endl;
	cout << "**************************3.ɾ����ְְ��**************************" << endl;
	cout << "**************************4.�޸�ְ����Ϣ**************************" << endl;
	cout << "**************************5.����ְ����Ϣ**************************" << endl;
	cout << "**************************6.���ձ������**************************" << endl;
	cout << "**************************7.��������ĵ�**************************" << endl;
	cout << "*****************************************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem() {
	cout << "Hope to see you next time!" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp() {
	cout << "����������ְ������:" << endl;
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

			cout << "�������" << i + 1 << "����ְ����ţ�" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;

			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin
		}
	}
}
WorkerManager::WorkerManager() {
	this->m_EmpNum = 0;
	this->m_EmpArray = NULL;
}