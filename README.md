Розподіл роботи у команді - "Айтівці".
Оголошення класу і методів писали колективно на парі. Методи писали таким чином:

Set(); - Грицик Діана.
Set(const Set& S); - Грицик Діана.
Set(T* elements, size_t n); - Грицик Діана.
Set(T element); - Грицик Діана.
~Set(); - Грицик Діана.
size_t size_of_set()const; - Лопатинський Олекса.
Set<T>& operator=(const Set& S); - Лопатинський Олекса.
Set<T>& add_element(T element); - Мрака Ольга.
Set<T>& add_range(T* elements, size_t n); - Мрака Ольга.
Set<T>& clear_set(); - Оверко Юліан-Ілля.
Set<T> set_union(const Set& S)const; - Лопатинський Олекса.
Set<T> set_difference(const Set& S)const; - Мрака Ольга.
Set<T> set_intersect(const Set& S)const; - Мрака Ольга.
Set<T> set_sum_diff(const Set& S)const; - Мрака Ольга.
bool is_valid(const T& x)const; - Фундак Юрій.
Set<T>& remove(const T& x); - Фундак Юрій.
void write_to(std::ostream& out)const; - Фундак Юрій.

	//допоміжні функції для тестів
bool sets_are_equal(const Set<T>& A); - Оверко Юліан-Ілля.
bool is_empty()const; - Оверко Юліан-Ілля(Фундак Юрій вносив зміни).
std::ostream& operator<<(std::ostream& out, const Set<T>& S); - Фундак Юрій.

Олекса Лопатинський в main писав демонстрацію деяких функцій.
Модульні тести кожен писав до своїх методів.

TEST_METHOD(TestingDefaultCreation) - Грицик Діана.
TEST_METHOD(TestCopyConstructor) - Грицик Діана.
TEST_METHOD(TestRangeConstructor) - Грицик Діана.
TEST_METHOD(TestingElementConstructor) - Грицик Діана.

TEST_METHOD(TestClear) - Оверко Юліан-Ілля.

TEST_METHOD(TestingAddElement) - Мрака Ольга.
TEST_METHOD(TestingAddRange) - Мрака Ольга.
TEST_METHOD(TestingAddRangeForChar) - Мрака Ольга.
TEST_METHOD(TestingSetDifference) - Мрака Ольга.
TEST_METHOD(TestingSetIntersection) - Мрака Ольга.
TEST_METHOD(TestingSumDifference) - Мрака Ольга.

TEST_METHOD(TestingIsValid) - Фундак Юрій.
TEST_METHOD(RemoveExistingElement) - Фундак Юрій.
TEST_METHOD(RemoveNonExistingElement) - Фундак Юрій.
TEST_METHOD(TestingPrint) - Фундак Юрій.

TEST_METHOD(TestingSetUnion) - Лопатинський Олекса.
TEST_METHOD(TestingOperator) - Лопатинський Олекса.
