#pragma once
#include "KitchenUtensil.h"

class Pot : virtual public KitchenUtensil {
public:
	int volume{};

	Pot(int inventory_number, int volume);

	Pot() = delete;
	virtual ~Pot() = default;
	Pot(Pot& other);
	Pot& operator=(Pot other);
	Pot(Pot&& other) noexcept;
	Pot& operator=(Pot&& other) noexcept;

	friend void swap(Pot& lhs, Pot& rhs) noexcept;

protected:
	void print(std::ostream & out) const override;
	std::string getType() const override;
};