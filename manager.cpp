#include "manager.h"

Manager::Manager(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Manager::showInfo() {
	cout << "Employee ID#£º " << this->m_Id
		<< "\tEmployee Name£º " << this->m_Name
		<<"\tPosition£º "<<this->getDeptName()
		<< "\tJob Duty£ºFinish tasks assigned from booss£¬distribute tasks to normal employees" << endl;
}

string Manager::getDeptName() {
	return string("Manager");
}