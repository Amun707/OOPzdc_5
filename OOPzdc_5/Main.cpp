#include <iostream>
#include <string>
#include <queue>//очереди стандартной библиотеки
#include <stack>//очереди
//Коллекции и шаблонные классы
//типы коллекций:
// -линейные массивы
//                - динамический vector
//                 -cтатический array
// -списки
//        -односвязные forward_list,
//        - двусвязные list
//        - кольца
// -деревья, set, map, и их производные
// -графы
// =========
// * очереди FIFO first inside first outside  | queue
// * стэки FILO first inside last outside     | stack
//

//коллекции данных
//реализация динамического массива
class DinamicArray {
public:
	DinamicArray() :data_(nullptr), size_(0) {}//конструктор по умолчанию заполняет нулями
	//конструктор копирования
	DinamicArray(const DinamicArray& other) {
		size_ = other.size_;
		data_ = new float[size_];
		for (int i = 0; i < size_; i++) {//переносим данные другого класса себе
			data_[i] = other.data_[i];
		}
	}

	//конструктор переноса
	DinamicArray(DinamicArray&& other) {//&& -  объект имеет короткий срок жизни и более в программе использоваться не будет
		this->size_ = 0;
		this->data_ = nullptr;
		std::swap(data_, other.data_);
		std::swap(size_, other.size_);
	}

	~DinamicArray() {   //деструктор, который смотрит содержимое и удаляет
		if (data_)      //если в поле data_ что то есть
			delete[]data_;

	}
	//метод добавления
	void AddBack(float value) {//если в поле data_ есть что то(ненулевой указатель),
		//то мы сохраняем и дополняем данные, на один элемент больше, чем у нас есть
		if (data_) {
			auto tmp = new float[size_ + 1];//auto - самоопределение, возвращает тип данных справа от auto
			for (size_t i = 0; i < size_; i++)//size_t - это беззнаковый 64 битный целый тип данных(очень большой)
			{
				tmp[i] = data_[i];
			}
			tmp[size_] = value;//на последнем месте массива размещаем value
			std::swap(tmp, data_);//меняем местами массивы
			size_ += 1;
			delete[]tmp;//освобождаем ненужную память
		}
		else {//если в поле дата ничего нет
			data_ = new float[1] {value};
			size_ += 1;
		}
	}

	//метод удаления с конца коллекции
	void PopBack() {//удалить чтото из конца коллекции(если она заполнена чем то)
		if (data_) {//если в поле data_ есть ненулевой указатель
			auto tmp = new float[size_ - 1];
			for (size_t i = 0; i < size_ - 1; i++) {
				tmp[i] = data_[i];
			}
			std::swap(tmp, data_);//меняем местами массивы
			size_ -= 1;//уменьшаем размер массива
			delete[]tmp;//освобождаем память
			if (size_ == 0) {//если в массиве ничего нет
				delete[] data_;//чтобы ОС помнила, что она под нас выделила - ничего...
				data_ = nullptr;//поле data_ на нулевой указатель, так как результат deleyte[] - муссорный адрес
			}
		}
	}

	float& operator[](int n) {//обращение к элементу массива нашего класса
		return data_[n];
	}
	const float& operator[](int n)const {//чтобы работал константный метод
		return data_[n];
	}

	//оператор присваивания копированием
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
	//оператор присваивания переносом
	DinamicArray& operator = (DinamicArray&& other) {
		std::swap(data_, other.data_);
		std::swap(size_, other.size_);
		return *this;
	}

private:
	float* data_;//указатель на данные где храним
	int size_;//сколько храним
	//int capacity_; требуется для более сложной но эфективной работы с выделенной памятью
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

	//перевести в строку дз
	//auto tmp =  std::to_string(2.65);
	//std::cout << tmp;

	return 0;
}