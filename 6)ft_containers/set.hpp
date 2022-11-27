/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:06:18 by doreshev          #+#    #+#             */
/*   Updated: 2022/11/14 13:45:55 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# include <stdexcept>
# include "iterators/tree.hpp"

namespace ft {
template< class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key> >
class set {
public:
	typedef	Key															key_type;
	typedef	Key															value_type;
	typedef	Compare														key_compare;
	typedef	Compare														value_compare;
	typedef	Allocator													allocator_type;
	typedef	typename allocator_type::reference							reference;
	typedef	typename allocator_type::const_reference					const_reference;
	typedef	typename allocator_type::pointer							pointer;
	typedef	typename allocator_type::const_pointer						const_pointer;
	typedef typename allocator_type::difference_type					difference_type;
	typedef	typename allocator_type::size_type							size_type;

	typedef	ft::tree<value_type, key_compare, allocator_type>			tree;
	typedef	typename tree::const_iterator								iterator;
	typedef	typename tree::const_iterator								const_iterator;
	typedef	typename tree::const_reverse_iterator						reverse_iterator;
	typedef	typename tree::const_reverse_iterator						const_reverse_iterator;

private:
	key_compare				_comp;
	allocator_type			_alloc;
	tree					_tree;

public:
// MEMBER FUNCTIONS
	// CONSTRUCTORS
		// 1) Empty
	explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
				: _comp(comp), _alloc(alloc), _tree() { }
		// 2) Range
	template <class InputIterator>
	set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc), _tree() {
		insert(first, last);
	}
		// 3) Copy
	set (const set& x) : _comp(x.key_comp()), _alloc(x.get_allocator()), _tree(x._tree) { }
	// DESTRUCTOR
	~set () { }
	// ASSIGN OPERATOR
		//assigns values to the container
	set& operator= (const set& x) {
		_alloc = x.get_allocator();
		_comp = x.key_comp();
		_tree = x._tree;
		return *this;
	}
	// ALLOCATOR GETTER -> Returns allocator
	allocator_type get_allocator() const { return _alloc; }

// ITERATORS
	// 1) begin -> returns an iterator to the beginning
	iterator begin() {
		return _tree.begin();
	}
	const_iterator begin() const {
		return _tree.begin();
	}
	iterator end() {
		return _tree.end();
	}
	const_iterator end() const {
		return _tree.end();
	}
	reverse_iterator rbegin() {
		return reverse_iterator(_tree.end());
	}
	const_reverse_iterator rbegin() const {
		return const_reverse_iterator(_tree.end());
	}
	reverse_iterator rend() {
		return reverse_iterator(_tree.begin());
	}
	const_reverse_iterator rend() const {
		return const_reverse_iterator(_tree.begin());
	}
// CAPACITY
	// 1) empty -> checks whether the container is empty
	bool empty() const { return _tree.empty(); }
	// 2) size -> Return container size
	size_type size() const { return _tree.size(); }
	// 3) maxsize -> Return container maximum size possible on current architecture
	size_type max_size() const { return _tree.max_size(); }
// MODIFIERS
	// 1) Removes all elements from the set
	void clear() { _tree.clear(); }
	// 2) Insertion of elements
		// a) Single element
	pair<iterator,bool> insert (const value_type& val) { return _tree.insert(val); }
		// b) With hint 
	iterator insert (iterator position, const value_type& val) {
		(void)position;
		return _tree.insert(val).first;
	}
		// c) Range
	template <class InputIterator>
	void insert (InputIterator first, InputIterator last) {
		for (; first != last; first++)
			_tree.insert(*first);
	}
	// 3) Erase -> Removes from container elements
		// a) Removes element in given position
	void erase (iterator position) { _tree.erase(*position); }
		// b) Removes element with given key
	size_type erase (const key_type& k) { return _tree.erase(k); }
		// c) Removes elemets in given range
	void erase (iterator first, iterator last) {
		while (first != last)
			_tree.erase(*first++);
	}
	// 4) Swap -> Exchanges the content of the container by the content of x
	void swap (set& x) {
		_tree.swap(x._tree);
	}
// LOOKUP (Operations)
	// 1) Count -> Count elements with a specific key
	size_type count (const key_type& k) const {
		return _tree.count(k);
	}
	// 2) Find -> finds element with specific key
	iterator find (const key_type& k) { return iterator(_tree.iter_find(k)); }
	const_iterator find (const key_type& k) const { return const_iterator(_tree.iter_find(k)); }
	// 3) Get range of equal elements
	pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
		return ft::make_pair(lower_bound(k), upper_bound(k));
	}
	pair<iterator,iterator> equal_range (const key_type& k) {
		return ft::make_pair(lower_bound(k), upper_bound(k));
	}
	// 4) Return iterator to lower bound
	iterator lower_bound (const key_type& k) { return _tree.lower_bound(k); }
	const_iterator lower_bound (const key_type& k) const { return _tree.lower_bound(k); }
	// 5) Return iterator to upper bound
	iterator upper_bound (const key_type& k) { return _tree.upper_bound(k); }
	const_iterator upper_bound (const key_type& k) const { return _tree.upper_bound(k); }
// OBSERVERS
	// Returns the function that compares keys
	key_compare key_comp() const { return _comp; }
	value_compare value_comp() const { return _comp; }
};

// RELATIONAL OPERATORS set
template< class Key, class Compare, class Alloc >
bool operator==( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs ) {
	if (lhs.size() != rhs.size())
		return false;
	return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}
template <class Key, class Compare, class Alloc> 
bool operator!= ( const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs ) {
	return !(lhs == rhs);
}
template <class Key, class Compare, class Alloc>
bool operator< ( const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs ) {
	return ft::lexicographical_compare (lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}
template <class Key, class Compare, class Alloc>
bool operator<= ( const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs ) {
	return 	!(rhs < lhs);
}
template <class Key, class Compare, class Alloc> 
bool operator>  ( const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs ) {
	return rhs < lhs;
}
template <class Key, class Compare, class Alloc>
bool operator>= ( const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs ) {
	return 	!(lhs < rhs);
}
//SWAP
template <class Key, class Compare, class Alloc>
void swap (set<Key,Compare,Alloc>& lhs, set<Key,Compare,Alloc>& rhs) { lhs.swap(rhs); }

}

#endif