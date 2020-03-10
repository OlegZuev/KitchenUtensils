#pragma once
#include "BinaryTreeWrapper.h"
#include <regex>

class KitchenUtensil;

class Interaction {
public:
	static void addUtensil(BinaryTreeWrapper<KitchenUtensil>& utensils);
	static void removeUtensil(BinaryTreeWrapper<KitchenUtensil>& utensils);
	static void printUtensils(BinaryTreeWrapper<KitchenUtensil>& utensils);
	static void eventHandler();
	static int readInt(const std::string& input_text, const std::regex& regex);
};
