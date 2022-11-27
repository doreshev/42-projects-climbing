/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:03:41 by doreshev          #+#    #+#             */
/*   Updated: 2022/10/28 19:29:09 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft {
	template<class T, class Container = ft::vector<T> >
	class stack	{
		public:
			typedef	T									value_type;
			typedef Container							container_type;
			typedef	typename Container::size_type		size_type;
			typedef typename Container::const_reference	const_reference;
			typedef typename Container::reference		reference;

			template< class T1, class T2 >
			friend bool	operator==( const ft::stack<T1,T2>& lhs, const ft::stack<T1,T2>& rhs );
			template< class T1, class T2 >
			friend bool	operator!=( const ft::stack<T1,T2>& lhs, const ft::stack<T1,T2>& rhs );
			template< class T1, class T2 >
			friend bool	operator>( const ft::stack<T1,T2>& lhs, const ft::stack<T1,T2>& rhs );
			template< class T1, class T2 >
			friend bool	operator>=( const ft::stack<T1,T2>& lhs, const ft::stack<T1,T2>& rhs );
			template< class T1, class T2 >
			friend bool	operator<=( const ft::stack<T1,T2>& lhs, const ft::stack<T1,T2>& rhs );
			template< class T1, class T2 >
			friend bool	operator<( const ft::stack<T1,T2>& lhs, const ft::stack<T1,T2>& rhs );

		protected:
			Container	c;

		public:
			explicit stack(const container_type& ctnr = container_type()) : c(ctnr) { }
			~stack() { }

			stack& operator=( const stack& other ) { this->c = other.c; return (*this); }

			bool				empty()	const 				{ return (this->c.empty()); }
			size_type			size()	const 				{ return (this->c.size()); }
			value_type&			top() 						{ return (this->c.back()); }
			const value_type&	top()	const				{ return (this->c.back()); }
			void				push(const value_type& val)	{ return (this->c.push_back(val)); }
			void				pop()						{ return (this->c.pop_back()); }
	};

	template< class T, class Container >
	bool	operator==( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) {
		return (lhs.c == rhs.c);
	}

	template< class T, class Container >
	bool	operator!=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) {
		return (lhs.c != rhs.c);
	}

	template< class T, class Container >
	bool	operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) { 
		return (lhs.c < rhs.c);
	}

	template< class T, class Container >
	bool	operator<=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) { 
		return (lhs.c <= rhs.c);
	}

	template< class T, class Container >
	bool	operator>( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) { 
		return (lhs.c > rhs.c);
	}

	template< class T, class Container >
	bool	operator>=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) { 
		return (lhs.c >= rhs.c);
	}
}

#endif