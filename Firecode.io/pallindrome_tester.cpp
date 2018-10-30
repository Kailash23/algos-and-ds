/*
   A palindrome is a string or sequence of characters that reads the same backward
   as forward. For example, "MADAM" is a palindrome.
   Write a function that takes in an input string: str and returns true if the input
   string is a palindrome, false otherwise.
   An empty string is considered a palindrome. You also need to account for the space
   character - i.e. "race car" should return false as read backward it is "rac ecar".
 */

bool is_string_palindrome(string str){
	if(str.size() <= 1) {
		return true;
	}
	bool smallAns;
	if(str[0] == str[str.size() - 1]) {
		smallAns = true;
	} else {
		smallAns = false;
	}
	return smallAns && is_string_palindrome(str.substr(1, str.size() - 2));
}
