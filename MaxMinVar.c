#include <stdio.h>
#include <math.h>

int MaxMinVar() {
   int n, i;
   float arr[100], sum=0.0, mean, variance=0.0, std_deviation;

   printf("Enter the number of elements: ");
   scanf("%d", &n);

   printf("Enter %d elements:\n", n);
   for(i=0; i<n; i++) {
      scanf("%f", &arr[i]);
      sum += arr[i];
   }

   mean = sum/n;
   for(i=0; i<n; i++)
      variance += pow(arr[i] - mean, 2);

   variance = variance/n;
   std_deviation = sqrt(variance);

   printf("Maximum element = %.2f\n", arr[0]);
   printf("Minimum element = %.2f\n", arr[0]);
   for(i=1; i<n; i++) {
      if(arr[i] > arr[0])
         arr[0] = arr[i];
      if(arr[i] < arr[1])
         arr[1] = arr[i];
   }

   printf("Variance = %.2f\n", variance);
   printf("Standard deviation = %.2f\n", std_deviation);

   return 0;
}
