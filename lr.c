#include <stdio.h>
#include "lr.h"


void h(float L, int t1, int t2)   // процедура h
{

    if (t2 > t1) {                                                                   // условие, если время против течения больше чем по выполнять следующие условия
        printf("%g = (%g / %d - %g / %d) / 2\n", (L / t1 - L / t2) / 2, L, t1, L, t2); // вывод на экран решение задачи
        printf("River flow = %g\n", (L / t1 - L / t2) / 2);                      // вывод на экран ответ задачи "River flow = "
    }
    else                                                                        // иначе
        printf("Error (t2<t1) it should be like this:(t2>t1)");                // вывод ошибки
}

float fun(double base,int current, int max)
{

    //знак буду вычислять как i%2==0?1:-1;

    if (current == max)
        return base;
    base += (current % 2 == 0 ? 1 : -1) * ((3.0 + current) / ((3 * current) + 1.0));
    return fun(base, current+1,max);
}

void first()
{
    float L; // расстояние между пунктами
    float t1; // время по течению
    float t2; // время против течения
    float v; // скорость течения
    printf("L = "); // вывод на экран "L ="
    scanf("%f", &L); // ввод с клавиатуры значения переменной L
    printf("t1 = "); // вывод на экран "t1 ="
    scanf("%f", &t1); // ввод с клавиатуры значения переменной t1
    printf("t2 = "); // вывод на экран  "t2 ="
    scanf("%f", &t2); // ввод с клавиатуры значения переменной t2
    v = (L / t1 - L / t2) / 2; // решение задачи
    printf("River flow = %f\n", v); // вывод на экран "River flow =" и значение v
    return;
}

void first_add()
{
    float L; // расстояние между пунктами
    int t1; // время по течению
    int t2; // время против течения
    printf("L = "); // вывод на экран "L ="
    scanf("%f", &L); // ввод с клавиатуры значения переменной L
    printf("t1 = "); // вывод на экран "t1 ="
    scanf("%d", &t1); // ввод с клавиатуры значения переменной t1
    printf("t2 = "); // вывод на экран  "t2 ="
    scanf("%d", &t2); // ввод с клавиатуры значения переменной t2
    h(L, t1, t2);  // Вызов процедуры h с задаными параметрами
}

void second()
{
    float s; // сумма ряда
    float a; // очередной элемент ряда
    int n; // число элементов ряда
    float i; // номер очередного элемента ряда
    int g; // знак очередного элемента ряда
    // ввод параметров ряда
    printf("n=");
    scanf("%d", &n);
    // начальное присваивание переменных
    s = 0;
    g = 1;
    i = 0;

    while (i < n)  // цикл
    {
        a = (3 + i) / ((3 * i) + 1);
        s += a * g;
        g = -g;
        i++;
    }
    // вывод результата
    printf("s = %f\n", s);
}

void second_add()
{
    float s; // сумма ряда
    float a; // очередной элемент ряда
    int n; // число элементов ряда
    float i; // номер очередного элемента ряда
    int g; // знак очередного элемента ряда
    // ввод параметров ряда
    printf("n=");
    scanf("%d", &n);
    // начальное присваивание переменных
    s = 0;
    g = 1;
    i = 0;
    s = fun(s,i,n);
    printf("s = %f\n", s); // вывод результата
}

void third()
{
    int c;
    int slov = 0;// вводим переменную и присвоим ей значение 0
    int flag = 0;
    while ((c = getchar()) != EOF) { // цикл чтения символов из потока
        if (c == 'a' || c == 'e' || c == 'y' || c == 'u' || c == 'i' || c == 'o') {//если есть гласная, то присвоить 1 к flag
            flag = 1;
        }
        if ((c == ' ' || c == '.' || c == ',' || c == '\n') && flag == 1) {//если обноружен разделитель и flag == 1, то добавим +1 к счёчику слов и сбрасываем флаг в 0
            slov++;
            flag = 0;
        }
    }
    printf("In a stream of symbols, count the number of words containing vowels = %d", slov);//выводи число слов с гласными
}
void third_add()
{
    int c;
    int slov = 0;// вводим переменную и присвоим ей значение 0
    int flag = 0;
    int alt_flag = 0;
    int altwords = 0;
    while ((c = getchar()) != EOF) { // цикл чтения символов из потока
        if (c == 'a' || c == 'e' || c == 'y' || c == 'u' || c == 'i' || c == 'o' || c == 'A' || c == 'E' || c == 'Y' || c == 'U' || c == 'I' || c == 'O') {//если есть гласная, то присвоить 1 к flag
            flag = 1;
        }
        else if (!(c == ' ' || c == '.' || c == ',' || c == '\n'))
            alt_flag = 1;

        if ((c == ' ' || c == '.' || c == ',' || c == '\n')) {//если обноружен разделитель и flag == 1, то добавим +1 к счёчику слов и сбрасываем флаг в 0
            if (flag == 1)
            {
                slov++;
                flag = 0;
            }
            if (alt_flag==1)
            {
                altwords++;
                alt_flag = 0;
            }
        }
    }
    printf("In a stream of symbols, count the number of words containing vowels = %d\n", slov);//выводи число слов с гласными
    printf("In a stream of symbols, count the number of words containing no-volwes = %d\n", altwords);//выводи число слов с не-гласными
}


void four()
{

    // Объявление переменных
    char str[100000]; // Массив символов для хранения вводимой строки
    char ch; // Переменная для хранения текущего символа
    int n; // Максимальная длина слова для удаления
    int len; // Длина текущего слова
    printf("Введите максимальную длину слова для удаления: ");
    scanf("%d", &n);
    // Ввод строки
    printf("Введите строку: ");
    getchar();
    gets(str);



    len = 0;
    for (int i = 0; i < 1000; i++)
    {
        if (str[i] != ' ')
            len++;
        if (str[i] == ' ')
        {
            if (len > n)
            {
                len = 0;
                continue;
            }
            for (int j = i - len; j < i; j++)
                printf("%c",str[j]);
            putchar(' ');
            len = 0;
        }
    }

    // Вывод новой строки
    putchar('\n');





}

void four_add()
{
// Объявление переменных
    char str[1000];  // Массив символов для хранения вводимой строки
    char ch;          // Переменная для хранения текущего символа
    char *start;       // Указатель на начало текущего слова
    char *end;         // Указатель на конец текущего слова
    int n;             // Максимальная длина слова для удаления
    int len;           // Длина текущего слова

    printf("Введите максимальную длину слова для удаления: ");
    scanf("%d", &n);
    // Ввод строки
    printf("Введите строку: ");
    getchar();
    gets(str);

    // Инициализация указателей
    start = str;

    // Цикл для обработки слов в строке
    while(*start) {
        // Пропуск ведущих пробелов
        while(*start && *start == ' ') start++;

        // Установка указателя на начало слова
        end = start;

        // Поиск конца слова
        while(*end && *end != ' ') end++;

        // Вычисление длины слова
        len = end - start;

        // Если длина слова не превышает заданную, вывести слово с пробелом
        if (len <= n) {
            while(start < end) {
                putchar(*start);
                start++;
            }
            putchar(' ');
        }

        // Переход к следующему слову
        start = end;
    }

    // Вывод новой строки
    putchar('\n');


}

void five()
{
    int N = 10;
    int i = 0;
    int s[N];
    int c = 0;
    int k = 0;
    for (i = 0; i < N; i++) //цикл, в котором происходит ввод элементов массива с клавиатуры
    {
        scanf_s("%d", &s[i]);
    }
    for (i = 0; i < N / 2; i++) //цикл, который проходится от начала массива до его середины
    {
        c = s[i];//переменной c присваивается значение текущего элемента массива
        s[i] = s[N - i - 1];//текущему элементу присваивается значение элемента, симметричного ему относительно середины.
        s[N - 1 - i] = c;//текущему (симметричному) элементу присваивается значение из c
    }
    for (i = 0; i < N; i++)//цикл, который выводит массив s на экран
        printf("%d ", s[i]);

}

void five_add()
{
  int N = 10;
  int i = 0;
  double mid = 0;
  int s[N];
  int c = 0;
  int k = 0;

  for (i = 0; i < N; i++) //цикл, в котором происходит ввод элементов массива с клавиатуры
  {
    scanf_s("%d", &s[i]);
  }

  //Высчитываем среднее арифметическое
  for (i = 0; i < N; i++)
  {
    mid += s[i];
  }
  mid /= 10;

  //Зеркалим элементы с 1 по 5
  for (i = 0; i < 2; i++)
  {
    c = s[i];
    s[i] = s[4 - i];
    s[4 - i] = c;
  }

  //Зеркалим с 6 по 10 элементы
  for (i = 5; i < 7; i++)
  {
    c = s[i];
    s[i] = s[14 - i];
    s[14 - i] = c;
  }

  printf("Среднее арифметическое массива равно %f\n", mid);
  for (i = 0; i < N; i++) //цикл, который выводит массив s на экран
    printf("%d ", s[i]);

}




void six()
{
int N = 4;
int K = 3;

int arr[K][N]; // Объявляем двумерный массив
  for (int i = 0; i < K; i++) // Цикл по строкам массива
  {
    for (int j = 0; j < N; j++) // Цикл по элементам строки
    {
      scanf("%d", &arr[i][j]); // Ввод элементов массива с клавиатуры
    }
  }



  int j, isMirror;
  for (int i = 0; i < K; i++) // Цикл по строкам массива
  {
    j = 0;
    isMirror = 1;
    for (; j < (N/2); j++) // Проверка зеркальности элементов в строке
    {
      if (arr[i][j] != arr[i][N - j - 1]) // Если элементы не являются зеркальными
      {
        isMirror = 0;
        break;
      }
    }
    if (isMirror == 1) // Если строка является зеркальной
    {
      for (int a=0; a < N; a++) // Обнуляем все элементы строки
      {
        arr[i][a] = 0;
      }
    }
  }

  for (int i = 0; i < K; i++) // Цикл по строкам массива для вывода результата
  {
    for (int j = 0; j < N; j++) // Цикл по элементам строки
    {
      printf("%d ", arr[i][j]); // Вывод элементов массива
    }
    printf("\n"); // Переход на новую строку после вывода одной строки массива
  }
}

void cocktailSort(int arr[], int size) // Функция для сортировки
{
  int swapped = 1, start = 0, end = size - 1; // Флаг для проверки перестановок, переменные для индексов начала и конца сортировки
  while (swapped == 1) // Пока были перестановки на предыдущей итерации
  {
    swapped = 0; // Сброс флага перестановок
    for (int i = start; i < end; i++) // Проход по массиву слева направо
    {
      if (arr[i] > arr[i + 1]) // Если текущий элемент больше следующего,
      {
        int tmp = arr[i]; // Меняем их местами
        arr[i] = arr[i + 1];
        arr[i + 1] = tmp;
        swapped = 1; // Устанавливаем флаг наличия перестановок
      }
    }

    if (swapped == 0) // Если на данной итерации не было перестановок, то выходим из цикла
      break;

    swapped = 0; // Сброс флага перестановок
    end--; // Уменьшаем правую границу области сортировки
    for (int i = end; i >= start; --i) // Проход по массиву справа налево
    {
      if (arr[i] > arr[i + 1]) // Если текущий элемент больше следующего,
      {
        int tmp = arr[i]; // Меняем их местами
        arr[i] = arr[i + 1];
        arr[i + 1] = tmp;
        swapped = 1; // Устанавливаем флаг наличия перестановок
      }
    }
    ++start; // Увеличиваем левую границу области сортировки
  }
}
void copyArr1d(int* src_arr, int* dis_arr, const int length)
{
  for (int i = 0; i < length; i++)
    dis_arr[i] = src_arr[i];
}

void copyArr2d(int** src_arr, int** dis_arr, const int height, const int length)
{
  for (int i = 0; i < height; i++)
    copyArr1d(src_arr[i], dis_arr[i], length);
}

void six_add()
{
  int K = 4; //y
  int N = 3; //x
  int arr[K][N]; // Объявляем двумерный массив
  int sorted_arr[K][N];

  for (int i = 0; i < K; i++) // Цикл по строкам массива
  {
    for (int j = 0; j < N; j++) // Цикл по элементам строки
    {
      scanf("%d", &arr[i][j]); // Ввод элементов массива с клавиатуры
      sorted_arr[i][j] = 0;
    }
  }

  printf("Sorting rows\n");
  for (int i = 0; i < K; i++)
    cocktailSort(arr[i], N);

    for (int i = 0; i < K; i++) // Цикл по строкам массива
  {
    for (int j = 0; j < N; j++) // Цикл по элементам строки
    {
      printf("%d\t", arr[i][j]); // Ввод элементов массива с клавиатуры
    }
    printf("\n");
  }

  int fst[K];
  int length = 0, tpos=0;
  for (; length < K; length++)
    fst[length] = arr[length][0];


  cocktailSort(fst, K);
  while (length != 0)
  {
    for (int i = 0; i < K; i++)
    {
      if (fst[tpos] == arr[i][0])
      {
        for (int j = 0; j < N; j++)
          sorted_arr[tpos][j] = arr[i][j];
      }

    }
    tpos++;
    length--;
  }
  printf("Sorting columns\n");
  for (int i = 0; i < K; i++) // Цикл по строкам массива
  {
    for (int j = 0; j < N; j++) // Цикл по элементам строки
    {
      printf("%d\t", sorted_arr[i][j]); // Ввод элементов массива с клавиатуры
    }
    printf("\n");
  }

}

void seven()
{
   int* arr;
    int length = 0;
    int tmp[255];
    printf("Enter a number: ");
    int num;
    scanf("%d", &num);
    while (num)
    {
        tmp[length] = num % 2;
        length++;
        num /= 2;
    }
    printf("%d\n", length);
    for (int i = 0; i < length; i++)
    {
        printf("%d", tmp[i]);
    }
}
