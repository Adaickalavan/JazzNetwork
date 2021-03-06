// Question3.cpp

#include "pch.h"
#include <iostream>
#include <bitset>
#include <thread>

using namespace std;

#define bits 8

//Reverse bits of a given byte
void reverse_bits(unsigned char *seqPtrFront) {
	unsigned char val = *seqPtrFront;
	val = ((val & 0b11110000) >> 4 | (val & 0b00001111) << 4);
	val = ((val & 0b11001100) >> 2 | (val & 0b00110011) << 2);
	val = ((val & 0b10101010) >> 1 | (val & 0b01010101) << 1);	
	*seqPtrFront = val;	
}

//Swap the values of two bytes
void swap_bytes(unsigned char *seqPtrFront, int length) {
	//Swap the front and back elements
	unsigned char *seqPtrBack = seqPtrFront + length - 1;
	unsigned char temp = *seqPtrFront;
	*seqPtrFront = *seqPtrBack;
	*seqPtrBack = temp;
	
	//Reverse sequence of bits within a single byte
	reverse_bits(seqPtrFront);
	reverse_bits(seqPtrBack);
}

//Reverse the sequence of bits
void reverse_bytes(unsigned char *seqPtr, int length){	
	//Completed reversing bytes
	if (length == 1) {
		reverse_bits(seqPtr);
		return;
	} 
	else if (length < 1) {
		return;
	}

	//Swap bytes in parallel using multiple threads
	thread t1(reverse_bytes, seqPtr + 1, length - 2); //Swap the remaining bytes in the middle
	thread t2(swap_bytes, seqPtr, length); //Swap the front and back bytes

	//Join threads
	t1.join();
	t2.join();
}

int main(){
	unsigned char seq[] = {"1234567"}; //unsigned char buffer
	int length = 7; //length of unsigned char buffer
	
	//Buffer contents before reversing
	cout << "Input: " << seq << "\n"; 
	for (int ii = 0; ii < length; ++ii) {
		cout << std::bitset<bits>(seq[ii]) << " ";
	}
	cout << "\n";

	//Reverse bytes function
	reverse_bytes(seq, length); 

	//Buffer contents after reversing
	cout << "Output: " << seq << "\n";
	for (int ii = 0; ii < length; ++ii) {
		cout << std::bitset<bits>(seq[ii]) << " ";
	}
	cout << "\n";
}
