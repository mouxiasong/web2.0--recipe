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

                   判断栈是否为空，若为空则返回true，非空则返回false

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

                   出栈操作，若正常出栈则返回success，若栈内无元素则返回underflow

          */

	ErrorCode pop(){
		if(pTop->next!=null)
			next.pop();
		return success;
		else
			return underfow;
	}

         /*

                   获取栈顶元素，若正常获取到栈顶元素则返回success，若栈内无元素则返回underflow

                   元素内容保存在引用参数item中

          */

	ErrorCode top(StackEntry &item) const{
	if(*pTop!=null)
		item.data=next.data;
	    return success;
	else
		return underflow;
	}

         /*

                   入栈操作，若正常入栈则返回success，若入栈失败则返回overflow

          */

	ErrorCode push(const StackEntry &item){
	if(item.push())
		return success;
	else
		return overflow;
	}

         /*

                   清空栈

          */

	void clear(){
	this.pop();
	}

private:

         Node<StackEntry> *pTop;

};