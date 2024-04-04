#include <iostream>
#include "Set.h"
#include "product.h"

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

    Set<Product> storeAssortment[10];

    storeAssortment[0].add_element(Bread).add_element(Butter).add_element(Milk);
    storeAssortment[1].add_element(Bread).add_element(Milk).add_element(Cheese);
    storeAssortment[2].add_element(Bread).add_element(Butter).add_element(Milk);
    
    Set<Product> productUnion = storeAssortment[0];
    for (size_t i = 1; i < 3; ++i)
    {
        productUnion = productUnion.set_intersect(storeAssortment[i]);
    }
    
    std::cout << "Products in all the shops: " << productUnion << std::endl;

    return 0;
}
