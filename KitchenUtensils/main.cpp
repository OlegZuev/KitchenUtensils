#include <iostream>
#include "Multicooker.h"
#include "BinaryTreeWrapper.h"
#include "GasStove.h"
#include "Interaction.h"

int main() {
	// Tests
	//BinaryTreeWrapper<KitchenUtensil> utensils;
	// utensils.add(new Stove(8, "Blue"));
	// utensils.add(new GasStove(1, "Blue", 100));
	// utensils.add(new Stove(5, "Blue"));
	// utensils.add(new Stove(2, "Blue"));
	// //utensils.add(new Stove(7, "Blue"));
	// utensils.add(new Multicooker(7, "Blue", 50, 200, true));
	// utensils.symmetricPrint();
	//
	// std::cout << std::endl;
	//
	// utensils.remove(2);
	// utensils.symmetricPrint();
	//
	// std::cout << std::endl;
	//
	// utensils.remove(5);
	// utensils.symmetricPrint();
	//
	// std::cout << std::endl;
	//
	// utensils.remove(7);
	// utensils.symmetricPrint();
	//
	// std::cout << std::endl;
	//
	// utensils.remove(1);
	// utensils.symmetricPrint();
	//
	// std::cout << std::endl;
	//
	// utensils.remove(8);
	// utensils.symmetricPrint();
	// std::cout << Multicooker(3, "Green", 10, 25, true);
	Interaction::eventHandler();
	return 0;
}
