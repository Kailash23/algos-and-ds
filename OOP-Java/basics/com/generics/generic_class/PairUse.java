package com.generics.generic_class;

public class PairUse {
	public static void main(String args[]){
		// Pair<int> p = new Pair<int>(1,2);
		// p.setFirst(10);
		// System.out.println(p.getFirst());
		// System.out.println(p.getSecond());

		Pair<String> ps = new Pair<String>("ab","bv");
		System.out.println(ps.getFirst());
		System.out.println(ps.getSecond());

		ps.setFirst("def");
		String s = ps.getFirst();
		System.out.println(s);

		Pair p = new Pair(1,2);   // Warning: Here T will be object by default - Problematic
		p.setFirst("abc");

		// Pair<int> p1 = new Pair<int>(1,2);    // Can't do this cause int is primitive datatype, only subclass of object are allowed.


		Pair<Integer> p1 = new Pair<Integer>(1,2);		//Integer - non primitive datatype

		Pair<Character> ch = new Pair<Character>('a','b');		// No need to write Character again

		Pair2<String, String> a1 = new Pair2<String, String>("ab","bv");
		Pair2<Integer, String> a2 = new Pair2<Integer, String>(2,"bv");
		Pair2<Character,Character> chr = new Pair2<Character,Character>('a','b');

		int a = 10;
		int b = 12;
		int c = 23;

		Pair2<Integer, Integer> internalPair = new Pair2<>(a,b);
		Pair2<Pair2<Integer, Integer>, Integer> p3 = new Pair2<>(internalPair,c);
		System.out.println(p3.getSecond());
		System.out.println(p3.getFirst().getFirst());
		System.out.println(p3.getFirst().getSecond());

	}
}

/*
   ab
   bv
   def
   23
   10
   12
 */
