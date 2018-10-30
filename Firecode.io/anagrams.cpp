/*
   Write a method is_anagram that checks if two lowercase input Strings are
   anagrams of each other. An anagram of a String is a String that is formed
   by simply re-arranging its letters, using each letter exactly once. Your
   algorithm should run in linear O(n) time and use constant O(1) space.

   Examples:
   is_anagram("abc","cab") => true
   is_anagram("b","b") => true
   is_anagram("bd","cb") => false
 */

bool is_anagram(string input1, string input2){
	int s1 = 0;
	int s2 = 0;
	for(int i = 0; i < input1.size(); i++) {
		s1 += input1[i];
		s2 += input2[i];
	}
	if(input1.size() == input2.size() && s1 == s2) {
		return true;
	} else {
		return false;
	}
}
