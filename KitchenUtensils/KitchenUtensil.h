#pragma once
#include <ostream>

class KitchenUtensil {
public:
	int inventory_number{};

	virtual ~KitchenUtensil() = default;
	KitchenUtensil(KitchenUtensil&) = delete;
	KitchenUtensil& operator=(const KitchenUtensil&) = delete;
	KitchenUtensil(KitchenUtensil&&) = delete;
	KitchenUtensil& operator=(const KitchenUtensil&&) = delete;

	friend bool operator<(const KitchenUtensil& left, const KitchenUtensil& right);
	friend bool operator>(const KitchenUtensil& left, const KitchenUtensil& right);
	friend bool operator==(const KitchenUtensil& left, const KitchenUtensil& right);

    friend std::ostream& operator<<(std::ostream& out, const KitchenUtensil& element);

protected:
	KitchenUtensil() = default;
	virtual void print(std::ostream& out) const;
	virtual std::string getType() const;
};
