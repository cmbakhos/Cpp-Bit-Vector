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

// Include .hpp file
#include "BitVector.hpp"

// Include C++ Standard Libraries
#include <bitset>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

// Main
int32_t main() {
	std::vector<BitVector> vectors;
	
	BitVector vector0;
	BitVector vector1 = BitVector( 128 );
	BitVector vector2 = BitVector( vector1 );
	BitVector vector3 = vector2;
	
	vector3 = 45675678567;
	vector3 = 0xf1fffffffffffccf;
	
	std::cout << vector3 << '\n';
	//std::cout << vector3.getRange(62, 66) << '\n';
	
	BitVector setVector1 = "0110";
	
	//vector3.setRange( 62, 66, 0, 4, setVector1 );
	std::cout << vector3 << '\n';
	
	vector3.setRange( 70, 128, 0, 70, vector3 );
	std::cout << vector3 << '\n';
	
	//vector3.setRange( 0, 128, vector1 );
	//std::cout << vector3 << '\n';
	
	vector3.numberOfBits( 10 );
	std::cout << vector3 << '\n';
	
	//std::cout << vector3(62, 66) << '\n';
	
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
	vector3 = "1000111";
	BitVector vector6 = BitVector( 16 );
	vector6 = "1100010000101110";
	
	BitVector vector7 = ~( vector3 | vector6 );
	BitVector vector8 = vector7 ^ vector7;
	BitVector vector9 = vector6 & vector3;
	
	BitVector vector10 = BitVector( "100011101" );
	BitVector vector11 = "101011101";
	
	std::vector<BitVector> vectors2;
	
	vectors2.push_back( std::move( vector3 ) );
	vectors2.push_back( std::move( vector4 ) );
	vectors2.push_back( std::move( vector5 ) );
	vectors2.push_back( std::move( vector6 ) );
	vectors2.push_back( std::move( vector7 ) );
	vectors2.push_back( std::move( vector8 ) );
	vectors2.push_back( std::move( vector9 ) );
	vectors2.push_back( std::move( vector10 ) );
	vectors2.push_back( std::move( vector11 ) );
	
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
	
	BitVector vector12 = vector3;
	
	std::cout << vector12 << '\n';
	
	vector12.numberOfBits( 11 );
	
	for( int i = vector12.numberOfBits() + 1; i >= 0; i-- ) {
		std::cout << i << ":" << vector12[i] << " ";
	}
	std::cout << '\n';
		
	std::cout << vector12 << " == " << vector12 << ": " << vector12.equalTo( vector12 ) << '\n';
	
	return 0;
}