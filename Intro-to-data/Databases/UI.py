def addStudent():
    id=input('Enter the new student id: ')
    first=input('First Name: ')
    last=input('Last Name: ')
    major=input('Major: ')
    phone=input('Phone: ')
    query= f"insert into students (id, first, last, phone, major) values ({id},'{first}','{last}','{major}','{phone}');"
    print(query)

def deleteStudent():
    pass

def showStudent():
    id=input('Enter id: ')
    query=f"""select * from students where id={id}"""
    print(query)

def updateStudent():
    print("Enter the ")
    id=input("ID:")
    first=input("First name: ")
    last=input("Last name: ")
    major=input("Major: ")
    phone=input("Phone number: ")
    query=f"""update students"""



while(choice !=0):
    print("1) Add a student")
    print("2) Delete a student")
    print("3) Show a student")
    print("4) Update a student")
    print("0) Quit")

    choice=input("Type the number of your choice: ")
    if (choice=='1'):
        addStudent()
    if (choice =='2'):
        deleteStudent()
    if (choice =='3'):
        showStudent()
    if (choice == '4'):
        updateStudent()