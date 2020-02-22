#include "boss.h"

Boss::Boss(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Boss::showInfo() {
	cout << "Employee ID#£º " << this->m_Id
		<< "\tEmployee Name£º " << this->m_Name
		<< "\tPosition£º " << this->getDeptName()
		<< "\tJob Duty£ºtake care the whole company" << endl;
}

string Boss::getDeptName() {
	return string("CEO");
}