#include "employee.h"

Employee::Employee(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Employee::showInfo() {
	cout << "Employee ID#£º " << this->m_Id
		<< "\tEmployee Name£º " << this->m_Name
		<< "\tPosition£º " << this->getDeptName()
		<< "\tJob Duty£ºFinish task from Manager"<<endl;
}

string Employee::getDeptName() {
	return string("Normal Employee");
}