/*****************************************************************************************************************************************************
*
* Christopher Bakhos
*
* Created:	December 19, 2021
* 
* <INSERT BAZAEL THING HERE>
*
*****************************************************************************************************************************************************/

// Include .hpp file
#include "BitVector.hpp"

// Public
// Constructors
// Default Constructor
BitVector::BitVector() {
	numberOfBits_ = 0;
}

// Constructor with number of bits
BitVector::BitVector( uint32_t numberOfBits_ ) : numberOfBits_(numberOfBits_) {
	for( uint32_t i = 0; i < numberOfBits_; i++ ) {
		bitsetVector_.emplace_back( baseBit_ );
	}
}

// Constructor with char const value[]
BitVector::BitVector( char const value[] ) : numberOfBits_(std::strlen( value )) {
	for( uint32_t i = 0; i < numberOfBits_; i++ ) {
		bitsetVector_.emplace_back( std::bitset<1>( value[numberOfBits_ - i - 1] ) );
	}
}



// Get and set numberOfBits_
// Get numberOfBits_
uint32_t BitVector::numberOfBits() {
	return numberOfBits_;
}

// Set numberOfBits_
void BitVector::numberOfBits( uint32_t numberOfBits_ ) {
	// Make some variables for clarity
	uint32_t oldNumberOfBits = this->numberOfBits_;
	uint32_t newNumberOfBits = numberOfBits_;
	
	// Create a new vector of std::bitset<1>s
	std::vector<std::bitset<1>> newVector;
	
	// Get the lower and bigger of the two numberOfBits_s
	uint32_t middlePartition = std::min( oldNumberOfBits, newNumberOfBits );
	
	// Loop through, copying all of the old vector into the new vector
	for( uint32_t i = 0; i < middlePartition; i++ ) {
		newVector.emplace_back( this->bitsetVector_[i] );\
		std::cout << i << ":" << newVector[i] << " ";
	}
	// Fill any extra with 0s
	for( uint32_t i = middlePartition; i < newNumberOfBits + 1; i++ ) {
		newVector.emplace_back( this->baseBit_ );
		std::cout << i << ":" << newVector[i][0] << " ";
	}
	std::cout << '\n';
	
	std::cout << (*this)[10][0] << '\n';
	
	// Change the number of bits to newNumberOfBits
	this->numberOfBits_ = newNumberOfBits + 1;
	
	std::cout << "Number of bits: " << this->numberOfBits_ << '\n';
}



// Get and set range from bitIndex1 (inclusive) to bitIndex2 (exclusive)
// Get the range of values from bitIndex1 (inclusive) to bitIndex2 (exclusive)
BitVector BitVector::getRange( int32_t bitIndex1, int32_t bitIndex2 ) {
	std::vector<std::bitset<1>> bitSubsetVector_;
	for( uint32_t i = bitIndex1; i < bitIndex2; i++ ) {
		bitSubsetVector_.push_back( bitsetVector_[i] );
	}
	return BitVector( bitSubsetVector_ );
}

// Set the range of values from bitIndex1 (inclusive) to bitIndex2 (exclusive)
void BitVector::setRange( int32_t bitIndex1, int32_t bitIndex2, BitVector values ) {
	// So, take the current BitVector and loop from bitIndex1 to bitIndex2. Set that equal to values.
	uint32_t j = 0;
	for( uint32_t i = bitIndex1; ( i < bitIndex2 ) && ( j < values.numberOfBits_ ); i++ ) {
		//std::cout << i << ": " << bitsetVector_[i] << ".\t" << j << ": " << values[j] << '\n';
		bitsetVector_[i] = values[j];
		j++;
	}
}

// Set the range of values from bitIndex1 (inclusive) to bitIndex2 (exclusive) from bitIndex3 (inclusive) to bitIndex4 (exclusive)
void BitVector::setRange( int32_t bitIndex1, int32_t bitIndex2, int32_t bitIndex3, int32_t bitIndex4, BitVector values ) {
	// So, take the current BitVector and loop from bitIndex1 to bitIndex2. Set that equal to values, looped over bitIndex3 to bitIndex4.
	uint32_t j = bitIndex3;
	for( uint32_t i = bitIndex1; ( i < bitIndex2 ) && ( j < bitIndex4 ); i++ ) {
		//std::cout << i << ": " << bitsetVector_[i] << ".\t" << j << ": " << values[j] << '\n';
		bitsetVector_[i] = values[j];
		j++;
	}
}



// Logical Operators
// Bitwise NOT
BitVector BitVector::bitwiseNot() {
	BitVector lhs = *this;
	BitVector notResult = BitVector( lhs.numberOfBits_ );
	for( uint32_t i = 0; i < lhs.numberOfBits_; i++ ) {
		notResult.bitsetVector_[i] = ~lhs.bitsetVector_[i];
	}
	return notResult;
}

// Bitwise OR
BitVector BitVector::bitwiseOr( BitVector& rhs ) {
	BitVector lhs = *this;
	BitVector orResult;
	uint32_t middlePartition = std::min( lhs.numberOfBits_, rhs.numberOfBits_ );
	bool lhsLarger = ( lhs.numberOfBits_ > rhs.numberOfBits_ );
	if( lhsLarger ) {
		orResult = lhs;
	}
	else {
		orResult = rhs;
	}
	for( uint32_t i = 0; i < middlePartition; i++ ) {
		orResult.bitsetVector_[i] = ( lhs.bitsetVector_[i] | rhs.bitsetVector_[i] );
	}
	return orResult;
}

// Bitwise AND
BitVector BitVector::bitwiseAnd( BitVector& rhs ) {
	BitVector lhs = *this;
	BitVector andResult;
	uint32_t middlePartition = std::min( lhs.numberOfBits_, rhs.numberOfBits_ );
	bool lhsLarger = ( lhs.numberOfBits_ > rhs.numberOfBits_ );
	if( lhsLarger ) {
		andResult = BitVector( lhs.numberOfBits_ );
	}
	else {
		andResult = BitVector( rhs.numberOfBits_ );
	}
	for( uint32_t i = 0; i < middlePartition; i++ ) {
		andResult.bitsetVector_[i] = ( lhs.bitsetVector_[i] & rhs.bitsetVector_[i] );
	}
	return andResult;
}

// Bitwise XOR
BitVector BitVector::bitwiseXor( BitVector& rhs ) {
	BitVector lhs = *this;
	BitVector xorResult;
	uint32_t middlePartition = std::min( lhs.numberOfBits_, rhs.numberOfBits_ );
	bool lhsLarger = ( lhs.numberOfBits_ > rhs.numberOfBits_ );
	if( lhsLarger ) {
		xorResult = lhs;
	}
	else {
		xorResult = rhs;
	}
	for( uint32_t i = 0; i < middlePartition; i++ ) {
		xorResult.bitsetVector_[i] = ( lhs.bitsetVector_[i] ^ rhs.bitsetVector_[i] );
	}
	return xorResult;
}



// Comparator Operations
// Equal to
bool BitVector::equalTo( BitVector& rhs ) {
	return this->bitsetVector_ == rhs.bitsetVector_;
	// Get the lower and bigger of the two numberOfBits_s
	// uint32_t middlePartition = std::min( oldNumberOfBits, newNumberOfBits );
	// uint32_t lastIndex = std::max( oldNumberOfBits, newNumberOfBits );
	
	// bool lhsLarger = ( lhs.numberOfBits_ > rhs.numberOfBits_ );
	
	// for( int32_t i = lastIndex
}

// Signed Comparisons
// Signed less than
bool BitVector::signedLessThan( BitVector& rhs ) {
	return false;
}

// Signed greater than
bool BitVector::signedGreaterThan( BitVector& rhs ) {
	return false;
}

// Signed less than or equal to
bool BitVector::signedLessThanOrEqualTo( BitVector& rhs ) {
	return false;
}

// Signed greater than or equal to
bool BitVector::signedGreaterThanOrEqualTo( BitVector& rhs ) {
	return false;
}

// Unsigned Comparisons
// Unsigned less than
bool BitVector::unsignedLessThan( BitVector& rhs ) {
	return false;
}

// Unsigned greater than
bool BitVector::unsignedGreaterThan( BitVector& rhs ) {
	return false;
}

// Unsigned less than or equal to
bool BitVector::unsignedLessThanOrEqualTo( BitVector& rhs ) {
	return false;
}

// Unsigned greater than or equal to
bool BitVector::unsignedGreaterThanOrEqualTo( BitVector& rhs ) {
	return false;
}



// Index Overloads
// [] overload
std::bitset<1>& BitVector::operator[]( int32_t bit ) {
	return bitsetVector_[bit];
}

// () overload (get range from bitIndex1 (inclusive) to bitIndex2 (exclusive))
BitVector BitVector::operator()( int32_t bitIndex1, int32_t bitIndex2 ) {
	return getRange( bitIndex1, bitIndex2 );
}



// Assignment Overloads
/*	Not how these behave:
*	101110110100101010
*	0000000000
*	1011101101
*
*	How these behave:
*	101110110100101010
*	        0000000000
*	        0100101010
*/
// int64_t Overload
bool BitVector::operator=( int64_t value ) {
	for( uint32_t i = 0; ( i < numberOfBits_ ) && ( i < 64 ); i++ ) {
		bitsetVector_[i] = ( value & ( 1ull << i ) ) >> i;
	}
	for( uint32_t i = std::min( numberOfBits_, 64u ); i < numberOfBits_; i++ ) {
		bitsetVector_[i] = 0;
	}
	return true;
}

// char const [] Overload
bool BitVector::operator=( char const value[] ) {
	// valueBits tells us how many bits are in value[]. This is equivalent to the length of the string
	uint32_t valueBits = strlen( value );
	// middlePartition tells us the minimum value of numberOfBits_ and how many bits are in value[]. We need to fill any extra bits in with zeros
	uint32_t middlePartition = std::min( numberOfBits_, valueBits );
	// differenceOffset is for when there are more bits in the value string than in our BitVector. This allows the lower bits to be copied with
	// priority over the upper bits
	uint32_t differenceOffset = std::max( (int32_t) valueBits - (int32_t) numberOfBits_, 0 );
	
	// Loop through the bits that have a value
	for( uint32_t i = 0; ( i < numberOfBits_ ) && ( i < valueBits ); i++ ) {
		bitsetVector_[middlePartition - i - 1] = value[i + std::max( (int32_t) valueBits - (int32_t) numberOfBits_, 0 )];
	}
	// Loop through any remaining bits to set them to zero
	for( uint32_t i = middlePartition; i < numberOfBits_; i++ ) {
		bitsetVector_[i] = 0;
	}
	return true;
}



// Logical Overloads
// NOT Overload
BitVector BitVector::operator~() {
	return this->bitwiseNot();
}

// OR Overload
BitVector BitVector::operator|( BitVector& rhs ) {
	return this->bitwiseOr( rhs );
}

// AND Overload
BitVector BitVector::operator&( BitVector& rhs ) {
	return this->bitwiseAnd( rhs );
}

// XOR Overload
BitVector BitVector::operator^( BitVector& rhs ) {
	return this->bitwiseXor( rhs );
}



// Private
// Constructor with vector of bitsets of 1 bit
BitVector::BitVector( const std::vector<std::bitset<1>> bitsetVector_ ) : bitsetVector_(bitsetVector_) {
	numberOfBits_ = bitsetVector_.size();
	
	for( uint32_t i = 0; i < numberOfBits_; i++ ) {
		//std::cout << this->bitsetVector_[i] << " " << bitsetVector_[i] << '\n';
		this->bitsetVector_[i] = bitsetVector_[i];
		//std::cout << this->bitsetVector_[i] << " " << bitsetVector_[i] << '\n';
	}
}



// Friend Functions
std::ostream& operator<<( std::ostream& lhs, const BitVector& rhs ) {
	for( int32_t i = 0; i < rhs.numberOfBits_; i++ ) {
		lhs << rhs.bitsetVector_[rhs.numberOfBits_ - i - 1];
	}
	return lhs;
}