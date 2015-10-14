//
//  main.cpp
//  Proy1Ejercicio2
//
//  Created by Zareek Galvan on 10/7/15.
//  Copyright © 2015 Trisquel Labs. All rights reserved.
//


#include <iostream>
#include <iomanip>
using namespace std;

double medianTwoArrays(double arr1[], double arr2[], int n)
{
    int l = n*2, j = 0, k = 0;
    double arr[l];
    for (int i = 0; i < l; i++)
    {
        if (arr1[j] > arr2[k])
        {
            arr[i] = arr2[k];
            k++;
        }
        else
        {
            arr[i] = arr1[j];
            j++;
        }
    }
    return  (arr[n] + arr[n - 1]) / 2;
}

double calculaMediana(double arr1[], double arr2[], int inicio, int fin, int n)
{
    if (inicio > fin)
        return calculaMediana(arr2, arr1, 0, n-1, n);
    
    int medio1 = (inicio+fin)/2;
    int medio2 = n-1-medio1;
    
    if (arr1[medio1] > arr2[medio2] && (medio2 == n-1 || arr1[medio1] <= arr2[medio2+1]))
    {
        if (medio1 == 0 || arr2[medio2] > arr1[medio1-1])
            return (arr1[medio1] + arr2[medio2])/2.0;
        else
            return (arr1[medio1] + arr1[medio1-1])/2.0;
    }
    else if (arr1[medio1] > arr2[medio2] && medio2 != n-1 && arr1[medio1] > arr2[medio2+1])
    {
        return calculaMediana(arr1, arr2, inicio, medio1-1, n);
    }
    else
    {
        return calculaMediana(arr1, arr2, medio1+1, fin, n);
    }
}

int main()
{
    int cases = 0;
    
    cin >> cases;
    
    for (int c = 0; c < cases; c++)
    {
        int length;
        cin >> length;
        double arr1[length], arr2[length];
        for (int i = 0; i < length; i++)
        {
            cin >> arr1[i];
        }
        for (int i = 0; i < length; i++)
        {
            cin >> arr2[i];
        }
        cout<<fixed<<setprecision(2);
        cout<<"Median case "<<c+1<<": "<< calculaMediana(arr1, arr2, 0, length - 1, length) <<endl;
        
    }
}