#include "employee.h"

Employee::Employee(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Employee::showInfo() {
	cout << "Employee ID#�� " << this->m_Id
		<< "\tEmployee Name�� " << this->m_Name
		<< "\tPosition�� " << this->getDeptName()
		<< "\tJob Duty��Finish task from Manager"<<endl;
}

string Employee::getDeptName() {
	return string("Normal Employee");
}