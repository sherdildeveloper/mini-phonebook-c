#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char first_name[50];
    char last_name[50];
    char tel[15];
    char email[50];
};

void add_contact(struct Contact **phonebook,int *count, int *capacity){
    if (*count==*capacity){
        *capacity*=2;
        struct Contact *temp;
        temp=realloc(*phonebook,*capacity*sizeof(struct Contact));
        if (temp==NULL){ return ; }
        *phonebook=temp;
    }
    printf("Enter First Name ");
    scanf("%49s",(*phonebook)[*count].first_name);

    printf("Enter Last Name ");
    scanf("%49s",(*phonebook)[*count].last_name);

    printf("Enter telephone number ");
    scanf("%15s",(*phonebook)[*count].tel);

    printf("Enter Email Address ");
    scanf("%49s",(*phonebook)[*count].email);

    printf("Contact Added Successfully \n");
    (*count)++;

}

void display_all(struct Contact *phonebook, int count){
    for (int i=0;i<count;i++){
        printf("Contact # %d First Name is %s \n",i+1,phonebook[i].first_name);
        printf("Contact # %d Last Name is %s \n",i+1,phonebook[i].last_name);
        printf("Contact # %d Tel is %s \n",i+1,phonebook[i].tel);
        printf("Contact # %d email is %s \n",i+1,phonebook[i].email);
    }
}

void search_contact (struct Contact *phonebook,int count){
    int found=0;
    char search_term[50];
    printf("Enter First Name to Search:");
    scanf("%49s",search_term);
    for (int i=0;i<count;i++){
        
        if(strcmp(phonebook[i].first_name,search_term)==0){
            found=1;
            printf(" Found \n");
            printf("Last Name %s \n",phonebook[i].last_name);
            printf("telephone : %s \n",phonebook[i].tel);
            printf("Email Address: %s \n",phonebook[i].email);
        }
        if(!found){
            printf("not found");
        }

    }
}

void delete_contact(struct Contact *phonebook,int *count){
    char name_del[50];
    int found=0;
    printf("Enter the first name of data to delete:");
    scanf("%49s",name_del);
    for(int i=0;i<*count;i++){
    if(strcmp(phonebook[i].first_name,name_del)==0){
        found=1;
        for(int j=i;j<*count-1;j++){
            phonebook[j]=phonebook[j+1];
        }
        (*count)--;
        printf("%s record deleted\n",name_del);
    }

    }
    if(!found){
        printf("Not Found\n");
    }

}
    


int main(void){
    int choice; 

    struct Contact *phonebook=NULL;
    int count=0;
    int capacity=2;
    phonebook=(struct Contact*)malloc(capacity*sizeof(struct Contact));
    if(phonebook==NULL){
        printf("malloc failed\n");
        return 1;

    }
    while (1){
        printf("1-Add Contact\n");
        printf("2-Search\n");
        printf("3-Delete\n");
        printf("4-Display All\n");
        printf("5-Exit\n");
        scanf("%d",&choice);

    switch(choice){

        case 1: add_contact(&phonebook, &count, &capacity); break;
        case 2: search_contact(phonebook,count); break;
        case 3: delete_contact(phonebook,&count); break;
        case 4: display_all(phonebook,count); break;
        case 5: printf("Exiting\n");
                phonebook=NULL;
                printf("Goodbye\n");
                 return 0;
        default: printf("invalid choice\n");
    }
    }
}