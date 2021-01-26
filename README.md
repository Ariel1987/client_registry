# Client Registry
Program to register clients and their expenses

## General Info

The user is prompted to give the following information in order to register the clients:

- name
- year of birth
- expenses

The program also gives different ways to update or edit the client's information:

- remove client
- update client's expenses
- zero clients' expenses
- show best buyer
- show client's expenses

## Technologies

- C language

## Setup

To run this program, the user must have a GCC compiler instaled in his IDE. 
It can be installed following the steps in the [GCC Official Page](https://gcc.gnu.org/install/index.html). 
For a detailed step-by-step tutorial on how to use the GCC compiler with C see [this article](https://medium.com/@laura.derohan/compiling-c-files-with-gcc-step-by-step-8e78318052).

## Features

When the user first compile and run the program, a few options will be given:

- add client 

- read or edit clients'list

- Exit

Pressing "1" adds a client. The user will get to choose how many clients to add and be prompted the information required (name, birth year, expenses). 
The file will automatically be created. And return to the main menu.

![](prints-for-git/print3.png)

If the user presses "2" he will be taken to a secondary menu. However, if the file doesn't exist, any of the options he chooses will take to a warning message and return to the menu.

![](prints-for-git/print2.png)

If there is already a file, the user can choose what to edit or list the file, being taken to a secondary menu

![](prints-for-git/print4.png)

The first option will simply is to remove a specific client. The user will be prompted to choose will client he wants to remove. 
After removing, the program returns to the main menu.



The second option is to update a certain client's expenses. The user will be again prompted to choose a client and to give the new value. 
After displaying it, the program returns to the main menu 

![](prints-for-git/print5.png)

The third option will zero all expenses from every client and return to the menu.

The fourth option will display the best buyer from the list and return to the menu.

The fifth shows the expenses of a specific client, also prompting the user to choose one from the list and return to the menu. 

Finally the user can return to the main menu by pressing "5" or exit the program pressing "6" 
