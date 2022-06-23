#include <iostream>
#include <climits>
using namespace std;

class myArray {
	private:
		int size_;
		int array_[100];
	public:
		myArray(int n) {
			size_ = n;
		}

		void recInput(int array[], int n) {
			if (n == 0) {
				return;
			}

			array_[n-1] = array[n-1];

			recInput(array, n-1);
		}

		int recMax(int n) {
			return recMaxHelper(n, INT_MIN);
		}

		int recMaxHelper(int n, int localMax) {
			if (n == 0) {
				return localMax;
			}

			if (array_[n-1] > localMax) {
				localMax = array_[n-1];
			}

			return recMaxHelper(n-1, localMax);
		}

		int recSum(int n) {
			return recSumHelper(n, 0);
		}

		int recSumHelper(int n, int sum) {
			if (n == 0) {
				return 0;
			}

			return array_[n-1] + recSumHelper(n-1, sum);
		}

		float recAve(int n) {
			return recAveHelper(n, n, 0);
		}

		float recAveHelper(int n, int size, float sum) {
			if (n == 0) {
				return sum / size;
			}

			return recAveHelper(n-1, size, array_[n-1] + sum);
		}
};

int main(int argc, char const *argv[])
{
	int size = 5;
	int array[] = {500, 1, 2, 3, 4};
	myArray A(size);
	A.recInput(array, size);
	cout << "The max is:  " << A.recMax(size) << endl;
	cout << "The sum is:  " << A.recSum(size) << endl;
	cout << "The avr is:  " << A.recAve(size) << endl;
	return 0;
}