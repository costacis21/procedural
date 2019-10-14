/*************************************************************************
University of Leeds
School of Computing
COMP1711-Procedural Programming
Coursework 1

I confirm that the following program has been developed and written bymeand it
is entirely the result of my own work. I also confirm that I have not copied any
parts of this program fromanother person or any other source or facilitated
someone to copy this program.

I confirm that I will not post this program online or share it with anyone before
the end of the semester.

Student Name: Giorgos Kosta
Student ID:
Email: sc19gl@leeds.ac.uk
DateWork Commenced:14-OCT
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>


int main(){
  int option;
  double electricityCost,standingCharge,profit,totalCharges,vat,amountDue,cost,cll,kwh,discount,costAdiscount,revenue,consumption=0;

  while(1){
    //display options
    printf("\n \n1.  Compute and print the bill for a domestic customer.\n");
    printf("2.  Compute and print the bill for a business customer. \n");
    printf("3.  Show the quarterly profit of the company\n");
    printf("4.  Quit \n");
    printf("\nPlease Enter the Number of Your Option:  ");

    //read option
    scanf("%i",&option);


    if (option==4){
      exit(0);
    }

    //option 1
    else if(option==1){

      printf("\n \nEnter the quarterly consumption in kWh: ");
      scanf("%lf", &kwh);
      consumption+= kwh;
      electricityCost= (kwh*0.65);
      standingCharge= (91*0.3);
      totalCharges= (electricityCost+standingCharge);
      revenue+=totalCharges;
      vat= (totalCharges*0.05);
      amountDue= ( totalCharges+vat);
      printf("\n \nThe bill (Domestic)\n");
      printf("Consumption:                  %lf kWh\n",kwh);
      printf("Electicity Cost:              £%lf \n",electricityCost);
      printf("Standing Charge:              £%lf \n",standingCharge);
      printf("Total charges:                £%lf \n",totalCharges);
      printf("VAT:                          £%lf \n",vat);
      printf("Amount to Pay:                £%.2lf \n",amountDue);



    }


    //option 2
    else if (option==2){
      discount=0;
      printf("\n \nEnter the quarterly consumption in kWh: ");
      scanf("%lf", &kwh);
      consumption+=kwh;
      electricityCost= (kwh*1.04);

      if (kwh>5000){
        discount= electricityCost*0.1;
        costAdiscount= electricityCost-discount;
      }else{
        costAdiscount=electricityCost;
      }

      standingCharge= (91*0.96);
      totalCharges= (costAdiscount+standingCharge);

      revenue+=totalCharges;

      if (kwh<1000){
        vat= (totalCharges*0.05);
      }
      else{
        vat= (totalCharges*0.20);
      }

      cll=kwh*0.00847;
      amountDue= ( totalCharges+vat+cll);

      printf("\n \nThe bill (business)\n");
      printf("Consumption:                  %lf kWh\n",kwh);
      printf("Electicity Cost:              £%lf \n",electricityCost);
      if (discount != 0){
        printf("Discount:                     £%lf\n",discount);
        printf("Cost after Discount           £%lf\n", costAdiscount);
      }
      printf("Standing Charge:              £%lf \n",standingCharge);
      printf("Total charges:                £%lf \n",totalCharges);
      printf("VAT:                          £%lf \n",vat);
      printf("CLL:                          £%lf \n",cll);
      printf("Amount to Pay:                £%.2lf \n",amountDue);

    }


    //option 3
    else if (option==3){
      printf("\n\nYour Quarterly Profit Report");
      printf("\n------------------------------------");
      printf("\nQuarterly Revenue           £%lf",revenue);
      cost= consumption* 0.48;
      printf("\nQuarterly cost              £%lf", cost);
      profit= revenue-cost;
      printf("\nQuarterly Profit            £%lf",profit);

    }



  }


  return 0;
}
