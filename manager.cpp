#include "manager.h"

Manager::Manager(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Manager::showInfo() {
	cout << "Employee ID#�� " << this->m_Id
		<< "\tEmployee Name�� " << this->m_Name
		<<"\tPosition�� "<<this->getDeptName()
		<< "\tJob Duty��Finish tasks assigned from booss��distribute tasks to normal employees" << endl;
}

string Manager::getDeptName() {
	return string("Manager");
}