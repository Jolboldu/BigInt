#include <sstream>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include "BigInt.h"

using namespace std;

int main(){
 /*  vector<int> big = {0};
     reverse(big.begin(), big.end());
    int number = 321;
    int carry = 0;
    for (int i = big.size()-1; i >= 0; --i) {
        int cur = big[i] + carry * 10;
        big[i] = cur / number;
        carry = cur % number;
    }
    reverse(big.begin(), big.end());
    for (int i = 0; i < big.size(); ++i)
    {
        cout << big[i];
    }
*/
/*    BigInt big = BigInt("2");
    
    BigInt big2 = BigInt("3");
    
    BigInt div = big * big2;
  cout << div << endl;
  */   
    try{
        BigInt big;
        cin >> big;
    }catch (runtime_error& e)
    {
        cout << e.what() << endl;
    }
   // cout << in.str();
/*BigInt operator / (BigInt a, BigInt b) {
    Set(a);
    Set(b);
    if (b == Integer(0)) return Integer("-1");
    BigInt ans, cur;
    FORD(i,a.size()-1,0) {
        cur.insert(cur.begin(), a[i]);
        int x = 0, L = 0, R = base;
        while (L <= R) {
            int mid = (L+R)>>1;
            if (b*Integer(mid) > cur) {
                x = mid;
                R = mid-1;
            }
            else
                L = mid+1;
        }
        cur = cur - Integer(x-1)*b;
        ans.insert(ans.begin(),x-1);
    }
    Set(ans);
    return ans;
}*/	return 0;
}