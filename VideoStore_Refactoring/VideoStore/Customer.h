// Customer.h
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>
#include "Rental.h"

class Customer {
public:
	Customer();
	explicit Customer(const std::string& name);

	Customer& addRental(const Rental& arg);
	std::string getName() const;
	std::string statement();

private:
	std::string _name;
	std::vector< Rental > _rentals;
};

inline Customer::
Customer() {}

inline Customer::
Customer(const std::string& name)
	: _name(name) {}

inline Customer& Customer::
addRental(const Rental& arg)
{
	_rentals.push_back(arg);
	return *this;
}

inline std::string Customer::
getName() const { return _name; }

#endif // CUSTOMER_H