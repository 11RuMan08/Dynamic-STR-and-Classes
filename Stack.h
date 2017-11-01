
struct node_s {
	int data;
	node_s* prev;
};

class Stack {
private:
	int size;
	node_s* top = nullptr;

public:
	int pop();
	void push(int);
	int get_size();
	bool isEmpty();
};
