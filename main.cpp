#include <iostream>
#include <string>
#include <Windows.h>

#include "vendingmachine.h"

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int numOfSnack1, numOfSnack2, numOfSnack3;
	
	std::cout << "������� �������� ������� �����: " << std::endl;
	std::string nameOfSnack1;
	std::getline(std::cin,nameOfSnack1);
	std::cout << "� ��� ���������� (�� 0 �� 10): " << std::endl;
	std::cin >> numOfSnack1;
	std::cin.ignore(32767, '\n');
	std::cout << "������� �������� ������� �����: " << std::endl;
	std::string nameOfSnack2;
	std::getline(std::cin, nameOfSnack2);
	std::cout << "� ��� ���������� (�� 0 �� 15): " << std::endl;
	std::cin >> numOfSnack2;
	std::cin.ignore(32767, '\n');
	std::cout << "������� �������� �������� �����: " << std::endl;
	std::string nameOfSnack3;
	std::getline(std::cin, nameOfSnack3);
	std::cout << "� ��� ���������� (�� 0 �� 20): " << std::endl;
	std::cin >> numOfSnack3;
	std::cin.ignore(32767, '\n');

	// ������������ ��������� ������ ��� ������� Snack � ��������� ����� ������ � ������� ������ SetName
	Snack* snack1 = new Snack(nameOfSnack1);
	snack1->setName(nameOfSnack1);
	Snack* snack2 = new Snack(nameOfSnack2);
	snack2->setName(nameOfSnack2);
	Snack* snack3 = new Snack(nameOfSnack3);
	snack3->setName(nameOfSnack3);
	// ������������ ��������� ������ ��� ������� Slot
	SnackSlot* slot1 = new SnackSlot(10);
	SnackSlot* slot2 = new SnackSlot(15);
	SnackSlot* slot3 = new SnackSlot(20);
	SnackSlot* slot4 = new SnackSlot(5);

	int a1 = slot1->getSnackCount();
	int a2 = slot2->getSnackCount();
	int a3 = slot3->getSnackCount();
	int a4 = slot4->getSnackCount();

	std::cout << "���������� ���������� ������ � ����� 1: " << a1
		<< "\n���������� ���������� ������ � ����� 2: " << a2
		<< "\n���������� ���������� ������ � ����� 3: " << a3
		<< "\n���������� ���������� ������ � ����� 4: " << a4 << std::endl;
	
	// ��������� ����� � ���� 1
	slot1->addSnack(snack1, numOfSnack1);
	// � ���� 2
	slot2->addSnack(snack2, numOfSnack2);
	// � ���� 3
	slot3->addSnack(snack3, numOfSnack3);

	// ����������������� ��� �������� ������ ������� getEmptySlotCount
	// ��� ���������������� ���� �� ������� addSnack
	//slot4->addSnack(snack2, numOfSnack2);

	std::cout << "\n���������� ������ " << snack1->getName() << " � ����� 1: " << slot1->countPos()
			<< "\n���������� ������ " << snack2->getName() << " � ����� 2: " << slot2->countPos()
			<< "\n���������� ������ " << snack3->getName() << " � ����� 3: " << slot3->countPos()
			// ������ ����
			<< "\n���������� ������ � ����� 4: " << slot4->countPos() << std::endl;

	VendingMachine* machine = new VendingMachine(10);
	
	// ��������� ����� � �������� ������� 
	machine->addSlot(slot1);
	machine->addSlot(slot2);
	machine->addSlot(slot3);
	machine->addSlot(slot4);

	// ��������� ���������� ������ ������ (��� ������)
	std::cout << "���������� ������ ������: " << machine->getEmptySlotCount() << std::endl;

	delete machine;
	delete slot1;
	delete slot2;
	delete slot3;
	delete slot4;
	delete snack1;
	delete snack2;
	delete snack3;
	
	return 0;
}