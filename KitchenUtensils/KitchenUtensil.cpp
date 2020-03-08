#include "KitchenUtensil.h"
#include <string>

bool operator>(const KitchenUtensil& left, const KitchenUtensil& right) {
	return left.inventory_number > right.inventory_number;
}

bool operator<(const KitchenUtensil& left, const KitchenUtensil& right) {
	return left.inventory_number < right.inventory_number;
}

bool operator==(const KitchenUtensil& left, const KitchenUtensil& right) {
	return left.inventory_number == right.inventory_number;
}

std::ostream& operator<<(std::ostream& out, const KitchenUtensil& element) {
	element.print(out);
	return out;
}

void KitchenUtensil::print(std::ostream& out) const {
	out << "Type: " << this->getType() << std::endl << "Inventory number: " << std::to_string(inventory_number)
		<< std::endl;
}

std::string KitchenUtensil::getType() const {
	return "Kitchen Utensil";
}
