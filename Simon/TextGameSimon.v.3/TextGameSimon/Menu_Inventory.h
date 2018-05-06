#pragma once
#include "stdafx.h"
#include "Inventory.h"
#include "Equipment_Inventory.h"

void display_equipment_inventory(Inventory* _inventory, Equipment_Inventory* _e_inventory);

void display_inventory(Inventory* _inventory, Equipment_Inventory* _e_inventory) {
	int _input;
	int _inventory_size = _inventory->get_inventory_size();

	if (_inventory_size == 0) {
		std::cout << "Inventory's empty! \n";
	}
	else {
		for (int i = 0; i < _inventory_size; i++) {
			std::cout << "Slot [" << i + 1 << "/" << "10" << "]: " << _inventory->get_name(i) << " ID: " << i << std::endl;
		}
	}

	std::cout << "[" << _inventory_size << "] Equipment Inventory \n[" << _inventory_size+1 << "] Back \n[n] Enter ID to equip" << std::endl;
	std::cin >> _input;

	if (_input == _inventory_size) { //Equipment inventory
		system("cls");
		display_equipment_inventory(_inventory, _e_inventory);
	}
	else if (_input == _inventory_size + 1) { //Back
		system("cls");
	} else if (_input < _inventory_size && _input >= 0) { //Equip item
		system("cls");
		_e_inventory->equip_item(_inventory->get_item(_input), _inventory, &test);
		display_inventory(_inventory, _e_inventory);
	}
	else {	//If the user doesnt input a matching number
		system("cls");
		display_inventory(_inventory, _e_inventory);
	}

}

void display_equipment_inventory(Inventory* _inventory, Equipment_Inventory* _e_inventory) {
	int _input;
	int _equipment_inventory_size = _e_inventory->get_equipment_inventory_size();

	if (_equipment_inventory_size == 0) {
		std::cout << "Equipment Inventory's empty! \n";	
	}
	else {
		std::cout << "Helmet: ";
		if (_e_inventory->get_got_helmet())
			std::cout << _e_inventory->get_item(0)->get_name() << " ID: 0" << std::endl;
		else
			std::cout << "Nothing \n";

		std::cout << "Chest: ";
		if (_e_inventory->get_got_chest())
			std::cout << _e_inventory->get_item(1)->get_name() << " ID: 1" << std::endl;
		else
			std::cout << "Nothing \n";

		std::cout << "Legs: ";
		if (_e_inventory->get_got_leg())
			std::cout << _e_inventory->get_item(2)->get_name() << " ID: 2" << std::endl;
		else
			std::cout << "Nothing \n";

		std::cout << "Feet: ";
		if (_e_inventory->get_got_feet())
			std::cout << _e_inventory->get_item(3)->get_name() << " ID: 3" << std::endl;
		else
			std::cout << "Nothing \n";

		std::cout << "Weapon: ";
		if (_e_inventory->get_got_weapon())
			std::cout << _e_inventory->get_item(4)->get_name() << " ID: 4" << std::endl;
		else
			std::cout << "Nothing \n";

		std::cout << "Potion: ";
		if (_e_inventory->get_got_potion())
			std::cout << _e_inventory->get_item(5)->get_name() << " ID: 5" << std::endl;
		else
			std::cout << "Nothing \n";
		
	}

	std::cout << "[" << _equipment_inventory_size << "] Back \n";
	std::cin >> _input;

	system("cls");
	if (_input == _equipment_inventory_size) {
		display_inventory(_inventory, _e_inventory);
	} else {
		display_equipment_inventory(_inventory, _e_inventory);
	}
}