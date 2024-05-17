#include <stdio.h>
#include "lr.h"


void h(float L, int t1, int t2)   // ��������� h
{

    if (t2 > t1) {                                                                   // �������, ���� ����� ������ ������� ������ ��� �� ��������� ��������� �������
        printf("%g = (%g / %d - %g / %d) / 2\n", (L / t1 - L / t2) / 2, L, t1, L, t2); // ����� �� ����� ������� ������
        printf("River flow = %g\n", (L / t1 - L / t2) / 2);                      // ����� �� ����� ����� ������ "River flow = "
    }
    else                                                                        // �����
        printf("Error (t2<t1) it should be like this:(t2>t1)");                // ����� ������
}

float fun(double base,int current, int max)
{

    //���� ���� ��������� ��� i%2==0?1:-1;

    if (current == max)
        return base;
    base += (current % 2 == 0 ? 1 : -1) * ((3.0 + current) / ((3 * current) + 1.0));
    return fun(base, current+1,max);
}

void first()
{
    float L; // ���������� ����� ��������
    float t1; // ����� �� �������
    float t2; // ����� ������ �������
    float v; // �������� �������
    printf("L = "); // ����� �� ����� "L ="
    scanf("%f", &L); // ���� � ���������� �������� ���������� L
    printf("t1 = "); // ����� �� ����� "t1 ="
    scanf("%f", &t1); // ���� � ���������� �������� ���������� t1
    printf("t2 = "); // ����� �� �����  "t2 ="
    scanf("%f", &t2); // ���� � ���������� �������� ���������� t2
    v = (L / t1 - L / t2) / 2; // ������� ������
    printf("River flow = %f\n", v); // ����� �� ����� "River flow =" � �������� v
    return;
}

void first_add()
{
    float L; // ���������� ����� ��������
    int t1; // ����� �� �������
    int t2; // ����� ������ �������
    printf("L = "); // ����� �� ����� "L ="
    scanf("%f", &L); // ���� � ���������� �������� ���������� L
    printf("t1 = "); // ����� �� ����� "t1 ="
    scanf("%d", &t1); // ���� � ���������� �������� ���������� t1
    printf("t2 = "); // ����� �� �����  "t2 ="
    scanf("%d", &t2); // ���� � ���������� �������� ���������� t2
    h(L, t1, t2);  // ����� ��������� h � �������� �����������
}

void second()
{
    float s; // ����� ����
    float a; // ��������� ������� ����
    int n; // ����� ��������� ����
    float i; // ����� ���������� �������� ����
    int g; // ���� ���������� �������� ����
    // ���� ���������� ����
    printf("n=");
    scanf("%d", &n);
    // ��������� ������������ ����������
    s = 0;
    g = 1;
    i = 0;

    while (i < n)  // ����
    {
        a = (3 + i) / ((3 * i) + 1);
        s += a * g;
        g = -g;
        i++;
    }
    // ����� ����������
    printf("s = %f\n", s);
}

void second_add()
{
    float s; // ����� ����
    float a; // ��������� ������� ����
    int n; // ����� ��������� ����
    float i; // ����� ���������� �������� ����
    int g; // ���� ���������� �������� ����
    // ���� ���������� ����
    printf("n=");
    scanf("%d", &n);
    // ��������� ������������ ����������
    s = 0;
    g = 1;
    i = 0;
    s = fun(s,i,n);
    printf("s = %f\n", s); // ����� ����������
}

void third()
{
    int c;
    int slov = 0;// ������ ���������� � �������� �� �������� 0
    int flag = 0;
    while ((c = getchar()) != EOF) { // ���� ������ �������� �� ������
        if (c == 'a' || c == 'e' || c == 'y' || c == 'u' || c == 'i' || c == 'o') {//���� ���� �������, �� ��������� 1 � flag
            flag = 1;
        }
        if ((c == ' ' || c == '.' || c == ',' || c == '\n') && flag == 1) {//���� ��������� ����������� � flag == 1, �� ������� +1 � ������� ���� � ���������� ���� � 0
            slov++;
            flag = 0;
        }
    }
    printf("In a stream of symbols, count the number of words containing vowels = %d", slov);//������ ����� ���� � ��������
}
void third_add()
{
    int c;
    int slov = 0;// ������ ���������� � �������� �� �������� 0
    int flag = 0;
    int alt_flag = 0;
    int altwords = 0;
    while ((c = getchar()) != EOF) { // ���� ������ �������� �� ������
        if (c == 'a' || c == 'e' || c == 'y' || c == 'u' || c == 'i' || c == 'o' || c == 'A' || c == 'E' || c == 'Y' || c == 'U' || c == 'I' || c == 'O') {//���� ���� �������, �� ��������� 1 � flag
            flag = 1;
        }
        else if (!(c == ' ' || c == '.' || c == ',' || c == '\n'))
            alt_flag = 1;

        if ((c == ' ' || c == '.' || c == ',' || c == '\n')) {//���� ��������� ����������� � flag == 1, �� ������� +1 � ������� ���� � ���������� ���� � 0
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
    printf("In a stream of symbols, count the number of words containing vowels = %d\n", slov);//������ ����� ���� � ��������
    printf("In a stream of symbols, count the number of words containing no-volwes = %d\n", altwords);//������ ����� ���� � ��-��������
}


void four()
{

    // ���������� ����������
    char str[100000]; // ������ �������� ��� �������� �������� ������
    char ch; // ���������� ��� �������� �������� �������
    int n; // ������������ ����� ����� ��� ��������
    int len; // ����� �������� �����
    printf("������� ������������ ����� ����� ��� ��������: ");
    scanf("%d", &n);
    // ���� ������
    printf("������� ������: ");
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

    // ����� ����� ������
    putchar('\n');





}

void four_add()
{
// ���������� ����������
    char str[1000];  // ������ �������� ��� �������� �������� ������
    char ch;          // ���������� ��� �������� �������� �������
    char *start;       // ��������� �� ������ �������� �����
    char *end;         // ��������� �� ����� �������� �����
    int n;             // ������������ ����� ����� ��� ��������
    int len;           // ����� �������� �����

    printf("������� ������������ ����� ����� ��� ��������: ");
    scanf("%d", &n);
    // ���� ������
    printf("������� ������: ");
    getchar();
    gets(str);

    // ������������� ����������
    start = str;

    // ���� ��� ��������� ���� � ������
    while(*start) {
        // ������� ������� ��������
        while(*start && *start == ' ') start++;

        // ��������� ��������� �� ������ �����
        end = start;

        // ����� ����� �����
        while(*end && *end != ' ') end++;

        // ���������� ����� �����
        len = end - start;

        // ���� ����� ����� �� ��������� ��������, ������� ����� � ��������
        if (len <= n) {
            while(start < end) {
                putchar(*start);
                start++;
            }
            putchar(' ');
        }

        // ������� � ���������� �����
        start = end;
    }

    // ����� ����� ������
    putchar('\n');


}

void five()
{
    int N = 10;
    int i = 0;
    int s[N];
    int c = 0;
    int k = 0;
    for (i = 0; i < N; i++) //����, � ������� ���������� ���� ��������� ������� � ����������
    {
        scanf_s("%d", &s[i]);
    }
    for (i = 0; i < N / 2; i++) //����, ������� ���������� �� ������ ������� �� ��� ��������
    {
        c = s[i];//���������� c ������������� �������� �������� �������� �������
        s[i] = s[N - i - 1];//�������� �������� ������������� �������� ��������, ������������� ��� ������������ ��������.
        s[N - 1 - i] = c;//�������� (�������������) �������� ������������� �������� �� c
    }
    for (i = 0; i < N; i++)//����, ������� ������� ������ s �� �����
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

  for (i = 0; i < N; i++) //����, � ������� ���������� ���� ��������� ������� � ����������
  {
    scanf_s("%d", &s[i]);
  }

  //����������� ������� ��������������
  for (i = 0; i < N; i++)
  {
    mid += s[i];
  }
  mid /= 10;

  //�������� �������� � 1 �� 5
  for (i = 0; i < 2; i++)
  {
    c = s[i];
    s[i] = s[4 - i];
    s[4 - i] = c;
  }

  //�������� � 6 �� 10 ��������
  for (i = 5; i < 7; i++)
  {
    c = s[i];
    s[i] = s[14 - i];
    s[14 - i] = c;
  }

  printf("������� �������������� ������� ����� %f\n", mid);
  for (i = 0; i < N; i++) //����, ������� ������� ������ s �� �����
    printf("%d ", s[i]);

}




void six()
{
int N = 4;
int K = 3;

int arr[K][N]; // ��������� ��������� ������
  for (int i = 0; i < K; i++) // ���� �� ������� �������
  {
    for (int j = 0; j < N; j++) // ���� �� ��������� ������
    {
      scanf("%d", &arr[i][j]); // ���� ��������� ������� � ����������
    }
  }



  int j, isMirror;
  for (int i = 0; i < K; i++) // ���� �� ������� �������
  {
    j = 0;
    isMirror = 1;
    for (; j < (N/2); j++) // �������� ������������ ��������� � ������
    {
      if (arr[i][j] != arr[i][N - j - 1]) // ���� �������� �� �������� �����������
      {
        isMirror = 0;
        break;
      }
    }
    if (isMirror == 1) // ���� ������ �������� ����������
    {
      for (int a=0; a < N; a++) // �������� ��� �������� ������
      {
        arr[i][a] = 0;
      }
    }
  }

  for (int i = 0; i < K; i++) // ���� �� ������� ������� ��� ������ ����������
  {
    for (int j = 0; j < N; j++) // ���� �� ��������� ������
    {
      printf("%d ", arr[i][j]); // ����� ��������� �������
    }
    printf("\n"); // ������� �� ����� ������ ����� ������ ����� ������ �������
  }
}

void cocktailSort(int arr[], int size) // ������� ��� ����������
{
  int swapped = 1, start = 0, end = size - 1; // ���� ��� �������� ������������, ���������� ��� �������� ������ � ����� ����������
  while (swapped == 1) // ���� ���� ������������ �� ���������� ��������
  {
    swapped = 0; // ����� ����� ������������
    for (int i = start; i < end; i++) // ������ �� ������� ����� �������
    {
      if (arr[i] > arr[i + 1]) // ���� ������� ������� ������ ����������,
      {
        int tmp = arr[i]; // ������ �� �������
        arr[i] = arr[i + 1];
        arr[i + 1] = tmp;
        swapped = 1; // ������������� ���� ������� ������������
      }
    }

    if (swapped == 0) // ���� �� ������ �������� �� ���� ������������, �� ������� �� �����
      break;

    swapped = 0; // ����� ����� ������������
    end--; // ��������� ������ ������� ������� ����������
    for (int i = end; i >= start; --i) // ������ �� ������� ������ ������
    {
      if (arr[i] > arr[i + 1]) // ���� ������� ������� ������ ����������,
      {
        int tmp = arr[i]; // ������ �� �������
        arr[i] = arr[i + 1];
        arr[i + 1] = tmp;
        swapped = 1; // ������������� ���� ������� ������������
      }
    }
    ++start; // ����������� ����� ������� ������� ����������
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
  int arr[K][N]; // ��������� ��������� ������
  int sorted_arr[K][N];

  for (int i = 0; i < K; i++) // ���� �� ������� �������
  {
    for (int j = 0; j < N; j++) // ���� �� ��������� ������
    {
      scanf("%d", &arr[i][j]); // ���� ��������� ������� � ����������
      sorted_arr[i][j] = 0;
    }
  }

  printf("Sorting rows\n");
  for (int i = 0; i < K; i++)
    cocktailSort(arr[i], N);

    for (int i = 0; i < K; i++) // ���� �� ������� �������
  {
    for (int j = 0; j < N; j++) // ���� �� ��������� ������
    {
      printf("%d\t", arr[i][j]); // ���� ��������� ������� � ����������
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
  for (int i = 0; i < K; i++) // ���� �� ������� �������
  {
    for (int j = 0; j < N; j++) // ���� �� ��������� ������
    {
      printf("%d\t", sorted_arr[i][j]); // ���� ��������� ������� � ����������
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
