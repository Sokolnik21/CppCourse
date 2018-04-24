#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>

#include "Data.h"

using namespace Cowboy;

namespace Cowboy {
	class Product {
	public:
		Product(const std::string& _name, const Data& _production);
		virtual ~Product() { }
		virtual std::string description() const;
		virtual float priceToPay() const { }
		bool write(std::ostream & os) const;
		bool load(std::istream & is);
		friend std::ostream& operator<<(std::ostream& stream, const Product& p);
		friend std::istream& operator>>(std::istream& stream, Product& p);
	protected:
		std::string name;
		Data production;
	};
}

#endif // POJAZD_H
