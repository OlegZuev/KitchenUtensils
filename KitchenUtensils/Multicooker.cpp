#include "Multicooker.h"
#include <utility>

Multicooker::Multicooker(const int inventory_number,
                         std::string color,
                         const int power,
                         const int volume,
                         const bool has_pressure_cooker_function): ElectricStove(inventory_number, std::move(color),
                                                                                 power),
                                                                   Pot(inventory_number, volume),
                                                                   has_pressure_cooker_function(
	                                                                   has_pressure_cooker_function) {}

Multicooker::Multicooker(Multicooker& other): ElectricStove(other),
                                              Pot(other),
                                              has_pressure_cooker_function(other.has_pressure_cooker_function) {}

Multicooker& Multicooker::operator=(Multicooker other) {
    swap(*this, other);

    return *this;
}

Multicooker::Multicooker(Multicooker&& other) noexcept: ElectricStove(std::move(other)), Pot(std::move(other)) {
	swap(*this, other);
}

Multicooker& Multicooker::operator=(Multicooker&& other) noexcept {
    swap(*this, other);

    return *this;
}


void swap(Multicooker& lhs, Multicooker& rhs) noexcept {
    using std::swap;

    swap(lhs.has_pressure_cooker_function, rhs.has_pressure_cooker_function);
}

void Multicooker::print(std::ostream& out) const {
    ElectricStove::print(out);
    out << "Volume: " << volume << std::endl;
    out << "Has Pressure Cooker Function: " << (has_pressure_cooker_function ? "Yes" : "No") << std::endl;
}

std::string Multicooker::getType() const {
    return "Multicooker";
}
