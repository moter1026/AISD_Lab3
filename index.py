import pandas as pd
import re
import matplotlib.pyplot as plt

if __name__ == "__main__":
    data_InsertSort_random = {
        "count": [],
        "comparison_count": [],
        "copy_count": []
    }
    data_InsertSort_sort = {
        "count": [],
        "comparison_count": [],
        "copy_count": []
    }
    data_InsertSort_reverse = {
        "count": [],
        "comparison_count": [],
        "copy_count": []
    }


    data_Shaker_random = {
        "count": [],
        "comparison_count": [],
        "copy_count": []
    }
    data_Shaker_sort = {
        "count": [],
        "comparison_count": [],
        "copy_count": []
    }
    data_Shaker_reverse = {
        "count": [],
        "comparison_count": [],
        "copy_count": []
    }


    data_HeapSort_random = {
        "count": [],
        "comparison_count": [],
        "copy_count": []
    }
    data_HeapSort_sort = {
        "count": [],
        "comparison_count": [],
        "copy_count": []
    }
    data_HeapSort_reverse = {
        "count": [],
        "comparison_count": [],
        "copy_count": []
    }


    





    try_encodings = ["cp1251", "utf-8", "utf-8-sig", "latin-1"]

    for encoding in try_encodings:
        try:
            with open("..\\out\\build\\x64-debug\\AISD Lab3\\example.txt", "r", encoding=encoding) as readFile:
                text_of_read = readFile.read()
                
                # Используем регулярное выражение для поиска чисел
                numbers = re.findall(r'\d+', text_of_read)

                # Преобразуем найденные строки в числа
                numbers = list(map(int, numbers))

                for i in range(13):
                    data_InsertSort_random["count"].append(numbers[0+19*i])
                    data_InsertSort_random["comparison_count"].append(numbers[1+19*i])
                    data_InsertSort_random["copy_count"].append(numbers[2+19*i])

                    data_InsertSort_sort["count"].append(numbers[0+19*i])
                    data_InsertSort_sort["comparison_count"].append(numbers[3+19*i])
                    data_InsertSort_sort["copy_count"].append(numbers[4+19*i])

                    data_InsertSort_reverse["count"].append(numbers[0+19*i])
                    data_InsertSort_reverse["comparison_count"].append(numbers[5+19*i])
                    data_InsertSort_reverse["copy_count"].append(numbers[6+19*i])
                


                    data_Shaker_random["count"].append(numbers[0+19*i])
                    data_Shaker_random["comparison_count"].append(numbers[7+19*i])
                    data_Shaker_random["copy_count"].append(numbers[8+19*i])

                    data_Shaker_sort["count"].append(numbers[0+19*i])
                    data_Shaker_sort["comparison_count"].append(numbers[9+19*i])
                    data_Shaker_sort["copy_count"].append(numbers[10+19*i])

                    data_Shaker_reverse["count"].append(numbers[0+19*i])
                    data_Shaker_reverse["comparison_count"].append(numbers[11+19*i])
                    data_Shaker_reverse["copy_count"].append(numbers[12+19*i])



                    data_HeapSort_random["count"].append(numbers[0+19*i])
                    data_HeapSort_random["comparison_count"].append(numbers[13+19*i])
                    data_HeapSort_random["copy_count"].append(numbers[14+19*i])

                    data_HeapSort_sort["count"].append(numbers[0+19*i])
                    data_HeapSort_sort["comparison_count"].append(numbers[15+19*i])
                    data_HeapSort_sort["copy_count"].append(numbers[16+19*i])

                    data_HeapSort_reverse["count"].append(numbers[0+19*i])
                    data_HeapSort_reverse["comparison_count"].append(numbers[17+19*i])
                    data_HeapSort_reverse["copy_count"].append(numbers[18+19*i])
                
                break
        except UnicodeDecodeError:
            continue
                
    dfData_InsertSort_random = pd.DataFrame(data_InsertSort_random)
    dfData_InsertSort_sort = pd.DataFrame(data_InsertSort_sort)
    dfData_InsertSort_reverse = pd.DataFrame(data_InsertSort_reverse)

    dfData_Shaker_random = pd.DataFrame(data_Shaker_random)
    dfData_Shaker_sort = pd.DataFrame(data_Shaker_sort)
    dfData_Shaker_reverse = pd.DataFrame(data_Shaker_reverse)

    dfData_HeapSort_random = pd.DataFrame(data_HeapSort_random)
    dfData_HeapSort_sort = pd.DataFrame(data_HeapSort_sort)
    dfData_HeapSort_reverse = pd.DataFrame(data_HeapSort_reverse)

    print(dfData_InsertSort_random)
    print(dfData_InsertSort_sort)
    print(dfData_InsertSort_reverse)

    print(dfData_Shaker_random)
    print(dfData_Shaker_sort)
    print(dfData_Shaker_reverse)
            
    
    # Строим первый график
    plt.subplot(3, 3, 1)
    plt.plot(dfData_InsertSort_random["count"], dfData_InsertSort_random["comparison_count"], label='Число проверок')
    # Строим второй график
    plt.plot(dfData_InsertSort_random["count"], dfData_InsertSort_random["copy_count"], label='Число копирований')
    # Добавляем заголовок и метки
    plt.title('Рандомный массив сортировки <<<вставками>>>')
    # Включаем легенду
    plt.legend()


    plt.subplot(3, 3, 2)
    plt.plot(dfData_InsertSort_sort["count"], dfData_InsertSort_sort["comparison_count"], label='Число проверок')
    # Строим второй график
    plt.plot(dfData_InsertSort_sort["count"], dfData_InsertSort_sort["copy_count"], label='Число копирований')
    # Добавляем заголовок и метки
    plt.title('сортированный массив')
    # Включаем легенду
    plt.legend()


    plt.subplot(3, 3, 3)
    plt.plot(dfData_InsertSort_reverse["count"], dfData_InsertSort_reverse["comparison_count"], label='Число проверок')
    # Строим второй график
    plt.plot(dfData_InsertSort_reverse["count"], dfData_InsertSort_reverse["copy_count"], label='Число копирований')
    # Добавляем заголовок и метки
    plt.title('обратный массив')
    # Включаем легенду
    plt.legend()


    plt.subplot(3, 3, 4)
    plt.plot(dfData_Shaker_random["count"], dfData_Shaker_random["comparison_count"], label='Число проверок')
    # Строим второй график
    plt.plot(dfData_Shaker_random["count"], dfData_Shaker_random["copy_count"], label='Число копирований')
    # Добавляем заголовок и метки
    plt.title('рандомный массив сортировки <<<шейкерной>>>')
    # Включаем легенду
    plt.legend()

    plt.subplot(3, 3, 5)
    plt.plot(dfData_Shaker_sort["count"], dfData_Shaker_sort["comparison_count"], label='Число проверок')
    # Строим второй график
    plt.plot(dfData_Shaker_sort["count"], dfData_Shaker_sort["copy_count"], label='Число копирований')
    # Добавляем заголовок и метки
    plt.title('сортированный массив')
    # Включаем легенду
    plt.legend()

    plt.subplot(3, 3, 6)
    plt.plot(dfData_Shaker_reverse["count"], dfData_Shaker_reverse["comparison_count"], label='Число проверок')
    # Строим второй график
    plt.plot(dfData_Shaker_reverse["count"], dfData_Shaker_reverse["copy_count"], label='Число копирований')
    # Добавляем заголовок и метки
    plt.title('обратный массив')
    # Включаем легенду
    plt.legend()

    plt.subplot(3, 3, 7)
    plt.plot(dfData_HeapSort_random["count"], dfData_HeapSort_random["comparison_count"], label='Число проверок')
    # Строим второй график
    plt.plot(dfData_HeapSort_random["count"], dfData_HeapSort_random["copy_count"], label='Число копирований')
    # Добавляем заголовок и метки
    plt.title('рандомный массив сортировки <<<пирамидальная>>>')
    # Включаем легенду
    plt.legend()

    plt.subplot(3, 3, 8)
    plt.plot(dfData_HeapSort_sort["count"], dfData_HeapSort_sort["comparison_count"], label='Число проверок')
    # Строим второй график
    plt.plot(dfData_HeapSort_sort["count"], dfData_HeapSort_sort["copy_count"], label='Число копирований')
    # Добавляем заголовок и метки
    plt.title('сортированный массив')
    # Включаем легенду
    plt.legend()

    plt.subplot(3, 3, 9)
    plt.plot(dfData_HeapSort_reverse["count"], dfData_HeapSort_reverse["comparison_count"], label='Число проверок')
    # Строим второй график
    plt.plot(dfData_HeapSort_reverse["count"], dfData_HeapSort_reverse["copy_count"], label='Число копирований')
    # Добавляем заголовок и метки
    plt.title('обратный массив')
    # Включаем легенду
    plt.legend()

    # Отображаем график
    plt.show()
