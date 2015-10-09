enum ErrorCode

{

         success,

         underflow,

         overflow
};
template <class StackEntry>
struct Node
{
         StackEntry data;
         Node *next;
};

template <class StackEntry>
class MyStack

{

public:

	MyStack(){}

         /*

                   �ж�ջ�Ƿ�Ϊ�գ���Ϊ���򷵻�true���ǿ��򷵻�false

          */

	bool empty() const{
		if(pTop->next==null)
		return true;
	else
		return false;
	}

	int size() const{
	int count=0;
	if(pTop->next!=null)
		count++;
	return count;
	}

         /*

                   ��ջ��������������ջ�򷵻�success����ջ����Ԫ���򷵻�underflow

          */

	ErrorCode pop(){
		if(pTop->next!=null)
			next.pop();
		return success;
		else
			return underfow;
	}

         /*

                   ��ȡջ��Ԫ�أ���������ȡ��ջ��Ԫ���򷵻�success����ջ����Ԫ���򷵻�underflow

                   Ԫ�����ݱ��������ò���item��

          */

	ErrorCode top(StackEntry &item) const{
	if(*pTop!=null)
		item.data=next.data;
	    return success;
	else
		return underflow;
	}

         /*

                   ��ջ��������������ջ�򷵻�success������ջʧ���򷵻�overflow

          */

	ErrorCode push(const StackEntry &item){
	if(item.push())
		return success;
	else
		return overflow;
	}

         /*

                   ���ջ

          */

	void clear(){
	this.pop();
	}

private:

         Node<StackEntry> *pTop;

};