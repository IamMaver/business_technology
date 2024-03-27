using System;

class Program
{
    static void Merge(int[] A, int p, int q, int r)
    {
        int n1 = q - p + 1;
        p--;
        q--;
        r--;
        // Эти три строчки кода введены из-за того, что в задании массив индексируется с 1, но в С# массивы с 0

        int[] tempArray = new int[n1];

        int i;

        for (i = 0; i < n1; i++)
        {
            tempArray[i] = A[p + i];
        }

        i = 0;
        int j = q + 1; 
        int k = p;

        while (i < n1 && j <= r)
        {
            if (tempArray[i] <= A[j])
            {
                A[k] = tempArray[i];
                i++;
            }
            else
            {
                A[k] = A[j];
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            A[k] = tempArray[i];
            i++;
            k++;
        }
    }

    static void Sort(int[] A, int p, int r)
    {
        if (p < r)
        {
            int q = (p + r) / 2; // Находим середину массива
            Sort(A, p, q);       // Рекурсивно сортируем левую половину
            Sort(A, q + 1, r);    // Рекурсивно сортируем правую половину
            Merge(A, p + 1, q + 1, r + 1);    // Объединяем две отсортированные половины
        }
    }

    static void Main()
    {
        // Пример использования функции Sort с Merge
        int[] A = { 12, 11, 13, 5, 6, 7 };
        int p = 0;
        int r = 5;

        Sort(A, p, r);

        // Вывод отсортированного массива
        Console.Write("Отсортированный массив: ");
        for (int i = p; i <= r; i++)
            Console.Write(A[i] + " ");

        Console.ReadLine(); // Чтобы консольное окно не закрывалось сразу
    }
}
