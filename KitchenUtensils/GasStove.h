#pragma once
#include "Stove.h"

class GasStove final : public Stove {
public:
	int gas_consumption{};

	explicit GasStove(int inventory_number, std::string color, int gas_consumption);

	GasStove() = delete;
	virtual ~GasStove() = default;
	GasStove(GasStove& other);
	GasStove& operator=(GasStove other);
	GasStove(GasStove&& other) noexcept;
	GasStove& operator=(GasStove&& other) noexcept;

	friend void swap(GasStove& lhs, GasStove& rhs) noexcept;

protected:
	void print(std::ostream& out) const override;
	std::string getType() const override;
};