//this指针：
//对于Stock类，还有很多工作要做。至此，每个类成员函数都只涉及到一个对象，即调用它的对象。
//但有时候方法可能涉及到两个对象，在这种情况下需要使用c++的指针。
class Stock
{
	private:
	 double total_val;
	public:
	double total() const{return total_val;}
};
//就直接程序访问而言，上述定义实际上是使total_val为只读。也就是说，可以使用方法total_val()来获得total_val的值，但这个类没有提供专用用于重新设置total_val的值的方法
