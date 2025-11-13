#!/bin/bash

create() {
	
	echo "Enter the new AddressBook name";
	read ab
	
	if [ -f "$ab" ] ; then
		echo "The Address Book with name already exists"
	else
		touch "$ab"
		echo "New Address Book Created"
	fi
}



view() {

	echo "Enter the address book that you want to view"
	read ab
	
	if [ ! -f "$ab" ] ; then
		echo "The address book does not exists"
	else 
		echo "*** Content of the Address Book $ab ***"
		cat "$ab"
		echo "*** end **"
	fi;

}

insert() {

	echo "Enter the name of Address Book"
	read ab
	
	if [ ! -f "$ab" ] ; then 
		echo "The address book does not exists"
	else
		echo "Enter the Name: "
		read name;
		echo "Enter the Email: "
		read email;
		echo "Enter the Address: "
		read address;
		
		echo "$name | $email | $address " >> "$ab"
	fi;

}

delete() {

	echo "Enter the name of Address Book"
	read ab
	
	if [ ! -f "$ab" ] ; then 
		echo "The address book does not exists"
	else
		echo "Enter name to delete"
		read name
		grep -v "^$name" "$ab" > temp  
		mv temp "$ab"
		echo "record deleted Successfully"
	fi;

}

modify() {

	echo "Enter the name of Address Book"
	read ab
	
	if [ ! -f "$ab" ] ; then 
		echo "The address book does not exists"
	else 
		echo "Enter the name to modify"
		read name;
		
		if ! grep -q "^$name" "$ab" ; then
			echo "Record not found"
		else
			grep -v "^$name" "$ab" > temp  
			mv temp "$ab"
			echo "Enter the Name: "
			read name;
			echo "Enter the Email: "
			read email;
			echo "Enter the Address: "
			read address;
			
			
			echo "$name | $email | $address " >> "$ab"
		fi
	fi
			

}

while true
do

echo "1 create | 2 insert | 3 delete | 4 modify | 5 view | 6 exit"
read chooise;

case $chooise in 
1) create;;
2) insert;;
3) delete;;
4) modify;;
5) view;;
6) exit;;
*) echo "invalid chooise";
esac
done
