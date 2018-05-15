#include "stdafx.h"
#include "Equipment_Inventory.h"
#include "Character.h"

Equipment_Inventory::Equipment_Inventory() {
	this->got_helmet = false; 
	this->got_chest = false;
	this->got_leg = false;
	this->got_feet = false;
	this->got_weapon = false;
	this->got_potion = false;

	//Fill the array with empty items
	for (int i = 0; i < this->equipment_inventory_size; i++) {
		this->equipment_inventory[i] = new Item("Empty", 0, 0, NoItem);
	}
}

void Equipment_Inventory::equip_item(Item* _item_to_equip, Inventory* _inventory, Character* _player) {
	switch (_item_to_equip->get_type()) {
	case WeaponItem:
		if (!this->got_weapon) {
			std::cout << _item_to_equip->get_name() << " was equipped! \n";
			this->equipment_inventory[4] = _item_to_equip; //Equipment from inventory
			_inventory->remove_item(_item_to_equip); //Remove item from inventory
			this->got_weapon = true; //Weapon equipped
			calculate_stats(_player); //Update stats
		}
		else {
			std::cout << "Replaced " << this->equipment_inventory[4]->get_name() << " with " << _item_to_equip->get_name() << std::endl;
			_inventory->add_item(this->equipment_inventory[4]); //Insert equipped item to inventory
			this->equipment_inventory[4] = _item_to_equip; //Replace equipment
			_inventory->remove_item(_item_to_equip); //Remove equipped item from inventory
			this->got_weapon = true; //Weapon equipped
			calculate_stats(_player); //Update stats
		}
		break;

	case ArmorItem:
		switch (_item_to_equip->get_armor_type()) {
		case Helmet:
			if (!this->got_helmet) {
				std::cout << _item_to_equip->get_name() << " was equipped! \n";
				this->equipment_inventory[0] = _item_to_equip;
				_inventory->remove_item(_item_to_equip);
				this->got_helmet = true;
				calculate_stats(_player);
			}
			else {
				std::cout << "Replaced " << this->equipment_inventory[0]->get_name() << " with " << _item_to_equip->get_name() << std::endl;
				_inventory->add_item(this->equipment_inventory[0]); //Insert equipped item to inventory
				this->equipment_inventory[0] = _item_to_equip; //Replace equipment
				_inventory->remove_item(_item_to_equip); //Remove equipped item from inventory
				this->got_helmet = true; //Weapon equipped
				calculate_stats(_player); //Update stats
			}
			break;

		case Chest:
			if (!this->got_chest) {
				std::cout << _item_to_equip->get_name() << " was equipped! \n";
				this->equipment_inventory[1] = _item_to_equip; 
				_inventory->remove_item(_item_to_equip);
				this->got_chest = true;
				calculate_stats(_player);
			}
			else {
				std::cout << "Replaced " << this->equipment_inventory[1]->get_name() << " with " << _item_to_equip->get_name() << std::endl;
				_inventory->add_item(this->equipment_inventory[1]); //Insert equipped item to inventory
				this->equipment_inventory[1] = _item_to_equip; //Replace equipment
				_inventory->remove_item(_item_to_equip); //Remove equipped item from inventory
				this->got_chest = true; //Weapon equipped
				calculate_stats(_player); //Update stats
			}
			break;

		case Leg:
			if (!this->got_leg) {
				std::cout << _item_to_equip->get_name() << " was equipped! \n";
				this->equipment_inventory[2] = _item_to_equip; 
				_inventory->remove_item(_item_to_equip);
				this->got_leg = true;
				calculate_stats(_player);
			}
			else {
				std::cout << "Replaced " << this->equipment_inventory[2]->get_name() << " with " << _item_to_equip->get_name() << std::endl;
				_inventory->add_item(this->equipment_inventory[2]); //Insert equipped item to inventory
				this->equipment_inventory[2] = _item_to_equip; //Replace equipment
				_inventory->remove_item(_item_to_equip); //Remove equipped item from inventory
				this->got_leg = true; //Weapon equipped
				calculate_stats(_player); //Update stats
			}
			break;

		case Feet:
			if (!this->got_feet) {
				std::cout << _item_to_equip->get_name() << " was equipped! \n";
				this->equipment_inventory[3] = _item_to_equip; //Equipment inventory
				_inventory->remove_item(_item_to_equip);
				this->got_feet = true;
				calculate_stats(_player);
			}
			else {
				std::cout << "Replaced " << this->equipment_inventory[3]->get_name() << " with " << _item_to_equip->get_name() << std::endl;
				_inventory->add_item(this->equipment_inventory[3]); //Insert equipped item to inventory
				this->equipment_inventory[3] = _item_to_equip; //Replace equipment
				_inventory->remove_item(_item_to_equip); //Remove equipped item from inventory
				this->got_feet = true; //Weapon equipped
				calculate_stats(_player); //Update stats
			}
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
			std::cout << "Replaced " << this->equipment_inventory[5]->get_name() << " with " << _item_to_equip->get_name() << std::endl;
			_inventory->add_item(this->equipment_inventory[5]); //Insert equipped item to inventory
			this->equipment_inventory[5] = _item_to_equip; //Replace equipment
			_inventory->remove_item(_item_to_equip); //Remove equipped item from inventory
			this->got_potion = true; //Weapon equipped
			calculate_stats(_player); //Update stats
		}
		break;
	}
}

void Equipment_Inventory::calculate_stats(Character* _player) {
	double _damage = 0, _crit_chance = 0, _accuracy = 0, _damage_reduction = 0, _deflect_chance = 0, _health_boost = 0;
	for (int i = 0; i < this->equipment_inventory_size; i++) {
		if (this->equipment_inventory[i]->get_type() == WeaponItem) { //Weapons
			_damage += this->equipment_inventory[i]->get_damage();
			_crit_chance += this->equipment_inventory[i]->get_crit_chance();
			_accuracy += this->equipment_inventory[i]->get_accuracy();
		}
		else if (this->equipment_inventory[i]->get_type() == ArmorItem) { //Armor
			_deflect_chance += this->equipment_inventory[i]->get_deflect_chance();
			_damage_reduction += this->equipment_inventory[i]->get_damage_reduction();
			_accuracy += this->equipment_inventory[i]->get_accuracy();
			_health_boost += this->equipment_inventory[i]->get_health_boost(); //No default value
		}
	}

	_player->set_damage(_damage + _player->get_default_damage());
	_player->set_crit_chance(_crit_chance + _player->get_default_crit_chance());
	_player->set_accuracy(_accuracy + _player->get_default_accuracy());
	_player->set_damage_reduction(_damage_reduction + _player->get_default_damage_reduction());
	_player->set_deflect_chance(_deflect_chance + _player->get_default_deflect_chance());
	_player->set_max_health(_player->get_max_health() * _health_boost + _player->get_default_max_health());
}