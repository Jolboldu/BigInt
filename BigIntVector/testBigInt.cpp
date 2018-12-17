#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <sstream>
#include "BigInt.h"
#include <cstdlib>
#include <ctime>
using namespace std;

TEST_CASE ("Check of constructors (BigInt)", "[constr]"){
	ostringstream sout;
	SECTION("constructor with no arg"){
		sout << BigInt();
		REQUIRE(sout.str() == "0");
	}
	SECTION("constructor with string arg"){
		SECTION("with regular BigInt"){
			sout << BigInt("556657777899445544411111145");
			REQUIRE(sout.str() == "556657777899445544411111145");
		}
		SECTION("with negative value"){
			sout << BigInt("-545457211112233636440001520");
			REQUIRE(sout.str() == "-545457211112233636440001520");
		}
	}
	SECTION("constructor with vector arg"){
		vector<int> v;
		for(int i = 1; i <= 10; i++){
			v.push_back(i);
		}
		sout << BigInt(v);
		REQUIRE(sout.str() == "12345678910");
	}
	SECTION("constructor with int arg"){
		for(int i = 0 ; i < 1000;i++){
			int x = rand()%1000000+1;
			int y = rand()%1000000+1;
			int sum = x + y;
			CHECK(BigInt(x) + BigInt(y) == BigInt(sum)); 	
		}
	}

}

TEST_CASE("Check of plus", "[plus]"){
	REQUIRE (BigInt("1234") + BigInt("72") == BigInt("1306"));
	REQUIRE (BigInt("4567851") + BigInt("2357894") == BigInt("6925745"));
	REQUIRE (BigInt("56545152354") + BigInt("15235478") == BigInt("56560387832"));
	REQUIRE (BigInt("131234") + BigInt("356332553213") == BigInt("356332684447"));
	REQUIRE (BigInt("684279250") + BigInt("987654321") == BigInt("1671933571"));
	REQUIRE (BigInt("-63") + BigInt("-9") == BigInt("-72"));
	srand(time(0));
	for(int i = 0 ; i < 1000;i++){
		int x = rand()%1000000+1;
		int y = rand()%1000000+1;
		int sum = x + y;
		CHECK(BigInt(to_string(x)) + BigInt(to_string(y)) == BigInt(to_string(sum))); 	
	}

	for(int i = 0; i < 1000; i++){
		int x = rand()%100000-100000;
		int y = rand()%100000-100000;
		int sum = x + y;
		CHECK(BigInt(to_string(x)) + BigInt(to_string(y)) == BigInt(to_string(sum))); 	
	}

	for(int i = 0; i < 1000; i++){
		int x = rand()%100000+1;
		int y = rand()%100000-100000;
		int sum = x + y;
		CHECK(BigInt(to_string(x)) + BigInt(to_string(y)) == BigInt(to_string(sum))); 	
	}

	for(int i = 0; i < 1000; i++){
		int x = rand()%100000-100000;
		int y = rand()%100000+1;
		int sum = x + y;
		CHECK(BigInt(to_string(x)) + BigInt(to_string(y)) == BigInt(to_string(sum))); 	
	}
	REQUIRE (BigInt("-17") + BigInt("-32") == BigInt("-49"));
	REQUIRE (BigInt("-17") + BigInt("32") == BigInt("15"));
	REQUIRE (BigInt("49") + BigInt("-6") == BigInt("43"));
	REQUIRE (BigInt("-56") + BigInt("-7") == BigInt("-63"));
	REQUIRE (BigInt("-105") + BigInt("5") == BigInt("-100"));
	REQUIRE (BigInt("6") + BigInt("-32") == BigInt("-26"));
}
TEST_CASE("Check of assignment addition", "[asadd]"){
	SECTION("both positive"){
		BigInt big1 = BigInt("68");
		BigInt big2 = BigInt("58");
		big1+=big2;
		REQUIRE (BigInt("68") + BigInt("58") == big1);
	}
	SECTION("first positive"){
		BigInt big1 = BigInt("68");
		BigInt big2 = BigInt("-55");
		big1+=big2;
		REQUIRE (BigInt("68") + BigInt("-55") == big1);
	}
	
	SECTION("second positive"){
		BigInt big1 = BigInt("-36");
		BigInt big2 = BigInt("64");
		big1+=big2;
		REQUIRE (BigInt("-36") + BigInt("64") == big1);
	}
	
	SECTION("both negative"){
		BigInt big1 = BigInt("-69");
		BigInt big2 = BigInt("-13");
		big1+=big2;
		REQUIRE (BigInt("-69") + BigInt("-13") == big1);
	}
}

TEST_CASE("Check of assignment subtraction", "[assub]"){
	SECTION("both positive"){
		BigInt big1 = BigInt("68");
		BigInt big2 = BigInt("58");
		big1-=big2;
		REQUIRE (BigInt("68") - BigInt("58") == big1);
	}
	SECTION("first positive"){
		BigInt big1 = BigInt("68");
		BigInt big2 = BigInt("-55");
		big1-=big2;
		REQUIRE (BigInt("68") - BigInt("-55") == big1);
	}
	
	SECTION("second positive"){
		BigInt big1 = BigInt("-36");
		BigInt big2 = BigInt("64");
		big1-=big2;
		REQUIRE (BigInt("-36") - BigInt("64") == big1);
	}
	
	SECTION("both negative"){
		BigInt big1 = BigInt("-69");
		BigInt big2 = BigInt("-13");
		big1-=big2;
		REQUIRE (BigInt("-69") - BigInt("-13") == big1);
	}
}

TEST_CASE("Check of assignment multiplication", "[asmul]"){
	SECTION("both positive"){
		BigInt big1 = BigInt("68");
		BigInt big2 = BigInt("58");
		big1*=big2;
		REQUIRE (BigInt("68") *BigInt("58") == big1);
	}
	SECTION("first positive"){
		BigInt big1 = BigInt("68");
		BigInt big2 = BigInt("-55");
		big1*=big2;
		REQUIRE (BigInt("68") * BigInt("-55") == big1);
	}
	
	SECTION("second positive"){
		BigInt big1 = BigInt("-36");
		BigInt big2 = BigInt("64");
		big1*=big2;
		REQUIRE (BigInt("-36") * BigInt("64") == big1);
	}
	
	SECTION("both negative"){
		BigInt big1 = BigInt("-69");
		BigInt big2 = BigInt("-13");
		big1*=big2;
		REQUIRE (BigInt("-69") * BigInt("-13") == big1);
	}
}

TEST_CASE("Check of assignment division", "[asdiv]"){
	SECTION("both positive"){
		BigInt big1 = BigInt("6874");
		BigInt big2 = BigInt("589");
		big1/=big2;
		REQUIRE (BigInt("6874") / BigInt("589") == big1);
	}
	SECTION("first positive"){
		BigInt big1 = BigInt("56475");
		BigInt big2 = BigInt("-6845");
		big1/=big2;
		REQUIRE (BigInt("56475") / BigInt("-6845") == big1);
	}
	
	SECTION("second positive"){
		BigInt big1 = BigInt("-368324");
		BigInt big2 = BigInt("65454");
		big1/=big2;
		REQUIRE (BigInt("-368324") / BigInt("65454") == big1);
	}
	
	SECTION("both negative"){
		BigInt big1 = BigInt("-64815");
		BigInt big2 = BigInt("-1523");
		big1/=big2;
		REQUIRE (BigInt("-64815") / BigInt("-1523") == big1);
	}
}
TEST_CASE("Check of minus", "[minus]"){
	srand(time(0));
	for(int i = 0; i < 1000; i++){
		int x = rand()%100000+1;
		int y = rand()%100000-100000;
		int dif = x - y;
		CHECK(BigInt(to_string(x)) - BigInt(to_string(y)) == BigInt(to_string(dif))); 	
	}

	for(int i = 0; i < 1000; i++){
		int x = rand()%100000-100000;
		int y = rand()%100000+1;
		int dif = x - y;
		CHECK(BigInt(to_string(x)) - BigInt(to_string(y)) == BigInt(to_string(dif))); 	
	}

	for(int i = 0; i < 10000; i++){
		int x = rand()%100000-100000;
		int y = rand()%100000-100000;
		int dif = x - y;
		CHECK(BigInt(to_string(x)) - BigInt(to_string(y)) == BigInt(to_string(dif))); 	
	}

	for(int i = 0; i < 10000; i++){
		int x = rand()%100000+1;
		int y = rand()%100000+1;
		int dif = x - y;
		CHECK(BigInt(to_string(x)) - BigInt(to_string(y)) == BigInt(to_string(dif))); 	
	}

	REQUIRE (BigInt("-96547") - BigInt("51354") == BigInt("-147901"));
	REQUIRE (BigInt("65610") - BigInt("-5986745") == BigInt("6052355"));
	REQUIRE (BigInt("-568") - BigInt("-568") == BigInt("0"));

}

TEST_CASE("test unary", "[unary]"){
	SECTION("unary plus and "){
		BigInt big = BigInt("5684");
		-big;
		REQUIRE(big == BigInt("-5684"));
		big = BigInt("-123456789");
		-big;
		REQUIRE(big == BigInt("123456789"));
		big = BigInt("789");
		+big;
		REQUIRE(big == BigInt("789"));
		big = BigInt("-321");
		+big;
		REQUIRE(big == BigInt("-321"));	
	}

}
TEST_CASE("Check equality and inequality","[eq]"){
	SECTION("equality 1"){
		REQUIRE(BigInt("-123456789") != BigInt("123456789"));
	}

	SECTION("inequality"){
		REQUIRE(BigInt("1223456789") == BigInt("1223456789"));
	}

	SECTION("inequality"){
		REQUIRE(BigInt("123456788") != BigInt("123456789"));
	}
	SECTION("inequality"){
		REQUIRE(BigInt("012345678") != BigInt("123456789"));
	}
}

TEST_CASE("Check negative","[negative]"){
	SECTION("negative 1"){
		REQUIRE(BigInt("123456789").isNegative() == false);
	}

	SECTION("negative 2"){
		REQUIRE(BigInt("-123456789").isNegative() == true);
	}

	SECTION("negative 3"){
		REQUIRE(BigInt("2432412").isNegative() == false);
	}

}
TEST_CASE("Check multiply","[mult]"){
	srand(time(0));
	for(int i = 0; i < 1000; i++){
			int first_size = rand()%200+1;
			int second_size = rand()%9999+1;
			int64_t max = pow(10,first_size);
			int64_t x = rand()% max +1;
			max = pow(10,second_size);
			int64_t y = rand()% max+1;

			int64_t m = x * y;
			CHECK(BigInt(to_string(x)) * BigInt(to_string(y)) == BigInt(to_string(m)));
	}

	for(int i = 0; i < 1000; i++){
			int first_size = rand()%200+1;
			int second_size = rand()%9999+1;
			int64_t max = pow(10,first_size);
			int64_t x = rand()% max +1;
			max = pow(10,second_size);
			int64_t y = rand()% max+1;

			int64_t m = x * y;
			CHECK(BigInt(to_string(x)) * BigInt(to_string(y)) == BigInt(to_string(m)));
	}

	for(int i = 0; i < 1000; i++){
			int first_size = rand()%200+1;
			int second_size = rand()%9999+1;
			int64_t max = pow(10,first_size);
			int64_t x = rand()% max +1;
			max = pow(10,second_size);
			int64_t y = rand()% max+1;

			int64_t m = x * y;
			CHECK(BigInt(to_string(x)) * BigInt(to_string(y)) == BigInt(to_string(m)));
	}
	for(int i = 0; i < 1000; i++){
			int first_size = rand()%200+1;
			int second_size = rand()%9999+1;
			int64_t max = pow(10,first_size);
			int64_t x = rand()% max +1;
			max = pow(10,second_size);
			int64_t y = rand()% max+1;

			int64_t m = x * y;
			CHECK(BigInt(to_string(x)) * BigInt(to_string(y)) == BigInt(to_string(m)));
	}

}
TEST_CASE("Check multi by int","[mulint]"){
	srand(time(0));
	for(int i = 0; i < 1000; i++){
			int x = rand()%10000+1;
			int y = rand()%10000+1;
			int m = x * y;
			BigInt first = BigInt(to_string(x));
			BigInt second = BigInt(to_string(y));
			BigInt multi = BigInt(multipleOfInt(x,y));
			CHECK( multi  == BigInt(to_string(m)));
	}

	for(int i = 0; i < 1000; i++){
			int x = rand()%10000-10000;
			int y = rand()%10000-10000	;
			int m = x * y;
			
			BigInt first = BigInt(to_string(x));
			BigInt second = BigInt(to_string(y));
			BigInt multi = BigInt(multipleOfInt(x,y));
			CHECK( multi  == BigInt(to_string(m)));
	}
}
TEST_CASE("Check division","[div]"){
	SECTION("just div"){

		REQUIRE(BigInt("156687456842") / BigInt("6987") == BigInt("22425569"));
		REQUIRE(BigInt("0") / BigInt("6987") == BigInt("0"));
	}
	SECTION("remainder"){
		SECTION("both positives"){
			REQUIRE(BigInt("156687") % BigInt("156687") == BigInt(to_string(156687 % 156687)));
			REQUIRE(BigInt("156687456842") % BigInt("6987") == BigInt(to_string(156687456842 % 6987)));
			REQUIRE(BigInt("0") % BigInt("57") == BigInt(to_string(0 % 56)));
			REQUIRE(BigInt("56") % BigInt("57") == BigInt(to_string(56 % 57)));

			BigInt big = BigInt("568746");;
			big %= BigInt("578");
			REQUIRE(big == BigInt(to_string(568746 % 578)));
		}

		SECTION("first is negative"){
			REQUIRE(BigInt("-156687") % BigInt("156687") == BigInt(to_string(-156687 % 156687)));
			REQUIRE(BigInt("-156687456842") % BigInt("6987") == BigInt(to_string(-156687456842 % 6987)));
			REQUIRE(BigInt("0") % BigInt("57") == BigInt(to_string(0 % 56)));
			REQUIRE(BigInt("-56") % BigInt("57") == BigInt(to_string(-56 % 57)));

			BigInt big = BigInt("-568746");;
			big %= BigInt("578");
			REQUIRE(big == BigInt(to_string(-568746 % 578)));
		}

		SECTION("second is negative"){
			REQUIRE(BigInt("156687") % BigInt("-156687") == BigInt(to_string(156687 % -156687)));
			REQUIRE(BigInt("156687456842") % BigInt("-6987") == BigInt(to_string(156687456842 % -6987)));
			REQUIRE(BigInt("0") % BigInt("-57") == BigInt(to_string(0 % -56)));
			REQUIRE(BigInt("56") % BigInt("-57") == BigInt(to_string(56 % -57)));

			BigInt big = BigInt("568746");;
			big %= BigInt("-578");
			REQUIRE(big == BigInt(to_string(568746 % -578)));
		}

		SECTION("both negative"){
			REQUIRE(BigInt("-156687") % BigInt("-156687") == BigInt(to_string(-156687 % -156687)));
			REQUIRE(BigInt("-156687456842") % BigInt("-6987") == BigInt(to_string(-156687456842 % -6987)));
			REQUIRE(BigInt("0") % BigInt("-57") == BigInt(to_string(0 % -56)));
			REQUIRE(BigInt("-56") % BigInt("-57") == BigInt(to_string(-56 % -57)));

			BigInt big = BigInt("-568746");;
			big %= BigInt("-578");
			REQUIRE(big == BigInt(to_string(-568746 % -578)));
		}
	
	}



}

TEST_CASE("Check copmapre operators","[compare]"){
	SECTION("greater both positives"){
		REQUIRE(BigInt("98745") > BigInt("68745"));
		REQUIRE(BigInt("-98745") < BigInt("-68745"));
		REQUIRE(BigInt("56874") >= BigInt("56874"));
		REQUIRE(BigInt("98745") <= BigInt("98745"));
				
	}
}