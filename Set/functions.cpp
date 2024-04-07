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

//5.1 Фундак Ю.
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

//5.2 Фундак Ю.
Set<Product> products_union(Set<Product>* shops, size_t nof_shops)
{
	Set<Product> any_products;

	for (size_t i = 0; i < nof_shops; ++i)
	{
		any_products = any_products.set_union(shops[i]);
	}

	return any_products;
}
