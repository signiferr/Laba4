#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>

int max(int **A,int R,int S);
int transpon (int **B,int **T,int R,int S);
int dobutok(int **A,int **B,int **Dob,int R,int S);
int sortt(int **A,int sort,int R,int S);
int suma(int **A,int **B,int sum,int R,int S);


int main()
{
    setlocale(LC_ALL, "Rus");
    int avto_or_no;
    int sort;
    int sum;
    int dija;
    int R=3;
    int S=4;

    for(int r=0;r<5;r++)
   {
       printf(" �������� �������?\n\n �����������-1\n ������� ���������-2\n\n");
       scanf("%d",&avto_or_no);

    if (avto_or_no==2)
      {
      printf("\n����i� ��������i ������i: ");
      scanf("%d",&R); //ʳ������ �����
      printf("\n����i� ���������i ������i: ");
      scanf("%d",&S); // ʳ������ ��������
      }

    int **A = NULL;
    A=(int**) malloc(R * sizeof(int));//�������� �����, ��� ������ ����� -������� mallok(������� ��������,����� � ������ ��������)
       for(int i=0;i<R;i++)
       {
        A[i]=(int*) malloc(R * sizeof(int));
       }

    int **B=NULL;
    B=(int**) malloc(S * sizeof(int));

    int **Dob=NULL;
    Dob=(int**) malloc(S * sizeof(int));

    int **T=NULL;
    T=(int**) malloc(R * sizeof(int));

    for(int i=0;i<S;i++)
    {
        B[i]=(int*) malloc(R * sizeof(int));
        Dob[i]=(int*) malloc(R * sizeof(int));
        T[i]=(int*) malloc(R * sizeof(int));
    }

    if(avto_or_no==2)
    {
    printf("��������� ��������� �������:\n");
    for (int i=0;i<R;i++)//�����
    {
        for (int j=0;j<R;j++)//�������
        {
            printf("A[%d][%d]=",i,j);
            scanf("%d",&A[i][j]);
        }
    }
    printf("��������� ���������� �������:\n");
    for (int i=0;i<R;i++)//�����
    {
        for (int j=0;j<S;j++)//�������
        {
            printf("B[%d][%d]=",i,j);
            scanf("%d",&B[i][j]);
        }
    }
    }
    else //�������������
    {
        for (int i=0;i<R;i++)   //���������
        {
            for (int j=0;j<R;j++)
            {
                A[i][j]= rand()%25;
            }
        }
        for (int i=0;i<R;i++)   //����������
        {
            for (int j=0;j<S;j++)
            {
                B[i][j]= rand()%25;
            }
        }
    }

    for (int i=0;i<R;i++)            //��������� �� ����� ���������
    {
        for (int j=0;j<R;j++)
        {
            printf("%3d ", A[i][j]);
        }
        printf("\n");
    }
        printf("\n");

    for (int i=0;i<R;i++)            //��������� �� ����� �����������
    {
        for (int j=0;j<S;j++)
        {
            printf("%3d ", B[i][j]);
        }
        printf("\n");
    }

    do
    {
        printf("\n�ii ���  ���������:\n1. �������� � \n2. ������������� B\n3. ��������� AxB\n4. ��������� ����� A\n5. �������� �����\n");
        scanf("%d",&dija);
    }while(dija != 1 && dija != 2 && dija != 3 && dija != 4 && dija != 5);

    switch (dija)
    {
    case 1:
        max(A,R,S);
    break;

    case 2:
        transpon(B,T,R,S);
    break;

    case 3:
        printf("AxB = \n");
        dobutok(A,B,Dob,R,S);
    break;

    case 4:
        printf("\n���i�� ����� ����� ��� ����������: ");
        scanf("%d",&sort);
        sortt(A,sort,R,S);
    break;

    case 5:
        suma(A,B,sum,R,S);
    break;
    }
        for(int i=0;i<1;i++)      //������� �����
        {
          free(A[i]);
        }
        free(A);
        for(int i=0;i<S;i++)
        {
          free(B[i]);
          free(Dob[i]);
          free(T[i]);
        }
        free(B);
        free(Dob);
        free(T);
        printf("\n\n");
 }
 return 0;
}

int max(int **A,int R,int S)
{
    int maximal= 0;
    for(int i=0;i<R;i++)
        {
            for(int j=0;j<R;j++)
            {
                if (A[i][j] > maximal)
                {
                maximal = A[i][j];
                }
            }
        }
    printf("\n����������� �������� ������i �: %d\n",maximal);
}

int transpon (int **B,int **T,int R,int S)
{
    for (int i=0;i<R;i++)
        {
            for (int j=0;j<S;j++)
            {
                T[j][i] = B[i][j];
            }
        }
    printf("\n ������������� ������� B :  \n");
    for (int i=0;i<S;i++)
    {
        for (int j=0;j<R;j++)
        {
            printf("%3d ", T[i][j]);
        }
    printf("\n");
    }
}

int dobutok(int **A,int **B,int **Dob,int R,int S)
{
     for(int i=0;i<R;i++)
        {
            for(int j=0;j<S;j++)
            {
                Dob[i][j]=0;
                for(int p=0;p<R;p++)
                {
                    Dob[i][j] += A[i][p] * B[p][j];
                }
            }
        }

        for (int i=0;i<R;i++)
        {
            for (int j=0;j<S;j++)
            {
                printf("%3d ", Dob[i][j]);
            }
            printf("\n");
        }
}

int sortt(int **A,int sort,int R,int S)
{
    int temp;
    for(int k=1;k<R;k++)
    {
        for(int j=0;j<R-k;j++)
        {

            if(A[sort][j]>A[sort][j+1])           //������������ �����
            {
                    temp = A[sort][j];
                    A[sort][j] = A[sort][j+1];
                    A[sort][j+1] = temp;
            }
        }
    }
    for(int j=0;j<R;j++)
    {
    printf("%3d ",A[sort][j]);
    }
}

int suma(int **A,int **B,int sum,int R,int S)
{
    for(int i=0;i<R;i++)
    {
        sum=0;
        for(int j=0;j<R;j++)
        {
            sum = sum + A[i][j];
        }
        printf("\n%d ����� e������i� ����i� ������i � =%d",i,sum);
    }
    for(int j=0;j<S;j++)
    {
        sum=0;
        for(int i=0;i<R;i++)
        {
            sum = sum + B[i][j];
        }
        printf("\n%d ����� e������i� ������i� ������i � =%d",j,sum);
    }
}


