#include "Pot.h"

Pot::Pot(const int inventory_number, const int volume) : volume(volume) {
	this->inventory_number = inventory_number;
}

Pot::Pot(Pot& other) : volume(other.volume) {
	this->inventory_number = other.inventory_number;
}

Pot& Pot::operator=(Pot other) {
	swap(*this, other);

	return *this;
}

Pot::Pot(Pot&& other) noexcept {
	swap(*this, other);
}

Pot& Pot::operator=(Pot&& other) noexcept {
	swap(*this, other);

	return *this;
}

void swap(Pot& lhs, Pot& rhs) noexcept {
	using std::swap;

	swap(lhs.inventory_number, rhs.inventory_number);
	swap(lhs.volume, rhs.volume);
}

void Pot::print(std::ostream& out) const {
	KitchenUtensil::print(out);
	out << "Volume: " << volume << std::endl;
}

std::string Pot::getType() const {
	return "Pot";
}
