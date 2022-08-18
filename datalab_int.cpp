#include <iostream>
#include <limits.h>

using namespace std;

int bitxor(int a, int b)
{
    return ~(~(~a & b) & ~(a & ~b));
}

int tmin() // judge a number is or not the minium number of the signed number
{
    return 1 << 31;
}

// return 1 or 0 but the now version is 0 or something else but not 0

int istmax(int y)
{
    int x = y + 1;
    // （~x^y）if y is tmax then this expr will be 0 which is the oppsite of the correct answer
    // pay attention to the example -1 which should be dealed with specially
    return !(~x ^ y) & !!(x + 1);
}

int alloddbits(int x)
{
    int a_8 = 0xAA;
    int a_16 = (a_8 << 8) | a_8;
    int a_32 = (a_16 << 16) | a_16;
    // get 32-bits int whose odd bits are 1
    // PS: no matter the even bit is 0 or 1
    // if the expr is 0 means that the odd bits are all 1,which should return 1
    return !((x & a_32) ^ a_32);
}

int negate(int x)
{
    return (~x + 1);
}

int isanscii(int x) // you pass the  correct but used 17 ops which is overflow
{
    int y = x & 15;
    int xf = y >> 1 & 1;
    int xs = y >> 2 & 1;
    int sit1 = y >> 3 & 1 & !(xf | xs);
    int sit2 = y >> 3 & 1;
    return !!(!sit2 | sit1);
}

// Legal ops: ! ~ & ^ | + << >>
int conditi(int x, int y, int z)
{
    int a = !!(x ^ 0); // if x == 0 a = 0 else a = 1;
    int b = ~a + 1;
    int c = ~(y & b) + 1; // if a != 0 ,c = -y;
    int d = ~(b & z) + 1; // if x == 0 ,d = -z;
    return y + z + c + d;
}

// *   Legal ops: ! ~ & ^ | + << >>
int lessequal(int a, int b)
{
    int as = a >> 31 & 1;
    int bs = b >> 31 & 1;
    int s1y = as & ~bs;
    int s2n = ~as & bs;
    int signsame = !(as ^ bs);
    int res = a + (~b + 1);
    int ressign = res >> 31 & 1;
    int resiszero = res ^ 0;
    return !resiszero | (signsame & ressign) | s1y;
}

//  *   Legal ops: ~ & ^ | + << >>
int logicneg(int x)
{
    int tem = x | (~x + 1);
    int sign = tem >> 31 & 1;
    return sign ^ 1;
}

int howmanybits(int x)
{
    int sign = x >> 31;
    int b0,b1, b2, b4, b8, b16;
    x = (~sign & x) | (~x & sign);
    b16 = !!(x >> 16) << 4; // is 0 return 0 else return 1 to show that it i
    x = x >> b16;
    b8 = !!(x >> 8) << 3;
    x = x >> b8;
    b4 = !!(x >> 4) << 2;
    x = x >> b4;
    b2 = !!(x >> 2) << 1;
    x = x >> b2;
    b1 = !!(x >> 1);
    x = x >> b1;
    b0 = x ;
    int res = b16 + b8 + b4 + b2 + b1 + b0 + 1; // 1 for sign bit
    return res;
}

int main()
{
    int t;
    // cin >> t;
    // cout << t << endl;
    cout << howmanybits(5) << endl;
    return 0;
}
