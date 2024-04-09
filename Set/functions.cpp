#include "set.h"

enum class Product
{
	Bread,
	Butter,
	Milk,
	Cheese,
	Meat,
	Fish,
	Salt,
	Sugar,
	Tea,
	Coffee,
	Water
};

std::ostream& operator<<(std::ostream& out, const Product& product) {
    switch (product) {
    case Product::Bread:
        out << "Bread";
        break;
    case Product::Butter:
        out << "Butter";
        break;
    case Product::Milk:
        out << "Milk";
        break;
    case Product::Cheese:
        out << "Cheese";
        break;
    case Product::Meat:
        out << "Meat";
        break;
    case Product::Fish:
        out << "Fish";
        break;
    case Product::Salt:
        out << "Salt";
        break;
    case Product::Sugar:
        out << "Sugar";
        break;
    case Product::Tea:
        out << "Tea";
        break;
    case Product::Coffee:
        out << "Coffee";
        break;
    case Product::Water:
        out << "Water";
        break;
    default:
        out << "Unknown Product";
    }
    return out;
}

//2 Fundak Y.

int digits(int n)
{
    Set<int> digits; 

    while (n > 0)
    {
        try
        {
            digits.add_element(n % 10);
        }
        catch(const std::exception& error){}
        n /= 10;
    }

    return digits.size_of_set();
}

//5.1 Fundak Y.
Set<Product> products_intersection(Set<Product>* shops, size_t nof_shops)
{
	if (nof_shops == 0)
	{
		return Set<Product>();
	}
	Set<Product> common_products = shops[0];

	for (size_t i = 1; i < nof_shops; ++i)
	{
		common_products = common_products.set_intersect(shops[i]);
	}

	return common_products;
}

//5.2 Fundak Y.
Set<Product> products_union(Set<Product>* shops, size_t nof_shops)
{
	Set<Product> any_products;

	for (size_t i = 0; i < nof_shops; ++i)
	{
        try
        {
            any_products = any_products.set_union(shops[i]);
        }
        catch (...){}
	}

	return any_products;
}
