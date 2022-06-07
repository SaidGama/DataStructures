#include<string>        //Libraries
#include<iostream>
#include<stdlib.h>

using namespace std;

/*                		Item structure
------------------------------------------------------------------------*/
struct item{
	int key;
	string value;
	item* next = NULL;
};

/*                		Hash table structure
------------------------------------------------------------------------*/
struct HashTable{
	int size;
	int count;
	item** items;
};

/*                 Function to create hash table
------------------------------------------------------------------------*/
HashTable* createTable(){
	int fullsize = 940;
	HashTable* table = new HashTable;
	if(table){
		table -> size = fullsize;
		table -> count = 0;
		table -> items = new item* [fullsize];
		cout<<"Table with "<<fullsize<<" elements created successfully"<<endl;

		for(int idx = 0; idx<fullsize; idx++){
			table -> items[idx] = NULL;

			return table;
		}
	}
	else{
		cout<<"Error, could not create table"<<endl;
		return NULL;
	}
}

/*                 Overflow function
------------------------------------------------------------------------*/
bool verifyOverflow(HashTable* table){
	if(table -> count < table -> size)
		return true;
	else
		return false;
}

/*                 Underflow function
------------------------------------------------------------------------*/
bool verifyUnderflow(HashTable* table){
	if(table -> count > 0)
		return true;
	else
		return false;
}

/*                 Hash function
------------------------------------------------------------------------*/
int Hash(string text){
	int idx;
	for(int i=0; i<text.size(); i++){
		idx += text[i]-32;
	}
	return idx;
}


/*           Function that hands the collisions
------------------------------------------------------------------------*/
void collisionHandling(HashTable* table, int idx, item* newCell){
	item* aux=table -> items[idx];
	while(aux -> next != NULL){
		aux = aux -> next;
	}
	aux -> next = newCell;
}

/*           Function that adds an element in the table
------------------------------------------------------------------------*/
void insertItem(HashTable* table){
	if(verifyOverflow(table)){
		string text;
		int idx;
		cout<<"Type text: ";
		cin>>text;
		if (text.length()<10){
			idx = Hash(text);
			item* newCell = new item;
			if (newCell){
				newCell -> key = idx;
				newCell -> value = text;
				if (table -> items[idx] == NULL)
					table -> items[idx] = newCell;
				else
					collisionHandling(table, idx, newCell);
					table -> count += 1;
					cout<<text<<" stored in the table in the index: "<<idx<<endl;
			}
			else
				cout<<"Error, could not insert element"<<endl;
		}
		else
			cout<<"Error, the string contains more than 10 elements"<<endl;
	}
	else
		cout<<"Full table, could not insert element"<<endl;
}

/*           Function that deletes an element in the table
------------------------------------------------------------------------*/
void deleteItem(HashTable* table){
	if(verifyUnderflow(table)){
		string text;
		int idx;
		item* temp = NULL;
		cout<<"Type text: ";
		cin>>text;
		idx = Hash(text);
		if(table -> items[idx]){
			if(table -> items[idx] -> value == text){
				delete table -> items[idx];
				table -> items[idx] = NULL;
				table -> count -= 1;
				cout<<"The text have been deleted successfully"<<endl;
			}
			temp = table -> items[idx] -> next;
			while(temp -> next != NULL){
				if (temp -> value == text){
					delete table -> items[idx];
					table -> items[idx] = NULL;
					table -> count -= 1;
					cout<<"The text have been deleted successfully"<<endl;
				}
				else
					temp = temp -> next;
			}
		}
		else
			cout<<"The string is not in the table"<<endl;
	}
	else
		cout<<"Empty table, there are not elements to delete"<<endl;
}

/*           Function that searchs an element in the table
------------------------------------------------------------------------*/
void searchItem(HashTable* table){
	string text;
	int idx;
	cout<<"Type text: ";
	cin>>text;
	idx = Hash(text);
	if(table -> items[idx])
		cout<<"The text is in the table"<<endl;
	else
		cout<<"The text is not in the table"<<endl;
}

/*           Function that prints the hash table
------------------------------------------------------------------------*/
void imprimirTabla (HashTable* table){
	
	for(int i=0; i<940; i++){
		item *ptr = new item();
		HashTable *temp = new HashTable;
		ptr = temp->items[i];
        if(temp->items[i]!=NULL){
            cout<<"Indice["<<i<<"]--> ";
		    while (ptr!=NULL){
			    cout<<ptr->value<<" --> ";
                ptr = ptr->next;
		    }
        }
	}
}

/*                    Options to perform menu
------------------------------------------------------------------------*/
int menu(){
	int opcabierta = 0;
	cout<<"1. Create a table"<<endl;
	cout<<"2. Insert an item"<<endl;
	cout<<"3. Delete an item"<<endl;
	cout<<"4. Search for an item"<<endl;
	cout<<"5. Print list"<<endl;
	cout<<"6. Close program"<<endl;
	cout<<"\n Choose option: ";
	cin>>opcabierta;
	cout<<"\n";
	return opcabierta;
}

/*           Function to in of each case
------------------------------------------------------------------------*/
void exeAction(){
	HashTable* table = NULL;
	bool numTable = false;
	int opcabierta = 0;
	while(opcabierta != 5){
		opcabierta = menu();
		switch(opcabierta){
			case 1:{
				if(!numTable){
					table = createTable();
					numTable = true;
				}
				else
					cout<<" Error, a table already exists"<<endl;
				break;
			}
			case 2:{
				insertItem(table);
				break;
			}
			case 3:{
				deleteItem(table);
				break;
			}
			case 4:{
				searchItem(table);
				break;
			}
			case 5:{
				imprimirTabla(table);
				break;
			}
			case 6:{
				cout<<"Closing program"<<endl;
				break;
			}
			default:{
				cout<<"Invalid option"<<endl;
				break;
			}
		}
	}
}

int main(){
	exeAction();
}

