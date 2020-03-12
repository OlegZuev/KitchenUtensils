#include "Interaction.h"
#include <iostream>
#include "Multicooker.h"
#include "GasStove.h"
#include <limits>


void Interaction::addUtensil(BinaryTreeWrapper<KitchenUtensil>& utensils) {
	std::cout << "Choose utensil type:" << std::endl << "Stove - 1" << std::endl << "Pot - 2" << std::endl <<
		"Gas Stove - 3" << std::endl << "Electric Stove - 4" << std::endl << "Multicooker - 5" << std::endl;
	const int index = readInt("Index: ", std::regex("[1-5]"));
	const int inventory_number = readInt("Input inventory number: ", std::regex("\\d+"));
	if (utensils.exists(inventory_number)) {
		KitchenUtensil* dummy_utensil = new Stove(inventory_number, "");
		utensils.add(dummy_utensil);
		delete dummy_utensil;
		return;
	}
		
	std::string color;
	int volume;
	int gas_consumption;
	int power;
	switch (index) {
	case 1:
		std::cout << "Input color: ";
		std::cin >> color;
		utensils.add(new Stove(inventory_number, color));
		break;
	case 2:
		volume = readInt("Input volume: ", std::regex("\\d+"));
		utensils.add(new Pot(inventory_number, volume));
		break;
	case 3:
		std::cout << "Input color: ";
		std::cin >> color;
		gas_consumption = readInt("Input gas consumption: ", std::regex("\\d+"));
		utensils.add(new GasStove(inventory_number, color, gas_consumption));
		break;
	case 4:
		std::cout << "Input color: ";
		std::cin >> color;
		power = readInt("Input power: ", std::regex("\\d+"));
		utensils.add(new ElectricStove(inventory_number, color, power));
		break;
	case 5:
		std::cout << "Input color: ";
		std::cin >> color;
		power = readInt("Input power: ", std::regex("\\d+"));
		volume = readInt("Input volume: ", std::regex("\\d+"));
		bool has_pressure_cooker_function;
		std::string has_pressure_cooker_function_str;
		std::cout << R"(Input "Does this multicooker has pressure cooker function?" (Yes \ No): )";
		std::cin >> has_pressure_cooker_function_str;
		has_pressure_cooker_function = has_pressure_cooker_function_str == "Yes";
		utensils.add(new Multicooker(inventory_number, color, power, volume, has_pressure_cooker_function));
		break;
	}
}

void Interaction::removeUtensil(BinaryTreeWrapper<KitchenUtensil>& utensils) {
	const int inventory_number = readInt("Input utensil's inventory number for remove: ", std::regex("\\d+"));
	utensils.remove(inventory_number);
}

void Interaction::printUtensils(BinaryTreeWrapper<KitchenUtensil>& utensils) {
	std::cout << "Choose way to represent the tree:" << std::endl << "Forward traversal of the tree - 1" << std::endl <<
		"Backward traversal of the tree - 2" << std::endl << "Symmetric traversal of the tree - 3" << std::endl;
	const int index = readInt("Index: ", std::regex("[1-3]"));
	std::cout << std::endl;
	switch (index) {
	case 1:
		utensils.forwardPrint();
		break;
	case 2:
		utensils.backwardPrint();
		break;
	case 3:
		utensils.symmetricPrint();
		break;
	}
}

void Interaction::eventHandler() {
	BinaryTreeWrapper<KitchenUtensil> utensils;
	while (true) {
		std::cout << "Choose one of the actions:" << std::endl << "Add utensil in tree - 1" << std::endl <<
			"Remove utensil from tree - 2" << std::endl << "Show current tree with utensils - 3" << std::endl << "Exit - 4" << std::endl;
		const int index = readInt("Index: ", std::regex("[1-4]"));
		std::cout << std::endl;
		switch (index) {
		case 1:
			addUtensil(utensils);
			break;
		case 2:
			removeUtensil(utensils);
			break;
		case 3:
			printUtensils(utensils);
			break;
		case 4:
			return;
		}
		std::cout << std::endl;
	}
}

int Interaction::readInt(const std::string& input_text, const std::regex& regex) {
	int x = 0;
	while (true) {
		// loop continually until valid input received
		std::cout << input_text;
		if (!(std::cin >> x)) {
			// check stream state
			// if eof() or bad() break read loop
			if (std::cin.eof() || std::cin.bad()) {
				std::cerr << "User canceled or unrecoverable error" << std::endl;
				return -1;
			}
			if (std::cin.fail()) {
				// if failbit
				std::cerr << "Error: invalid input" << std::endl;
				std::cin.clear(); // clear failbit
				// extract any characters that remain unread
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		} else {
			std::string str_x = std::to_string(x);
			if (!std::regex_match(str_x.begin(), str_x.end(), regex))
				continue;
			// on successful read of int
			// extract any characters that remain unread
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break; // then break read loop
		}
	}

	return x;
}
