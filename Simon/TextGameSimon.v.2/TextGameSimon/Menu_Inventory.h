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
	for (int i = 0; i < _inventory_size; i++) {
		std::cout << "Slot [" << i+1 << "/" << _inventory_size << "]: " << _inventory->get_name(i) << " ID: " << i << std::endl;
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
		_e_inventory->equip_item(_inventory->get_item(_input), _inventory);
		std::cout << _inventory->get_item(_input)->get_name() << " was equipped! \n";
		display_inventory(_inventory, _e_inventory);
	}
	else {	//If the user doesnt input a matching number
		system("cls");
		display_inventory(_inventory, _e_inventory);
	}

}

void display_equipment_inventory(Inventory* _inventory, Equipment_Inventory* _e_inventory) {
	int _input;
	int _equipment_inventory_size = _e_inventory->get_inventory_size();

	if (_equipment_inventory_size == 0) {
		std::cout << "Equipment Inventory's empty! \n";
	}
	else {
		for (int i = 0; i < _equipment_inventory_size; i++) {
			std::cout << "Slot [" << i+1 << "]: " << _e_inventory->get_name(i) << " ID: " << i << std::endl;
		}
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