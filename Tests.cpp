/*****************************************************************************************************************************************************
*
* Christopher Bakhos
*
* Created:	December 19, 2021
* 
* "and I have filled him with the Spirit of God, with ability and intelligence, with knowledge and all craftmanship,
* 	to devise artistic designs, to work in gold, silver, and bronze, in cutting stones for setting, and in carving wood,
* 	for work in every craft" (Exodus 31:3-5, RSV-2CE).
*
* "For God so loved the world that he gave his only-begotten Son, that whoever believes in him should not perish but
*	have eternal life" (John 3:16, RSV-2CE).
*
* "He has showed you, O man, what is good; and what does the LORD require of you but to do justice, and to love kindness,
*	and to walk humbly with your God?" (Micah 6:8, RSV-2CE).
*
*****************************************************************************************************************************************************/

// Include C++ Standard Libraries
#include <bitset>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

// Include any other files
//#include BitVector.hpp

// The structure of the BitVector is a vector of bytes. By definition, each byte holds 8 bits, so, for a given BitVector of n bits, where n is a
// non-negative integer, there will be ( ( ( n - 1 ) / 8 ) + 1 ) bytes.
class BitVector {
	public:
	// Constructors
	BitVector();
	BitVector( const uint32_t numberOfBits_ );
	BitVector( const std::vector<std::bitset<1>> bitsetVector_ );
	BitVector( char const value[] );
	BitVector( const BitVector& BitVector_ ) = default;
	
	// Getters and setters. TODO: Rework these? Consider other options?
	uint32_t numberOfBits();
	void numberOfBits( uint32_t numberOfBits_ );
	void setRange( int32_t bitIndex1, int32_t bitIndex2, BitVector values );
	
	// Overloads
	std::bitset<1>& operator[]( int32_t bit );
	BitVector operator()( int32_t bitIndex1, int32_t bitIndex2 );
	bool operator=( int64_t value );
	bool operator=( char const value[] ); // string of 1s and 0s
	
	
	
	private:
	// Number of bits
	uint32_t numberOfBits_;
	
	// Bit storing
	std::bitset<1> baseBit_;
	std::vector<std::bitset<1>> bitsetVector_;
};


// Default Constructor
BitVector::BitVector() {
	numberOfBits_ = 0;
}

// Constructor with number of bits
BitVector::BitVector( uint32_t numberOfBits_ ) : numberOfBits_(numberOfBits_) {
	for( uint32_t i = 0; i < numberOfBits_; i++ ) {
		bitsetVector_.push_back( baseBit_ );
	}
}

// Constructor with vector of bitsets of 1 bit
BitVector::BitVector( const std::vector<std::bitset<1>> bitsetVector_ ) : bitsetVector_(bitsetVector_) {
	numberOfBits_ = bitsetVector_.size();
	
	for( uint32_t i = 0; i < numberOfBits_; i++ ) {
		std::cout << this->bitsetVector_[i] << " " << bitsetVector_[i] << '\n';
		this->bitsetVector_[i] = bitsetVector_[i];
		std::cout << this->bitsetVector_[i] << " " << bitsetVector_[i] << '\n';
	}
}

// Constructor with char const value[]
BitVector::BitVector( char const value[] ) {
	
}


// Getters and setters. TODO: Rework these? Consider other options?
// number of bits getter
uint32_t BitVector::numberOfBits() {
	return numberOfBits_;
}

// number of bits setter
void BitVector::numberOfBits( uint32_t numberOfBits_ ) {
	this->numberOfBits_ = numberOfBits_;
}


// TODO; FIX THIS
// Set a range of values
void BitVector::setRange( int32_t bitIndex1, int32_t bitIndex2, BitVector values ) {
	uint32_t valuesSize = values.numberOfBits();
	uint32_t j = 0;
	for( uint32_t i = bitIndex1; ( i < bitIndex2 ) && ( i < valuesSize ); i++ ) {
		bitsetVector_[i] = values[j];
		j++;
	}
}


// [] overload
std::bitset<1>& BitVector::operator[]( int32_t bit ) {
	return bitsetVector_[bit];
}

// () overload (get a range of values)
BitVector BitVector::operator()( int32_t bitIndex1, int32_t bitIndex2 ) {
	std::vector<std::bitset<1>> bitSubsetVector_;
	for( uint32_t i = bitIndex1; i < bitIndex2; i++ ) {
		bitSubsetVector_.push_back( bitsetVector_[i] );
	}
	return BitVector( bitSubsetVector_ );
}

// = overloads
bool BitVector::operator=( int64_t value ) {
	for( uint32_t i = 0; ( i < numberOfBits_ ) && ( i < 64 ); i++ ) {
		bitsetVector_[i] = ( value & ( 1ull << i ) ) >> i;
	}
	for( uint32_t i = std::min( numberOfBits_, 64u ); i < numberOfBits_; i++ ) {
		bitsetVector_[i] = 0;
	}
	return true;
}

// this cuts off the wrong bits when value is oversized. it should cut off the bigger bits but it will truncate the smaller ones
bool BitVector::operator=( char const value[] ) {
	uint32_t valueBits = strlen( value );
	uint32_t middlePartition = std::min( numberOfBits_, valueBits );
	for( uint32_t i = 0; ( i < numberOfBits_ ) && ( i < valueBits ); i++ ) {
		bitsetVector_[middlePartition - i - 1] = value[i + std::max( (int32_t) valueBits - (int32_t) numberOfBits_, 0 )];
	}
	for( uint32_t i = middlePartition; i < numberOfBits_; i++ ) {
		bitsetVector_[i] = 0;
	}
	return true;
}


// Main
int32_t main() {
	std::vector<BitVector> vectors;
	
	BitVector vector0;
	BitVector vector1 = BitVector( 128 );
	BitVector vector2 = BitVector(vector1);
	BitVector vector3 = vector2;
	
	vector3 = 45675678567;
	vector3 = 0xf1ffffffffffffff;
	
	//std::cout << vector3(62, 66)[3] << vector3(62, 66)[2] << vector3(62, 66)[1] << vector3(62, 66)[0] << '\n';
	
	//BitVector vectortest = BitVector(std::vector({1}));
	
	//std::cout << vectortest.numberOfBits() << " " << vectortest[0] << '\n';
	
	//vector3.setRange( 64, 65, BitVector({1}) );
	
	//std::cout << vector3(62, 66)[3] << vector3(62, 66)[2] << vector3(62, 66)[1] << vector3(62, 66)[0] << '\n';
	
	vectors.push_back( std::move( vector0 ) );
	vectors.push_back( std::move( vector1 ) );
	vectors.push_back( std::move( vector2 ) );
	vectors.push_back( std::move( vector3 ) );
	
	for( auto it = std::begin( vectors ); it != std::end( vectors ); ++it ) {
		std::cout << "Vector: " << ( it - std::begin( vectors ) ) << '\n';
		std::cout << "Number of bits: " << it->numberOfBits() << '\n';
		std::cout << "Bits: ";
		for( int32_t i = it->numberOfBits() - 1; i >= 0; i-- ) {
			std::cout << (*it)[i];
		}
		std::cout << '\n';
	}
	
	BitVector vector4 = vector3;
	BitVector vector5 = BitVector( vector3 );
	vector3 = "10111011111011111110111111111011111111111011111111111110111111111111111011111111111111111011111111111111111110111111111111111111111";
	//vector3 = "1000111";
	
	std::vector<BitVector> vectors2;
	
	vectors2.push_back( std::move( vector3 ) );
	vectors2.push_back( std::move( vector4 ) );
	vectors2.push_back( std::move( vector5 ) );
	
	std::cout << "New Vectors" << '\n';
	
	for( auto it = std::begin( vectors2 ); it != std::end( vectors2 ); ++it ) {
		std::cout << "Vector: " << ( it - std::begin( vectors2 ) ) + 3 << '\n';
		std::cout << "Number of bits: " << it->numberOfBits() << '\n';
		std::cout << "Bits: ";
		for( int32_t i = it->numberOfBits() - 1; i >= 0; i-- ) {
			std::cout << (*it)[i];
		}
		std::cout << '\n';
	}
	
	return 0;
}