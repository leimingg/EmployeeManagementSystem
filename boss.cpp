#include "boss.h"

Boss::Boss(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Boss::showInfo() {
	cout << "Employee ID#�� " << this->m_Id
		<< "\tEmployee Name�� " << this->m_Name
		<< "\tPosition�� " << this->getDeptName()
		<< "\tJob Duty��take care the whole company" << endl;
}

string Boss::getDeptName() {
	return string("CEO");
}