#pragma once
#include "Stove.h"

class ElectricStove : public Stove {
public:
	int power{};

	ElectricStove(int inventory_number, std::string color, int power);

	ElectricStove() = delete;
	virtual ~ElectricStove() = default;
	ElectricStove(ElectricStove& other);
	ElectricStove& operator=(ElectricStove other);
	ElectricStove(ElectricStove&& other) noexcept;
	ElectricStove& operator=(ElectricStove&& other) noexcept;

	friend void swap(ElectricStove& lhs, ElectricStove& rhs) noexcept;

protected:
	void print(std::ostream& out) const override;
	std::string getType() const override;
};