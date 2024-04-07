#include <iostream>
#include "Set.h"
#include "functions.cpp"

using namespace std;

int main() {
    Set<int> set1;
    Set<int> set2;
    Set<int> set3;

    set1.add_element(1).add_element(2).add_element(3);
    set2.add_element(2).add_element(3).add_element(4);
    set3.add_element(3).add_element(4).add_element(5);

    cout << "Set 1: " << set1 << endl;
    cout << "Set 2: " << set2 << endl;
    cout << "Set 3: " << set3 << endl;

    cout << "Union of set1 and set 2: " << set1.set_union(set2) << endl;
 
    cout << "Intersection of set1 and set2: " << set1.set_intersect(set2) << endl;

    cout << "Difference of set2 and set1: " << set2.set_difference(set1) << endl;

    cout << "Symmetric Difference of set2 and set1: " << set2.set_sum_diff(set1) << endl;

    cout << "Size of set1: " << set1.size_of_set() << endl;

    cout << "Is set3 empty? " << (set3.is_empty() ? "Yes" : "No") << endl;

    set1.remove(3);
    cout << "Set 1 after removing 3: " << set1 << endl;

    Set<Product> shop1, shop2, shop3;

    shop1.add_element(Product::Bread).add_element(Product::Butter).add_element(Product::Milk).add_element(Product::Cheese).add_element(Product::Tea).add_element(Product::Coffee);
    shop2.add_element(Product::Milk).add_element(Product::Cheese).add_element(Product::Coffee).add_element(Product::Tea).add_element(Product::Sugar).add_element(Product::Salt);
    shop3.add_element(Product::Bread).add_element(Product::Cheese).add_element(Product::Water).add_element(Product::Salt).add_element(Product::Tea).add_element(Product::Meat);

    Set<Product> shops[] = { shop1,shop2,shop3 };
    size_t n = 3;

    Set<Product> union_of_shops = products_union(shops, n);
    cout << "All the products from the shops : " << union_of_shops << endl;
    Set<Product> intersection_of_shops = products_intersection(shops, n);
    cout << "Products that are in all the shops: " << intersection_of_shops << endl;

    return 0;
}
