#include <bits/stdc++.h>
using namespace std;


class Node {
public:
	int data;
	Node* next;
public:
	Node(int data1, Node* next1) {
		data = data1;
		next = next1;
	}
public:
	Node(int data1) {
		data = data1;
		next = nullptr;
	}
};

//Convert Array to L.L
Node* convertArr2LL(vector<int> &arr) {
	Node* head = new Node(arr[0]);
	Node* mover = head;
	for (int i = 0; i < arr.size(); i++) {
		Node* temp = new Node(arr[i]);
		mover->next = temp;
		mover = temp;
	}
	return head;

}


// Remove head of L.L
Node* removesHead(Node* head) {
	if (head == NULL) return head;
	Node* temp = head;
	head = head->next;
	delete temp;
	return head;
}

//Remove Tail of L.L
Node* removeTail(Node* head) {
	if (head == NULL  || head->next == NULL) return NULL;
	Node* temp = head;
	while (temp->next->next != NULL) {
		temp = temp->next;
	}
	delete temp->next;
	temp->next = NULL;

	return head;
}


//delete kth node of L.L
Node* deleteEl(Node* head, int el) {
	if (head == NULL) return head;
	if (head->data == el) {
		Node* temp = head;
		head = head->next;
		delete(temp);
		return head;
	}
	Node* temp = head;
	Node* prev = NULL;
	while (temp != NULL) {
		if (temp->data == el) {
			prev->next = prev->next->next;
			free(temp);
			break;
		}
		prev = temp;
		temp = temp->next;
	}
	return head;
}

//Insert to head
Node* insertHead(Node* head, int val) {
	Node* temp = new Node(val, head);
	return temp;
}


//Insert to tail
Node* insertTail(Node* head, int val) {
	if (head == NULL) {
		return new Node(val);
	}
	Node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	Node* newNode = new Node(val);
	temp->next = newNode;
	return head;
}

//Insert at any position
Node* insertPosition(Node* head, int el, int k) {
	if (head == NULL) {
		if (k == 1) {
			return new Node(el);
		}
		else {
			return head;
		}
	}

	if (k == 1) {
		return new Node(el, head);
	}
	int cnt = 0;
	Node* temp = head;
	while (temp != NULL) {
		cnt++;
		if (cnt == (k - 1)) {
			Node* x = new Node(el, temp->next);
			temp->next = x;
			break;
		}
		temp = temp->next;
	}
	return head;
}

void print(Node* head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	vector<int> arr = {9, 5, 8, 7};
	Node* head = convertArr2LL(arr);
	// cout << head->data << endl;

	// Node* temp = head;
	// while (temp != NULL) {
	// 	cout << temp->data << endl;
	// 	temp = temp->next;

	// }

	//Remove head
	head = removesHead(head);
	cout << head << endl;

	//Remove tail
	head = removeTail(head);
	cout << head;

	head = insertHead(head, 100);
	cout << head;



	// return 0;
}


















