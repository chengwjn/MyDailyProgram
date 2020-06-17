//stack.h -- class definition for the stack ADT
#ifndef STACK_H_
#define STACK_H_
typeof unsigned long Item;
class Stack
{
	private:
				enum{MAx=10};//constant specific to class
				Item items[MAX];//constant specific to class
				int top;//index for top stack item
	public:
				Stack();
				bool isempty() const;
				bool isfull() const;
				//push() returns false if stack already is full,true otherwise
				bool push(const Item &item);//add item to stack
				//pop() returns falseif stack already is empty,true otherwise
				bool pop(Item &item);//pop top into item
};
#endif
