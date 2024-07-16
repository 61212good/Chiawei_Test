//gcc -o Recursion_Test Recursion_Test.c & Recursion_Test.exe

#include <stdio.h>

//	1. Towers
void Towers(int n, char A, char C, char B){
	if (n == 1){
		printf("Move disk%d, from %c to %c\n", n, A, C);
	}else{
		Towers(n-1, A, B, C);

		printf("Move disk%d, from %c to %c\n", n, A, C);
		
		Towers(n-1, B, C, A);
	}
}

//	2. Greatest Common Divisor (GCD)
int GCD(int A, int B){
	if ((A % B) == 0){
		return B;
	}else{
		return GCD(B, (A % B));
	}
}

int main(){
	//	1. Towers
	char A = 'A';	char B = 'B';	char C = 'C';
	Towers(2, A, C, B);

	//	2. Greatest Common Divisor (GCD)
	printf("\nGCD(100, 60) = %d\n", GCD(100, 60));
	printf("GCD(100, 7) = %d\n", GCD(100, 7));

	return 0;
}

/*	Towers tracking

Towers_org =>
					01	 |	 |
					02	 |	 |
					03	 |	 |
					04___|___|
					(A)	(B)	(C)

Towers(4, placeA, placeC, placeB);
|->	Towers(3, placeA, placeB, placeC);
|	|->	Towers(2, placeA, placeC, placeB);
|	|	|->	Towers(1, placeA, placeB, placeC);
|	|	|	|->	print(“Move disk”, 1, “from”, placeA, “to”, placeB);
|	|	|	|->	|	|	|
|	|	|		2	|	|
|	|	|		3	|	|
|	|	|		4___1___|
|	|	|
|	|	|->	print(“Move disk”, 2, “from”, placeA, “to”, placeC);
|	|	|->	|	|	|
|	|	|	|	|	|
|	|	|	3	|	|
|	|	|	4___1___2
|	|	|
|	|	|->	Towers(1, placeB, placeC, placeA);
|	|		|->	print(“Move disk”, 1, “from”, placeB, “to”, placeC);
|	|		|->	|	|	|
|	|			|	|	|
|	|			3	|	1
|	|			4___|___2
|	|
|	|->	print(“Move disk”, 3, “from”, placeA, “to”, placeB);
|	|->	|	|	|
|	|	|	|	|
|	|	|	|	1
|	|	4___3___2
|	|
|	|->	Towers(2, placeC, placeB, placeA);
|		|->	Towers(1, placeC, placeA, placeB);
|		|	|->	print(“Move disk”, 1, “from”, placeC, “to”, placeA);
|		|	|->	|	|	|
|		|		|	|	|
|		|		1	|	|
|		|		4___3___2
|		|
|		|->	print(“Move disk”, 2, “from”, placeC, “to”, placeB);
|		|->	|	|	|
|		|	|	|	|
|		|	1	2	|
|		|	4___3___|
|		|
|		|->	Towers(1, placeA, placeB, placeC);
|			|->	print(“Move disk”, 1, “from”, placeA, “to”, placeB);
|			|->	|	|	|
|				|	1	|
|				|	2	|
|				4___3___|
|
|->	print(“Move disk”, 4, “from”, placeA, “to”, placeC);
|->	|	|	|
|	|	1	|
|	|	2	|
|	|___3___4
|
|->	Towers(3, placeB, placeC, placeA);
	|->	Towers(2, placeB, placeA, placeC);
	|	|->	Towers(1, placeB, placeC, placeA);
	|	|	|->	print(“Move disk”, 1, “from”, placeB, “to”, placeC);
	|	|	|->	|	|	|
	|	|		|	|	|
	|	|		|	2	1
	|	|		|___3___4
	|	|	
	|	|->	print(“Move disk”, 2, “from”, placeB, “to”, placeA);
	|	|->	|	|	|
	|	|	|	|	|
	|	|	|	|	1
	|	|	2___3___4
	|	|
	|	|->	Towers(1, placeC, placeA, placeB);
	|		|->	print(“Move disk”, 1, “from”, placeC, “to”, placeA);
	|		|->	|	|	|
	|			|	|	|
	|			1	|	|
	|			2___3___4
	|
	|->	print(“Move disk”, 3, “from”, placeB, “to”, placeC);
	|->	|	|	|
	|	|	|	|
	|	1	|	3
	|	2___|___4
	|
	|->	Towers(2, placeA, placeC, placeB);
		|->	Towers(1, placeA, placeB, placeC);
		|	|->	print(“Move disk”, 1, “from”, placeA, “to”, placeB);
		|	|->	|	|	|
		|		|	|	|
		|		|	|	3
		|		2___1___4
		|
		|->	print(“Move disk”, 2, “from”, placeA, “to”, placeC);
		|->	|	|	|
		|	|	|	2
		|	|	|	3
		|	|___1___4
		|
		|->	Towers(1, placeB, placeC, placeA);
			|->	print(“Move disk”, 1, “from”, placeB, “to”, placeC);
			|->	|	|	1
				|	|	2
				|	|	3
				|___|___4

Towers_finish =>
					 |	 |	 01
					 |	 |	 02
					 |	 |	 03
					 |___|___04
					(A)	(B)	(C)
*/
