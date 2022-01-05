/*****************************************************************************************************************************************************
*
* Christopher Bakhos
*
* Created:	December 19, 2021
* 
* <INSERT BAZAEL THING HERE>
*
*****************************************************************************************************************************************************/

// Include C++ Standard Libraries
#include <bitset>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

class BitVector {
	public:
	// Constructors
	BitVector();
	BitVector( const uint32_t numberOfBits_ );
	BitVector( char const value[] );
	BitVector( const BitVector& BitVector_ ) = default;
	
	// Get and set numberOfBits_
	uint32_t numberOfBits();
	void numberOfBits( uint32_t numberOfBits_ );
	
	// Get range from bitIndex1 (inclusive) to bitIndex2 (exclusive)
	BitVector getRange( int32_t bitIndex1, int32_t bitIndex2 );
	
	// Set range from bitIndex1 (inclusive) to bitIndex2 (exclusive) from bitIndex3 (inclusive) to bitIndex4 (exclusive)
	void setRange( int32_t bitIndex1, int32_t bitIndex2, BitVector values );
	void setRange( int32_t bitIndex1, int32_t bitIndex2, int32_t bitIndex3, int32_t bitIndex4, BitVector values );
	
	// Logical Operations
	BitVector bitwiseNot();
	BitVector bitwiseOr( BitVector& rhs );
	BitVector bitwiseAnd( BitVector& rhs );
	BitVector bitwiseXor( BitVector& rhs );
	
	// TODO: implement these? condense these?
	// Shifting Operations
	BitVector shiftRightZero(); // fills empty with 0. discards extra
	BitVector shiftLeftZero();
	BitVector shiftRightOne(); // fills empty with 1. discards extra
	BitVector shiftLeftOne();
	BitVector shiftRightSame(); // fills empty with the same value as the adjacent value. discards extra
	BitVector shiftLeftSame();
	BitVector shiftRightNot(); // fills empty with not value of the adjacent value. discards extra
	BitVector shiftLeftNot();
	
	BitVector rotateRight();
	BitVector rotateLeft();
	
	// TODO:
	// Comparator Operations
	bool signedLessThan( BitVector& rhs );
	bool unsignedLessThan( BitVector& rhs );
	bool equalTo( BitVector& rhs );
	bool signedGreaterThan( BitVector& rhs );
	bool unsignedGreaterThan( BitVector& rhs );
	bool signedLessThanOrEqualTo( BitVector& rhs );
	bool unsignedLessThanOrEqualTo( BitVector& rhs );
	bool signedGreaterThanOrEqualTo( BitVector& rhs );
	bool unsignedGreaterThanOrEqualTo( BitVector& rhs );
	
	// Index Overloads
	std::bitset<1>& operator[]( int32_t bit );
	BitVector operator()( int32_t bitIndex1, int32_t bitIndex2 );	// bitIndex1 (inclusive) to bitIndex2 (exclusive)
	
	// Assignment Overloads
	bool operator=( int64_t value );
	bool operator=( char const value[] ); // value[] is a string of 1s and 0s
	
	// Logical Overloads
	BitVector operator~();
	BitVector operator|( BitVector& rhs );
	BitVector operator&( BitVector& rhs );
	BitVector operator^( BitVector& rhs );
	
	// TODO:
	// Shifting Overloads
	BitVector operator<<( int32_t rhs );
	BitVector operator>>( int32_t rhs );
	
	// TODO:
	// Stream Insertion and Extraction Operator Overloads
	friend std::ostream& operator<<( std::ostream& lhs, const BitVector& rhs );
	friend std::istream& operator>>( std::istream& lhs, const BitVector& rhs );
	
	
	private:
	// Number of bits
	uint32_t numberOfBits_;
	
	// Bit storing
	std::bitset<1> baseBit_ = '0';
	std::vector<std::bitset<1>> bitsetVector_;
	
	// Private constructor with the semi-complicated type const std::vector<std::bitset<1>>
	BitVector( const std::vector<std::bitset<1>> bitsetVector_ );
};