#pragma once
#include "KitchenUtensil.h"

class Stove : virtual public KitchenUtensil {
public:
	std::string color;

	Stove(int inventory_number, std::string color);

	Stove() = delete;
	virtual ~Stove() = default;
	Stove(Stove& other);
	Stove& operator=(Stove other);
	Stove(Stove&& other) noexcept;
	Stove& operator=(Stove&& other) noexcept;

	friend void swap(Stove& lhs, Stove& rhs) noexcept;

protected:
	void print(std::ostream& out) const override;
	std::string getType() const override;
};