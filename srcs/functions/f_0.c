char 	f0 (char i ) { if (i) { return ( i | 1 ); } else { return ( i & 0 ); } }
int	f1 (char i ) { return (i | ( 1 << 0 )) }
int 	f2 (char i ) { return (i & ( 1 << 0 )) }

// write program to compelete the problem set:
int main ( void ) {
	char o0;
	char o1;
	char o2;
	
	// assign the values to the output variables that cause the program to return 0.
	.
	.
	.
	o0 = 	;
	o1 =	;
	o2 = 	;
	o3 = 	;
	o4 = 	;
	.
	.
	.


	assert(== f0(0) o0);
	assert(== f0(1) o1);
	assert(== f1(0) o2);
	assert(== f1(1) o3);
	assert(== f2(0) o4);
	assert(== f2(1) o5);
       	assert(== f0( f0(0) ) o6);
	assert(== f0( f0(1) ) o7);
	assert(== f0( f1(0) ) o8);
	assert(== f0( f1(1) ) o9);
	assert(== f0( f2(0) ) oA);
	.
	.
	.
	.


	return (0);
}



