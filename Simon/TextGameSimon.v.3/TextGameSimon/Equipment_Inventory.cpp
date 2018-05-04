#include "stdafx.h"
#include "Equipment_Inventory.h"
#include "Character.h"

Equipment_Inventory::Equipment_Inventory() {
	this->equipment_inventory_size = 6;
	got_helmet = false; 
	got_chest = false;
	got_leg = false;
	got_feet = false;
	got_weapon = false;
	got_potion = false;
}

void Equipment_Inventory::equip_item(Item* _item_to_equip, Inventory* _inventory, Character* _player) {
	switch (_item_to_equip->get_type()) {
	case WeaponItem:
		if (!this->got_weapon) {
			std::cout << _item_to_equip->get_name() << " was equipped! \n";
			this->equipment_inventory[4] = _item_to_equip; //Equipment inventory
			_inventory->remove_item(_item_to_equip);
			got_weapon = true;
		}
		else {
			std::cout << "Weapon already equipped! \n";
		}
		break;

	case ArmorItem:
		switch (_item_to_equip->get_armor_type()) {
		case Helmet:
			if (!this->got_helmet) {
				std::cout << _item_to_equip->get_name() << " was equipped! \n";
				this->equipment_inventory[5] = _item_to_equip; //Equipment inventory
				_inventory->remove_item(_item_to_equip);
				got_helmet = true;
			}
			else {
				std::cout << "Helmet already equipped! \n";
			}
			break;

		case Chest:

			break;

		case Leg:

				break;

		case Feet:

			break;
		}
		break;

	case PotionItem:
		if (!this->got_potion) {
			std::cout << _item_to_equip->get_name() << " was equipped! \n";
			this->equipment_inventory[5] =_item_to_equip; //Equipment inventory
			_inventory->remove_item(_item_to_equip);
			got_potion = true;
		}
		else {
			std::cout << "Potion already equipped! \n";
		}
		break;
	}
}

void Equipment_Inventory::calculate_stats(Character* _player) {
	double _damage = 0, _crit_chance = 0, _accuracy = 0, _damage_reduction = 0, _deflect_chance = 0, _health_boost = 0;
	for (int i = 0; i < this->equipment_inventory_size; i++) {
		if (this->equipment_inventory[i]->get_type() == WeaponItem) {
			_damage += this->equipment_inventory[i]->get_damage();
			_crit_chance += this->equipment_inventory[i]->get_crit_chance();
			_accuracy += this->equipment_inventory[i]->get_accuracy();
		}
		else if (this->equipment_inventory[i]->get_type() == ArmorItem) {
			_deflect_chance += this->equipment_inventory[i]->get_deflect_chance();
			_damage_reduction += this->equipment_inventory[i]->get_damage_reduction();
			_accuracy += this->equipment_inventory[i]->get_accuracy();
			_health_boost += this->equipment_inventory[i]->get_health_boost();
		}
	}

	_player->set_damage(_damage);
	_player->set_crit_chance(_crit_chance);
	_player->set_accuracy(_accuracy);
	_player->set_damage_reduction(_damage_reduction);
	_player->set_deflect_chance(_deflect_chance);
	_player->set_max_health(_player->get_max_health() * (1 + _health_boost));
}