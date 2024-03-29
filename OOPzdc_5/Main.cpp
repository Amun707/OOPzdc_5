#include <iostream>
#include <string>
#include <queue>//������� ����������� ����������
#include <stack>//�������
//��������� � ��������� ������
//���� ���������:
// -�������� �������
//                - ������������ vector
//                 -c���������� array
// -������
//        -����������� forward_list,
//        - ���������� list
//        - ������
// -�������, set, map, � �� �����������
// -�����
// =========
// * ������� FIFO first inside first outside  | queue
// * ����� FILO first inside last outside     | stack
//

//��������� ������
//���������� ������������� �������
class DinamicArray {
public:
	DinamicArray() :data_(nullptr), size_(0) {}//����������� �� ��������� ��������� ������
	//����������� �����������
	DinamicArray(const DinamicArray& other) {
		size_ = other.size_;
		data_ = new float[size_];
		for (int i = 0; i < size_; i++) {//��������� ������ ������� ������ ����
			data_[i] = other.data_[i];
		}
	}

	//����������� ��������
	DinamicArray(DinamicArray&& other) {//&& -  ������ ����� �������� ���� ����� � ����� � ��������� �������������� �� �����
		this->size_ = 0;
		this->data_ = nullptr;
		std::swap(data_, other.data_);
		std::swap(size_, other.size_);
	}

	~DinamicArray() {   //����������, ������� ������� ���������� � �������
		if (data_)      //���� � ���� data_ ��� �� ����
			delete[]data_;

	}
	//����� ����������
	void AddBack(float value) {//���� � ���� data_ ���� ��� ��(��������� ���������),
		//�� �� ��������� � ��������� ������, �� ���� ������� ������, ��� � ��� ����
		if (data_) {
			auto tmp = new float[size_ + 1];//auto - ���������������, ���������� ��� ������ ������ �� auto
			for (size_t i = 0; i < size_; i++)//size_t - ��� ����������� 64 ������ ����� ��� ������(����� �������)
			{
				tmp[i] = data_[i];
			}
			tmp[size_] = value;//�� ��������� ����� ������� ��������� value
			std::swap(tmp, data_);//������ ������� �������
			size_ += 1;
			delete[]tmp;//����������� �������� ������
		}
		else {//���� � ���� ���� ������ ���
			data_ = new float[1] {value};
			size_ += 1;
		}
	}

	//����� �������� � ����� ���������
	void PopBack() {//������� ����� �� ����� ���������(���� ��� ��������� ��� ��)
		if (data_) {//���� � ���� data_ ���� ��������� ���������
			auto tmp = new float[size_ - 1];
			for (size_t i = 0; i < size_ - 1; i++) {
				tmp[i] = data_[i];
			}
			std::swap(tmp, data_);//������ ������� �������
			size_ -= 1;//��������� ������ �������
			delete[]tmp;//����������� ������
			if (size_ == 0) {//���� � ������� ������ ���
				delete[] data_;//����� �� �������, ��� ��� ��� ��� �������� - ������...
				data_ = nullptr;//���� data_ �� ������� ���������, ��� ��� ��������� deleyte[] - ��������� �����
			}
		}
	}

	float& operator[](int n) {//��������� � �������� ������� ������ ������
		return data_[n];
	}
	const float& operator[](int n)const {//����� ������� ����������� �����
		return data_[n];
	}

	//�������� ������������ ������������
	DinamicArray& operator = (const DinamicArray& other) {
		if (data_) {
			delete[]data_;
		}
		size_ = other.size_;
		data_ = new float[size_];
		for (int i = 0; i < size_; ++i) {
			data_[i] = other.data_[i];
		}
		return *this;
	}
	//�������� ������������ ���������
	DinamicArray& operator = (DinamicArray&& other) {
		std::swap(data_, other.data_);
		std::swap(size_, other.size_);
		return *this;
	}

private:
	float* data_;//��������� �� ������ ��� ������
	int size_;//������� ������
	//int capacity_; ��������� ��� ����� ������� �� ���������� ������ � ���������� �������
};

void FOO(DinamicArray obj) {}
DinamicArray Gen(int length) {
	DinamicArray result;
	for (size_t i = 0; i < length; i++)
	{
		result.AddBack(::rand() % 10);
	}
	return result;
}

int main() {
	system("chcp 1251>nul");
	DinamicArray arrd;
	arrd.AddBack(1234.5);
	std::cout << arrd[0];
	FOO(arrd);
	arrd.PopBack();
	DinamicArray arrd2 = Gen(15);
	DinamicArray();

	//��������� � ������ ��
	//auto tmp =  std::to_string(2.65);
	//std::cout << tmp;

	return 0;
}