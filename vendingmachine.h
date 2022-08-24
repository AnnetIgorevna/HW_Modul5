#pragma once
#include <iostream>
#include <string>

class Snack
{
public:
	Snack(std::string name);
	Snack(std::string name, double price, double weight, int numOfCalories);
	std::string getName() const;
	void setName(std::string name);
private:
	std::string snackName{};
	double snackPrice{};
	double snackWeight{};
	int snackCalories{};
};

class SnackSlot
{
public:
	SnackSlot(int size);
	~SnackSlot();
	int getSnackCount() const;
	void addSnack(Snack* snack, int numOfSnack);
	int countPos() const;
private:
	Snack** snacks;
	int snackCount{};
	int pos{};
	int numOfSnack{};
};

class VendingMachine
{
public:
	VendingMachine(int size);
	~VendingMachine();
	void addSlot(SnackSlot* slot);
	int getEmptySlotCount() const;
private:
	SnackSlot** slots;
	std::string name{};
	int slotCount{};
	int pos{};
};




