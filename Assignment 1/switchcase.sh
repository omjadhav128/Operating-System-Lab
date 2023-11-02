echo "Enter Address Book Name: "
read fname
touch $fname
echo -e "Address Book created \n"
echo -e "Name: \t Id \t DOB\t\tAddress\t Mob_No\t\t Salary">>$fname
ch=0
while [ $ch -lt '7' ]
do
echo -e "Address Book :\n"
echo -e "1. Create Address Book "
echo -e "2. View Address Book"
echo -e "3. Insert a Record"
echo -e "4. Delete a Record"
echo -e "5. Modify a Record"
echo -e "6. Search a Record"
echo -e "7. Exit from Address Book"
echo -e "Enter your choice"
read ch
case $ch in
	1)echo -e "Enter Number of records you want to enter \t"
	  read n
	  for((i=0; i<$n; i++))
	  do
		echo -e "Enter name of Employee\t"
		read ename
		echo -e "Enter id of Employee\t"
		read eid
		echo -e "Enter DOB of Employee\t"
		read edob
		echo -e "Enter Address of Employee\t"
		read eadd
		echo -e "Enter Mobile No of Employee\t"
		read emob
		echo -e "Enter salary of Employee\t"
		read esal
		echo -e " $ename \t $eid \t $edob \t $eadd \t $emob \t $esal \n">>$fname
	  done
	  ;;
	2)
		cat $fname
	  ;;
	3)
	  echo -e "Enter new Record"
	  echo -e "Enter name of Employee\t"
	  read ename
	  echo -e "Enter id of Employee\t"
	  read eid
	  echo -e "Enter DOB of Employee\t"
	  read edob
	  echo -e "Enter Address of Employee\t"
	  read eadd
	  echo -e "Enter Mobile No of Employee\t"
	  read emob
	  echo -e "Enter salary of Employee\t"
	  read esal
	  echo -e " $ename \t $eid \t $edob \t $eadd \t $emob \t $esal \n">>$fname
	  ;;
	4)
	  echo -e "Enter Employee ID to be deleted "
	  read eid
	  if grep -w $eid $fname
	  then 
		grep -wv $eid $fname >>temp
		rm $fname
		mv temp $fname
		echo "Record Deleted"
	  else
		echo "Record does not exist"
	  fi
	  ;;
	5)
	  echo "Enter Employee ID to be Modify"
	  read eid
	  if grep -w $eid $fname
	  then 
		grep -wv $eid $fname >> temp
		rm $fname
		mv temp $fname
		echo -e "Enter modified record"
		echo -e "Enter name of Employee\t"
	   	read ename
	    	echo -e "Enter id of Employee\t"
	    	read eid
	    	echo -e "Enter DOB of Employee\t"
	    	read edob
	    	echo -e "Enter Address of Employee\t"
	    	read eadd
	    	echo -e "Enter Mobile No of Employee\t"
	    	read emob
	    	echo -e "Enter salary of Employee\t"
	    	read esal
	    	echo -e " $ename \t $eid \t $edob \t $eadd \t $emob \t $esal \n">>$fname
	  else
		echo "Record does not Exist"
	  fi
	  ;;
	6)
	  echo -e "Enter Employee to be searched "
	  read eid
	  if grep $eid $fname
	  then
		grep -w $eid $fname
		echo "Record Found "
	  else
		echo "Record does no Exists"
	  fi
	  ;;
esac
done