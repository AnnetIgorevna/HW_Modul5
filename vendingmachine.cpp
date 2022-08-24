#include <iostream>
#include <string>
#include "vendingmachine.h"

Snack::Snack(std::string name)
{
	this->snackName = name;
}

Snack::Snack(std::string name, double price, double weight, int numOfCalories)
{
	this->snackName = name;
	this->snackPrice = price;
	this->snackWeight = weight;
	this->snackCalories = numOfCalories;
}

std::string Snack::getName() const
{
	return snackName;
}
void Snack::setName(std::string name)
{
	this->snackName = name;
}

SnackSlot::SnackSlot(int size)
{
	snackCount = size;
	snacks = new Snack* [size];
}

int SnackSlot::getSnackCount() const
{
	return snackCount;
}

SnackSlot::~SnackSlot()
{
	delete[] snacks;
}


void SnackSlot::addSnack(Snack* snack, int numOfSnack)
{
	for (int i = 0; i < numOfSnack; i++)
	{
		snacks[pos++] = snack;
	}
}

int SnackSlot::countPos() const
{
	return pos;
}

VendingMachine::VendingMachine(int size)
{
	slotCount = size;
	slots = new SnackSlot* [size];
	for (int i = 0; i < slotCount; i++)
	{
		slots[i] = nullptr; // ни одна полка не поставлена
	}
}

VendingMachine::~VendingMachine()
{
	delete[] slots;
}

void VendingMachine::addSlot(SnackSlot* slot)
{
	slots[pos++] = slot;
}

int VendingMachine::getEmptySlotCount() const
{
	int result{};
	for (int i = 0; i < slotCount; i++) {
		result += !slots[i] || slots[i]->countPos() == 0;
	}
	return result;
}
