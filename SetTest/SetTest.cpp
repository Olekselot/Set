#include "pch.h"
#include "CppUnitTest.h"
#include "..\Set\set.h"
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SetTest
{
	TEST_CLASS(SetTest)
	{
	public:
		TEST_METHOD(TestingDefaultCreation)
		{
			Set<int> IntSet;
			Assert::AreEqual(IntSet.size_of_set(), (size_t)0);
			Set<char> CharSet;
			Assert::AreEqual(CharSet.size_of_set(), (size_t)0);
		}
		TEST_METHOD(TestCopyConstructor)
		{
			Set<char> MySet("abcdefg", 7);
			Set<char> Copied(MySet);
			Assert::IsTrue(MySet.sets_are_equal(Copied));
			Assert::AreEqual(MySet.size_of_set(), Copied.size_of_set());
		}
		TEST_METHOD(TestRangeConstructor)
		{
			Set<char> MySet("abcdefg", 7);
			Assert::IsTrue(MySet.is_valid('a'));
			Assert::IsTrue(MySet.is_valid('b'));
			Assert::IsTrue(MySet.is_valid('c'));
			Assert::IsTrue(MySet.is_valid('d'));
			Assert::IsTrue(MySet.is_valid('e'));
			Assert::IsTrue(MySet.is_valid('f'));
			Assert::IsTrue(MySet.is_valid('g'));
			Assert::AreEqual(MySet.size_of_set(), (size_t)7);
		}
		TEST_METHOD(TestingElementConstructor)
		{
			Set<char> MySet('a');
			Assert::AreEqual(MySet.size_of_set(), (size_t)1);
			Assert::IsTrue(MySet.is_valid('a'));

			Set<std::string> StringSet("Olya");
			Assert::AreEqual(StringSet.size_of_set(), (size_t)1);
			Assert::IsTrue(StringSet.is_valid("Olya"));
		}
		TEST_METHOD(TestingAddElement)
		{
			int arr[] = { 11,56,78,9,3,44,56,7,9,5,1 };
			size_t n = sizeof arr / sizeof arr[0];
			Set<int> T(arr, n);
			T.add_element(12).add_element(22);

			int other_arr[] = { 11,56,78,9,3,44,56,7,9,5,1,12,22 };
			size_t m = sizeof other_arr / sizeof other_arr[0];
			Set<int> D(other_arr, m);


			Assert::IsTrue(T.is_valid(12));
			Assert::IsTrue(T.is_valid(22));
			Assert::IsTrue(T.sets_are_equal(D));
			Assert::ExpectException<exception>([]
				{
					int other_arr[] = { 11,56,78 };
					size_t m = sizeof other_arr / sizeof other_arr[0];
					Set<int> D(other_arr, m);
					D.add_element(11);
				});
		}
		TEST_METHOD(TestingAddRange)
		{
			Set<int> T;
			int arr[] = { 9,5,1 };
			size_t n = sizeof arr / sizeof arr[0];
			T.add_range(arr, n);
			Assert::IsTrue(T.is_valid(9));
			Assert::IsTrue(T.is_valid(5));
			Assert::IsTrue(T.is_valid(1));

			int other_arr[] = { 9,5,1,0 };
			size_t m = sizeof other_arr / sizeof other_arr[0];
			Set<int> D(other_arr, m);

			Assert::IsTrue(T.sets_are_equal(D));
		}
		TEST_METHOD(TestingAddRangeForChar)
		{
			Set<char> Chars("abcdefg", 7);
			Chars.add_range("efght", 5);
			Set<char> result("abcdefght", 9);
			Assert::IsTrue(Chars.sets_are_equal(result));
			Assert::AreEqual((size_t)9, Chars.size_of_set());
		}
		TEST_METHOD(TestingSetDifference)
		{
			int arr[] = { 9,5,1,3 };
			size_t n = sizeof arr / sizeof arr[0];
			Set<int> T(arr, n);

			int other_arr[] = { 9,5,1,3 };
			size_t m = sizeof other_arr / sizeof other_arr[0];
			Set<int> D(other_arr, m);

			Set<int> Diff = T.set_difference(D);
			Assert::IsTrue(Diff.is_empty());
			Assert::AreEqual(Diff.size_of_set(), (size_t)0);

			int another_arr[] = { 9,5,1,3,2,56,66 };
			size_t k = sizeof another_arr / sizeof another_arr[0];
			Set<int> A(another_arr, k);

			int diff_arr[] = { 2,56,66 };
			size_t d = sizeof diff_arr / sizeof diff_arr[0];
			Set<int> B(diff_arr, d);

			Set<int> C = A.set_difference(D);
			Assert::IsTrue(C.sets_are_equal(B));
			Assert::AreEqual(C.size_of_set(), (size_t)3);
		}
		TEST_METHOD(TestingSetIntersection)
		{
			int arr[] = { 9,5,1,3 };
			size_t n = sizeof arr / sizeof arr[0];
			Set<int> T(arr, n);

			int another_arr[] = { 111,222,333,444 };
			size_t a = sizeof another_arr / sizeof another_arr[0];
			Set<int> A(another_arr, a);

			Assert::IsTrue(T.set_intersect(A).is_empty());
			Assert::AreEqual(T.set_intersect(A).size_of_set(), (size_t)0);

			int other_arr[] = { 9,8,5,67,1,70 };
			size_t m = sizeof other_arr / sizeof other_arr[0];
			Set<int> D(other_arr, m);

			int result_arr[] = { 9,5,1 };
			size_t r = sizeof result_arr / sizeof result_arr[0];
			Set<int> RESULT(result_arr, r);

			Set<int> intersect = T.set_intersect(D);
			Assert::IsTrue(RESULT.sets_are_equal(intersect));
			Assert::AreEqual(intersect.size_of_set(), (size_t)3);
		}
		TEST_METHOD(TestingSumDifference)
		{
			double a[] = { 2.3,4.5,6.7 };
			Set<double> A(a, 3);
			Set<double> A1(a, 3);
			Assert::IsTrue(A.set_sum_diff(A1).is_empty());

			double b[] = { 1.3,2.3,4.6 };
			Set<double> B(b, 3);

			double ab[] = { 1.3,4.5,4.6,6.7 };
			Set<double> AB(ab, 4);
			Assert::IsTrue(AB.sets_are_equal(A.set_sum_diff(B)));
			Assert::AreEqual(A.set_sum_diff(B).size_of_set(), (size_t)4);
		}
		TEST_METHOD(TestingIsValid)
		{
			Set<char> A("abcdefg", 7);
			Assert::IsFalse(A.is_valid('x'));
			Assert::IsFalse(A.is_valid('p'));
			Assert::IsFalse(A.is_valid('q'));
			Assert::IsTrue(A.is_valid('a'));
			Assert::IsTrue(A.is_valid('b'));
			Assert::IsTrue(A.is_valid('c'));
			Assert::IsTrue(A.is_valid('d'));
		}
		TEST_METHOD(RemoveExistingElement)
		{
			Set<int> set;
			set.add_element(1);
			set.add_element(2);
			set.add_element(3);

			set.remove(2);

			Assert::AreEqual((size_t)2, set.size_of_set());
			Assert::IsFalse(set.is_valid(2));
		}
		TEST_METHOD(RemoveNonExistingElement)
		{
			Set<int> set;
			set.add_element(1);
			set.add_element(2);
			set.add_element(3);

			try
			{
				set.remove(4);
			}
			catch (std::out_of_range& error)
			{
				Assert::AreEqual("Element not found in set", error.what());
				Assert::AreEqual((size_t)3, set.size_of_set());
			}
		}
		TEST_METHOD(TestingPrint)
		{
			int arr[] = { 1,2,3,4,5,6,7,8 };
			Set<int> A(arr, 8);
			std::ostringstream out;
			A.write_to(out);
			Assert::AreEqual("1 2 3 4 5 6 7 8 ", out.str().c_str());
			out.str("");

			Set<char> Chars("abcdefg", 7);
			Chars.write_to(out);
			Assert::AreEqual("a b c d e f g ", out.str().c_str());
			out.str("");

			string names[] = { "Artur","Artem","Ivan","Oleg" };
			Set<std::string> Names(names, 4);
			Names.write_to(out);
			Assert::AreEqual("Artem Artur Ivan Oleg ", out.str().c_str());
		}
	};

}
