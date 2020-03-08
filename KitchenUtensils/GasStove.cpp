#include "GasStove.h"
#include <utility>

GasStove::GasStove(const int inventory_number,
                   std::string color,
                   const int gas_consumption): Stove(inventory_number, std::move(color)),
                                               gas_consumption(gas_consumption) {}

GasStove::GasStove(GasStove& other) : Stove(other), gas_consumption(other.gas_consumption) {}

GasStove& GasStove::operator=(GasStove other) {
	swap(*this, other);

	return *this;
}

GasStove::GasStove(GasStove&& other) noexcept: Stove(std::move(other)) {
	swap(*this, other);
}

GasStove& GasStove::operator=(GasStove&& other) noexcept {
	swap(*this, other);

	return *this;
}

void swap(GasStove& lhs, GasStove& rhs) noexcept {
	using std::swap;

	swap(lhs.gas_consumption, rhs.gas_consumption);
}

void GasStove::print(std::ostream& out) const {
	Stove::print(out);
	out << "Gas Consumption: " << gas_consumption << std::endl;
}

std::string GasStove::getType() const {
	return "Gas Stove";
}
