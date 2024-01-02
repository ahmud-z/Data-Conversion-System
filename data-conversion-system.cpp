#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

void printResult(int resultArray[], int sz)
{
    for(int j = sz-1; j>=0; j--)
    {
        cout<<resultArray[j];
    }
    cout<<" ";
}

void printArray(int arr[], int sz)
{
    for(int i = 0; i<sz; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void convertDecimalToBinary(int num)
{
    int resultArray[100] = {0};
    int i = 0;

    while(num!=0)
    {
        if(num!=0)
        {
            resultArray[i] = num%2;
            i++;
        }
        num = num/2;
    }
    printResult(resultArray, i);
}


int convertBinaryToDecimal(int num)
{
    int sum = 0;
    int x = 0;
    int powerResult = 0;

    while(num!=0)
    {
        int powerResult = pow(2, x);

        int temp = num%2;
        sum += (temp * powerResult);

        x++;
        powerResult = 0;
        num = num/10;
    }
    return sum;
}

void convertIPV4ToBinary(int num)
{
    int resultArray[8] = {0};
    int i = 0;

    while(num!=0)
    {
        if(num!=0)
        {
            resultArray[i] = num%2;
            i++;
        }
        num = num/2;
    }

    printResult(resultArray, 8);
}

void convertIntoBinary(int num)
{
    int sum = 0;
    int x = 0;
    int powerResult = 0;
    int temp = 0;

    while(num!=0)
    {
        int powerResult = pow(2, x);

        int temp = num%2;
        sum += (temp * powerResult);

        x++;
        powerResult = 0;
        num = num/10;
        temp++;
    }

    cout<<sum;
    sum = 0;
}

void binaryIPV4_to_DecimalIPV4()
{
    int a,b,c,d;

    cout<<"Enter an 32 bit address: ";
    scanf("%d.%d.%d.%d", &a, &b, &c, &d);

    int arr[] = {a, b, c, d};

    cout<<"Decimal address of given IPV4 address: ";
    for(int i = 0; i<4; i++)
    {
        convertIntoBinary(arr[i]);
        if(i != 3)
        {
            cout<<".";
        }
    }
    cout<<endl;
    cout<<endl;
}


void checkEvenParity(int arr[], int sz)
{
    int temp = 0;

    for(int i = 0; i<sz-1; i++)
    {
        if(arr[i]==1)
        {
            temp++;
        }
    }

    if(temp%2==0)
    {
        cout<<"Parity Bit: 0"<<endl;
        arr[sz-1] = 0;
        cout<<"Even Parity Final Result: ";
        printArray(arr,sz);
        cout<<endl;
    }
    else
    {
        cout<<"Parity Bit: 1"<<endl;
        arr[sz-1] = 1;
        cout<<"Even Parity Final Result: ";
        printArray(arr,sz);
        cout<<endl;
    }
}

void checkOddParity(int arr[], int sz)
{
    int temp = 0;
    for(int i = 0; i<sz-1; i++)
    {
        if(arr[i]==1)
        {
            temp++;
        }
    }

    if(temp%2==0)
    {
        cout<<"Parity Bit will be: 1"<<endl;
        arr[sz-1] = 1;
        cout<<"Odd Parity Final Result: ";
        printArray(arr,sz);
        cout<<endl;
        cout<<endl;
    }
    else
    {
        cout<<"Parity Bit will be: 0"<<endl;
        arr[sz-1] = 0;
        cout<<"Odd Parity Final Result: ";
        printArray(arr,sz);
        cout<<endl;
        cout<<endl;
    }
}


void findParity()
{
    int option = 0;
    int sz;

    cout<<"Enter array size: ";
    cin>>sz;

    int arr[sz];


    cout<<"Enter "<<sz-1<<" array elements: ";
    for(int i = 0; i<sz-1; i++)
    {
        cin>>arr[i];
    }

    cout<<"\n1. Even Parity Check"<<endl;
    cout<<"2. OddParity Check"<<endl;
    cout<<"Enter your option: ";

    cin>>option;

    if(option==1)
    {
        cout<<endl;
        checkEvenParity(arr,sz);
    }
    else
    {
        cout<<endl;
        checkOddParity(arr,sz);
    }
}

void clearScreen()
{
    system("cls");
}


int main()
{
    int choice;
    int num;

    do
    {
        cout<<"1. Decimal to Binary"<<endl;
        cout<<"2. Binary to Decimal"<<endl;
        cout<<"3. Decimal IPV4 to Binary 32 bit Address"<<endl;
        cout<<"4. 32 bit Binary Address to Decimal Address"<<endl;
        cout<<"5. Parity Check"<<endl;
        cout<<"6. Clear Screen"<<endl;
        cout<<"0. exit\n"<<endl;

        cout<<"Enter your Choice: ";
        cin>>choice;
        cout<<endl;


        switch(choice)
        {
        case 1:
            cout<<"Enter a decimal number: ";
            cin>>num;
            cout<<"Binary of given decimal: ";
            convertDecimalToBinary(num);
            cout<<endl<<endl;
            break;

        case 2:
            cout<<"Enter a binary number: ";
            cin>>num;
            cout<<"Decimal of given binary: "<<convertBinaryToDecimal(num)<<endl<<endl;
            break;

        case 3:
            int a,b,c,d;

            cout<<"Enter a Dotted IPV4 Address: ";
            scanf("%d.%d.%d.%d.", &a, &b, &c, &d);

            int addressArray[4];

            addressArray[0]  = a;
            addressArray[1]  = b;
            addressArray[2]  = c;
            addressArray[3]  = d;

            cout<<"32 Bit Binary Address: ";

            for(int i = 0; i<4; i++)
            {
                convertIPV4ToBinary(addressArray[i]);
            }
            cout<<endl<<endl;
            break;

        case 4:
            binaryIPV4_to_DecimalIPV4();
            break;

        case 5:
            findParity();
            break;

        case 6:
            clearScreen();
            break;

        case 0:
            cout<<"Exit successfully!"<<endl;
            break;

        default:
            cout<<"Invalid Choice"<<endl<<endl;
        }
    }
    while(choice!=0);

    cout<<endl;
    return 0;
}
