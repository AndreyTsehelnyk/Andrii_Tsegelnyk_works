#pragma once
#include <iostream>
#include <fstream>
#include <initializer_list>
#include <list>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <type_traits>

template <class T>
class Poly {
private:
	std::list<T> coeffs;
public:
	Poly();
	Poly(const std::initializer_list<T>& lst);

	unsigned get_order() const;

	void output();

	Poly<T> operator+(const Poly<T>& right);
	Poly<T> operator-(const Poly<T>& right);
	Poly<T> operator*(const Poly<T>& right);
};

template<class T>
inline Poly<T>::Poly() {
	coeffs.push_back(0);
}

template<class T>
inline Poly<T>::Poly(const std::initializer_list<T>& lst) {
	std::copy(lst.begin(), lst.end(), std::back_insert_iterator<std::list<T>>(coeffs));
}

template<class T>
inline unsigned Poly<T>::get_order() const {
	return coeffs.size() - 1;
}

template<class T>
inline Poly<T> Poly<T>::operator+(const Poly<T>& right) {
	if (coeffs.size() < right.coeffs.size()) {
		Poly<T> poly = right;
		typename std::list<T>::reverse_iterator it = poly.coeffs.rbegin();
		typename std::list<T>::reverse_iterator it2 = coeffs.rbegin();

		for (; it2 != coeffs.rend(); it++, it2++)
			*it += *it2;

		return poly;
	}

	Poly<T> poly = *this;
	typename std::list<T>::reverse_iterator it = poly.coeffs.rbegin();
	typename std::list<T>::const_reverse_iterator it2 = right.coeffs.rbegin();

	for (; it2 != right.coeffs.rend(); it++, it2++)
		*it += *it2;

	return poly;
}

template<class T>
inline Poly<T> Poly<T>::operator-(const Poly<T>& right) {
	if (coeffs.size() < right.coeffs.size()) {
		Poly<T> poly = right;
		typename std::list<T>::reverse_iterator it = poly.coeffs.rbegin();
		typename std::list<T>::reverse_iterator it2 = coeffs.rbegin();

		for (; it2 != coeffs.rend(); it++, it2++)
			*it -= *it2;

		return poly;
	}

	Poly<T> poly = *this;
	typename std::list<T>::reverse_iterator it = poly.coeffs.rbegin();
	typename std::list<T>::const_reverse_iterator it2 = right.coeffs.rbegin();

	for (; it2 != right.coeffs.rend(); it++, it2++)
		*it -= *it2;

	return poly;
}

template<class T>
inline Poly<T> Poly<T>::operator*(const Poly<T>& right) {
	std::vector<T> a(coeffs.cbegin(), coeffs.cend()), b(right.coeffs.cbegin(), right.coeffs.cend());
	std::vector<T> mult(get_order() + right.get_order() + 1);
	size_t i, j;

	for (i = 0; i < coeffs.size(); i++) {
		for (j = 0; j < right.coeffs.size(); j++)
			mult[i + j] += a[i] * b[j];
	}

	Poly poly;
	poly.coeffs = std::list<T>(mult.cbegin(), mult.cend());

	return poly;
}

template <class T>
void Poly<T>::output() {
	size_t i = 0;

	for (auto& x : coeffs) {
		std::cout << x << "*x^" << i;

		++i;

		if (i < coeffs.size()) std::cout << " + ";
	}

	std::cout << "\n";
}