#include<stdio.h>
structmenu_admin
{
intitem_no;
char name[30];
float price;
}ad_m;

void main()
{
int c, emp;
intadminp=12345;
printf("\n\n----------------------------------------------------------------------------------------------------------------\n");
printf("\t\t\t-->We cordially invite you to our restaurant 'The FoodHouse'.");
printf("\n\t\n\t\t\tIt combines tradition with modernity in an exceptional way.");
printf("\n\t\n\t\t\tIts interior is unique because fragments of old walls have been preserved");
printf("\t\n\t\t\tand they have been ingeniously blended with the modern decor.");
printf("\n\t\n\t\t\tWe mainly serve traditional Indian cuisine and add variety to our menu according to the season.");
printf("\n\t\n\t\t\tWe can satisfy even the most sophisticated culinary expectations of our customers.");
printf("\n\t\n\t\t\tWe provide a professional service.<--\n\n");
printf("----------------------------------------------------------------------------------------------------------------\n");
printf("\t\t--------------WELCOME TO FOOD ORDERING SYSTEM----------------\n");
printf("\n\t\t===> 1. Food List");
sleep(1);
printf("\n\t\t===> 2. Order Food");
sleep(1);
printf("\n\t\t===> 3. Admin Panel");
sleep(1);
printf("\n\t\t===> 4. Exit\n");

int menu_choice;
scanf("\n%d",&menu_choice);
if(menu_choice==1)
{
	disp();
}

if(menu_choice==2)
{
	disp();
	input();
}

if(menu_choice==3)
{
	printf("Enter Pin:");
	scanf("%d",&adminp);
if(adminp==12345)
{
 do
 {
printf("\n\t\t<<<-------Enter your choice--------->>>\n");
printf("\n\t\t1. INSERT\n\n\t\t\t");
sleep(1);
printf("2. DISPLAY\n\n\t\t\t\t");
sleep(1);
printf("3. SEARCH");
sleep(1);
printf("\n\n\t\t\t\t\t4. DELETE\n\n\t\t\t\t\t\t");
sleep(1);
printf("5. UPDATE\n\n\t\t\t\t\t\t\t");
sleep(1);
printf("6. SORT");
sleep(1);
printf("\n\n\t\t\t\t\t\t\t\t7. EXIT");
printf("\n\n------------------------------------------\n");
printf("\nEnter your choice:");
scanf("%d", &c);
printf("\n");
  switch (c)
  {
    case 1:
insert();
	break;

	case 2:
	emp = empty();
	if (emp == 0)
	{
	printf("\nThe file is EMPTY\n");
    }
	else
	{
	disp();
	 break;
    }

	case 3:
	search();
	break;

	case 4:
	deletefile();
	break;

	case 5:
	update();
	break;

	case 6:
	emp = empty();
	if (emp == 0)
	{
	printf("\n The file is EMPTY\n");
    }
	else
	{
	sort();
	 break;
    }

	case 7:
	exit(0);
	break;

	default:
	printf("\nYour choice is wrong\nPlease try again...\n");
	break;

 }
}


while (c != 7);
}
else
{
printf("Wrong Password!!!!");
}
}
if(menu_choice==4)
{
	exit(0);
}
getch();
}

//insert records to file
void insert()
{
	FILE *fp;
	fp = fopen("Record", "a");
	printf("Enter the Item Number:");
	scanf("%d", &ad_m.item_no);
	printf("Enter the Name:");
	scanf("%s", &ad_m.name);
	printf("Enter the price:");
	scanf("%f", &ad_m.price);
	fwrite(&ad_m, sizeof(ad_m), 1, fp);
	fclose(fp);
}

//input order
void input()
{
	FILE *fp2;
	int r, s, avl;
	printf("\nEnter the Item no you want to order:");
	scanf("%d", &r);
	avl = avlitem_no(r);
	if (avl == 0)
	printf("Item No %d is not available\n",r);
	else
	{
		fp2 = fopen("Record", "r");
		while (fread(&ad_m, sizeof(ad_m), 1, fp2))
		{
		s = ad_m.item_no;
		if (s == r)
		{
			printf("\nITEM NO.= %d", ad_m.item_no);
			printf("\nNAME= %s", ad_m.name);
			printf("\nPRICE= %.2f\n", ad_m.price);
		}
		}
	fclose(fp2);
	}
}

//display records
void disp()
{
	FILE *fp1;
	fp1 = fopen("Record", "r");
	printf("\nItem Number\tName\tPrice\n\n");
	while (fread(&ad_m, sizeof(ad_m), 1, fp1))
	printf("  %d\t\t%s\t%.2f\n", ad_m.item_no, ad_m.name, ad_m.price);
	fclose(fp1);
}

//search the given record
void search()
{
	FILE *fp2;
	int r, s, avl;
	printf("\nEnter the Item no you want to search:");
	scanf("%d", &r);
	avl = avlitem_no(r);
	if (avl == 0)
	printf("Item No %d is not available in the file\n",r);
	else
	{
		fp2 = fopen("Record", "r");
		while (fread(&ad_m, sizeof(ad_m), 1, fp2))
		{
		s = ad_m.item_no;
		if (s == r)
		{
			printf("\nITEM NO.= %d", ad_m.item_no);
			printf("\nNAME= %s", ad_m.name);
			printf("\nPRICE= %.2f\n", ad_m.price);
		}
		}
	fclose(fp2);
	}
}

//delete a record
void deletefile()
{
FILE *fpo;
FILE *fpt;
int r, s;
printf("Enter the Item no you want to delete:");
scanf("%d", &r);
if (avlitem_no(r) == 0)
printf("Item no %d is not available in the file\n", r);
else
{
fpo = fopen("Record", "r");
fpt = fopen("TempFile", "w");
while (fread(&ad_m, sizeof(ad_m), 1, fpo))
{
s = ad_m.item_no;
if (s != r)
fwrite(&ad_m, sizeof(ad_m), 1, fpt);
}
fclose(fpo);
fclose(fpt);
fpo = fopen("Record", "w");
fpt = fopen("TempFile", "r");
while (fread(&ad_m, sizeof(ad_m), 1, fpt))
fwrite(&ad_m, sizeof(ad_m), 1, fpo);
printf("\nRECORD DELETED\n");
fclose(fpo);
fclose(fpt);
}

}

//update an existing record
void update()
{
intavl;
FILE *fpt;
FILE *fpo;
int s, r, ch;
printf("Enter Item number to update:");
scanf("%d", &r);
avl = avlitem_no(r);
if (avl == 0)
{
printf("Item number %d is not Available in the file", r);
}
else
{
fpo = fopen("Record", "r");
fpt = fopen("TempFile", "w");
while (fread(&ad_m, sizeof(ad_m), 1, fpo))
{
s = ad_m.item_no;
if (s != r)
fwrite(&ad_m, sizeof(ad_m), 1, fpt);
else
{
printf("\n\t1. Update Item Number %d", r);
printf("\n\t2. Update Price  %d", r);
printf("\n\t3. Update both Item and Price %d", r);
printf("\nEnter your choice:");
scanf("%d", &ch);
switch (ch)
{
case 1:
printf("Enter Name:");
scanf("%s", &ad_m.name);
break;
case 2:
printf("Enter Price:");
scanf("%f", &ad_m.price);
break;
case 3:
printf("Enter Name:");
scanf("%s", &ad_m.name);
printf("Enter Price:");
scanf("%f", &ad_m.price);
break;
default:
printf("Invalid Selection");
break;
}
fwrite(&ad_m, sizeof(ad_m), 1, fpt);
}
}
fclose(fpo);
fclose(fpt);
fpo = fopen("Record", "w");
fpt = fopen("TempFile", "r");
while (fread(&ad_m, sizeof(ad_m), 1, fpt))
{
fwrite(&ad_m, sizeof(ad_m), 1, fpo);
}
fclose(fpo);
fclose(fpt);
printf("RECORD UPDATED");
}
}

//sorting the record
void sort()
{
inta[20], count = 0, i, j, t, c;
FILE *fpo;
fpo = fopen("Record", "r");
while (fread(&ad_m, sizeof(ad_m), 1, fpo))
{
a[count] = ad_m.item_no;
count++;
}
c = count;
for (i = 0; i<count - 1; i++)
{
for (j = i + 1; j<count; j++)
{
if (a[i]>a[j])
{
t = a[i];
a[i] = a[j];
a[j] = t;
}
}
}
printf("Item No.\tName\t\tPrice\n\n");
count = c;
for (i = 0; i<count; i++)
{
rewind(fpo);
while (fread(&ad_m, sizeof(ad_m), 1, fpo))
{
if (a[i] == ad_m.item_no)
printf("\n %d\t\t %s \t\t %2f",ad_m.item_no, ad_m.name, ad_m.price);
}

}
}

//checking existance of the record
intavlitem_no(intrno)
{
FILE *fp;
int c = 0;
fp = fopen("Record", "r");
while (!feof(fp))
{
fread(&ad_m, sizeof(ad_m), 1, fp);

if (rno == ad_m.item_no)
{
fclose(fp);
return 1;
}
}
fclose(fp);
return 0;
}

//to check if file is empty
intempty()
{
int c = 0;
FILE *fp;
fp = fopen("Record", "r");
while (fread(&ad_m, sizeof(ad_m), 1, fp))
c = 1;
fclose(fp);
return c;
}
