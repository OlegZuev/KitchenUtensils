#include "ElectricStove.h"
#include <utility>

ElectricStove::ElectricStove(const int inventory_number,
                             std::string color,
                             const int power): Stove(inventory_number, std::move(color)), power(power) {}

ElectricStove::ElectricStove(ElectricStove& other): Stove(other), power(other.power) {}

ElectricStove& ElectricStove::operator=(ElectricStove other) {
    swap(*this, other);

    return *this;
}

ElectricStove::ElectricStove(ElectricStove&& other) noexcept: Stove(std::move(other)) {
    swap(*this, other);
}

ElectricStove& ElectricStove::operator=(ElectricStove&& other) noexcept {
    swap(*this, other);

    return *this;
}

void swap(ElectricStove& lhs, ElectricStove& rhs) noexcept {
    using std::swap;

    swap(lhs.power, rhs.power);
}

void ElectricStove::print(std::ostream& out) const {
    Stove::print(out);
    out << "Power: " << power << std::endl;
}

std::string ElectricStove::getType() const {
    return "Electric Stove";
}
