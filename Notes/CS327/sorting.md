- quick sort example
	- want qsort(array, length); 
	- in java you have a comparator
	- in c can use pointers to functions
	- ex:
		```c
		eval.c
		float plus(float a, floatb){
			return a+b;
		}
		float minus(float a, float b){
			return a-b;
		}
		float multiply(float a, float b){
			return a*b;
		}
		.
		.
		.
		
		float evaluate(float a, float b, char op){
			float result;
			switch(op){
				case '+':
					result = plus(a,b);
					break;
				case '-':
					result = minus(a,b);
					break;
				.
				.
				.
			}
			return result;
		}
		```
		
		better way:
		#functionPointer
		**can also declare variables that are pointers to functions**
		float (\*opfunc)(float, float)
		^expects a pointer to a function with two float arguments
		```c
		float evaluate(float a, float b, float (*opfunc)(float, float)){
			return opfunc(a, b);
		}
		
		main(){
			float (*func)(float, float);
			//declares variable called func to be a pointer
			//to a function that returns a float and takes 
			//to float arguments
			
			func = &plus;
			evaluate (2.0, 3.0, func);
		}
		```