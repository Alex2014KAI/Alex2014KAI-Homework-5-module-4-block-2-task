#include <iostream>

#define WORK
void print_dynamic_array(int* arr, int logical_size, int actual_size);
int* append_to_dynamic_array(int* arr, int& logical_size, int& actual_size, int newData);

// #define QUESTION
void debugAppend_to_dynamic_array(int* arr, int& logical_size, int& actual_size, int newData);

int main()
{
    setlocale(LC_ALL, "RU");

    int actual_size{ 0 };
    int logical_size{ 0 };


    std::cout << "Введите фактичеcкий размер массива: ";
    std::cin >> actual_size;

    int* arr = new int[actual_size];

    std::cout << "Введите логический размер массива: ";
    std::cin >> logical_size;

    if (logical_size > actual_size) {
        std::cout << "Ошибка! Логический размер массива не может превышать фактический!";
        return 0;
    }
    else {
        for (size_t i = 0; i < logical_size; i++)
        {
            std::cout << "Введите arr[" << i << "]: ";
            std::cin >> arr[i];
        };
    };

    print_dynamic_array(arr, logical_size, actual_size);

    while (true) {
        std::cout << "Введите элемент для добавления: ";
        int newData{ 0 };
        std::cin >> newData;
        if (newData == 0) {
            break;
        }
        else {
            
#ifdef WORK
            arr = append_to_dynamic_array(arr, logical_size, actual_size, newData);
            print_dynamic_array(arr, logical_size, actual_size);
#endif // !WORK

           
#ifdef QUESTION
            debugAppend_to_dynamic_array(arr, logical_size, actual_size, newData);
            print_dynamic_array(arr, logical_size, actual_size);
#endif // !QUESTION

            
        }
    }

    delete[] arr;
    return 0;
}

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    std::cout << "Динамический массив: ";

    for (int i = 0; i < actual_size; i++)
    {
        if (i < logical_size) {
            std::cout << arr[i] << " ";
        }
        else {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
};

int* append_to_dynamic_array(int* arr, int& logical_size, int& actual_size, int newData) {
    logical_size++;

    if (logical_size < actual_size) {
        arr[logical_size - 1] = newData;
    };

    if (logical_size == actual_size) {
        int* copyArr = new int[logical_size];
        for (int i = 0; i < (logical_size - 1); i++)
        {
            copyArr[i] = arr[i];
        };
        copyArr[logical_size - 1] = newData;

        actual_size *= 2;
        delete[] arr;
        
        arr = new int[actual_size];
        for (int i = 0; i < logical_size; i++)
        {
            arr[i] = copyArr[i];
        };
        delete[] copyArr;
    };

    return arr;
};


void debugAppend_to_dynamic_array(int* arr, int& logical_size, int& actual_size, int newData) {
    logical_size++;

    if (logical_size < actual_size) {
        arr[logical_size - 1] = newData;
    };

    if (logical_size == actual_size) {
        int* copyArr = new int[logical_size];
        for (int i = 0; i < (logical_size - 1); i++)
        {
            copyArr[i] = arr[i];
        };
        copyArr[logical_size - 1] = newData;

        actual_size *= 2;

        delete[] arr;
        arr = new int[actual_size];

        for (int i = 0; i < logical_size; i++)
        {
            arr[i] = copyArr[i];
        };
        delete[] copyArr;
    };
}