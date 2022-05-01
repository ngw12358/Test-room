// 서로 크기가 다른 배열을 변환하는 다음 2개 static 멤버 함수를 가진 ArrayUtility2 클래스를 만들어라
// 아래 코드와 주석을 이해하고 필요한 내용을 코딩함.
//
#include <iostream>
#include <string>
using namespace std;

class ArrayUtility2 {
public:
	static int* concat(int s1[], int s2[], int size_s1, int size_s2); // s1과 s2를 연결한 새로운 배열을 동적 생성하고 포인터 리턴
	                                                                  // size_s1, size_s2는 각각 배열 s1과 s2의 크기
	static int* remove(int s1[], int s2[], int size_s1, int size_s2, int&retSize); // s1에서 s2에 있는 숫자를 모두 삭제한 새로운 배열을 동적 생성하여 리턴
	                                                                               // return하는 배열의 크기는  retSize에 전달
};

// 위에 코드는 수정 불가

//여기에 코드 작성

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
/* 입력과 출력 예제
(출력)Enter number of integer : (입력)5
(출력)Enter 5 integer(s) : (입력)1 2 4 5 6
(출력)Enter number of integer : (입력)7
(출력)Enter 7 integer(s) : (입력)2 4 6 7 9 0 10
(출력)1 2 4 5 6 2 4 6 7 9 0 10
(출력)1 5


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

   // 합친 정수 배열을 출력한다
    for(int i=0; i< size1 + size2 ;  i++) cout << p[i] << ' ';
    cout << endl;

    int retSize;
    int* q = ArrayUtility2::remove(x, y, size1, size2, retSize);

     //배열 x[]에서 y[]를 뺀 결과를 출력한다;
    for(int i=0; i< retSize ; i++) cout << q[i] << ' ';
    cout << endl;

    delete [] p;
    delete [] q;
    delete [] x;
    delete [] y;

}
