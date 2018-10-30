/*
   Implement a method that checks if two strings are permutations of each other.

   permutation("CAT","ACT") --> true
   permutation("hello","aloha") --> false
 */

bool permutation(string input1, string input2){
	int s1 = 0;
	int s2 = 0;
	for(int i = 0; i < input1.size(); i++) {
		s1 += input1[i];
		s2 += input2[i];
	}
	if(s1 == s2 && input1.size() == input2.size()) {
		return true;
	} else {
		return false;
	}
}
