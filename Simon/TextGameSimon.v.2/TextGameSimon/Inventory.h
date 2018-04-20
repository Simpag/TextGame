#pragma once

void display_inventory() {
	int _back;
	int inventory_size = inventory.size();

	for (int i = 0; i < inventory_size; i++) {
		std::cout << "Slot [" << i << "]: " << inventory[i]->get_name() << std::endl;
	 }

	std::cout << "[0] Back" << std::endl;
	std::cin >> _back;
	system("cls");
}