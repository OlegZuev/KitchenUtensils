#include "Stove.h"
#include <utility>

Stove::Stove(const int inventory_number, std::string color): color(std::move(color)){
	this->inventory_number = inventory_number;
}

Stove::Stove(Stove& other): color(other.color) {
	this->inventory_number = other.inventory_number;
}

Stove& Stove::operator=(Stove other) {
	swap(*this, other);

	return *this;
}

Stove::Stove(Stove&& other) noexcept {
	swap(*this, other);
}

Stove& Stove::operator=(Stove&& other) noexcept {
	swap(*this, other);

	return *this;
}

void swap(Stove& lhs, Stove& rhs) noexcept {
	using std::swap;

	swap(lhs.inventory_number, rhs.inventory_number);
	swap(lhs.color, rhs.color);
}

void Stove::print(std::ostream& out) const {
	KitchenUtensil::print(out);
	out << "Color: " << color << std::endl;
}

std::string Stove::getType() const {
	return "Stove";
}
