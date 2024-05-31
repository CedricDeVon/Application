// int is_not_terminated = 1;
// while (is_not_terminated)
// {
//     printf("Do you want to try again: [Y] / [N] \n");
//     char x = toupper(getch());

//     if (x == 'N')
//     {
//         is_not_terminated = 0;
//     }
//     else if (x == 'Y')
//     {
//         x = toupper(getch());
//     }
// }

// char x;
// do
// {
//     //
//     x = '0';
//     printf("Do you want to try again: [Y] / [N] \n");
//     while (x != 'Y')
//     {
//         x = toupper(getch());
//         if (x == 'N')
//         {
//             break;
//         }
//         else if (x == 'Y')
//         {
//             x = toupper(getch());
//         }
//     }
// } while (x == 'Y');



// Exercise No. 6
// int is_not_terminated = 1;
// float remaining_balance = 10000.0;
// while (is_not_terminated)
// {
//     int option = 0;
//     float deposit = 0, withdrawl = 0;
//     printf("-------------------- \n");
//     printf("[1] check balance \n");
//     printf("[2] deposit \n");
//     printf("[3] withdraw \n");
//     printf("[4] exit \n");
//     printf("Enter option: ");
//     scanf("%d", &option);

//     switch (option)
//     {
//         case 1:
//             printf("Remaining balance: %.2f \n", remaining_balance);
//             break;

//         case 2:
//             printf("Enter deposit: ");
//             scanf("%f", &deposit);
//             remaining_balance += deposit;
//             break;

//         case 3:
//             printf("Enter withdrawl: ");
//             scanf("%f", &withdrawl);
//             if (withdrawl > remaining_balance)
//             {
//                 printf("Invalid withdrawl! \n");
//             }
//             else
//             {
//                 remaining_balance -= withdrawl;
//             }
//             break;

//         case 4:
//             is_not_terminated = 0;
//             printf("Program terminated! \n");
//             break;

//         default:
//             printf("Invalid option! \n");
//     }
// }

// Exercise No. 1
// int is_not_terminated = 1;
// while (is_not_terminated)
// {
//     int option = 0;
//     float input = 0;
//     printf("-------------------- \n");
//     printf("[1] inches to centimeters \n");
//     printf("[2] centimeters to inches \n");
//     printf("[3] dollars to pesos \n");
//     printf("[4] pesos to dollars \n");
//     printf("[5] gallons to liters \n");
//     printf("[6] liters to gallons \n");
//     printf("[7] exit \n");
//     printf("Enter option: ");
//     scanf("%d", &option);

//     if (option == 1)
//     {
//         printf("Enter inches: ");
//         scanf("%f", &input);
//         printf("%f inches is %f centimeters \n", input, input * 2.54);
//     }
//     else if (option == 2)
//     {
//         printf("Enter centimeters: ");
//         scanf("%f", &input);
//         printf("%f centimeters is %f inches \n", input, input * 0.39);
//     }
//     else if (option == 3)
//     {
//         printf("Enter dollars: ");
//         scanf("%f", &input);
//         printf("%f dollars is %f pesos \n", input, input * 58.77);
//     }
//     else if (option == 4)
//     {
//         printf("Enter pesos: ");
//         scanf("%f", &input);
//         printf("%f pesos is %f dollars \n", input, input * 0.02);
//     }
//     else if (option == 5)
//     {
//         printf("Enter gallons: ");
//         scanf("%f", &input);
//         printf("%f gallons is %f liters \n", input, input * 3.78);
//     }
//     else if (option == 6)
//     {
//         printf("Enter liters: ");
//         scanf("%f", &input);
//         printf("%f liters is %f gallons \n", input, input * 0.26);
//     }
//     else if (option == 7)
//     {
//         is_not_terminated = 0;
//         printf("Program terminated! \n");
//     }
//     else
//     {
//         printf("Invalid option! \n");
//     }
// }
/*
- 1 inch is [2.54] cm
- 1 cm is [0.39] inches
- 1 dollar is [58.77] pesos (www.openexchangerates.com On 12:00 PM, October 25, 2022)
- 1 peso is [0.02] dollar (www.openexchangerates.com On 12:03 PM, October 25, 2022)
- 1 gallon is [3.78] liters
- 1 liter is [0.26] gallon
*/

// Exercise No. 2
// int is_not_terminated = 1;
// int input = 0;
// int purchase_count = 0;
// int purchase_prices[100] = {};
// char purchase_names[100][32] = {};
// while (is_not_terminated)
// {
//     printf("-------------------- \n");
//     printf("[1] Food-1 \n");
//     printf("[2] Food-2 \n");
//     printf("[3] Food-3 \n");
//     printf("[4] Drink-1 \n");
//     printf("[5] Drink-2 \n");
//     printf("[6] Proceed to the counter \n");
//     scanf("%d", &input);
//     if (input == 1)
//     {
//         strcpy(purchase_names[purchase_count], "Food-1");
//         purchase_prices[purchase_count] = 1;
//         purchase_count += 1;
//     }
//     else if (input == 2)
//     {
//         strcpy(purchase_names[purchase_count], "Food-2");
//         purchase_prices[purchase_count] = 2;
//         purchase_count += 1;
//     }
//     else if (input == 3)
//     {
//         strcpy(purchase_names[purchase_count], "Food-3");
//         purchase_prices[purchase_count] = 3;
//         purchase_count += 1;
//     }
//     else if (input == 4)
//     {
//         strcpy(purchase_names[purchase_count], "Drink-1");
//         purchase_prices[purchase_count] = 4;
//         purchase_count += 1;
//     }
//     else if (input == 5)
//     {
//         strcpy(purchase_names[purchase_count], "Drink-2");
//         purchase_prices[purchase_count] = 5;
//         purchase_count += 1;
//     }
//     else if (input == 6)
//     {
//         int total_price = 0;
//         printf("Purchases: \n");
//         for (int index = 0; index < purchase_count; index++)
//         {
//             printf("- %s: %i \n", purchase_names[index], purchase_prices[index]);
//             total_price += purchase_prices[index];
//         }

//         printf("Total price: %d \n", total_price);
//         int is_shopping_continuted = 1;
//         while (is_shopping_continuted)
//         {
//             printf("-------------------- \n");
//             printf("[1] Continue shopping? \n");
//             printf("[2] Exit \n");
//             scanf("%d", &input);
//             if (input == 1) {
//                 is_shopping_continuted = 0;
//             }
//             else if (input == 2)
//             {
//                 is_shopping_continuted = 0;
//                 is_not_terminated = 0;
//             }
//             else
//             {
//                 printf("Please supply a valid input! \n");
//             }
//         }
//     }
//     else
//     {
//         printf("Please supply a valid input! \n");
//     }
// }
