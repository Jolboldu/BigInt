#include <iosfwd>
#include <vector>
#include <algorithm>

#include <string>
#include <istream>
#include <cmath>
#include <stdexcept>
#include <iostream>

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

using namespace std;

BigInt::BigInt(string n)
	:isNeg(false)
	{
		if(!isdigit(n[0])){
			if(n[0] == '-'){
				isNeg = true;
				n.erase(n.begin());	
			}else if(n[0] != '+') throw runtime_error("invalid arg");
		}

		for(auto e : n){
			if(!isdigit(e)) throw runtime_error("invalid arg");
			e = e - '0';
			Numbers.push_back(e); 
		}
		Numbers = filter(Numbers);
}

BigInt::BigInt(int n)
	:BigInt(to_string(n)){}
		


BigInt::BigInt(std::vector<int> v)
	:isNeg(false)
	{
		Numbers = filter(v);
	}

BigInt::BigInt(std::vector<int> v, bool isMinus)
	:isNeg(false)
	{
		isNeg = isMinus;
		Numbers = filter(v);
		if(Numbers.size() == 1 and Numbers[0] == 0) isNeg = false;
		
	}

ostream& operator<<(ostream& out, const BigInt& big){
	vector<int> v = big.numbers();
	string sint;
	if(big.isNegative()){
		sint+='-';
	}
	for(auto e : v){
		sint+=to_string(e);
	}
	return out << sint;
}


std::istream& operator>>(std::istream& in, BigInt& big){
	string number;
	in >> number;
	big = BigInt(number);
	return in;
}


BigInt add(const BigInt& first, const BigInt& second){
	vector<int> result;
	vector<int> big1 = first.numbers();
	vector<int> big2 = second.numbers();
	if(big2.size() > big1.size()){
		vector<int> temp = big1;
		big1 = big2;
		big2 = temp;
	}
	int sum = 0;
	for(int i = big1.size()-1; i >= 0; i--){
		if(i >= big1.size()-big2.size()){
			sum += big1[i] + big2[i-(big1.size()-big2.size())];
			if(sum >= 10){
				result.push_back(sum-10);
				sum = 1;
			}else{
				result.push_back(sum);
				sum = 0;
			}
		}else{
			sum+=big1[i];
			if(sum >= 10){
				result.push_back(sum-10);
				sum = 1;
			}else{
				result.push_back(sum);
				sum = 0;
			}
		}
	}
	if(sum == 1) result.push_back(sum);
	reverse(result.begin(),result.end());
	
	if(first.isNegative() and second.isNegative()) return BigInt(result, true);
	if(first.isNegative() and  !second.isNegative()) return BigInt(result, true);

	return BigInt(result);
}
BigInt sub(const BigInt& first, const BigInt& second){
	bool isSwapped = false;
	vector<int> result;
	vector<int> big1 = first.numbers();
	vector<int> big2 = second.numbers();
	
	if(absGreater(second,first)){
		vector<int> temp = big1;
		big1 = big2;
		big2 = temp;
		isSwapped = true;
	}
	
	int dif = 0;
	for(int i = big1.size()-1; i >= 0; i--){
		if(i >= big1.size()-big2.size()){
			dif += big1[i] - big2[i-(big1.size()-big2.size())];
			if(dif < 0){
				result.push_back(dif+10);
				dif = -1;
			}else{
				result.push_back(dif);
				dif = 0;
			}
		}else{
			dif+=big1[i];
			if(dif < 0){
				result.push_back(dif+10);
				dif = -1;
			}else{
				result.push_back(dif);
				dif = 0;
			}
		}
	}
	reverse(result.begin(),result.end());
	if(first.isNegative() == second.isNegative()){
		if(first.isNegative() == false and second.isNegative() == false){
			if(isSwapped) return BigInt(result, true);
			else return BigInt(result, false);
		}else{
			if(isSwapped) return BigInt(result, false);
			else return BigInt(result, true);
		}

	}

	if(isSwapped) return BigInt(result,second.isNegative());
	else return BigInt(result, first.isNegative());

	
	return BigInt(result);
}

BigInt operator+(const BigInt& first, const BigInt& second){
	BigInt sum;
	if(first.isNegative() == second.isNegative()){
		sum = add(first,second);
	}else{
		sum = sub(first, second);
	}

	return sum;

}

BigInt operator-(const BigInt& first, const BigInt& second){
	BigInt dif;
	if(first.isNegative() != second.isNegative()){
		dif = add(first,second);
	}else{
		dif = sub(first, second);
	}
	return dif;
}
vector<int> multipleOfInt(const BigInt& first, const BigInt& second){
	vector<int> big = first.numbers();
	vector<int> small = second.numbers();

	reverse(small.begin(),small.end());	
	int sum = ParseVecInt(small);
	reverse(big.begin(), big.end());
	int carry = 0;
	for (int i = 0; i < big.size() || carry; ++i) {
		if (i == big.size()){
			big.push_back (0);
		}
		int cur = carry + (big[i] * sum);
		big[i] = cur % 10;
		carry = cur / 10;
	}
	reverse(big.begin(), big.end());
	return big;

}
vector<int> divisionOfInt(const BigInt& first, const BigInt& second){
	vector<int> big = first.numbers();
	vector<int> small = second.numbers();
	reverse(small.begin(),small.end());	
	int number = ParseVecInt(small);
	reverse(big.begin(), big.end());

	int carry = 0;
	for (int i = big.size()-1; i >= 0; --i) {
		int cur = big[i] + carry * 10;
		big[i] = cur / number;
		carry = cur % number;
	}
	reverse(big.begin(), big.end());
	return big;
}
BigInt operator*(const BigInt& first, const BigInt& second){
	vector<int> result;
	if(first.numbers().size() <= 9) result =  multipleOfInt(second,first);
	else if(second.numbers().size() <= 9) result = multipleOfInt(first,second);
	else{
		vector<int> a = first.numbers();
		vector<int> b = second.numbers();
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		
		vector<int> c (a.size()+b.size());
		for (int i = 0; i < a.size(); ++i){
			for (int j = 0, carry = 0; j < b.size() || carry; ++j) {
				int cur = c[i+j] + a[i] * (j < b.size() ? b[j] : 0) + carry;
				c[i+j] = cur % 10;
				carry = cur / 10;
			}
		}
		reverse(c.begin(),c.end());	
		result = c;
	}
	if(first.isNegative() != second.isNegative()) return BigInt(result, true);
	return BigInt(result);
}



BigInt operator/(const BigInt& first, const BigInt& second){
	vector<int> result;
	if(second == BigInt()) throw runtime_error("division by zero");
	else{
		if(second.numbers().size() <= 9) result = divisionOfInt(first,second);
	}
	
	if(first.isNegative() != second.isNegative()) return BigInt(result, true);
	return BigInt(result);
}
BigInt operator%(const BigInt& first, const BigInt& second){
	if(second == BigInt()) throw runtime_error("division by zero");
	else{
		BigInt div = first / second;
		BigInt multi = second * div;
		return first - multi;
	}
}

void operator*=(BigInt& first, const BigInt& second){
	BigInt multi = first * second;
	first = multi;
}

void operator/=(BigInt& first, const BigInt& second){
	BigInt div = first / second;
	first = div;
}

void operator+=(BigInt& first, const BigInt& second){
	BigInt sum = first + second;
	first = sum;
}

void operator-=(BigInt& first, const BigInt& second){
	BigInt dif = first - second;
	first = dif;
}

void operator%=(BigInt& first, const BigInt& second){
	BigInt rem = first % second;
	first = rem;
}

bool operator==(const BigInt& first, const BigInt& second){
	bool isEqual = true;
	if(first.isNegative() != second.isNegative()){
		isEqual = false;
	}else{
		vector<int> big1 = first.numbers();
		vector<int> big2 = second.numbers();
		if(big1.size() == big2.size()){
			for(int i = 0; i < big1.size(); i++){
				if(big1[i]!=big2[i]){
					isEqual = false;
				}
			}
		}else{
			isEqual = false;
		}	
	}
	
	return isEqual;
}

bool operator!=(const BigInt& first, const BigInt& second){
	return not (first==second);
}

bool absGreater(const BigInt& first, const BigInt& second){
	vector<int> big1 = first.numbers();
	vector<int> big2 = second.numbers();
	if(big1.size() > big2.size()) return true;
	else if(big1.size() < big2.size()) return false;
	else{
		return big1 > big2;
	}

	return false;
}

bool operator>(const BigInt& first, const BigInt& second){
	if(first.isNegative() and second.isNegative() == false){
		return false;
	}else if(first.isNegative() == false and second.isNegative()){
		return true;
	}else{
		if(first.isNegative() and second.isNegative()){
			return absGreater(second, first); 
		}else{
			return absGreater(first, second);
		}
	} 
	return false;
}
bool operator<(const BigInt& first, const BigInt& second){
	return second > first;
}

bool operator>=(const BigInt& first, const BigInt& second){
	return not (second > first);
}

bool operator<=(const BigInt& first, const BigInt& second){
	return not (second < first);
}

BigInt operator++(BigInt& big){
	big += 1;
	return big;
}

BigInt operator--(BigInt& big){
	big -= 1;
	return big;
}	

BigInt operator++(BigInt& first, int){
	BigInt old = first;
	first += 1;
	return old;
}

BigInt operator--(BigInt& first, int){
	BigInt old = first;
	first -= 1;
	return old;
}

int ParseVecInt(vector<int> v){
	int sum = 0;
	for(int i = 0; i < v.size(); i++){
		sum += (v[i] * pow(10,i));
	}
	return sum;
}
	
vector<int> filter(vector<int> v){
	vector<int> result;
	int i = 0;
	while(v[i] == 0  and i != v.size()-1){
		i++;
	}
	while(i < v.size()){
		result.push_back(v[i]);
		i++;
	}
	return result;
}
int main(){
	BigInt big; cin >> big;
	int i = 1;
	while(i*i <= big){
		i++;
	}
	cout << --i;
	return 0;
}