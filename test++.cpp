// ���� ũ�Ⱑ �ٸ� �迭�� ��ȯ�ϴ� ���� 2�� static ��� �Լ��� ���� ArrayUtility2 Ŭ������ ������
// �Ʒ� �ڵ�� �ּ��� �����ϰ� �ʿ��� ������ �ڵ���.

#include <iostream>
#include <string>
using namespace std;

class ArrayUtility2 {
public:
	static int* concat(int s1[], int s2[], int size_s1, int size_s2); // s1�� s2�� ������ ���ο� �迭�� ���� �����ϰ� ������ ����
	                                                                  // size_s1, size_s2�� ���� �迭 s1�� s2�� ũ��
	static int* remove(int s1[], int s2[], int size_s1, int size_s2, int&retSize); // s1���� s2�� �ִ� ���ڸ� ��� ������ ���ο� �迭�� ���� �����Ͽ� ����
	                                                                               // return�ϴ� �迭�� ũ���  retSize�� ����
};

// ���� �ڵ�� ���� �Ұ�

//���⿡ �ڵ� �ۼ�

int* ArrayUtility2::concat(int s1[], int s2[], int size_s1, int size_s2) {
	int i, *p=new int[size_s1+size_s2];
	for(i=0;i<size_s1;i++)
		p[i]=s1[i];
	for(int k=0;k<size_s2;k++) {
		p[i]=s2[k];
		i++;
	}
	return p;
}

int* ArrayUtility2::remove(int s1[], int s2[], int size_s1, int size_s2, int &retSize) {
	int count=size_s1, i, j, count2=0;

	for(i=0;i<size_s1;i++)
		for(j=0;j<size_s2;j++)
			if(s1[i]==s2[j])
				count--;

	retSize=count;
	int* q=new int[retSize];

	for(i=0;i<size_s1;i++) {
		count=0;

		for(j=0;j<size_s2;j++) {
			if(s1[i]==s2[j])
				count++;
		}
		if(count==0) {
			q[count2]=s1[i];
			count2++;
		}
	}

	return q;
}

//
/* �Է°� ��� ����
(���)Enter number of integer : (�Է�)5
(���)Enter 5 integer(s) : (�Է�)1 2 4 5 6
(���)Enter number of integer : (�Է�)7
(���)Enter 7 integer(s) : (�Է�)2 4 6 7 9 0 10
(���)1 2 4 5 6 2 4 6 7 9 0 10
(���)1 5


*/
int main() {
	int size1;
	int size2;

    int *x, *y;

    cout << "Enter number of integer : ";
    cin >> size1;
    x = new int [size1];

    cout << "Enter " << size1 << " integer(s) : ";
    for(int i=0; i < size1 ; i++)
    	cin >> x[i];

    cout << "Enter number of integer : ";
    cin >> size2;

    if (size1 == size2) {
    	cout << "Input Error";
    	delete [] x;
		return -1;
    }

    y = new int [size2];
    cout << "Enter " << size2 << " integer(s) : ";
    for(int i=0; i < size2 ; i++)
    	cin >> y[i];

    int* p = ArrayUtility2::concat(x, y, size1, size2);

   // ��ģ ���� �迭�� ����Ѵ�
    for(int i=0; i< size1 + size2 ;  i++) cout << p[i] << ' ';
    cout << endl;

    int retSize;
    int* q = ArrayUtility2::remove(x, y, size1, size2, retSize);

     //�迭 x[]���� y[]�� �� ����� ����Ѵ�;
    for(int i=0; i< retSize ; i++) cout << q[i] << ' ';
    cout << endl;

    delete [] p;
    delete [] q;
    delete [] x;
    delete [] y;

}
