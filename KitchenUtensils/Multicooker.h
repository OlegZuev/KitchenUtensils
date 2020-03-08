#pragma once
#include "ElectricStove.h"
#include "Pot.h"

class Multicooker final : public ElectricStove, Pot {
public:
	bool has_pressure_cooker_function{};

	Multicooker(int inventory_number, std::string color, int power, int volume, bool has_pressure_cooker_function);

	Multicooker() = delete;
	virtual ~Multicooker() = default;
	Multicooker(Multicooker& other);
	Multicooker& operator=(Multicooker other);
	Multicooker(Multicooker&& other) noexcept;
	Multicooker& operator=(Multicooker&& other) noexcept;
	
	friend void swap(Multicooker& lhs, Multicooker& rhs) noexcept;

protected:
	void print(std::ostream & out) const override;
	std::string getType() const override;
};