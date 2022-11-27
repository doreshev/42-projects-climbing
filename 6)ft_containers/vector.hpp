/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:03:14 by doreshev          #+#    #+#             */
/*   Updated: 2022/11/14 15:35:46 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <stdexcept>
# include "iterators/VectorIterator.hpp"
# include "algorithm.hpp"
# include "type_traits.hpp"

namespace ft {
	template<class T, class Allocator = std::allocator<T> >
	class vector {
	public:
		typedef	T											value_type;
		typedef	Allocator									allocator_type;
		typedef	typename allocator_type::size_type			size_type;
		typedef typename allocator_type::difference_type	difference_type;
		typedef	typename allocator_type::reference			reference;
		typedef	typename allocator_type::const_reference	const_reference;
		typedef	typename allocator_type::pointer			pointer;
		typedef	typename allocator_type::const_pointer		const_pointer;
		typedef	ft::VectorIterator<value_type>				iterator;
		typedef	ft::VectorIterator<const value_type>		const_iterator;
		typedef	ft::reverse_iterator<iterator>				reverse_iterator;
		typedef	ft::reverse_iterator<const_iterator>		const_reverse_iterator;

	protected:
		size_type		_size;
		size_type		_cap;
		pointer			_begin;
		allocator_type	_alloc;

	public:
	// ******CONSTRUCTORS******
		// 1) Default
		explicit vector ( const allocator_type& alloc = allocator_type() )
						: _size(0), _cap(0), _begin(nullptr), _alloc(alloc) { }
		// 2) Fill
		explicit vector ( size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type() )
							: _size(0), _cap(0), _begin(nullptr), _alloc(alloc) {
			assign(n, val);
		}
		// 3) Range
		template <class InputIterator>
		vector ( InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type() )
				: _size(0), _cap(0), _begin(nullptr), _alloc(alloc) {
			assign(first, last);
		}
		// 4) Copy
		vector ( const vector& x ) : _size(0), _cap(0), _begin(nullptr), _alloc(x.get_allocator()) { 
			_vallocate(x.capacity());
			for ( ; _size < x._size; _size++) {
				try {
					_alloc.construct(_begin + _size, x[_size]);
				}
				catch(...) {
					_vdeallocate();
				}
			}
		}

	// DESTRUCTOR
		~vector() { _vdeallocate(); }

	// ASSIGN CONTENT
		vector& operator=( const vector& x ) {
			if (*this == x)
				return (*this);
			assign(x.begin(), x.end());
			return *this;
		}

	// ASSIGN - Assigns new contents to the vector, replacing its current contents
		// 1) Fill
		void	assign(size_type count, const value_type& val) {
			if (count == 0)
				return;
			clear();
			if (count > _cap) {
				if (_cap > 0)
					_alloc.deallocate(_begin, _cap);
				_vallocate(count);
			}
			for ( ; _size < count; _size++) {
				try {
					_alloc.construct(_begin + _size, val);
				}
				catch(...) {
					_vdeallocate();
				}
			}
		}
		// 2) Range
		template <class InputIterator>
		void	assign(InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = NULL) {
			_assignrange(first, last, typename iterator_traits<InputIterator>::iterator_category());
		}

	// ALLOCATOR
		// Returns the allocator associated with the container
		allocator_type	get_allocator() const { return _alloc; }

	// ELEMENT ACCESS
		// 1) "at" - Returns a reference to the element at position n in the vector
		reference	at(size_type pos) {
			if (pos >= size())			
				throw std::out_of_range("ft::vector");
			return *(_begin + pos);
		}
		const_reference	at(size_type pos) const {
			if (pos >= size())			
				throw std::out_of_range("ft::vector");
			return *(_begin + pos);
		}
		// 2) "[]" - The same behavior as 'at' operator function, but no bounds checking is performed
		reference		operator[](size_type pos)		{ return *(_begin + pos); }
		const_reference	operator[](size_type pos) const	{ return *(_begin + pos); }
		// 3) "front" - Returns a reference to the first element in the vector
		reference 		front()							{ return *_begin; }
		const_reference front() const					{ return *_begin; }
		// 4) "back" - Returns a reference to the last element in the vector
		reference		back() 							{ return *(_begin + _size - 1); }
		const_reference	back() const					{ return *(_begin + _size - 1); }
		// 5) "data" - Returns a direct pointer to the memory array used internally by the vector
		value_type*			data() 						{ return _begin; }
		const value_type*	data() const				{ return _begin; }

	// ITERATORS
		// 1) Begin - iterator pointing first element position
		iterator				begin()			{ return iterator(_begin); }
		const_iterator 			begin() const	{ return const_iterator(_begin); }
		// 2) End - iterator pointing last element position
		iterator				end()			{ return iterator(_begin + _size); }
		const_iterator			end() const 	{ return const_iterator(_begin + _size); }
		// 3) Reverse Begin - iterator pointing after the last element position
		reverse_iterator		rbegin()		{ return reverse_iterator(_begin + _size); }
		const_reverse_iterator	rbegin() const	{ return reverse_iterator(_begin + _size); }
		// 4) Reverse End - iterator pointing first element position
		reverse_iterator		rend()			{ return reverse_iterator(_begin); }
		const_reverse_iterator	rend() const	{ return const_reverse_iterator(_begin); }

	// CAPACITY FUNCTIONS
		// 1) Checks if the current vector is empty
		bool	empty() const {
			if (_size == 0)
				return true;
			return false;
		}
		// 2) Size of the vector
		size_type	size() const {
			return _size;
		}
		// 3) Max possible size of the vector
		size_type max_size() const {
			size_type _amax = _alloc.max_size();
			size_type _nmax = std::numeric_limits<size_type>::max() / 2;
			if (_amax < _nmax)
				return _amax;
			return _nmax;
		}
		// 4) Creating memory with given capacity
		void	reserve( size_type new_cap ) {
			if (new_cap > max_size())
				throw std::length_error("ft::vector");
			else if (new_cap > _cap) {
				pointer	tmp = _pallocate(new_cap);
				size_type i = 0;
				for ( ; i < _size; i++) {
					try {
						_alloc.construct(tmp + i, _begin[i]);
					}
					catch(...) {
						for (size_type j = 0; j < i; j++)	
							_alloc.destroy(tmp + i);
						_alloc.deallocate(tmp, new_cap);
					}
				}
				_vdeallocate();
				_begin = tmp; _size = i; _cap = new_cap;
			}
		}
		// 5) Capacity of the vector
		size_type	capacity() const {
			return _cap;
		}

	// MODIFIERS
		// 1) Clearing array, calling destructor to all members;
		void	clear() {
			for (; _size != 0; --_size) {
				_alloc.destroy(_begin + _size - 1);
			}
		}
		// 2) Inserting value to the given position
			// a) Single Element
		iterator	insert( iterator position, const value_type& val ) {
			pointer		tmp;
			size_type	cap = _vcapcheck();
			size_type	dist = static_cast<size_type>(ft::distance(begin(), position));
			size_type	i = 0;

			if (position == end()) {
				push_back(val);
				return &back();
			}
			tmp = _pallocate(cap);
			for (size_type k = 0; i < _size; i++) {
				try {
					if (i == dist) {
						_alloc.construct(tmp + i, val);
						k = 1;
					}
					_alloc.construct(tmp + i + k, _begin[i]);
				}
				catch(...) {
					for (size_type j = 0; j < i + k; j++)
						_alloc.destroy(tmp + i + k);
					_alloc.deallocate(tmp, cap);
				}
			}
			_vdeallocate();
			_begin = tmp; _size = i + 1; _cap = cap;
			return iterator(_begin + dist);
		}
			// b) Fill
		void	insert (iterator position, size_type n, const value_type& val) {
			pointer		new_vec;
			size_type	new_cap = _vcapcheck();
			size_type	new_size = n + _size;
			size_type	pos = static_cast<size_type>(ft::distance(begin(), position));
			size_type	i = 0;

			if (new_size > new_cap)
				new_cap = new_size;
			new_vec = _pallocate(new_cap);
			for (size_type k = 0; i < new_size; i++) {
				try {
					if (i == pos) {
						for ( ; k < n; k++)
							_alloc.construct(new_vec + i + k, val);
					}
					if (i < _size)
						_alloc.construct(new_vec + i + k, *(_begin + i));
				}
				catch(...) {
					for (size_type j = 0; j < i + k; j++)
						_alloc.destroy(new_vec + i + k);
					_alloc.deallocate(new_vec, new_cap);
				}
			}
			_vdeallocate();
			_begin = new_vec; _size = new_size; _cap = new_cap;
		}
			// c) Range
		template <class Iterator>
		void insert (iterator position, Iterator first, Iterator last,
					typename ft::enable_if<!ft::is_integral<Iterator>::value, Iterator>::type * = NULL) {
			_insertrange(position, first, last,
						typename iterator_traits<Iterator>::iterator_category());
		}
		// 3) Removing element from given position
			// a) Single Element
		iterator	erase(iterator position) {
			iterator	last(_begin + _size - 1);

			try	{
				_vdestroy(&(*position));
				for (iterator	tmp = position; tmp != last; tmp++) {
					_alloc.construct(&(*tmp), *(tmp + 1));
					_alloc.destroy(&(*(tmp + 1)));
				}
			}
			catch(...) {
				_vdeallocate();
			}
			return position;
		}
			//b) Range 
		iterator	erase(iterator first, iterator last) {
			iterator	end(_begin + _size);

			if (first != last) {
				try	{
					for (iterator tmp = first; tmp != last; tmp++)
						_vdestroy(&(*tmp));
					for (iterator tmp = first; last != end; last++, tmp++) {
						_alloc.construct(&(*tmp), *last);
						_alloc.destroy(&(*last));
					}
				}
				catch(...) {
					_vdeallocate();
				}
			}
			return first;
		}
		// 4) Adds the last element of the container
		void push_back (const value_type& val) {
			reserve(_vcapcheck());
			try {
				_alloc.construct(_begin + _size, val);
			}
			catch(...) {
				_vdeallocate();
			}
			_size++;
		}
		// 5) Removes the last element of the container
		void	pop_back() {
			if (_size != 0) {
				_vdestroy(_begin + _size - 1);
			}
		}
		// 6) Resizes the container so that it contains n elements
		void	resize(size_type n, value_type val = value_type()) {
			if (n < _size) {
				while (_size != n)
					_vdestroy(_begin + _size - 1);
			}
			else if (n > _size) {
				reserve(n);
				for ( ; _size != n; _size++)
					_alloc.construct(_begin + _size, val);
			}
		}
		// 7) Swap values of the vector with given one;
		void	swap( vector& x ) {
			if (*this != x) {
				ft::swap(_begin, x._begin);
				ft::swap(_cap, x._cap);
				ft::swap(_size, x._size);
			}
		}

	// UTILS
	private:
		// 1) Vector allocation
		void	_vallocate(size_type n) {
			if (n > max_size())
				throw std::length_error("ft::vector");
			_begin = _alloc.allocate(n);
			_cap = n;
		}
		// 2) Vector deallocation
		void	_vdeallocate() {
			if (_begin != nullptr) {
				clear();
				_alloc.deallocate(_begin, _cap);
				_begin = nullptr;
				_cap = 0;
			}
		}
		// 3) Checks capacity to allocate
		size_type	_vcapcheck() {
			size_type	cap = _cap;

			if (_cap == 0)
				cap = 1;
			else if (_cap == _size)
				cap = _cap * 2;
			return (cap);
		}
		// 4) Allocates n memory and returns pointer to it
		pointer	_pallocate(size_type n) {
			if (n > max_size())
				throw std::length_error("ft::vector");
			return _alloc.allocate(n);
		}
		// 5) Destroys an element from this vector
		void	_vdestroy(pointer element) {
			_alloc.destroy(element);
			_size--;
		}
		// 6) Assigning 
			// for random_access_iterator
		template <class InputIterator>
		void	_assignrange(InputIterator first, InputIterator last, random_access_iterator_tag) {
			size_type	count = ft::distance(first, last);

			clear();
			if (count > _cap) {
				if (_cap > 0)
					_alloc.deallocate(_begin, _cap);
				_vallocate(count);
			}
			for ( ; first != last; first++, _size++) {
				try {
					_alloc.construct(_begin + _size, *first);
				}
				catch(...) {
					_vdeallocate();
				}
			}
		}
			// for Input Iterator tag
		template <class InputIterator>
		void	_assignrange(InputIterator first, InputIterator last, input_iterator_tag) {
			clear();
			for ( ; first != last; first++)
				push_back(*first);
		}
		// 7) Insert Range
			// for random_access_iterator 
		template <class Iterator>
		void _insertrange (iterator position, Iterator first, Iterator last, random_access_iterator_tag) {
			pointer		new_vec;
			size_type	new_cap = _vcapcheck();
			size_type	pos = static_cast<size_type>(ft::distance(begin(), position));
			size_type	dist = static_cast<size_type>(ft::distance(first, last));
			size_type	new_size = dist + _size;
			size_type	i = 0;

			if (new_size > new_cap)
				new_cap = new_size;
			new_vec = _pallocate(new_cap);
			try {
				for (size_type j = 0; i < new_size; i++, j++) {
					if (i == pos) {
						for (; first != last; first++, i++)
							_alloc.construct(new_vec + i, *first);
					}
					if (j < _size)
						_alloc.construct(new_vec + i, *(_begin + j));
				}
			}
			catch (...) {
				for (; i != 0; i--)
					_alloc.destroy(new_vec + i - 1);
				_alloc.deallocate(new_vec, new_cap);
			}
			_vdeallocate();
			_begin = new_vec; _size = new_size; _cap = new_cap;
		}
			// for input_iterator_tag 
		template <class Iterator>
		void _insertrange (iterator position, Iterator first, Iterator last, input_iterator_tag) {
			for (; first != last; ++first, position++)
				position = insert(position, *first);
		}
	}; // vector

	// SWAP (vectors)
	template <class T, class Alloc> 
	void	swap(vector<T,Alloc>& x, vector<T,Alloc>& y) {
		x.swap(y);
	}

	// RELATIONAL OPERATORS (vectors)
	template <class T, class Alloc>
	bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return lhs.size() == rhs.size() &&ft::equal(lhs.begin(), lhs.end(), rhs.begin());		
	}
	template <class T, class Alloc>
	bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	template <class T, class Alloc>
	bool	operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { 
		return rhs < lhs;
	}
	template <class T, class Alloc>
	bool	operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !(lhs == rhs);
	}
	template <class T, class Alloc>
	bool	operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !(rhs < lhs);
	}
	template <class T, class Alloc>
	bool	operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !(lhs < rhs);
	}
} // ft

#endif