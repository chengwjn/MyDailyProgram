#include<iostream>
int main()
{
	using namespace std;
	int updates=6;//declare a variable 
	int *p_updates;//declare pointer to an init
	p_updates=&updates;//assign address of int to pointer,��int�ĵ�ַ�����ָ��
	
	//express values two ways
	cout<<"Values:updates="<<updates;
	cout<<",*p_updates="<<*p_updates<<endl;
	
	//express address two ways��ʾ�洢��ַ 
	cout<<"Address:&updates="<<&updates;
	cout<<",p_updates="<<p_updates<<endl;
	
	//use pointer to change value
	*p_updates=*p_updates+1;
	cout<<"Now updates="<<updates<<endl;
	
	return 0;
	
	//int����updates��ָ�����p_updates������updates��ʾֵ����ʹ��&���������ȡ��ַ��������p_updates��ʾ��ַ����ʹ��*����������ֵ������p_updatesָ��updates
	// ���*p_updates��updates��ȫ�ȼۡ�������ʹ��int��������ʹ��*p_updates�� 
} 
