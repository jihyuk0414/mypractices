# include <cassert>

template < class queueElementType >
class Queue { 
public:
	Queue();
	~Queue();
	void enqueue(queueElementType e);
	queueElementType dequeue(); 
	queueElementType front(); 
	bool isEmpty(); 
private:
	struct Node; 
	typedef Node* nodePtr; 
	struct Node { 
		queueElementType data;
		nodePtr next; }; 
	nodePtr f; 
	nodePtr r; 
};

template < class queueElementType >
Queue < queueElementType >::Queue()
{// set both front and rear to null pointers
	f = 0;
	r = 0;
}

template < class queueElementType >
Queue < queueElementType >::~Queue()
{// set both front and rear to null pointers
	while (f!= 0)
	{
		nodePtr delNode = f;
		f = f->next;
		delete delNode;
	}
}

template < class queueElementType >
void Queue < queueElementType >::enqueue(queueElementType e)
{// create a new node, insert it at the rear of the queue
	nodePtr n(new Node);
	assert(n);
	n->next = 0;
	n->data = e;
	if (f != 0)
	{ // existing queue is not empty
		r->next = n;
		// add new element to end of list
		r = n;
	}
	else {
		// adding first item in the queue
		f = n;
		// so front, rear must be same node
		r = n;
	}
}

template < class queueElementType >
queueElementType Queue < queueElementType >::dequeue()
{
	assert(f); // make sure queue is not empty
	nodePtr n(f);
	queueElementType frontElement(f->data);
	f = f->next;
	delete n;
	if (f == 0)
		// we're deleting last node
		r = 0;
	return frontElement;
}

template < class queueElementType >
queueElementType Queue < queueElementType >::front()
{
	assert(f);
	return f->data;
}

template < class queueElementType >
bool Queue < queueElementType >::isEmpty() 
{// true if the queue is empty --when f is a null pointer
	return bool(f == 0);
}