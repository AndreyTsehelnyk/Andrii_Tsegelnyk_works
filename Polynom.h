#ifndef _POLYNOM_H_
#define _POLYNOM_H_


class Polynom {
	size_t n;
	double* p;

public:
	Polynom() { n = 0; }
	Polynom(size_t n);

	Polynom(size_t n, double* arr); // P(2,1.0,1.0);

	~Polynom();

	Polynom& operator=(const Polynom& a);

	Polynom(const Polynom& p);

	int set(size_t k, double a); //P.set(1,2.0) -> p[1] = 2.0

	double get(size_t k);

	void show();

	friend int saveFile(const char* fname, const Polynom& P);
	friend int readFile(const char* fname, Polynom& P);
};

#endif //_POLYNOM_H_