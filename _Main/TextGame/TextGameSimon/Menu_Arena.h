#pragma once
#include "stdafx.h"

#include "Menu_Challenge_Mode.h"
#include "Menu_Training.h"

void display_arena_menu() {
	int _input;

	cout << "[0] Challenge \n[1] Training \n[2] Back \n";
	cin >> _input;

	switch (_input) {
	case 0:
		system("cls");
		display_challenge_mode_menu(&player);
		break;
	case 1:
		system("cls");
		display_training_menu(&player);
		break;
	case 2:
		system("cls");
		break;
	}
}