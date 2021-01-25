slicing
``` C++
example.cpp
-------------
class A{
	public:
		A():dataOne(2){}
		virtual void whoami(){
			cout << "CLASS A" << endl;
		}
	private:
		int datOne;
};

class B : public A{
	public:
		B():dataTwo(9){}
		virtual void whoami(){
			cout << "CLASS B" << endl;
		}
	private:
		int dataTwo();
};


int main(){
	A objectA;		//has dataOne 
	B objectB;		//has dataOne and dataTwo
	
	objectA = objectB;		//only copies dataOne into objectA, still a A object
							//this is called slicing
	objectA.whoami();	//outputs "CLASS A"
}

```
slicing does not occur with pointers and references!!!
`A &refA = B;`
can only call stuff defined in A, but runs the methods in B
```c++
	B* ptrB = new B();
	A* ptrA = ptrB;
	prtA -> whoami(); //outputs "class B"
```
what you can call is defined by the class type (compile time)
where it gets called (the implementation) is defined by the object type (run time)


slicing can be non obvious
```c++
class ick
{
	A foo(A x){
		return (something that is an A);
	}
	
};

ick* c = new ick();
B* b = new b();
A* a = &c->foo(*b);		//passing in a B object when it takes an A type, will slice B so it fits A
```


calling constructors in a super class
```c++
class box{
	private:
		int val;
	public:
		box(int v): val(v){}
};

class bigBox: public box{
	private:
		double dval;
	public:
		bigBox(double d, int v):	//note colon required box(v) must be in the initializer
			box(v), dval(v){}
};

```

combining constructors
```c++
class A{
	public:
	A(int i){
	}
	A(int i, int j){
		A(i);	//calling other constructor	
	}
};
```


visibility modifies
- public
- private
- protected
- c++ allows the subclass to change the visibility of the super class (in some sense)

```c++
class parent{
	public:
		virtual void test(){	//test() is public in the parent
			cout << "in parent" <<endl;
		}
};

class child : public parent{
	private:
		void test(){		//test() is private in the child
			cout << "in child" endl;
		}
};

int main(){
	Parent* p = new child();
	p->test();	//outputs in child
}

int main(){
	child* c = new child();
	c->test();		//syntax error
					//if child did not have the private test method
					//would work fine and output would be "in parent"
}
```

types of inheritance
![[Pasted image 20201103135030.png]]
polymorphism examples
![[Pasted image 20201105130558.png]]
![[Pasted image 20201105133914.png]]