#ifndef BIGINT_H
#define BIGINT_H

#include <iosfwd>
#include <vector>
#include <algorithm>

class BigInt{
	friend std::istream& operator>>(std::istream& in, BigInt& big);

	public:
	BigInt()
	:isNeg(false)
	{
		Numbers.push_back(0);
	}

	BigInt(std::string n);

	BigInt(int n);

	BigInt(std::vector<int> v);

	BigInt(std::vector<int> v, bool isMinus);


	std::vector<int> numbers() const{
		return Numbers;
	}
	bool isNegative() const{
		return isNeg;
	}
	void setNeg(bool change){
		isNeg = change;
	}
	private:
	bool isNeg;
	std::vector<int> Numbers;	

};
	
	std::ostream& operator<<(std::ostream& out, const BigInt& big);
	std::istream& operator>>(std::istream& in, BigInt& big);

	bool operator==(const BigInt& first, const BigInt& second);
	bool operator!=(const BigInt& first, const BigInt& second);
	bool operator>(const BigInt& first, const BigInt& second);
	bool operator<(const BigInt& first, const BigInt& second);
	bool operator>=(const BigInt& first, const BigInt& second);
	bool operator<=(const BigInt& first, const BigInt& second);
	bool absGreater(const BigInt& first, const BigInt& second);

	std::vector<int>  filter(std::vector<int> v);	

	BigInt operator+(const BigInt& first, const BigInt& second);
	BigInt operator-(const BigInt& first, const BigInt& second);
	BigInt operator*(const BigInt& first, const BigInt& second);
	BigInt operator/(const BigInt& first, const BigInt& second);
	BigInt operator%(const BigInt& first, const BigInt& second);
	
	std::vector<int> multipleOfInt(const BigInt& first, const BigInt& second);
	std::vector<int> divisionOfInt(const BigInt& first, const BigInt& second);
	int ParseVecInt(std::vector<int> v);	

	std::vector<int> filter(std::vector<int> v);	
	
	inline
	BigInt abs(const BigInt& first){
		std::vector<int> result = first.numbers();
		return (result,false);
	}

	
	void operator+=(BigInt& first, const BigInt& second);
	void operator-=(BigInt& first, const BigInt& second);
	void operator*=(BigInt& first, const BigInt& second);
	void operator/=(BigInt& first, const BigInt& second);
	void operator%=(BigInt& first, const BigInt& second);
	BigInt operator++(BigInt& first, int);
	BigInt operator--(BigInt& first, int);

	
	BigInt operator++(BigInt& big);

	
	BigInt operator--(BigInt& big);

	inline
	BigInt operator+(const BigInt& big){
		return big;
	}

	inline
	void operator-(BigInt& big){
		if(big.isNegative() == false) big.setNeg(true);
		else big.setNeg(false);
	}

	

	BigInt add(const BigInt& big1, const BigInt& big2);
	BigInt sub(const BigInt& big1, const BigInt& big2);

	



#endif
