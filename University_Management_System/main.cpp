#include <iostream>
#include<mysql.h>
#include<mysqld_error.h>
#include<windows.h>
#include<bits/stdc++.h>
#include<sstream>

using namespace std;

const char* HOST = "localhost";
const char* USER = "root";
const char* PASSW = "HelloWorld@1312";
const char* DB = "mydb";

void now(MYSQL* conn);
void removeTeacher(MYSQL* conn);
void removeStudent(MYSQL* conn);

class Student
{
   string name,password,section;
   int id, n;

  public:
    Student() {}
    //static int Studentcount; //static integer is used to count
    void FromFile(MYSQL *conn);
    void getFile(MYSQL* conn);
    void updateData(long int idd,MYSQL* conn);
    void deleteSectionassignment(string k,MYSQL *conn);
    void StudentData();
    string getName();
    string getSPassword();
    string sec();
    int getIdOfStudent();
    void display();
    void storeDataInDB(Student &s,MYSQL* );
};
void Student::storeDataInDB(Student &s,MYSQL* conn)
{
    
    cout << "enter the username of the student" << endl;
    cin>>s.name;
    
    cout << "enter the pass word for the student" << endl;
    cin>>s.password;

    cout << "enter student section" << endl;
    cin>>s.section;
    
    cout << "enter id of the student" << endl;
    cin >>s.id;
    
    stringstream ss;
    ss << id;
    string ID_str = ss.str();

            
    string query = "INSERT INTO student(id,name,section,password) VALUES('" + ID_str + "','" + name + "','"+ section + "','" + password +"')";

            
    if (mysql_query(conn, query.c_str())) {
    cout << "Query Error: " << mysql_error(conn) << endl;
    } else {
    cout << "Data Inserted: " << endl << endl;
                }
    Sleep(2000);
    
}

void Student::getFile(MYSQL* conn)
{
	
	cout<<"enter id : ";
	int id;
	cin>>id;
	
	stringstream ss;
		ss << id;
	string idStr = ss.str();	
	
	string get = "SELECT * from student where id = '"+ idStr +"'";
	
	if (mysql_query(conn, get.c_str())) 
	{
    	cout << "Query Error: " << mysql_error(conn) << endl;
    } 
	else 
	{
    	MYSQL_RES* result = mysql_store_result(conn);
    	if(result){
    		
    		int num = mysql_num_fields(result);
    		
    		MYSQL_ROW row;
    		cout<<"\n\n";
    		cout<<"\t\t ID\t\t name\t\t section\t\t Password"<<endl;
    		cout<<"\t\t --\t\t ------\t\t -------"<<endl;
    		
    		
    		
    		while(row = mysql_fetch_row(result))
    		for(int i = 0;i<num;i++){
    			cout<<"\t\t "<<row[i];
			}
			cout<<endl;
		}
		mysql_free_result(result);
    }
    Sleep(2000);
	

}


void Student::StudentData()
{
    Student s;
    cout << "enter the username of the student" << endl;
    cin>>s.name;
    
    cout << "enter the pass word for the student" << endl;
    cin>>s.password;

    cout << "enter student section" << endl;
    cin>>s.section;
    
    cout << "enter id of the student" << endl;
    cin >>s.id;


}

//returnns the password of the student

inline string Student::getSPassword() //inline keyword is used
{
    return password;
}
//returnds the username of the student
inline string Student::getName() //inline keyword is used
{
    return name;
}
//returns the id of the partiuclar student
inline int Student::getIdOfStudent() //inline keyword is used
{
    return id;
}



//-------------------STUDENT CLASSS END----------------


class Lecturer
{
    string password,username;
    int lecturerId;

  public:
    //default constructor
    static int LecturerCount; //static interger used to count
    Lecturer() {}
    //member function to get data from the user
    void getData();
    //getters
    string getPassword();
    string getUserName();
    void display();
    void storeDataInDB(Lecturer &l,MYSQL* conn);
    void getDataFromDB(MYSQL* conn);
    void FromFile(MYSQL* conn);
};

class AssignmentForAll
{
    string section;
    string assignmentforall;

  public:
    AssignmentForAll() //default constructor
    {
    	
    }
    void getDataForAssignForAll();
    string getSec();
    void display();
    void storeDataInDB(AssignmentForAll& obj,MYSQL* conn);
    void searchDataInDB(string s,MYSQL* conn);
    int getDataFromDB(MYSQL* conn);
};
void AssignmentForAll::searchDataInDB(string s,MYSQL *conn)
{
	cout<<"Section is: "<<s<<endl;
	string get = "SELECT * from AssignmentForAll where section = '"+ s +"'";
	
	if (mysql_query(conn, get.c_str())) 
	{
    	cout << "Query Error: " << mysql_error(conn) << endl;
    } 
	else 
	{
    	MYSQL_RES* result = mysql_store_result(conn);
    	if(result){
    		
    		int num = mysql_num_fields(result);
    		
    		MYSQL_ROW row;
    		cout<<"\n\n";
    		cout<<"\t\t section\t\t assignmentForAll"<<endl;
    		cout<<"\t\t ----------\t\t -------"<<endl;
    		
    			
    		while(row = mysql_fetch_row(result))
    		for(int i = 0;i<num;i++){
    			cout<<"\t\t "<<row[i];
			}
			cout<<endl;
		}
		mysql_free_result(result);
    }
    Sleep(2000);
	
    
}
inline void AssignmentForAll::display() 
{
    cout << section << endl;
    cout << assignmentforall << endl;
};

string AssignmentForAll::getSec() { return section; }

void AssignmentForAll::storeDataInDB(AssignmentForAll& obj,MYSQL* conn)
{
    cout << "enter the name of the section" << endl;
    //do not enter morw tham 9 charecters
    cin>>obj.section;
    cout << "enter assignment in 200 charecters" << endl;
    cin.ignore();
    getline(cin,obj.assignmentforall);
    
    string query = "INSERT INTO AssignmentForAll(section,assignmentForAll) VALUES('" + section + "','" + assignmentforall + "')";

            
    if (mysql_query(conn, query.c_str())) {
    cout << "Query Error: " << mysql_error(conn) << endl;
    } else {
    cout << "Data Inserted: " << endl << endl;
                }
    Sleep(2000);
    
}

int AssignmentForAll::getDataFromDB(MYSQL *conn)
{
    string get = "SELECT * from AssignmentForAll";
	
	if (mysql_query(conn, get.c_str())) 
	{
    	cout << "Query Error: " << mysql_error(conn) << endl;
    } 
	else 
	{
    	MYSQL_RES* result = mysql_store_result(conn);
    	if(result){
    		
    		int num = mysql_num_fields(result);
    		
    		MYSQL_ROW row;
    		cout<<"\n\n";
    		cout<<"\t\t section\t\t assignmentForAll"<<endl;
    		cout<<"\t\t ----------\t\t -------"<<endl;
    		
    		
    		
    		while(row = mysql_fetch_row(result))
    		for(int i = 0;i<num;i++){
    			cout<<"\t\t "<<row[i];
			}
			cout<<endl;
		}
		mysql_free_result(result);
    }
    Sleep(2000);
	
}
//--------------------------------------------------------------------------------

class AssignmentForOne
{
    int id;
    string assignment;

  public:
    AssignmentForOne()
    {
    }
    int getId();
    void getData();
    void display();
    void storeDataInDB(MYSQL* conn);
    void searchFromDB(string idd,MYSQL* conn);
    int getDataFromDB();
    int iddd();
};

void AssignmentForOne::searchFromDB(string id,MYSQL* conn)
{	

 string get = "SELECT * from assignmentforone where id = '"+ id +"'";
	
	if (mysql_query(conn, get.c_str())) 
	{
    	cout << "Query Error: " << mysql_error(conn) << endl;
    } 
	else 
	{
    	MYSQL_RES* result = mysql_store_result(conn);
    	if(result){
    		
    		int num = mysql_num_fields(result);
    		
    		MYSQL_ROW row;
    		cout<<"\n\n";
    		cout<<"\t\t id \t\t assignmentForYou"<<endl;
    		cout<<"\t\t ----------\t\t ----------"<<endl;
    		
    		
    		
    		while(row = mysql_fetch_row(result))
    		for(int i = 0;i<num;i++){
    			cout<<"\t\t "<<row[i];
			}
			cout<<endl;
		}
		mysql_free_result(result);
    }
    Sleep(2000);
	
    
}
//getter for id

inline int AssignmentForOne::getId() { return id; } //inline keyword is used


inline void AssignmentForOne::display() 
{
    cout << assignment << id << endl;
}

void AssignmentForOne::storeDataInDB(MYSQL* conn)
{
	cout << "enter the assignment that u want to assign" << endl;
    getline(cin,assignment);
    cin.ignore();
    cout << "enter the id of the student u want to assign the assignment" << endl;
    cin >> id;
    
    stringstream ss;
	ss << id;
	string idStr = ss.str();
    
    
    
    string query = "INSERT INTO assignmentforone(id,assignment) VALUES('" + idStr + "','" + assignment + "')";

            
    if (mysql_query(conn, query.c_str())) {
    cout << "Query Error: " << mysql_error(conn) << endl;
    } else {
    cout << "Data Inserted: " << endl << endl;
    }
    Sleep(2000);
   
}
//-----------------------*****************-----------------

int AssignmentForOne::iddd()
{
    return id;
}

void DeleteDataForOne(MYSQL* conn)
{
 	string query = "TRUNCATE TABLE assignmentforone";
    
    if (mysql_query(conn, query.c_str())) 
	{
    	cout << "Query Error: " << mysql_error(conn) << endl;
    } 
	else
	{
    	cout << "Data Deleted: " << endl << endl;
    	
    }
    Sleep(2000);
}

void DeleteDataForAll(MYSQL* conn)
{
    string query = "TRUNCATE TABLE assignmentforall";
    
    if (mysql_query(conn, query.c_str())) 
	{
    	cout << "Query Error: " << mysql_error(conn) << endl;
    } 
	else
	{
    	cout << "Data Deleted: " << endl << endl;
    	
    }
    Sleep(2000);
}
string Student::sec() { return section; }

void Student::FromFile(MYSQL* conn)
{
    Student a;
    AssignmentForAll b;
    AssignmentForOne c;
    char ch;
    int i;
    string nameOfStudent;
    string passwordOfStudent;
    cout << "enter your username" << endl;
    getline(cin,nameOfStudent);
    cin.ignore();
    
    string get = "SELECT * from student where name = '"+ nameOfStudent +"'";
    
    if (mysql_query(conn, get.c_str())) 
	{
    	cout << "Query Error: " << mysql_error(conn) << endl;
    } 
	else 
	{
    	MYSQL_RES* result = mysql_store_result(conn);
    	if(result){
    		
    		int num = mysql_num_fields(result);
    		
    		MYSQL_ROW row;
    		if ((row = mysql_fetch_row(result))) {
    			
        		std::cout << "Username found: " << row[0] << std::endl;
        		cout << "enter your password" << endl;
	            getline(cin,passwordOfStudent);
            	cin.ignore();
            	
            	if(passwordOfStudent == row[3]){
            		cout<<"Password Matched\n";
            		cout<<"-------------------------------------------------------------------------------------\n";
            		cout << "Welcome Student " << endl;
            		cout<<"-------------------------------------------------------------------------------------\n";

                do
                {
                    cout << "enter  1 for assignment for all" << endl;
                    cout << "enter  2 for assignment of you" << endl;
                    
                    cout<<"-------------------------------------------------------------------------------------\n";
                    
    				
                    cin >> i;
                    cin.ignore();

					
                    if(i == 1) 
                    {
                    	MYSQL_ROW row;
                    	MYSQL_RES *res;
                    
                 	    string get = "SELECT section FROM student WHERE name = '" + nameOfStudent + "'";
				        string section;
				
				    if (mysql_query(conn, get.c_str())) {
				        cout << "Query Error: " << mysql_error(conn) << endl;
				    }
				    else{
				    	res = mysql_store_result(conn);
				        if (res == NULL) {
				            cout << "mysql_store_result() failed\n";
				        } else {
				            row = mysql_fetch_row(res);
				            if (row != NULL) {
				                string section = row[0];
				                cout << "Section: " << section << endl;
				                	b.searchDataInDB(section,conn);
				                	return;
				            
				            } else {
				                cout << "No data found\n";
				            }
				            mysql_free_result(res);

					}
				
				}
				    	
				}
				
				else
				{
					   	MYSQL_ROW row;
                    	MYSQL_RES *res;
                    
                 	    string get = "SELECT id FROM student WHERE name = '" + nameOfStudent + "'";
				        string id;
				       
				    if (mysql_query(conn, get.c_str())) {
				        cout << "Query Error: " << mysql_error(conn) << endl;
				    }
				    else{
				    	res = mysql_store_result(conn);
				        if (res == NULL) {
				            cout << "mysql_store_result() failed\n";
				        } else {
				            row = mysql_fetch_row(res);
				            if (row != NULL) {
				                string id = row[0];
				                	c.searchFromDB(id,conn);
				                	return;
				            
				            } else {
				                cout << "No data found\n";
				            }
				            mysql_free_result(res);

					}
				
				}
					 
				}
                    cout << "do u want to continue" << endl
                         << "Enter Y||y for continue \n N||n for return to main menu" << endl;
                    cin >> ch;
                    cin.ignore(2);
                } while (ch == 'y' || ch == 'Y');
                
                if (ch == 'n' || ch == 'N')
    			{
			        cout << "logged out" << endl;
			        now(conn);
        			
    			}
            		
				}
				else{
					cout<<"Not Allowed";
				}
          
    		} 
			else 
			{
        		std::cout << "Username not found." << std::endl;
    		}
    		
			mysql_free_result(result);
	}
  }
    
    Sleep(2000);

}

class printdata 
{
    Student s;

  public:
    void print(int i)
    {
        cout << "total no.  is-";
        exit(-1);
    }
};


void Student::deleteSectionassignment(string str,MYSQL* conn)
{
	
       string deleteQuery = "DELETE FROM student WHERE section = '" + str + "'";
        if (mysql_query(conn, deleteQuery.c_str())) 
        {
                cout << "Delete Error: " << mysql_error(conn) << endl;
        } 
        else 
        {
                    cout << "Section assignment deleted successfully." << endl;
        }
}
void Student::updateData(long int idd,MYSQL* conn)
{
	
	stringstream ss;
	ss << idd;
	string idStr = ss.str();
	
	cout<<"Enter New Assignment : ";
    string newAssignment;
    cin>>newAssignment;

    string get = "UPDATE assignmentforone SET assignment = '" + newAssignment + "' WHERE id = '"+ idStr+"'";
    
    if (mysql_query(conn, get.c_str())) 
    {
        cout << "Query Error: " << mysql_error(conn) << endl;
    } 
    else 
    {
        	cout<<"Updated Successfully:";
            
    }
}


int GetIdStudent()
{
    int m;
    cout << "Enter the id of student u want to update" << endl;
    cin >> m;
    return m;
}
void Lecturer::FromFile(MYSQL *conn)
{
    Lecturer c;
    Student s;
    AssignmentForAll a;
    AssignmentForOne b;

    /********************/
    string currPass;
    string currUsername;
    char ch;
    cout << "please enter your username" << endl;
    getline(cin,currUsername);
    cin.ignore();
    int swi;
    
     string get = "SELECT * from lecturer where username = '"+ currUsername +"'";
    
    if (mysql_query(conn, get.c_str())) 
	{
    	cout << "Query Error: " << mysql_error(conn) << endl;
    } 
	else 
	{
    	MYSQL_RES* result = mysql_store_result(conn);
    	if(result){
    		
    		int num = mysql_num_fields(result);
    		
    		MYSQL_ROW row;
    		if ((row = mysql_fetch_row(result))) {
    			
        		std::cout << "Username found: " << row[0] << std::endl;
        		cout << "enter your password" << endl;
	            getline(cin,currPass);
            	cin.ignore();
            	
            	if(currPass == row[2]){
            		cout<<"Password Matched\n";
            		cout << "Welcome Lecturer " << endl;

                cout << "succesful login" << endl;
                cout << endl;

                do
                {
                	cout<<"-------------------------------------------------------------------------------------\n";
                	
                    cout << "enter 1 assigning assignment to all" << endl;
                    cout << "enter 2 for assigning for one" << endl;
                    cout << "enter 3 for deleteing all the individual assignment u assigned" << endl;
                    cout << "enter 4 for deleteing All the  assignment u assigned For All" << endl;
                    cout << "enter 5 for update the individual assinment" << endl;
                    cout << "enter 6 for update the sectionwise assignment" << endl;
                    cout << "enter 10 for exit the program" << endl;
                    cout << "enter your choice" << endl;
                    
                    cout<<"-------------------------------------------------------------------------------------\n";
                    cin >> swi;
                    cin.ignore();
                    switch (swi)
                    {
                    case 1:
                        a.storeDataInDB(a,conn);
                        break;
                    case 2:
                        b.storeDataInDB(conn);
                        break;
                    case 3:
                        DeleteDataForOne(conn);
                        break;
                    case 4:
                        DeleteDataForAll(conn);
                        break;
                    case 5:
                        s.updateData(GetIdStudent(),conn);
                        break;
                    case 6:
                        s.deleteSectionassignment(a.getSec(),conn);
                        break;
                    case 10:
                        exit(-1);
                    
                    default:
                        break;
                    }
                    cout << "enter if u want to continue press y||Y  to end enter n||n" << endl;
                    cin >> ch;
                    cin.ignore(2);
                    
                    if (ch == 'n' || ch == 'N')
    			    {
			        	cout << "logged out" << endl;
			        	now(conn);
        				
    				}
                } while (ch == 'Y' || ch == 'y');
                
                
            		
				}
				else{
					cout<<"Invalid Credentials";
				}
          
    		} 
			else 
			{
        		std::cout << "Username not found." << std::endl;
    		}
    		
			mysql_free_result(result);
	}
  }
}


inline void Lecturer::display() //inline keyword is used
{
    cout << username << " " << lecturerId << password << endl;
}
void Lecturer::getDataFromDB(MYSQL* conn)
{
    Lecturer a;
    ifstream fin;
    fin.open("LecturerData.bin", ios::in | ios::binary);
    fin.read((char *)&a, sizeof(class Lecturer));
    while (!fin.eof())
    {
        a.display();
        fin.read((char *)&a, sizeof(class Lecturer));
    }
    fin.close();
}

void Lecturer::storeDataInDB(Lecturer &l,MYSQL* conn)
{
    //LecturerCount++;
    cout << "enter the username of the lecturer" << endl;
    cin>>l.username;
    
    cout << "enter the password for the lecturer" << endl;
    cin>>l.password;

    cout << "enter id of the lecturer" << endl;
    cin >>l.lecturerId;
    
    stringstream ss;
    ss << lecturerId;
    string ID_str = ss.str();

            
    string query = "INSERT INTO lecturer(id,username,password) VALUES('" + ID_str + "','" + username + "','" + password +"')";

            
    if (mysql_query(conn, query.c_str())) {
    cout << "Query Error: " << mysql_error(conn) << endl;
    } else {
    cout << "Data Inserted: " << endl << endl;
                }
    Sleep(2000);
    
}
//defination for password getter
string Lecturer::getPassword() { return password; }
//defination for userName getter
string Lecturer::getUserName() { return username; }
//defination of member function to get details from the user
void Lecturer::getData()
{
    //LecturerCount++;
    cout << "enter UserName" << endl;
    getline(cin,username);
    cout << "enter password" << endl;
    getline(cin,password);
    cout << "enter lecturer id" << endl;
    // cin.getline(lecturerId,10);
    cin >> lecturerId;
    cin.ignore();
}

//-----------------------------------------------------------------

string adminName = "suvrat";
string adminPassword = "OpenUp";

void removeTeacher(MYSQL* conn){
	
		cout<<"Enter Lecturer Id : ";
		int id;
		cin>>id;
		
		stringstream ss;
	    ss << id;
	    string ID_str = ss.str();
		
	 	string deleteQuery = "DELETE FROM lecturer WHERE id = '" + ID_str + "'";
     	if (mysql_query(conn, deleteQuery.c_str())) 
    	{
                cout << "Delete Error: " << mysql_error(conn) << endl;
        } 
        else 
        {
                    cout << "Lecturer deleted successfully." << endl;
        }
         Sleep(2000);
        now(conn);
	
}

void removeStudent(MYSQL* conn){
	
		cout<<"Enter Student Id : ";
		int id;
		cin>>id;
		
		stringstream ss;
	    ss << id;
	    string ID_str = ss.str();
		
	 	string deleteQuery = "DELETE FROM student WHERE id = '" + ID_str + "'";
     	if (mysql_query(conn, deleteQuery.c_str())) 
    	{
                cout << "Delete Error: " << mysql_error(conn) << endl;
        } 
        else 
        {
                    cout << "Student deleted successfully." << endl;
        }
         Sleep(2000);
        now(conn);
	
}


void adminLogin(MYSQL *conn){
	
	string name,password;
	
	cout<<"Enter name : ";
	cin>>name;
	
	cout<<"Enter password : ";
	cin>>password;
	
	if(name == adminName && password == adminPassword){
		cout<<"Enter 1 to remove teacher.\n";
		cout<<"Enter 2 to remove student.\n";
		
		int val;
		cin>>val;
		
		switch(val){
			case 1:
				removeTeacher(conn);
				break;
			case 2:
				removeStudent(conn);
				break;
		}	
	}
	else{
		cout<<"Not Allowed....!";
	}
}
//----------------------------------------------------------------

void now(MYSQL* conn)
{
    Student s;
    Lecturer l;
    
    system("cls");
	
	cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t\t\t\t\t\tWELCOME\n";
	cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;

    cout << "Register Student in our system enter 1" << endl;
    cout << "Register Teacher in our system enter 2" << endl;
    cout << "Student Sign in enter 3"<< endl;
    cout << "Teacher Sign in enter 4"<< endl;
    cout <<"Admin Login 5"<<endl;
    cout << "enter 6 for exit"<< endl;
    
    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
    
    	int i;
    	cin >> i;
	    cin.ignore();

	    switch (i)
	    {
	    case 1:
	        s.storeDataInDB(s,conn);
	        break;
	    case 2:
	        l.storeDataInDB(l,conn);
	    case 3:
	        s.FromFile(conn);
	        break;
	    case 4:
	        l.FromFile(conn);
	        break;
	    case 5:
	    	adminLogin(conn);
	    case 6:
	        exit(-1);
	    default:
	        break;
	    }	
	    
	    now(conn);
}


//------------------------------------------------------------------------------------

int main() {
	
	MYSQL* conn;
	conn = mysql_init(NULL);
	
	if(!mysql_real_connect(conn,HOST,USER,PASSW,DB,3306,NULL,0)){
		cout<<mysql_error(conn);
	}
	else{
			now(conn);
	}
	

	mysql_close(conn);	
	return 0;
}
