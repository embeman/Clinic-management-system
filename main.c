#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// user mode
    /*
        * view patient record
        * view reservations for today
    */
// admin mode
    /*
        *** 
            Check for password 3 attemp and default password is 1234
        *** 
            * add new pationt record
            * edit pationt record
            * reserve a slot with a doctor
            * cancel reservation with a doctor
    */

void clear_screen(){system("clear");}

struct _patient{
    int ID;
    char* name;
    int age;
    char gender;
    struct _patient* next;
};

static struct _patient* _pa_head = NULL;

static struct _patient* search(struct _patient** head, int _id){
    struct _patient* current = *head;
    while(current != NULL){
        if(current->ID == _id){
            return current;
        }
        current = current->next;
    }
    return NULL; // Element Not Found
}

void add_new_pationt_record(){
    clear_screen();
    printf("Adding New Patient Record\n");
    printf("ID : ");
    int _id;
    scanf("%d",&_id);
    // search for ID in the list
    if(search(&_pa_head , _id) != NULL){ // if found
        // id found can't create new pationt id
        printf("ID Found Can't add new pationt with this ID\n");
        return;
    }
    struct _patient* _node = malloc(sizeof(struct _patient));
    _node->ID = _id;
    _node->name = malloc(sizeof(char) * 100);
    // reading patient info
    printf("Name : ");
    scanf("%s",_node->name);
    printf("Age : ");
    scanf("%d",&_node->age);
    printf("Gender (M/F) : ");
    scanf("%c",&_node->gender);
    
    // adding node to the list
    _node->next = _pa_head;
    _pa_head = _node;
    
}

void edit_pationt_record(){
    printf("Edit patient record\n");
}

void reserve_slot(){
    printf("Reserve a slot with the doctor\n");            
}

void cancel_reservation(){
    printf("Cancel reservation\n");            
}

void view_patient_record(){
    clear_screen();
    printf("View Patient record\nID : ");
    int _id;
    scanf("%d" , &_id);
    struct _patient* _pa = search(&_pa_head , _id);
    if(_pa == NULL){
        printf("Not Found\n");
    }else{
        printf("Patient ID : %d\nPatient Name : %s\nPatient Age : %d\nPatient Gender : %c\n" , _pa->ID , _pa->name , _pa->age , _pa->gender);
    }
}

void view_reservations_for_today(){
    printf("View today’s reservations\n");
}


int main()
{
    // choose your mode (admin / user)
    int sel;
    while(sel != 3){
        printf("Welcome to Clinic Management System.\n");
        printf("Choose Your Mode : \n\t1. Admin\n\t2. User\n\t3. Terminate\n");
        scanf("%d",&sel);
        if(sel == 1) // Admin
        {
            int tries = 0;
            while(tries <3){
                // reading password
                printf("Admin Loging in : admin\npassword : ");
                char pass[50];
                scanf("%s",pass);
                if(strcmp(pass, "1234") == 0){
                    // correct Password
                    break;
                }else{
                    // wrong password
                    if(++tries == 3){
                        printf("Wrong Password 3 attempt\nExiting...");
                        return 0;
                    }
                    printf("Wrong Password %d attempt \n" , tries);
                }
            }
                printf("1. Add new patient record\n2. Edit patient record\n3. Reserve a slot with the doctor\n4. Cancel reservation.\nEnter Your Choice : ");
                int _sel;
                scanf("%d" , &_sel);
                
                switch(_sel){
                    case 1:
                        // Add new patient record
                        add_new_pationt_record();
                        break;
                    case 2:
                        // Edit patient record
                        edit_pationt_record();
                        break;
                    case 3:
                        // Reserve a slot with the doctor
                        reserve_slot();     
                        break;
                    case 4:
                        // Cancel reservation
                        cancel_reservation();
                        break;
                    default:
                        printf("Unknowing Command\nExiting...\n");
                        return 0;               
                        break;
                }
        }else if(sel == 2) // User
        {
            printf("User Logedin Succefully\n\t1 - View patient record.\n\t2 - View today's reservations.\nEnter Your Choice : ");
            scanf("%d" , &sel);
            switch(sel){
                case 1:
                    // View Patient record
                    view_patient_record();
                    break;
                case 2:
                    // View today’s reservations
                    view_reservations_for_today();
                    break;
                default:
                    printf("Unknowing Command\nExiting...\n");
                    return 0;               
                    break;
            }
        }else{ // Invalid Input
            printf("Unknowing Command\nExiting...\n");
            return 0;
        }
    }
    return 0;
}