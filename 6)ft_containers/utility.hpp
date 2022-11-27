/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:04:46 by doreshev          #+#    #+#             */
/*   Updated: 2022/10/31 12:18:23 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
# define UTILITY_HPP

namespace ft{
	template <class T1, class T2>
	struct pair {
		public:
			typedef	T1		first_type;
			typedef	T2		second_type;

			////MEMBERS
			first_type		first;
			second_type		second;

			////CONSTRUCTORS

			//1)default
			pair() : first(), second() { }

			//2)copy
			template<class U, class V>
			pair( const pair<U,V>& pr ) : first( pr.first ), second( pr.second ) { }

			//3)initialization
			pair( const first_type& a, const second_type& b ) : first( a ), second( b ) { }
			
			////COPY ASSIGNMENT OPERATOR
			pair& operator=( const pair& pr ) {
				this->first = pr.first;
				this->second = pr.second;
				return(*this);
			}
	};
	
	////MAKEPAIR
	template <class T1,class T2>
  	pair<T1,T2> make_pair( T1 x, T2 y )
  	{ return ( pair<T1,T2>(x,y) ); }

	////RELATIONAL OPERATORS
	template <class T1, class T2>
	bool operator==( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{ return lhs.first == rhs.first && lhs.second == rhs.second; }
	
	template <class T1, class T2>
	bool operator!=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{ return !(lhs == rhs); }
	
	template <class T1, class T2>
	bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second); }
	
	template <class T1, class T2>
	bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(rhs < lhs); }
	
	template <class T1, class T2>
	bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return rhs < lhs; }
	
	template <class T1, class T2>
	bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs < rhs); }
}

#endif