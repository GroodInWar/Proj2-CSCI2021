/*
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to this part of the project by
editing the collection of functions in this source file.

INTEGER CODING RULES:

Replace the "return" statement in each function with one
or more lines of C code that implements the function. Your code
must conform to the following style:

int Funct(arg1, arg2, ...) {
    /* brief description of how your implementation works */
    int var1 = Expr1;
    ...
    int varM = ExprM;

    varJ = ExprJ;
    ...
    varN = ExprN;
    return ExprR;
}

Each "Expr" is an expression using ONLY the following:
1. Integer constants 0 through 255 (0xFF), inclusive. You are
not allowed to use big constants such as 0xffffffff.
2. Function arguments and local variables (no global variables).
3. Unary integer operations ! ~
4. Binary integer operations & ^ | + << >>

Some of the problems restrict the set of allowed operators even further.
Each "Expr" may consist of multiple operators. You are not restricted to
one operator per line.

You are expressly forbidden to:
1. Use any control constructs such as if, do, while, for, switch, etc.
2. Define or use any macros.
3. Define any additional functions in this file.
4. Call any functions.
5. Use any other operations, such as &&, ||, -, or ?:
6. Use any form of casting.
7. Use any data type other than int.  This implies that you
cannot use arrays, structs, or unions.


You may assume that your machine:
1. Uses 2s complement, 32-bit representations of integers.
2. Performs right shifts arithmetically.
3. Has unpredictable behavior when shifting if the shift amount
is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
/*
 * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
 */
int pow2plus1(int x) {
    /* exploit ability of shifts to compute powers of 2 */
    return (1 << x) + 1;
}

/*
 * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
 */
int pow2plus4(int x) {
    /* exploit ability of shifts to compute powers of 2 */
    int result = (1 << x);
    result += 4;
    return result;
}

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
1. Define or use any macros.
2. Define any additional functions in this file.
3. Call any functions.
4. Use any form of casting.
5. Use any data type other than int or unsigned.  This means that you
cannot use arrays, structs, or unions.
6. Use any floating point data types, operations, or constants.


NOTES:
1. Use the dlc (data lab checker) compiler (described in the spec) to
check the legality of your solutions.
2. Each function has a maximum number of operations (integer, logical,
or comparison) that you are allowed to use for your implementation
of the function.  The max operator count is checked by dlc.
Note that assignment ('=') is not counted; you may use as many of
these as you want without penalty.
3. Use the btest test harness to check your functions for correctness.
4. The maximum number of ops for each function is given in the
header comment for each function. If there are any inconsistencies
between the maximum ops in the writeup and in this file, consider
this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the btest checker to verify that your solutions produce
 *      the correct answers.
 */
#endif


/*
 * minusOne - return a value of -1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void) {
    int i = 0x00;
    i = ~i;
    return i;
}

/*
 * thirdBits - return int with every third bit (starting from the LSB) set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 *  0100 1001 0010 0100 1001 0010 0100 1001
 *   4    9    2    4    9    2     4    9
 */
int thirdBits(void) {
    int i = 0x49;
    i = (i << 8) + 0x24;
    i = (i << 8) + 0x92;
    i = (i << 8) + 0x49;
    return i;
}

/*
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
    int m1 = m<<3; // shift by 3 bits
    int n1 = n<<3; // shift by 3 bits
    int a;
    
    int m2 = ((x & (0xFF << m1)) >> m1) & 0xFF; 
    int n2 = ((x &(0xFF << n1)) >> n1) & 0xFF;

    m2 = m2 << n1; // shift by n1 bits m2
    n2 = n2 << m1; // shift by m1 bits n2   

    a = ~((0xFF << m1) | (0xFF << n1)) & x; 
    return a | m2 | n2; // or all bits in a, m2, n2 aka add all the numbers
}

/*
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
    return (x << 31) >> 31;
}

/*
 * isPositive - return 1 if x > 0, return 0 otherwise
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int isPositive(int x) {
    int y = x & (1 << ((4<<3) + (~0x00)));
    return !(y | (!x)); // negate x, or the bits with y, and negate that
}

/*
 * floatNegate - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatNegate(unsigned uf) {
    unsigned a = (uf >> 23) & 0xFF;  
    unsigned b = uf << 9;
    // check if a is 1's and b is different than 0's
    if(a == 0xFF && b != 0x00) { 
        return uf; 
    }
    return uf ^ (1<<31); // xor uf with the most negative int 
}

/*
 * anyEvenBit - return 1 if any even-numbered bit in input set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples anyEvenBit(0xA) = 0, anyEvenBit(0xE) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 * 
 *  y = 0101 0101 0101 0101 0101 0101 0101 0101
 *        5    5    5    5    5    5    5    5
 */
int anyEvenBit(int x) {
    int y = 0x55;
    y += 0x55<<8;
    y += 0x55<<16;
    y += 0x55<<24;
    return !(!(x&y));
}

/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
    int lb = (x +(~0x30 +1))>>31; // lower bound 
    int ub =  (0x39+(~x+1))>>31;  // upper bound
    int val = (!lb & !ub); // negation and negation where it is ASCII digit
  return  val;
}

/*
 * floatIsLess - Compute f < g for floating point arguments f and g.
 *   Both the arguments are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   If either argument is NaN, return 0.
 *   +0 and -0 are considered equal.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 3
 */
int floatIsLess(unsigned uf, unsigned ug) {
    return 2;
}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int logicalShift(int x, int n) {
    int shift = x >> n;
    int delLeft = ~0 << (32 + ~n) << 1; // shift 1's left by 32-n
    delLeft = ~delLeft; // flip all the bits
    return delLeft & shift; // return the right side of shift
}

/*
 * greatestBitPos - return a mask that marks the position of the
 *               most significant 1 bit. If x == 0, return 0
 *   Example: greatestBitPos(96) = 0x40
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 70
 *   Rating: 4
 */
int greatestBitPos(int x) {
    // shift then or with min val for int
    // Gets rid of extra 1's and leaves the most significant 1 bit
    int a = x|(x>>1);
    a |= a>>2;
    a |= a>>4;
    a |= a>>8;
    a |= a>>16;
    return ((a^(a>>1)) | (1<<31)) & a;
}

/*
 * floatScale1d2 - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale1d2(unsigned uf) {
    return 2;
}
