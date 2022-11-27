#include <vector>
#include <stack>
#include <map>
#include <set>
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include "set.hpp"
#include <iostream>
#include <list>


int main(void)
{
	{
		std::cout << "########    TESTING VECTOR AND STACK      ##########\n" << std::endl;
		/*-------------size() && top()-----------------*/
		std::cout << "\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-." <<std::endl;
		ft::stack<int> prueba;
		prueba.push(6);
		prueba.push(6);
		prueba.push(6);
		prueba.push(16);
		std::cout << "stack size:" << prueba.size() << std::endl;
		std::cout << "stack top:" << prueba.top() << std::endl;
		/*-------------empty(), push() && pop()-----------------*/
		std::cout << "\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-." <<std::endl;
		ft::stack<int> mystack;
		for (int i=0; i<5; ++i) mystack.push(i);
		std::cout << "Popping out elements..." <<std::endl;
		while (!mystack.empty())
		{
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		std::cout << std::endl;
		/*---------------different constructors---------------*/
		std::cout << "\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-." <<std::endl;
		// std::deque<int> mydeque(3,100); //deque with 3 elements
		ft::vector<int> myftvector(3,100); //deque with 3 elements
		std::vector<int> myvector(2, 200); //vector with 2 elements
		std::list<int> mylist;
		ft::stack<int> first; //empty stack
		// ft::stack<int> second(mydeque); //stack initialized to copy of deque [si container=vector no funciona]
		ft::stack<int> second(myftvector); //stack initialized to copy of deque [si container=vector no funciona]
		ft::stack<int, std::vector<int> > third; //empty stack using vector
		ft::stack<int, std::vector<int> > fourth(myvector);
		ft::stack<int, std::list<int> > fifth(mylist);
		std::cout << "size of first: " << first.size() << std::endl;
		std::cout << "size of second: " << second.size() << std::endl;
		std::cout << "size of third: " << third.size() << std::endl;
		std::cout << "size of fourth: " << fourth.size() << std::endl;
		std::cout << "size of fifth: " << fifth.size() << std::endl;
		/*---------------------swap() && bool operators--------------------*/
		std::cout << "\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-." <<std::endl;
		ft::vector<int> mystack1;
		for (int i=0; i<5; ++i) mystack1.push_back(i);
		ft::vector<int> mystack2;
		for (int i=0; i<8; ++i) mystack2.push_back(-i);
		std::cout << "size of mystack1 before swap: " << mystack1.size() << std::endl;
		std::cout << "size of mystack2 before swap: " << mystack2.size() << std::endl;
		mystack1.swap(mystack2);
		std::cout << "size of mystack1 after swap: " << mystack1.size() << std::endl;
		std::cout << "size of mystack2 after swap: " << mystack2.size() << std::endl;
		ft::vector<int> mystack3(mystack2);
		if (mystack1 == mystack3)
		    std::cout << "mystack1 and mystack2 are equal" << std::endl;
		else
			std::cout << "mystack1 and mystack2 are different" << std::endl;
		if (mystack2 != mystack3)
			std::cout << "mystack2 and mystack3 are different" << std::endl;
		else
			std::cout << "mystack2 and mystack3 are equal" << std::endl;
	}
	{
		std::cout << "########    TESTING PAIR      ##########\n" << std::endl;
		ft::pair<int,int> par1(3,5);
		ft::pair<int,int> par2(4,5);
		ft::pair<int,int> par3(3,8);
		ft::pair<int,int> par4(3,0);
		std::cout << " compare 1 y 2: " << (par1 < par2) << std::endl;
		std::cout << " compare 1 y 3: " << (par1 < par3) << std::endl;
		std::cout << " compare 1 y 4: " << (par1 < par4) << std::endl;
		std::cout << " compare 2 y 3: " << (par2 < par3) << std::endl;
		ft::pair<std::string,int> specialpar= ft::make_pair("Keyvalue",15);
		std::cout << "special par: (" << specialpar.first << "," << specialpar.second << ")" <<std::endl;
	}
	{
		std::cout << "########    TESTING MAP      ##########\n" << std::endl;
		std::list<ft::pair<const int, std::string> > lst;
		unsigned int lst_size = 10;
		for (unsigned int i = 0; i < lst_size; ++i)
			lst.push_back(ft::pair<const int, std::string>(i, std::string((lst_size - i), i + 65)));
		ft::map<int, std::string> mp(lst.begin(), lst.end());
		std::cout << "\n******[1]******\n";
		std::cout << "Map size : = " << mp.size() << ";\n";
		ft::map<int, std::string>::iterator it = mp.begin();
		for (; it != mp.end(); it++)
			std::cout << "mp[" << it->first << "] = " << it->second << ";\n";
		std::cout << "###############################################" << std::endl;
		mp.erase(++mp.begin());

		mp.erase(mp.begin());
		mp.erase(--mp.end());

		mp.erase(mp.begin(), ++(++(++mp.begin())));
		mp.erase(--(--(--mp.end())), --mp.end());

		mp[10] = "Hello";
		mp[11] = "Hi there";
		std::cout << "\n******[2]******\n";
		std::cout << "Map size : = " << mp.size() << ";\n";
		it = mp.begin();
		for (; it != mp.end(); it++)
			std::cout << "mp[" << it->first << "] = " << it->second << ";\n";
		std::cout << "###############################################" << std::endl;
		mp.erase(--(--(--mp.end())), mp.end());

		mp[12] = "ONE";
		mp[13] = "TWO";
		mp[14] = "THREE";
		mp[15] = "FOUR";
		std::cout << "\n******[3]******\n";
		std::cout << "Map size : = " << mp.size() << ";\n";
		it = mp.begin();
		for (; it != mp.end(); it++)
			std::cout << "mp[" << it->first << "] = " << it->second << ";\n";
		std::cout << "###############################################" << std::endl;
		mp.erase(mp.begin(), mp.end());
	}
	{
		std::cout << "########    SET SET      ##########\n" << std::endl;
		std::list<std::string> lst;
		unsigned int lst_size = 10;
		for (unsigned int i = 0; i < lst_size; ++i)
			lst.push_back(std::string((lst_size - i), i + 65));
		ft::set<std::string> st(lst.begin(), lst.end());
		std::cout << "\n******[1]******\n";
		std::cout << "Set size : = " << st.size() << ";\n";
		ft::set<std::string>::iterator it = st.begin();
		for (size_t i = 0; it != st.end(); it++, i++)
			std::cout << i << ": = " << *it << ";\n";
		std::cout << "###############################################" << std::endl;
		st.erase(++st.begin());

		st.erase(st.begin());
		st.erase(--st.end());

		st.erase(st.begin(), ++(++(++st.begin())));
		st.erase(--(--(--st.end())), --st.end());

		st.insert("Hello");
		st.insert("Hi there");
		std::cout << "\n******[2]******\n";
		std::cout << "Set size : = " << st.size() << ";\n";
		it = st.begin();
		for (size_t i = 0; it != st.end(); it++, i++)
			std::cout << i << ": = " << *it << ";\n";
		std::cout << "###############################################" << std::endl;
		st.erase(--(--(--st.end())), st.end());

		st.insert("ONE");
		st.insert("TWO");
		st.insert("THREE");
		st.insert("FOUR");
		std::cout << "\n******[3]******\n";
		std::cout << "Set size : = " << st.size() << ";\n";
		it = st.begin();
		for (size_t i = 0; it != st.end(); it++, i++)
			std::cout << i << ": = " << *it << ";\n";
		std::cout << "###############################################" << std::endl;
		st.erase(st.begin(), st.end());
	}
	
	return (0);
 }
