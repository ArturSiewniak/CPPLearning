#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <numeric>	//For std::iota
#include <set>
#include <string>
#include <vector>

int main()
{
	//Vector
	std::vector<int> vect;

	for (int count = 0; count < 6; ++count)
		vect.push_back(10 - count);

	for (int index = 0; index < vect.size(); ++index)
		std::cout << vect[index] << ' ';
	
	std::cout << '\n';

	//Deque
	std::deque<int> deq;
	for (int count = 0; count < 3; ++count)
	{
		deq.push_back(count);
		deq.push_front(10 - count);
	}

	for (int index = 0; index < deq.size(); ++index)
		std::cout << deq[index] << ' ';

	std::cout << '\n';

	//Vector iteration
	std::vector<int> vect1;
	for (int count = 0; count < 6; ++count)
		vect1.push_back(count);

	std::vector<int>::const_iterator itve;
	itve = vect1.cbegin();
	while (itve != vect1.cend())
	{
		std::cout << *itve << ' ';
		++itve;
	}

	std::cout << '\n';

	//List iteration
	std::list<int> li;
	for (int count = 0; count < 6; ++count)
		li.push_back(count);

	std::list<int>::const_iterator itli;
	itli = li.cbegin();
	while (itli != li.cend())
	{
		std::cout << *itli << ' ';
		++itli;
	}

	std::cout << '\n';

	//Set iteration
	std::set<int> myset;
	myset.insert(7);
	myset.insert(2);
	myset.insert(-6);
	myset.insert(8);
	myset.insert(1);
	myset.insert(-4);

	std::set<int>::const_iterator itset;
	itset = myset.cbegin();
	while (itset != myset.cend())
	{
		std::cout << *itset << ' ';
		++itset;
	}

	std::cout << '\n';

	//Map iteration
	std::map<int, std::string> mymap;
	mymap.insert(std::make_pair(4, "apple"));
	mymap.insert(std::make_pair(2, "orange"));
	mymap.insert(std::make_pair(1, "banana"));
	mymap.insert(std::make_pair(3, "grapes"));
	mymap.insert(std::make_pair(6, "mango"));
	mymap.insert(std::make_pair(5, "peach"));

	auto itmap{ mymap.cbegin() };
	while (itmap != mymap.cend())
	{
		std::cout << itmap->first << "=" << itmap->second << ' ';
		++itmap;
	}

	std::cout << '\n';

	//min/max_element
	std::list<int> li1(6);
	std::iota(li1.begin(), li1.end(), 0);

	std::cout << *std::min_element(li1.begin(), li1.end()) << ' '
		<< *std::max_element(li1.begin(), li1.end()) << '\n';

	std::cout << '\n';

	//find and insert
	std::list<int> li2(6);
	std::iota(li2.begin(), li2.end(), 0);

	auto itli2{ find(li2.begin(), li2.end(),3) };

	li2.insert(itli2, 8);

	for (int i : li2)
		std::cout << i << ' ';

	std::cout << '\n';

	//sort and reverse
	std::vector<int> vect2{ 7, -3, 6, 2, -5, 0, 4 };

	std::sort(vect2.begin(), vect2.end());
	
	for (int i : vect2)
		std::cout << i << ' ';
	std::cout << '\n';

	std::reverse(vect2.begin(), vect2.end());

	for (int i : vect2)
		std::cout << i << ' ';
	std::cout << '\n';

	return 0;
}