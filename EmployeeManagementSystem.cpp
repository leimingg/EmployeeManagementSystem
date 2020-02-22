#include "workerManager.h"
#include<iostream>
using namespace std;

int main() {
	WorkerManager wm;
	int choice = 0;
	while (true) {
		wm.Show_Menu();

		cout << "Enter your choice:" << endl;
		cin >> choice;

		switch (choice) {
		case 0://Exist system
			wm.exitSystem();
			break;
		case 1://add employee
			wm.Add_Emp();
			break;
		case 2://display employee information
			wm.Show_Emp();
			break;
		case 3://delete employee
			wm.Del_Emp();
			break;
		case 4://modify employee
			wm.Mod_Emp();
			break;
		case 5://search employee
			wm.Find_Emp();
			break;
		case 6://sort employee
			wm.Sort_Emp();
			break;
		case 7://clean file
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