#include<iostream>
#include<limits>
#include<fstream>
#include<conio.h>
#include<iomanip>
#include<string>
#include<sstream>
#include<windows.h>
using namespace std;


class Staff
{
	private:
	    string staff_FName;
		string staff_LName;
		string staffworkdays;
		string staffworktimings;
	    int staffAge;
		int staffId;
	    long long int staffPhoneNumber;
	    string staffDesignation;
    public:
    	void addStaff();
	    void showstaffdata();
		void searchstaffdata();
		void removeStaff();
		void updateStaff();
		void staffMenu() 
		{
			system("CLS");
		    while (true) 
			{
		    
		        char choice;
		         cout << "\n\t\t========================================" << endl;
				cout << "\t\t|       Staff Management System        |" << endl;
				cout << "\t\t========================================" << endl;
				cout << "\t\t| 1. Add Staff                         |" << endl;
				cout << "\t\t| 2. Show Staff                        |" << endl;
				cout << "\t\t| 3. Search Staff                      |" << endl;
				cout << "\t\t| 4. Remove Staff                      |" << endl;
				cout << "\t\t| 5. Update Staff                      |" << endl;
				cout << "\t\t| 6. Exit                              |" << endl;
				cout << "\t\t========================================" << endl;
				cout << "\t\t| Enter your choice: ";
    
		        choice = _getch();  // Get single character input
		        
		        switch (choice) 
				{
		            case '1':
		               system("CLS");
		               addStaff();
		                break;
		            case '2':
		                system("CLS");
						showstaffdata();
		                break;
		            case '3':
		            	system("CLS");
		                searchstaffdata();
		                break;
		            case '4':
		            	system("CLS");
		                removeStaff();
		                break;
		            case '5':
		            	system("CLS");
		            	updateStaff();
		            	break;
		            case '6':
		                return;
		            default:
		                cout << "\n\t Invalid choice. Please try again.";
		                Sleep(2000);
		                break;
		        }
		    }
		}
	   
    
	
};



class Patient 
{
	
	private:
		int doctor_fee;
		string _time;
		int Patient_id;
		string _date ;
	    string firstName;
		string lastName;
		string bloodGroup;
		string diagnosis;
	    int age;
	    string diagnosis_field;
	    string doctor_reffered;
	    string* BLOODGROUPS ;
	    int roomID;
	    long long int phoneNumber;
		long long int cnic;
	public:
		Patient()
		{
		   _time = __TIME__;
		   _date = __DATE__;
		}
		
		//sets to current date and returns the value
		string date()
		{
			 _date = __DATE__;
			 return _date;
		}
		
		//sets to current time and returns it
		string time()
		{
			  _time = __TIME__;
			 return _time;
		}
		
		~Patient()
		{
			delete[] BLOODGROUPS;
		}
		
		//setting the bloodgroups
		void setbloodgroups()
		{
			string Bloodgroups[]=  {"A+", "A-", " B+", "B-", "AB+", "AB-", "O+", "O-"};
			int size=8;
			BLOODGROUPS = new string[size];
			for (int i=0;i<8;i++)
			{
				BLOODGROUPS[i] = Bloodgroups[i];
			}
		}
		
		//checking wheter a patient is admitted in a room or not
		bool is_present_in_room(string Room_id,int P_id) 
		{
				
			fstream file;
	        int room_occupancy;
			file.open(Room_id, ios:: in );
			
			
			if(!file.is_open())
			{
				cout<<"Error Opening File!!"<<endl;
				return false;
			}
			file>>room_occupancy;
			 while(file >> Patient_id )
		  	{   
			  	  file.ignore();
				  getline(file, _time );  
				  getline(file, _date );  
				   if(Patient_id == P_id)
				   {
				   	 return true;
				   	 //if present returns true else false
				   }
				   
					  
				   	
				   
		   }
		     return false;
		}
		
		//checking wheter the id used is valid or not for indoor patients
		bool isidvalid(int id)
		{ 
		    
			ifstream file;
			int file_id;
			int pat_id;
			 file.open("indoor.txt");
		    while (file >> firstName >> lastName >> pat_id >> age >> phoneNumber >> cnic)
			{
		        file.ignore();
		        getline(file, bloodGroup);
		        getline(file, diagnosis);
		        file>>roomID;
		        file.ignore();
		        getline(file, _date);
		        getline(file, _time);
		        if (pat_id == id) 
				{
				   return true;
				}
				
		        
		    }
		    file.close();
				return false;
				
		}
		
		//validation to ensure unique id for every patient
		bool is_outdoorid_unique(int id) 
		{
		    ifstream file;
		    int pat_id;
		    
		    file.open("outdoor.txt");
		    while (file >> firstName >> lastName >> pat_id >> age >> phoneNumber >> cnic) 
			{
		        file.ignore();
		        getline(file, bloodGroup);
		        getline(file, diagnosis);
		        getline(file, doctor_reffered);
		        getline(file, _time);
				getline(file, _date);
				file >> doctor_fee;
		        if (id == pat_id) 
		        {
					return true;
				}
		       
		    }
		    file.close();
		
		   
		
		    return false;
     	}

		//adding new patient two choice either indoor or outdoor
		void addpatient()
		{
		i:
		    system("cls");
		    
			fstream file;
			//variables of indooer case
			fstream room_file;
			    string Room_id;             //variables to be used in subswitch declared here
			    int max_occupancy,count=0;
			    	fstream ifile;
			int j;
			char ch;
		cout << "\n";
		cout << "\n\t\t *************************************************************************" << endl;
		cout << "\t\t ||\t\t  Patient Type Selection"
		     << "\t\t\t        || " << endl;
		cout << "\t\t ||_____________________________________________________________________||" << endl;
		cout << "\t\t ||                                                                     ||" << endl;
		cout << "\t\t || Enter whether the patient is an indoor or outdoor patient:          ||" << endl;
		cout << "\t\t ||                                                                     ||" << endl;
		cout << "\t\t || Enter 'o' for outdoor patient.                                      ||" << endl;
		cout << "\t\t || Enter 'i' for indoor patient.                                       ||" << endl;
		cout << "\t\t ||                                                                     ||" << endl;
		cout << "\t\t *************************************************************************" << endl;
		cout << "\n";

			ch=getch();
			cout<<"\n\n";
			  
			switch(ch)
			{
			case 'o':
				system("cls");
				int j;
		        cout << "\t\t\t\tData of outdoor patient " << endl;
		        x:
		        cout << "\n\tPatient ID : ";
				cin>>Patient_id;
				while(cin.fail())   //when input fails the(putting char etc in int) buffer remains in error state
		    	{
		    		cout << "\n\t Invalid input! Enter integers only " << endl;
					cin.clear();
					cin.ignore(132, '\n');    //clearing the input buffer from error state
					goto x;
				}
		        while(Patient_id<1000 || Patient_id>=10000)
                {
                	cout<<"\n\t\tEnter a valid Patient_id";
                	goto x;
				}	
				while(is_outdoorid_unique(Patient_id))
				{
					cout<<"\n\t\tThis id already exsists enter a valid Patient_id";
                    goto x;
				}
				
		        cout << "\tFirst name of patient : ";
		        cin >> firstName;
		
		
		        cout << "\n\tLast name of patient : ";
		        cin >> lastName;
                	
               
		       
		        
		
		        cout << "\n\tPatient age : ";
		        cin >> age;
		        while(cin.fail())   //when input fails the(putting char etc in int) buffer remains in error state
		    	{
		    		cout << "\n\t Invalid input! Enter integers only " << endl;
					cin.clear();
					cin.ignore(132, '\n');    //clearing the input buffer from error state
					cout << "\n\tPatient age : ";
		            cin >> age;
				}
		
		        cout << "\n\tPatient phone no : ";
		        cin >> phoneNumber;
		        while(cin.fail())
		    	{
		  			cout << "\n\t Invalid input! Enter integers only " << endl;
					cin.clear();
					cin.ignore(132, '\n');
					cout << "\n\tPatient phone no : ";
			        cin >> phoneNumber;
				}
		
		        cout << "\n\tPatient cnic : ";
		        cin >> cnic;
		        while(cin.fail())
		    	{
		    		cout << "\n\t Invalid input! Enter integers only " << endl;
					cin.clear();
					cin.ignore(132, '\n');
					cin >> cnic;
				}
		        
		        setbloodgroups();
		        cout << "\n\tPatient's Blood group " << endl;
		        cout << "\tPress the following " << endl;
		        cout << " \t 1--> for A+ \t 2--> for A- "
		             << "\n\t 3--> for B+ \t 4--> for B- "
		             << " \n\t 5--> for AB+ \t 6--> for AB- "
		             << "\n\t 7--> for O+ \t 8--> O-: " << endl;
		        cout << "\tEnter your input ";
		        cin >> j;
		        while (j < 1 || j > 8)
		        {
		            cout << "\n\tInvalid input please enter a valid choice " << endl;
		            cout << "\tEnter your input again ";
		            cin >> j;
		        }
		        cout << "\tThe blood group you selected is :" << BLOODGROUPS[j - 1] << endl;
		
		        cout << "\tPatient diagnosis disease : ";
		        cin.ignore();
		        getline(cin, diagnosis);
		        
		        cout << "\tEnter the doctor id Patient is reffered to: ";
		        cin.ignore();
		        getline(cin, doctor_reffered);
		        
		        cout << "\tCurrent  date is : " << date();
		        cout << "\n\tCurrent Time is : " << time();
		        cout<<"\n\t\tThe Doctor fee is :";
		        cin>>doctor_fee;
		        file.open("outdoor.txt", ios::out | ios::app);
		        if (!file.is_open())
		        {
		            cout << "\tError opening file " << endl;
		        }
		        file << " " << firstName << "\n";
		        file << " " << lastName << "\n";
		        file << " " << Patient_id << "\n";
		        file << " " << age << "\n";
		        file << " " << phoneNumber << "\n";
		        file << " " << cnic << "\n";
		        file << " " << BLOODGROUPS[j - 1] << "\n";
		        file << " " << diagnosis << "\n";
		        file << " " << doctor_reffered<< endl;
		        file << " " << date() << endl;
		        file << " " << time() << endl;
		        file << " " << doctor_fee << endl;
		        file.close();
				break;
				
			case 'i':
				system("cls");
				cout << "\t\t\t\tData of indoor patient " << endl;
		      o:
		       cin.clear();
		       cout << "\n\tPatient ID : ";
		       cin>>Patient_id;
		    
				while(cin.fail())   //when input fails the(putting char etc in int) buffer remains in error state
		    	{
		    		cout << "\n\t Invalid input! Enter integers only " << endl;
					cin.clear();
					cin.ignore(132, '\n');    //clearing the input buffer from error state
					goto o;
				}
		        while(Patient_id<1000 || Patient_id>=10000)
                {
                	cout<<"\n\t\tEnter a valid Patient_id ";
                	goto o;
				}	
				 while(isidvalid(Patient_id))
			    {
			    	cout<<"\n\t\tEnter a valid Patient_id ";
                	goto o;
				}
                 
		      
		        
		        cout<<Patient_id<<endl;
		        cout << "\tFirst name of patient : ";
		        cin >> firstName;
		
		
		        cout << "\n\tLast name of patient : ";
		        cin >> lastName;
		
		        cout << "\n\tPatient age : ";
		        cin >> age;
		        while(cin.fail())
		    	{
		    		cout << "\n\t Invalid input! Enter integers only " << endl;
					cin.clear();
					cin.ignore(132, '\n');
					cin >> age;
				}
		
		        cout << "\n\tPatient phone no : ";
		        cin >> phoneNumber;
		        while(cin.fail())
		    	{
		  			cout << "\n\t Invalid input! Enter integers only " << endl;
					cin.clear();
					cin.ignore(132, '\n');
					cin >> phoneNumber;
				}
		
		        cout << "\n\tPatient cnic : ";
		        cin >> cnic;
		        while(cin.fail())
		    	{
		    		cout << "\n\t Invalid input! Enter integers only " << endl;
					cin.clear();
					cin.ignore(132, '\n');
					cin >> cnic;
				}
				
				setbloodgroups();
		        cout << "\n\tPatient's Blood group " << endl;
		        cout << "\tPress the following " << endl;
		        cout << " \t 1--> for A+ \t 2--> for A- "
		             << "\n\t 3--> for B+ \t 4--> for B- "
		             << " \n\t 5--> for AB+ \t 6--> for AB- "
		             << "\n\t 7--> for O+ \t 8--> O-: " << endl;
		        cout << "\tEnter your input ";
		        cin >> j;
		        while (j < 1 || j > 8)
		        {
		            cout << "\n\tInvalid input please enter a valid choice " << endl;
		            cout << "\tEnter your input again ";
		            cin >> j;
		        }
		        cout << "\tThe blood group you selected is :" << BLOODGROUPS[j - 1] << endl;
		
		        cout << "\tPatient diagnosis disease : ";
		        cin.ignore();
		        getline(cin, diagnosis);
				
				pointzero:       //point zero declared here
				
				char choose;
				cout << "\n\t\t========================================" << endl;
			    cout << "\t\t|         Room Type Selection           |" << endl;
			    cout << "\t\t========================================" << endl;
			    cout << "\t\t| Whether he wants a single, double,    |" << endl;
			    cout << "\t\t| or triple bed room.                   |" << endl;
			    cout << "\t\t| Press 1 for single, 2 for double,     |" << endl;
			    cout << "\t\t| 3 for triple.                         |" << endl;
			    cout << "\t\t| Enter your choice:                    |" << endl;
			    cout << "\t\t========================================" << endl;
			    choose=getch();
			    int Pat_id;
//			    fstream room_file;
//			    string Room_id;             //variables to be used in switch declared here
//			    int max_occupancy,count=0;
			    switch(choose)
			    {
			    	//validations also provided in every case to ensure that room may not contain more than its capaccity patients
			    	case '1':
			    	
			    		cout<<"\n\t\tSingle bed contaiing rooms are listed below."<<endl;
			    		file.open("singlebed.txt",ios::in);
			    		if(!file.is_open())
			    		{
			    			cout<<"\t\tError accessing Room data due to file not opening."<<endl;
			    		    return;
						}
						else 
						{
							while(file>>Room_id)
							{
								cout<<Room_id<<endl;
								
							}
						}
						file.close();
						start:                                    //start point declared
						cout<<"\t\tSelect the Room id from above and enter below.";
						cin>>Room_id;
						room_file.open(Room_id,ios::in);
						if(!room_file.is_open())
						{
							cout<<"\t\tError opening file."<<endl;
							return;
						}
						else
						{ 
						    
							room_file>>max_occupancy;
							while(room_file>>Pat_id)
							{
								room_file.ignore();
								getline(room_file,_time);
								getline(room_file,_date);
								count++;          
							}
					    }
					    room_file.close();
					    room_file.open(Room_id,ios::out|ios::app);
						if(!room_file.is_open())
						{
							cout<<"Error opening file."<<endl;
							return;
						}
						else
						{ 
							if(count < max_occupancy)   //checking whether room max occupancy is reached
							{
							    room_file<<Patient_id<<"\n"<<time()<<"\n"<<date()<<endl;
							    cout<<"\t\tRoom Alloted successfully ."<<endl;
							}
							else
							{
								cout<<"\t\tThe room is already full choose another room"<<endl;
								goto start;
							}
			    	    }
						room_file.close();
					break;
					
					case '2':
			    		cout<<"\n\t\tDouble bed contaiing rooms are listed below."<<endl;
			    		file.open("2bedroom.txt",ios::in);
			    		if(!file.is_open())
			    		{
			    			cout<<"\t\tError accessing Room data due to file not opening."<<endl;
			    		    return;
						}
						else 
						{
							while(file>>Room_id)
							{
								cout<<Room_id<<endl;
							}
						}
						file.close();
						start2:                                    //start2 point declared
						cout<<"\t\tSelect the Room id from above and enter below.";
						cin>>Room_id;
						room_file.open(Room_id,ios::in);
						if(!room_file.is_open())
						{
							cout<<"\t\tError opening file."<<endl;
							return;
						}
						else
						{ 
						    
							room_file>>max_occupancy;
							while(room_file>>Pat_id)
							{
								room_file.ignore();
								getline(room_file,_time);
								getline(room_file,_date);
								count++;          
							}
					    }
					    room_file.close();
					    room_file.open(Room_id,ios::out|ios::app);
						if(!room_file.is_open())
						{
							cout<<"\t\tError opening file."<<endl;
							return;
						}
						else
						{ 
							if(count < max_occupancy)   //checking whether room max occupancy is reached
							{
							    room_file<<Patient_id<<"\n"<<time()<<"\n"<<date()<<endl;
							    cout<<"\t\tRoom Alloted successfully ."<<endl;
							}
							else
							{
								cout<<"\t\tThe room is already full choose another room"<<endl;
								goto start2;
							}
			    	    }
						room_file.close();
						break; 
						
						case '3':
			    	
			    		cout<<"\n\t\tTriple bed contaiing rooms are listed below."<<endl;
			    		file.open("3bedroom.txt",ios::in);
			    		if(!file.is_open())
			    		{
			    			cout<<"Error accessing Room data due to file not opening."<<endl;
			    		    return;
						}
						else 
						{
							while(file>>Room_id)
							{
								cout<<Room_id<<endl;
							}
						}
						file.close();
						start3:                                    //start point declared
						cout<<"\n\t\tSelect the Room id from above and enter below.";
						cin>>Room_id;
					    room_file.open(Room_id,ios::in);
						if(!room_file.is_open())
						{
							cout<<"Error opening file."<<endl;
							return;
						}
						else
						{ 
						    
							room_file>>max_occupancy;
							while(room_file>>Pat_id)
							{
								room_file.ignore();
								getline(room_file,_time);
								getline(room_file,_date);
								count++;          
							}
					    }
					    room_file.close();
					    room_file.open(Room_id,ios::out|ios::app);
						if(!room_file.is_open())
						{
							cout<<"\t\tError opening file."<<endl;
							return;
						}
						else
						{ 
							if(count < max_occupancy)   //checking whether room max occupancy is reached
							{
							    room_file<<Patient_id<<"\n"<<time()<<"\n"<<date()<<endl;
							    cout<<"\t\tRoom Alloted successfully ."<<endl;
							}
							else
							{
								cout<<"\t\tThe room is already full choose another room"<<endl;
								goto start3;
							}
			    	    }
						room_file.close();
					    
					break;
					
					default:
						cout<<"\t\tEnter a valid choice .";
						goto pointzero;
				}
			
		        cout << "\tCurrent  date is : " << date();
		        cout << "\n\tCurrent Time is : " << time();   

					ifile.open("indoor.txt",ios::out|ios::app);
					ifile << " " << firstName << "\n";
				    ifile << " " << lastName << "\n";
				    ifile << " " << Patient_id << "\n";
				    ifile << " " << age << "\n";
				    ifile << " " << phoneNumber << "\n";
				    ifile << " " << cnic << "\n";
				    ifile << " " << BLOODGROUPS[j - 1] << "\n";
				    ifile << " " << diagnosis << "\n";
				    ifile << " " << Room_id <<"\n";
				    ifile << " " << date() << "\n";
				    ifile << " " << time() << "\n";
				    ifile.close();
				break;
				default:
					cout<<"\n\t\tEnter a valid choice ."<<endl;
					Sleep(2000);
					goto i;
					
				
			    
			}
			return;
		}
		
		void searchMenu() 
		{
			//creating a search menu giving choice to search patients from indoor and outdoor file
		system("cls");
        char choice;
        cout << "\n";
		cout << "\n\t\t *************************************************************************" << endl;
		cout << "\t\t ||\t\t\t       Search Menu"
		     << "\t\t\t        || " << endl;
		cout << "\t\t ||_____________________________________________________________________||" << endl;
		cout << "\t\t ||                                                                     ||" << endl;
		cout << "\t\t || 1. Search for Outdoor Patients                                      ||" << endl;
		cout << "\t\t || 2. Search for Indoor Patients                                       ||" << endl;
		cout << "\t\t ||                                                                     ||" << endl;
		cout << "\t\t *************************************************************************" << endl;
		cout << "\n";
		cout << "Enter your choice: ";

         choice = getch();
        switch (choice) 
		{
            case '1':
                searchoutdoorpatientdata();
                break;
            case '2':
                searchindoorpatientdata();
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }

    void searchindoorpatientdata() 
	{
  	    system("cls");
	    int search_id;
	    bool found = false;
	    cout << "\tEnter the ID of the indoor patient you want to search: ";
	    cin >> search_id;
	
	    ifstream file("indoor.txt");
	
	    if (!file.is_open()) {
	        cout << "\tError opening file." << endl;
	        return;
	    }
	
	    while (file >> firstName >> lastName >> Patient_id >> age >> phoneNumber >> cnic) {
	        file.ignore();
	        getline(file, bloodGroup);
	        getline(file, diagnosis);
	        file>>roomID;
	        file.ignore();
	        getline(file, _date);
	        getline(file, _time);
	
	        if (search_id == Patient_id) {
	            cout << "\n";
	            cout << "\n\t\t *************************************************************************" << endl;
	            cout << "\t\t ||\t               Data of Indoor Patient    "
	                 << "\t\t        || " << endl;
	            cout << "\t\t ||_____________________________________________________________________||" << endl;
	            cout << "\t\t ||                                                                     ||" << endl;
	            cout << "\t\t || Patient First Name       : " << setw(25) << left << firstName << "\t\t||" << endl;
	            cout << "\t\t || Patient Last Name        : " << setw(25) << left << lastName << "\t\t||" << endl;
	            cout << "\t\t || Patient Id               : " << setw(25) << left << Patient_id << "\t\t||" << endl;
				cout << "\t\t || Patient Age              : " << setw(25) << left << age << "\t\t||" << endl;
	            cout << "\t\t || Patient Phone Number     : " << setw(25) << left << phoneNumber << "\t\t||" << endl;
	            cout << "\t\t || Patient Cnic             : " << setw(25) << left << cnic << "\t\t||" << endl;
	            cout << "\t\t || Patient BloodGroup       : " << setw(25) << left << bloodGroup << "\t\t||" << endl;
	            cout << "\t\t || Patient Diagnosis        : " << setw(25) << left << diagnosis << "\t\t||" << endl;
	            cout << "\t\t || Patient Alloted Room     : " << setw(25) << left << roomID << "\t\t||" << endl;
	            cout << "\t\t || Date                     : " << setw(25) << left << _date << "\t\t||" << endl;
	            cout << "\t\t || Time                     : " << setw(25) << left << _time << "\t\t||" << endl;
				cout << "\t\t ||                                                                     ||";
	            cout << "\n\t\t *************************************************************************" << endl;
	            cout << "\n";
	            found = true;
	            break;
	        }
	    }
	
	    file.close();
	
	    if (found==false) 
		{
	    	
	        cout << "\tThere is no data of any indoor patient with this ID." << endl;
	    }
	    
	}
	
	//used in validation in billing function returns room id by searching the file through the id provided 
	string searchindoorpatientdata(int search_id) 
	{
	   
	    bool found = false;
	    
	
	    ifstream file("indoor.txt");
	
	    if (!file.is_open()) {
	        cout << "\tError opening file." << endl;
	        
	    }
	    string roomid;
	    while (file >> firstName >> lastName >> Patient_id >> age >> phoneNumber >> cnic)
		 {
	        file.ignore();
	        getline(file, bloodGroup);
	        getline(file, diagnosis);
	        file>>roomid;
	        file.ignore();
	        getline(file, _date);
	        getline(file, _time);
	        
	        if(search_id==Patient_id)
	        {
	            found = true;
	            break;
	        }
	    }
	
	    file.close();
	
	    if (found==false) 
		{
	        cout << "\tThere is no data of any indoor patient with this ID." << endl;
	        return 0;
	    }
	    else
		{
	    	return roomid;
		}
	    
	}


    void searchoutdoorpatientdata() 
	{
	  	system("cls");
	    int search_id;
	    bool found = false;
	    cout << "\tEnter the ID of the outdoor patient you want to search: ";
	    cin >> search_id;
	
	    ifstream file("outdoor.txt");
	
	    if (!file.is_open()) {
	        cout << "\tError opening file." << endl;
	        return;
	    }
	
	    while (file >> firstName >> lastName >> Patient_id >> age >> phoneNumber >> cnic) {
	        file.ignore();
	        getline(file, bloodGroup);
	        getline(file, diagnosis);
	        getline(file, doctor_reffered);
	        getline(file, _time);
			getline(file, _date);
			file >> doctor_fee;
	
	        if (search_id == Patient_id) {
	            cout << "\n";
	            cout << "\n\t\t *************************************************************************" << endl;
	            cout << "\t\t ||\t               Data of Outdoor Patient    "
	                 << "\t\t        || " << endl;
	            cout << "\t\t ||_____________________________________________________________________||" << endl;
	            cout << "\t\t ||                                                                     ||" << endl;
	            cout << "\t\t || Patient First Name       : " << setw(25) << left << firstName << "\t\t||" << endl;
				cout << "\t\t || Patient Last Name        : " << setw(25) << left << lastName << "\t\t||" << endl;
	            cout << "\t\t || Patient Id               : " << setw(25) << left << Patient_id << "\t\t||" << endl;
	            cout << "\t\t || Patient Age              : " << setw(25) << left << age << "\t\t||" << endl;
	            cout << "\t\t || Patient Phone Number     : " << setw(25) << left << phoneNumber << "\t\t||" << endl;
	            cout << "\t\t || Patient Cnic             : " << setw(25) << left << cnic << "\t\t||" << endl;
	            cout << "\t\t || Patient Bloodgrouo       : " << setw(25) << left << bloodGroup << "\t\t||" << endl;
	            cout << "\t\t || Patient Diagnosis        : " << setw(25) << left << diagnosis << "\t\t||" << endl;
	            cout << "\t\t || Patient reffered doc     : " << setw(25) << left << doctor_reffered << "\t\t||" << endl;
	            cout << "\t\t || Visit date               : " << setw(25) << left << _date << "\t\t||" << endl;
	            cout << "\t\t || Visit Time               : " << setw(25) << left << _time << "\t\t||" << endl;
	            cout << "\t\t || Doctor fee               : " << setw(25) << left << doctor_fee << "\t\t||" << endl;
				cout << "\t\t ||                                                                     ||";
	            cout << "\n\t\t *************************************************************************" << endl;
	            cout << "\n";
	            found = true;
	            break;
	        }
	    }
	
	    file.close();
	
	    if (found==false) 
		{
	        cout << "\tThere is no data of any outdoor patient with this ID." << endl;
	    }
	}

    
    
    void UpdateMenu() 
	{
    
        char choice;
        cout << "\n";
		cout << "\n\t\t *************************************************************************" << endl;
		cout << "\t\t ||\t\t\t       Search Menu"
		     << "\t\t\t        || " << endl;
		cout << "\t\t ||_____________________________________________________________________||" << endl;
		cout << "\t\t ||                                                                     ||" << endl;
		cout << "\t\t || 1. Update for Outdoor Patients                                      ||" << endl;
		cout << "\t\t || 2. Update for Indoor Patients                                       ||" << endl;
		cout << "\t\t ||                                                                     ||" << endl;
		cout << "\t\t *************************************************************************" << endl;
		cout << "\n";
		cout << "Enter your choice: ";	

        choice = getch();
        
        switch (choice) 
		{
            case '1':
                outdoorUpdatePatient();
                break;
            case '2':
                 indoorUpdatePatient(); 
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }
    
    

	void outdoorUpdatePatient()
	 {
	 	system("cls");
	    int temp_Id;
	    cout << "Enter the Patient_id of the patient you want to update: ";
	    cin >> temp_Id;
	
	    fstream file, tempFile;
	    file.open("outdoor.txt", ios::in);
	    tempFile.open("temp.txt", ios::out);
	
	    if (!file.is_open() || !tempFile.is_open()) {
	        cout << "Error opening file!" << endl;
	        return;
	    }
	
	    bool found = false;
	    while (file >> firstName >> lastName >> Patient_id >> age >> phoneNumber >> cnic) 
		{
	        file.ignore();
	        getline(file, bloodGroup);
	        getline(file, diagnosis);
	        getline(file, doctor_reffered);
	        file.ignore();
	        getline(file, _date);
	        getline(file, _time);
	        file >> doctor_fee;
	        if (Patient_id == temp_Id) 
			{
	            found = true;
	            cout << "\n\tPatient CNIC found. Update the information" << endl;
	            cout << "\n\t======================================" << endl;
			    cout << "\t|      Patient Information Update    |" << endl;
			    cout << "\t======================================" << endl;
			    cout << "\t| Patient CNIC found.                |" << endl;
			    cout << "\t| Update the information             |" << endl;
			    cout << "\t======================================" << endl;
			    cout << "\t| 1 --> Diagnosis                    |" << endl;
			    cout << "\t| 2 --> Phone Number                 |" << endl;
			    cout << "\t| 3 --> Doctor Referred              |" << endl;
			    cout << "\t| 4 --> Time                         |" << endl;
			    cout << "\t======================================" << endl;
			    cout << "\t| Enter your choice:                 |" << endl;
			    cout << "\t======================================" << endl;
	            char updateChoice;
	            updateChoice = getch();
	
	            system("CLS");
	            switch (updateChoice)
				 {
	                case '1':
	                    cout << "\tEnter the new Diagnosis: ";
	                    cin.ignore();
	                    getline(cin, diagnosis);
	                    break;
	                case '2':
	                    cout << "\tEnter Patient's new Phone number: ";
	                    cin >> phoneNumber;
	                    break;
	                case '3':
	                    cout << "\tEnter new Doctor Referred: ";
	                    cin.ignore();
	                    getline(cin, doctor_reffered);
	                    break;
	                case '4':
	                    cout << "\tEnter new Date: ";
	                    getline(cin, _date);
	                    cout << "\tEnter new Time: ";
	                    getline(cin, _time);
	                    break;
	                default:
	                    cout << "\n\tInvalid Input. No such update of data available." << endl;
	            }
	
	            tempFile << firstName << "\n " << lastName << "\n " << Patient_id << "\n " << age << "\n" << phoneNumber << "\n" 
	                     << cnic << "\n" << bloodGroup << "\n" << diagnosis << "\n" << doctor_reffered 
	                     << "\n" << _date << "\n" << _time << endl<<doctor_fee<<endl;;
	        }
			else
			 {
	            tempFile << firstName << "\n" << lastName << "\n" << Patient_id << "\n " << age << "\n" << phoneNumber << "\n" 
	                     << cnic << "\n" << bloodGroup << "\n" << diagnosis << "\n" << doctor_reffered 
	                     << "\n" << _date << "\n" << _time << endl<<doctor_fee<<endl;
	        }
	    }
	
	    file.close();
	    tempFile.close();
	
	    remove("outdoor.txt");
	    rename("temp.txt", "outdoor.txt");
	
	    if (found==true) {
	        cout << "\tData Updated Successfully." << endl;
	    } 
		else
		 {
	        cout << "\tPatient CNIC not found." << endl;
	    }
	}
	
	void indoorUpdatePatient() 
	{
		system("cls");
	    int temp_Id;
	    cout << "Enter the Patient_id of the patient you want to update: ";
	    cin >> temp_Id;
	
	    fstream file, tempFile;
	    file.open("indoor.txt", ios::in);
	    tempFile.open("temp.txt", ios::out);
	
	    if (!file.is_open() || !tempFile.is_open()) {
	        cout << "Error opening file!" << endl;
	        return;
	    }
	
	    bool found = false;
	    while (file >> firstName >> lastName >> Patient_id >> age >> phoneNumber >> cnic) {
	        file.ignore();
	        getline(file, bloodGroup);
	        getline(file, diagnosis);
	        file>>roomID;
	        file.ignore();
	        getline(file,_date);
	        getline(file,_time);
	
	        if (Patient_id == temp_Id) 
			{
	            found = true;
	            cout << "\n\t===================================================" << endl;
			    cout << "\t|          Patient Information Update             |" << endl;
			    cout << "\t===================================================" << endl;
			    cout << "\t| Patient CNIC found. Update the information      |" << endl;
			    cout << "\t| What do you want to update?                    |" << endl;
			    cout << "\t| 1. Diagnosis                                    |" << endl;
			    cout << "\t| 2. Phone Number                                 |" << endl;
			    cout << "\t| 3. Time                                         |" << endl;
			    cout << "\t| Enter your choice:                              |" << endl;
			    cout << "\t===================================================" << endl;
	            char updateChoice;
	            updateChoice = getch();
	
	            system("CLS");
	            switch (updateChoice) 
				{
	                case '1':
	                    cout << "\tEnter the new Ddiagnosis: ";
	                    cin.ignore();
	                    getline(cin, diagnosis);
	                    break;
	                case '2':
	                    cout << "\tEnter Patient's new Phone number: ";
	                    cin >> phoneNumber;
	                    break;
	                case '3':
	                    cout << "\tEnter new Date format(Jun  4 2024): ";
	                    getline(cin, _date);
	                    cout << "\tEnter new Time format(10:48:24): ";
	                    getline(cin, _time);
	                    break;
	                default:
	                    cout << "\n\tInvalid Input. No such update of data available." << endl;
	            }
	
	            tempFile << firstName << "\n" << lastName << "\n" << Patient_id << "\n "  << age << "\n" << phoneNumber << "\n" 
	                     << cnic << "\n" << bloodGroup << "\n" << diagnosis << "\n" << roomID 
	                     << "\n" << _date<< "\n" << _time << endl;
	        } 
			else 
			{
	            tempFile << firstName << "\n" << lastName << "\n" << Patient_id << "\n "  << age << "\n" << phoneNumber << "\n" 
	                     << cnic << "\n" << bloodGroup << "\n" << diagnosis << "\n" << roomID 
	                      << "\n" << _date<< "\n" << _time << endl;
	        }
	    }
	
	    file.close();
	    tempFile.close();
	
	    remove("indoor.txt");
	    rename("temp.txt", "indoor.txt");
	
	    if (found==true) 
		{
	        cout << "\tData Updated Successfully." << endl;
	    }
		else {
	        cout << "\tPatient Id not found." << endl;
	    }
	}

     
	 
	void deleteMenu() 
	{
		//creating a delete menu to give a choice wheter to delete from indoor or outdoor
		system("cls");
	    char choice;
	    cout << "\n";
		cout << "\n\t\t *************************************************************************" << endl;
		cout << "\t\t ||\t\t\t       Delete Menu"
		     << "\t\t\t        || " << endl;
		cout << "\t\t ||_____________________________________________________________________||" << endl;
		cout << "\t\t ||                                                                     ||" << endl;
		cout << "\t\t || 1. Delete Outdoor Patient                                           ||" << endl;
		cout << "\t\t || 2. Delete Indoor Patient                                            ||" << endl;
		cout << "\t\t ||                                                                     ||" << endl;
		cout << "\t\t *************************************************************************" << endl;
		cout << "\n";
		cout << "Enter your choice: ";

	    choice=getch();
	    switch (choice) 
		{
	        case '1':
	            outdoorDeletePatient();
	            break;
	        case '2':
	            indoorDeletePatient();
	            break;
	        default:
	            cout << "Invalid choice!" << endl;
	            break;
    }
  }

	void outdoorDeletePatient() 
	{
		system("cls");
	    int tempId;
	    cout << "Enter the Patient_id of the patient you want to delete: ";
	    cin >> tempId;
	
	    ifstream inFile("outdoor.txt");
	    ofstream tempFile("temp.txt");
	
	    if (!inFile.is_open() || !tempFile.is_open()) {
	        cout << "Error opening file!" << endl;
	        return;
	    }
	
	    bool found = false;
	    while (inFile >> firstName >> lastName >> Patient_id >> age >> phoneNumber >> cnic) {
	        inFile.ignore();
	        getline(inFile, bloodGroup);
	        getline(inFile, diagnosis);
	        getline(inFile, doctor_reffered);
	        getline(inFile,_date);
			getline(inFile, _time);
	        inFile >> doctor_fee;
	        if (Patient_id != tempId)
			 {
	        	tempFile << firstName << "\n" << lastName << "\n" << Patient_id << "\n "<< age << "\n" << phoneNumber << "\n" 
		                 << cnic << "\n" << bloodGroup << "\n" << diagnosis << "\n" << doctor_reffered 
		                 << "\n" << _date<< "\n" << _time << "\n"<<doctor_fee<<endl;
	            
	        }
	        else
	        {
	        	found = true;
			}
	        
	    }
	
	
	    inFile.close();
	    tempFile.close();
	
	    remove("outdoor.txt");
	    rename("temp.txt", "outdoor.txt");
	
	    if (found) 
		{
	        cout << "Patient deleted successfully." << endl;
	    } else 
		{
	        cout << "Patient with this Id " << tempId << " not found." << endl;
	    }
	}
	
	void indoorDeletePatient() 
	{
		system("cls");
	    int temp_Id;
	    cout << "Enter the Patient_id of the patient you want to delete: ";
	    cin >> temp_Id;
	
	    ifstream inFile("indoor.txt");
	    ofstream tempFile("temp.txt");
	
	    if (!inFile.is_open() || !tempFile.is_open()) 
		{
	        cout << "Error opening file!" << endl;
	        return;
	    }
	
	    bool found = false;
	    while (inFile >> firstName >> lastName >>Patient_id >> age >> phoneNumber >> cnic) 
		{
	        inFile.ignore();
	        getline(inFile, bloodGroup);
	        getline(inFile, diagnosis);
	        inFile>>roomID;
	        getline(inFile, _date);
	        getline(inFile, _time);
	
	        if (Patient_id != temp_Id) 
			{
	             tempFile << firstName << "\n" << lastName << "\n" << Patient_id << "\n " << age << "\n" << phoneNumber << "\n" 
		                 << cnic << "\n" << bloodGroup << "\n" << diagnosis << "\n" << roomID 
		                 << "\n" << _date<< "\n" << _time << "\n";
	        }
	        else
			{
	        	found=true;
			}
	        
	    }
	
	    inFile.close();
	    tempFile.close();
	
	    remove("indoor.txt");
	    rename("temp.txt", "indoor.txt");
	
	    if (found==true) 
		{
	        cout << "Patient deleted successfully." << endl;
	    }
		 else
		  {
	        cout << "Patient with Patient Id " << temp_Id << " not found." << endl;
	    }
	    
	    bool foundRoom =false;
	    fstream Room("temp.txt",ios::out);
	    string roomFileName = to_string(roomID) ;
	    fstream file(roomFileName,ios::in);

		   
		
		    if(!file.is_open())
		    {
		    	cout<<"\n\t\tError opening file ."<<endl;
			}
		    int room_occupant;
		    file>>room_occupant;
		    Room<<room_occupant<<endl;
		    while(file>>Patient_id)
		    {
		    	file.ignore();
		    	getline(file, _time);
		    	getline(file, _date);
		    	
			    	if (temp_Id != Patient_id) 
					{
			           Room << Patient_id<< endl;
			           Room << _time << endl;
			           Room << _date << endl;
			        }
					 else 
					{
			            foundRoom = true;
			        }
						
				
			}
			    file.close();
			    Room.close();
				remove(roomFileName.c_str());
				rename("temp.txt",roomFileName.c_str());
			
		   if (foundRoom == false)
			 {
			 
		        cout << "Patient's room record not found!" << endl;
		    }
		   
		
		  
	}

	
};


class Doctor
{
	private:
	    string doctorName;
		string specialization;
		string docworkdays;
		string docworktimings;
	    int doctorId;
		int doctorfee;
	    long long int doctorPhoneNumber;
	public:
		string getdoctorName()
		{
			return doctorName;
		}
		void addDoctorsdata();
		void showDoctors();
		void removeDoctor();
	    void updateDoctor();
	    void searchDoctor();
	     void doctorMenu() 
		 {
		 	system("CLS");
	        while (true) 
			{
	            char choice;
	            cout << "\n\t\t========================================" << endl;
			    cout << "\t\t|       Staff Management System        |" << endl;
			    cout << "\t\t========================================" << endl;
			    cout << "\t\t| 1. Add Doctors                       |" << endl;
			    cout << "\t\t| 2. Update Doctors                    |" << endl;
			    cout << "\t\t| 3. Search Doctors                    |" << endl;
			    cout << "\t\t| 4. Remove Doctors                    |" << endl;
			    cout << "\t\t| 5. Update Doctors                    |" << endl;
			    cout << "\t\t| 6. Exit                              |" << endl;
			    cout << "\t\t========================================" << endl;
			    cout << "\t\t| Enter your choice: ";
    
	            choice = _getch();  // Get single character input
	            
	            switch (choice) {
	                case '1':
	                	system("CLS");
	                    addDoctorsdata();
	                    break;
	                case '2':
	                	system("CLS");
	                    updateDoctor();
	                    break;
	                 case '3':
	                	system("CLS");
	                    searchDoctor();
	                    break;
	                case '4':
	                	system("CLS");
	                    removeDoctor();
	                    break;
	                case '5':
	                	system("CLS");
	                    updateDoctor();
	                    break;
	                case '6':
	                    return;
	                    break;
	                default:
	                    cout << "\n\t Invalid choice. Please try again.";
	                    Sleep(2000);
	                    break;
	            }
	        }
	    }
	    
	    bool isdoctoridvalid(int id)
	    {
	    	int d_Id;
		    ifstream file;
		    file.open("doctors.txt");
		
		    if (!file.is_open())
		    {
		        cout << "\tError opening file." << endl;
		        return false;
		    }
		
		    getline(file, doctorName);
		    file >> d_Id >> specialization >> doctorPhoneNumber;
		    file.ignore();
		    getline(file, docworkdays);
		    getline(file, docworktimings);
		
		    while (!file.eof())
		    {
		        if(d_Id == id)
		        {
		        	return true;
				}
		
		        getline(file, doctorName);
		        file >> d_Id >> specialization >> doctorPhoneNumber;
		        file.ignore();
		        getline(file, docworkdays);
		        getline(file, docworktimings);
		        
		    }
		    cout << "\n";
		
		    file.close();
		
		    return false;
		}
	        
	   void Doctorlogin()
	    {
	    	
	    	start:
	        system("CLS");
	        int doctorId, P_id_;
	        string username_1, pass_1, password, username;
	        bool found = false; // bool found used to check conditions
	
	        cout << "\n\n\t\t========================================" << endl;
		    cout << "\t\t|       Hospital Management System     |" << endl;
		    cout << "\t\t========================================" << endl;
		    cout << "\t\t| Please Login by adding Your:         |" << endl;
		    cout << "\t\t| 1. Doctor ID                         |" << endl;
		    cout << "\t\t| 2. Username                          |" << endl;
		    cout << "\t\t| 3. Password                          |" << endl;
		    cout << "\t\t========================================" << endl;
	        cout << "\n\n\t\tEnter DoctorId: ";
	        cin >> doctorId;
	        cout << "\n\n\t\tEnter Username: ";
	        cin.ignore();
	        getline(cin, username_1);
	        cout << "\n\n\t\tPassword: ";
	        
	        char pass;
	        pass_1.clear();
	        while ((pass = _getch()) != '\r') {
	            if (pass >= 32 && pass <= 126) {
	                cout << '*';
	                pass_1.push_back(pass);
	            } else if (pass == 8 && pass_1.length() > 0) {
	                pass_1.pop_back();
	                cout << "\b \b";
	            }
	        }
	        cout << "\n";
	
	        ifstream file("doctorlogins.txt");
	        if (!file.is_open())
			{
	            cout << "\t Error opening file ";
	            Sleep(3000);
	            return;
	        }
	
	        int doc_id;
	        while (file >> doc_id) 
			{
	            file.ignore();
	            getline(file, username);
	            getline(file, password);
	            if (doctorId == doc_id && username == username_1 && password == pass_1) 
				{
	                found = true;
	                break;
	            }
	        }
	        file.close();
	
	        if (found) 
			{
				Patient p;
	           	string R_id;
	            system("cls");
	            Patient P;
	            while (true)
				 {
				 	p:
	                char z;
	                fstream ifile;
	
	                cout << "\n";
	                cout << "\n\t\t *************************************************************************" << endl;
	                cout << "\t\t ||\t\t\t       Patient Management"
	                     << "\t\t        || " << endl;
	                cout << "\t\t ||_____________________________________________________________________||" << endl;
	                cout << "\t\t ||                                                                     ||" << endl;
	                cout << "\t\t || 1. Enter patient ID you are visiting                                ||" << endl;
	                cout << "\t\t || 2. Check patient details                                            ||" << endl;
	                cout << "\t\t ||                                                                     ||" << endl;
	                cout << "\t\t || 3. Logout                                                           ||" << endl;
	                cout << "\t\t ||                                                                     ||" << endl;
	                cout << "\t\t *************************************************************************" << endl;
	                cout << "\n";
	
	                z = getch();
	                switch (z)
					 {
	                    case '1':
	                    	
	                        cout << "\n\t\tEnter Patient ID you are visiting: ";
	                        cin >> P_id_;
	                        if(!p.isidvalid(P_id_))
							{
								cout<<"\n\t\tThe patient against this Id "<<P_id_<<" is not present ."<<endl;
								Sleep(5000);
								system("cls");
								goto p;
								
							    
							}
							else 
							{ 
						    //if patient is found searching wheter he is admitted in a room or not
								R_id = p.searchindoorpatientdata(P_id_);
								if(!p.is_present_in_room(R_id,P_id_))
								{
									cout<<"\n\t\tThe patient against this Id "<<P_id_<<" is not present or either discharged."<<endl;
									Sleep(5000);
									system("cls");
									goto p;
								}
								else
								{
									cout<<"\t\tThe patient is present in Room "<<R_id<<endl;
								}
						    }
						    
	                        cout << "\n\t\tEnter your Doctor Id: ";
	                        cin >> doctorId;
	                        ifile.open("visits.txt", ios::out | ios::app);
	                        ifile << P_id_ << endl;
	                        ifile << doctorId << endl;
	                        ifile.close();
	                        system("cls");
	                        break;
	                    case '2':
	                        P.searchMenu();
	                        break;
	                    case '3':
	                        cout << "Logging out ";
	                        for (int i = 0; i < 5; i++) 
							{
								cout<<".";
	                            Sleep(1000);
	                        }
	                        return;  // Log out and end the function
	                        break;
	                    default:
	                        cout << "Enter a valid choice....";
	                        Sleep(2000);
	                        break;
	                }
	            }
	        } 
			else 
			{
	            cout << "\n\n\t\tNo account exists against these credentials " << endl;
	            Sleep(3000);
	            goto start;
	        }
	    
	}
};

class Login
{

	protected:
		string username;
		string password;
		int security_num;
	public:
		
		bool authenticateUsername(string user)
		{
			return(username == user );
		}
		
		bool authenticate(string pass)
		{
			return(password == pass);
		}
		
		void resetpassword(string opass)
		{
			password = opass;
		}
		
		bool verifySecurityNumber(int answer) 
		{
        	return security_num == answer;
        }
		
};

class Roomadmin : public Login
{
	private:
		string room_id;
		int room_capacity;
		double onebed_roomcharge;
		double twobed_roomcharge;
		double threebed_roomcharge;
		int room_occupants;
		
	public:
		Roomadmin()
		{
			onebed_roomcharge =15000;
			twobed_roomcharge =11000;
			threebed_roomcharge =7500;
			writeRoomChargesToFile();
			loadRoomCharges();
		}
		
		Roomadmin(string u,string p,int num)
		{
			username = u;
			password = p;
			security_num = num;
			onebed_roomcharge =15000;
			twobed_roomcharge =11000;
			threebed_roomcharge =7500;

			loadRoomCharges();
		}
		
		double get_one_bed_room_charges()
		{
			return onebed_roomcharge;
		}
		
		double get_two_bed_room_charges()
		{
			return twobed_roomcharge;
		}
		
		double get_three_bed_room_charges()
		{
			return	threebed_roomcharge;
		}
		
		void roomadminlogin()
		{
				start:
			Roomadmin ad("Rd_Admin","Admin@auhospital123",694422);
			ad.getpassword();
			string username, password;
		    cout << "\n\n\t\t\tAdmin Login " << endl;
		    cout << "\n\n\t\tEnter Username: ";
		    cin.ignore();
		    getline(cin, username);
		    cout << "\n\n\t\tEnter Password: ";
		    char pass;
		    while ((pass = getch()) != '\r') // while loop continues until user press the enter key
		    {
		        if (pass >= 32 && pass <= 126) // Check if pass is printable ASCII character. IF true then print '*'
		        {                              // and adds characters enteres to string password by .push_back
		            cout << '*';
		            password.push_back(pass);
		        }
		        else if (pass == 8 && password.length() > 0) // Check if character entered is backspace ( 8 ASCII value of backspace) and password string is not empty
		        {                                            // IF true then if user enterd backspace then it erases  the last digit
		            password.pop_back();
		            cout << "\b \b"; // Moves the moves the cursor or pointer one position back. It's used to implement a backspace functionality in console-based applications
		        }
		    }
		    cout << "\n";
		    
		    
		    if(!ad.authenticateUsername(username) || !ad.authenticate(password))
		    {
		    	cout<<"Invalid Username or password :"<<endl;
		    	char reset;
		    	cout<<"If you forgot your password reset it by pressing (y or Y)";
		    	cin>>reset;
		    	if(reset == 'y' || reset == 'Y')
		    	{
		    		
		            cout << "\n\t\tEnter the answer to your security number: ";
		            cin>>security_num;
		            if (ad.verifySecurityNumber(security_num)) 
					{
		                string new_password;
		                cout << "\t\tEnter the new password: ";
		                cin >> new_password;
		                ad.resetpassword(new_password);
		    	     	ad.savepassword();
				        cout<<"\t\tPassword changed successfully "<<endl;
				    	Sleep(2000);
				    	system("cls");
				    	goto start;
				    }
				    else
					{
				    	cout<<"\t\tSecurity num was invalid enter again "<<endl;
				    	Sleep(2000);
				    	system("cls");
				    	goto start;
				    	
					}
			    }
			    else
				{
						cout<<"Going back to login enter username and password again";
						for (int i=0;i<5;i++)
						{
							cout<<".";
							Sleep(1000);
						}
				    	system("cls");
				    	goto start;
			    }
		    	
				}
			
			
		
			else
			{
				system("cls");
				cout<<"\n\t\t\t\tLOGIN SUCCESSFULL!!!!!!"<<endl;
				cout<<"\n\n\t\t\tLoading menu"<<endl;
				for (int i=0;i<5;i++)
				{
					cout<<".";
					Sleep(1000);
				}
				system("cls");
				while(true)
				{
					p:       //point p here
					cout << "\n";
					cout << "\n\t\t *************************************************************************" << endl;
					cout << "\t\t ||\t\t       Room Management"
					     << "\t\t\t\t        || " << endl;
					cout << "\t\t ||_____________________________________________________________________||" << endl;
					cout << "\t\t ||                                                                     ||" << endl;
					cout << "\t\t || 1. Add new rooms                : " << setw(30) << left << "" << "\t||" << endl;
					cout << "\t\t || 2. Change room charges          : " << setw(30) << left << "" << "\t||" << endl;
					cout << "\t\t || 3. Check room occupancy         : " << setw(30) << left << "" << "\t||" << endl;
					cout << "\t\t || 4. Logout                       : " << setw(30) << left << "" << "\t||" << endl;
					cout << "\t\t ||                                                                     ||" << endl;
					cout << "\t\t *************************************************************************" << endl;
					cout << "\n";

					char c;
					c = getch();
					switch(c)
					{
						case '1':
							system("cls");
							addrooms();
							break;
						case '2':
							system("cls");
							changeroomcharges();
							break;
						case '3':
							system("cls");
							checkroomoccupants();
							break;
						case '4':
						    system("cls");
						    return;
						     break;
						default:
							cout<<"Enter a valid choice ....";
							Sleep(2000);
							system("cls");
							goto p;
					}
			}
				
			}
		}
	
	
	
	
	
		
		
		void savepassword()
		{
			fstream file;
			file.open("roomadmin.txt",ios::out);
			if(file.is_open())
			{
				file<<password;
			}
			else
			{
				cout<<"Error opening file "<<endl;
			}
			file.close();
			
		}
		
		void getpassword()
		{
			fstream file;
			file.open("roomadmin.txt",ios::in);
			if(file.is_open())
			{
				file>>password;
			}
			else
			{
				cout<<"Error opening file "<<endl;
			}
			file.close();
		}
		
	    void loadRoomCharges() 
		{
	        fstream file("roomcharges.txt",ios::in);
	        if (file.is_open())
			 {
	            file >> onebed_roomcharge >> twobed_roomcharge >> threebed_roomcharge;
	            file.close();
	        }
			 else 
			{
	            cout << "Error opening file. Using default charges." << endl;
	        }
       }

        void writeRoomChargesToFile() 
		{
	        fstream file("roomcharges.txt",ios::out);
	        if (file.is_open()) 
			{
	            file << onebed_roomcharge << " " << twobed_roomcharge << " " << threebed_roomcharge;
	            file.close();
	        } 
			else
			{
	            cout << "Error opening file. Charges not updated." << endl;
	        }
        }

		 
	    void changeroomcharges() 
		{
	        cout << "Enter new charges for one-bed room: ";
	        cin >> onebed_roomcharge;
	
	        cout << "Enter new charges for two-bed room: ";
	        cin >> twobed_roomcharge;
	
	        cout << "Enter new charges for three-bed room: ";
	        cin >> threebed_roomcharge;
	
	        writeRoomChargesToFile(); // Write new charges to file
	        cout<<"Charges updated successfully."<<endl;
	    }
	    
	bool checkRoomExists(const string& filename, const string& room_id) 
	{
	    ifstream file(filename);
	    if (!file.is_open()) 
		{
	        cout << "Error opening file: " << filename << endl;
	        return false;
	    }
	    string id;
	    while (file >> id) 
		{
	        if (id == room_id) 
			{
	            return true;
	        }
	    }
	    return false;
    }

    void addrooms() 
	{
	    int room_capacity;
	    string room_id;
	    cout << "Enter the new room capacity (1-3): ";
	    cin >> room_capacity;
	    while (room_capacity <= 0 || room_capacity > 3)  
		{
	        cout << "Enter a room with capacity 1-3: ";
	        cin >> room_capacity;
	    }
	    
	    cout << "Enter the room ID: ";
	    cin >> room_id;
	
	    string filename;
	    if (room_capacity == 1) 
		{
	        filename = "singlebed.txt";
	    } 
		else if (room_capacity == 2) 
		{
	        filename = "2bedroom.txt";
	    } 
		else if (room_capacity == 3) 
		{
	        filename = "3bedroom.txt";
	    }
	
	    if (checkRoomExists(filename, room_id)) 
		{
	        cout << "Room ID already exists in " << filename << ". Please enter a unique room ID." << endl;
	        return;
	    }
	
	    fstream room_file(room_id, ios::out);
	    if (!room_file.is_open()) 
		{
	        cout << "Error creating room file." << endl;
	        return;
	    }
		else 
		{
	        room_file << room_capacity << endl;
	        cout << "New room added successfully." << endl;
	    }
	    room_file.close();
	
	    fstream file;
	    file.open(filename, ios::out | ios::app);
	    if (!file.is_open()) 
		{
	        cout << "Error opening file: " << filename << endl;
	        return;
	    }
		 else 
		 {
	        file << room_id << endl;
	    }
	    file.close();
	}
	 	
		void checkroomoccupants()
		{
			string details;
			cout<<"\n\t\tEnter the room id whose occupancy you want to check .";
			cin>>room_id;
			fstream file;
			file.open(room_id,ios::in|ios::app);
			if(!file.is_open())
			{
				cout<<"Error opening file ."<<endl;
				return;
			}
			file>>room_occupants;
			cout<<"\n\t\tThe room occupancy is :";
			cout<<room_occupants;
			cout<<"\n\t\tThe Patient_id,time and date of patients is listed below :";
			while(getline(file,details))
			{
				cout<<"\n\t\t"<<details<<endl;
			}
			file.close();
		}
		
		
};


class Admin : public Login
{
	public:
		Doctor d;
		Staff s;
		Admin()
		{
			
		}
		
		Admin(string u,string p,int num)
		{
			username = u;
			password = p;
			security_num = num;
		}
		
		
		void retrieveAdminCredentials() 
		{
	        fstream file;
	        file.open("admin.txt", ios::in);
	        if (file.is_open()) 
			{
	            getline(file, username);
	            getline(file, password);
	            file >> security_num;
	            file.close();
	            
	        }
			else 
			{
	            cout << "\n\tError opening file." << endl;
	        }
	    }
	    
		void adminlogin()
		{
				start:
			Admin ad("Admin","Admin@au123",295422);
			ad.retrieveAdminCredentials();
			
			string username, password;
		    cout << "\n\n\t\t\tAdmin Login " << endl;
		    cout << "\n\n\t\tEnter Username: ";
		    cin.ignore();
		    getline(cin, username);
		    cout << "\n\n\t\tEnter Password: ";
		    char pass;
		    while ((pass = getch()) != '\r') // while loop continues until user press the enter key
		    {
		        if (pass >= 32 && pass <= 126) // Check if pass is printable ASCII character. IF true then print '*'
		        {                              // and adds characters enteres to string password by .push_back
		            cout << '*';
		            password.push_back(pass);
		        }
		        else if (pass == 8 && password.length() > 0) // Check if character entered is backspace ( 8 ASCII value of backspace) and password string is not empty
		        {                                            // IF true then if user enterd backspace then it erases  the last digit
		            password.pop_back();
		            cout << "\b \b"; // Moves the moves the cursor or pointer one position back. It's used to implement a backspace functionality in console-based applications
		        }
		    }
		    cout << "\n";
		    
		    
		    if(!ad.authenticateUsername(username) || !ad.authenticate(password))
		    {
		    	cout<<"\n\t\tInvalid Username or password "<<endl;
		    	char reset;
		    	cout<<"\n\t\tIf you forgot your password reset it by pressing (y or Y)";
		    	cin>>reset;
		    	if(reset == 'y' || reset == 'Y')
		    	{
		    		
		            cout << "\n\t\tEnter the answer to your security number: ";
		            cin>>security_num;
		            if (ad.verifySecurityNumber(security_num)) 
					{
		                string new_password;
		                ad.resetAdminCredentials();
				        cout<<"\t\tCredentials changed successfully "<<endl;
				    	Sleep(2000);
				    	system("cls");
				    	goto start;
				    }
				    else
					{
				    	cout<<"\t\tSecurity num was invalid enter again "<<endl;
				    	Sleep(2000);
				    	system("cls");
				    	goto start;
				    	
					}
			}
				else
				{
					cout<<"\t\tGoing back to login enter username and password again";
					for (int i=0;i<5;i++)
					{
						cout<<".";
						Sleep(1000);
					}
			    	system("cls");
			    	goto start;
			    }
			}
			else
			{
				system("cls");
				cout<<"\n\n\t\t\tLOGIN SUCCESSFULL!!!!!!"<<endl;
				cout<<"\n\n\n\t\t\tLoading menu";
				for (int i=0;i<5;i++)
				{
					cout<<".";
					Sleep(1000);
				}
				while(true)
				{
					p:       //point p here
					system("cls");
					cout << "\n\t\t *************************************************************************" << endl;
					cout << "\t\t ||\t\t    Select from the following options"
					     << "\t\t        || " << endl;
					cout << "\t\t ||_____________________________________________________________________||" << endl;
					cout << "\t\t ||                                                                     ||" << endl;
					cout << "\t\t || 1-Make staff login            : " << setw(34) << left << "" << "\t||" << endl;
					cout << "\t\t || 2-Reset staff logins          : " << setw(34) << left << "" << "\t||" << endl;
					cout << "\t\t || 3-Doctors Menu                : " << setw(34) << left << "" << "\t||" << endl;
					cout << "\t\t || 4_Staff Menu                  : " << setw(34) << left << "" << "\t||" << endl;
					cout << "\t\t || 5_Change your credentials     : " << setw(34) << left << "" << "\t||" << endl;
					cout << "\t\t || 6-Logout                      : " << setw(34) << left << "" << "\t||" << endl;
					cout << "\t\t ||                                                                     ||";
					cout << "\n\t\t *************************************************************************" << endl;
					cout << "\n";

					char c;
					c = getch();
				    switch(c)
					{
						case '1':
							createstafflogins();
							break;
						case '2':
							resetStaffCredentials();
							break;
						case '3':
							d.doctorMenu();
							break;
						case '4':
							 s.staffMenu();
							 break;
						case '5':
						     ad.resetAdminCredentials();
						     break;
						case '6':
						     system("cls");
						     return;
						     break;
						default:
							cout<<"Enter a valid choice ....";
							Sleep(2000);
							system("cls");
							goto p;
					}
			}
				
			}
	}
	
	
	
	void resetAdminCredentials() 
	{
	        string new_username, new_password;
	        int new_security_num;
	
	        // Input new username
	        cout << "\n\n\t\tEnter New Username: ";
	        cin.ignore(); // Clear the input buffer
	        getline(cin, new_username);
	        while (new_username.length() <= 6 || new_username.length() >= 20 || !isStrongUsername(new_username)) 
			{
	            if (new_username.length() <= 6) 
				{
	                cout << "\tThe username must consist of more than six characters " << endl;
	            }
	            if (new_username.length() >= 20) 
				{
	                cout << "\tThe username must consist of less than twenty characters " << endl;
	            }
	            if (!isStrongUsername(new_username)) 
				{
	                cout << "\tThe username must consist of at least one uppercase letter, one lowercase letter, and one symbol" << endl;
	            }
	            cout << "\n\n\t\tEnter New Username: ";
	            getline(cin, new_username);
	        }
	
	       
	        cout << "\n\n\t\tEnter New Password: ";
	        new_password.clear();
	        char pass;
	        while ((pass = getch()) != '\r') {
	            if (pass >= 32 && pass <= 126) {
	                cout << '*';
	                new_password.push_back(pass);
	            } else if (pass == 8 && new_password.length() > 0) {
	                new_password.pop_back();
	                cout << "\b \b";
	            }
	        }
	        cout << "\n";
	
	        // Input new security number
	        cout << "\n\n\t\tEnter New Security Number: ";
	        while (!(cin >> new_security_num)) {
	            cout << "Invalid input. Please enter a valid number: ";
	            cin.clear();
	            cin.ignore(numeric_limits<streamsize>::max(), '\n');
	        }
	
	        // Save the new credentials
	        fstream file;
	        file.open("admin.txt", ios::out);
	        if (file.is_open()) 
			{
	            file << new_username << "\n";
	            file << new_password << "\n";
	            file << new_security_num << "\n";
	            file.close();
	            cout << "\n\tAdmin credentials reset successfully!" << endl;
	        } 
			else 
			{
	            cout << "\n\tError opening file." << endl;
	        }
	    }

		
	
		
		
		bool isStrongUsername(string username) 
	    {
		    bool hasUppercase = false;
		    bool hasLowercase = false;
		    bool hasSymbol = false;
		
		    for (char ch : username)  		//for each loop executing on each character of the username.
			{
		        if (isupper(ch))      		//check for uppercase letters
				{
		            hasUppercase = true;
		        } 
				else if (islower(ch))  		//check for lowercase letters
				{
		            hasLowercase = true;
		        } 
				else if (ispunct(ch))   	//check for punctuation(symbol)
				{
		            hasSymbol = true;
		        }
		        if(hasUppercase && hasLowercase && hasSymbol)
		        {
		            return true;
				}
			}
		    return false;
	    }
	    
		void createstafflogins() 
		{
			fstream file;
			int staff_id;
		    cout << "\t\t ____Create Staff login____ " << endl;
		
		    point0:
		    system("CLS");
		    string  staffType;
		    
		
		   
			cout << "\n\t\t *************************************************************************" << endl;
			cout << "\t\t ||\t\t     Hospital Management System"
			     << "\t\t\t\t|| " << endl;
			cout << "\t\t ||_____________________________________________________________________||" << endl;
			cout << "\t\t ||                                                                     ||" << endl;
			cout << "\t\t ||Please SIGN UP by selecting the role and adding required info.       ||" << endl;
			cout << "\t\t ||                                                                     ||" << endl;
			cout << "\t\t || Select Staff Role:                                                  ||" << endl;
			cout << "\t\t ||1. Receptionist                    " << setw(30) << left << "" << "\t||" << endl;
			cout << "\t\t ||2. Nurse                           " << setw(30) << left << "" << "\t||" << endl;
			cout << "\t\t ||3. Doctor                          " << setw(30) << left << "" << "\t||" << endl;
			cout << "\t\t ||                                                                     ||" << endl;
			cout << "\t\t || 	   	Enter your choice (1-3): "   << setw(30) << left << "" << "\t||" << endl;
			cout << "\t\t ||                                                                     ||" << endl;
			cout << "\t\t *************************************************************************" << endl;
			cout << "\n";

		    char choice;
		    choice=getch();
		    switch (choice) 
			{
		        case '1': 
		        p1:                       //point p1 declared here                     
				staffType = "receptionist";
				int receptionist_id,rep_id;
				cout<<"\n\n\t\tEnter the receptionist id : ";
				cin>>receptionist_id;
				file.open("receptionistlogins.txt",ios::in);
				if(!file.is_open())
				{
					cout<<"Error opening file "<<endl;
				}
				else
				{
					while(file>>rep_id)
					{
						file.ignore();
						getline(file,username);
						getline(file,password);
						if(receptionist_id == rep_id)
						{
							cout<<"The login of this id already exsists ."<<endl;
							Sleep(2000);
							system("cls");
							goto p1;
							
						}
				
					}
					
				
				}
				staff_id = receptionist_id;
				file.close();
				
				
				break;
		        case '2': 
		        p2:                          //p2 declared here
				staffType = "nurse"; 
				int nurse_id,nus_id;
				cout<<"\n\n\t\tEnter the receptionist id : ";
				cin>>nurse_id;
				file.open("nurselogins.txt",ios::in);
				if(!file.is_open())
				{
					cout<<"Error opening file "<<endl;
				}
				else
				{
					while(file>>nus_id)
					{
						file.ignore();
						getline(file,username);
						getline(file,password);
						if(nurse_id == nus_id)
						{
							cout<<"The login of this id already exsists ."<<endl;
							Sleep(2000);
							system("cls");
							goto p2;
							
						}
					}
					
		
				}
				staff_id = nurse_id;
				file.close();
			
				
				
				break;
				
		        case '3': 
		        p3:                      //p3 declared here
		        	
				staffType = "doctor"; 
				int doctor_id,doc_id;
				cout<<"Enter the doctor id : ";
				cin>>doctor_id;
				file.open("doctorlogins.txt",ios::in);
				if(!file.is_open())
				{
					cout<<"Error opening file "<<endl;
				}
				else
				{
					while(file>>doc_id)
					{
						file.ignore();
						getline(file,username);
						getline(file,password);
						if(doctor_id == doc_id)
						{
							cout<<"The login of this id already exsists ."<<endl;
							Sleep(2000);
							system("cls");
							goto p3;
							
						}
					}
					staff_id = doctor_id;
					file.close();
					
				}
				
			
				file.close();
				break;
				
		        default: 
		            cout << "\tInvalid choice. Please select a valid role." << endl;
		            Sleep(2000);
		            goto point0;
		    }
		
		    cout << "\t\tEnter Username:  ";
		    cin.ignore();
		    username.clear();
		    getline(cin, username);
		
		    if (username.length() <= 6) 
			{
		        cout << "\tThe username must consist of more than six characters " << endl;
		        Sleep(2000);
		        goto point0;
		    } 
			else if (username.length() >= 20) 
			{
		        cout << "\tThe username must consist of less than twenty characters " << endl;
		        Sleep(2000);
		        goto point0;
		    } 
			if (!isStrongUsername(username)) 
			{
		        cout << "\tThe username must consist of at least one uppercase letter, one lowercase letter, and one symbol" << endl;
		        Sleep(2000);
		        goto point0;
		    }
		
		    cout << "\t\tPassword: ";
		    password.clear();
		    char pass;
		    while ((pass = _getch()) != '\r') 
			{
		        if (pass >= 32 && pass <= 126) 
				{
		            cout << '*';
		            password.push_back(pass);
		        } 
				else if (pass == 8 && password.length() > 0) 
				{
		            password.pop_back();
		            cout << "\b \b";
		        }
		    }
		
		    string filename = staffType + "logins.txt";
		    
		    file.open(filename, ios::out | ios::app);
		    if (!file.is_open()) {
		        cout << "\tError opening file." << endl;
		    } else {
		    	file << staff_id << "\n";
		        file << username << "\n";
		        file << password << "\n";
		        file.close();
		        cout << "\n\tLogin created successfully for " << staffType << "!" << endl;
		    }
		}
		
		void resetStaffCredentials() 
		{
		    fstream file;
		    string staffType;
		    int staff_id;
		
		point0:
		    system("CLS");
		    cout << "\n";
			cout << "\n\t\t *************************************************************************" << endl;
			cout << "\t\t ||\t\t     Hospital Management System"
			     << "\t\t\t\t|| " << endl;
			cout << "\t\t ||_____________________________________________________________________||" << endl;
			cout << "\t\t ||                                                                     ||" << endl;
			cout << "\t\t || Reset Staff Credentials:                                            ||" << endl;
			cout << "\t\t ||                                                                     ||" << endl;
			cout << "\t\t || Select Staff Role:                                                  ||" << endl;
			cout << "\t\t ||1. Receptionist                    " << setw(30) << left << "" << "\t||" << endl;
			cout << "\t\t ||2. Nurse                           " << setw(30) << left << "" << "\t||" << endl;
			cout << "\t\t ||3. Doctor                          " << setw(30) << left << "" << "\t||" << endl;
			cout << "\t\t ||                                                                     ||" << endl;
			cout << "\t\t ||       Enter your choice (1-3)     " << setw(30) << left << "" << "\t||" << endl;
			cout << "\t\t ||                                                                     ||" << endl;
			cout << "\t\t *************************************************************************" << endl;
			cout << "\n";

		    char choice;
		    choice = getch();
		
		    switch (choice)
			 {
		        case '1':
		            staffType = "receptionist";
		            break;
		        case '2':
		            staffType = "nurse";
		            break;
		        case '3':
		            staffType = "doctor";
		            break;
		        default:
		            cout << "\tInvalid choice. Please select a valid role." << endl;
		            Sleep(2000);
		            goto point0;
		    }
		
		    cout << "\n\n\t\tEnter Staff ID: ";
		    cin >> staff_id;
		    cin.ignore(); // Ignore newline character left in the buffer
		
		    string filename = staffType + "logins.txt";
		    fstream tempFile;
		    string line;
		    bool found = false;
		
		    file.open(filename, ios::in);
		    tempFile.open("temp.txt", ios::out);
		    if (!file.is_open() || !tempFile.is_open())
			{
		        cout << "\tError opening file." << endl;
		        return;
		    }
		    int s_id;
		    while (file>>s_id) 
			{
				file.ignore();
				getline(file,username);
				getline(file,password);
		        if (s_id == staff_id) 
				{
		            found = true;
		            cout << "\n\n\t\tEnter New Username: ";
		            getline(cin, username);
		            while (username.length() <= 6 || username.length() >= 20 || !isStrongUsername(username)) 
					{
		                if (username.length() <= 6) 
						{
		                    cout << "\tThe username must consist of more than six characters " << endl;
		                }
						else if (username.length() >= 20) 
						 {
		                    cout << "\tThe username must consist of less than twenty characters " << endl;
		                } 
						if (!isStrongUsername(username)) 
						{
		                    cout << "\tThe username must consist of at least one uppercase letter, one lowercase letter, and one symbol" << endl;
		                }
		                cout << "\n\n\t\tEnter New Username: ";
		                getline(cin, username);
		            }
		
		            cout << "\n\n\t\tEnter New Password: ";
		            password.clear();
		            char pass;
		            while ((pass = _getch()) != '\r') {
		                if (pass >= 32 && pass <= 126) {
		                    cout << '*';
		                    password.push_back(pass);
		                } else if (pass == 8 && password.length() > 0) {
		                    password.pop_back();
		                    cout << "\b \b";
		                }
		            }
		
		            tempFile << s_id << "\n" << username << "\n" << password << "\n";
		            
		        } 
				else 
				{
		            tempFile << staff_id << "\n" << username << "\n" << password << "\n";
		        }
		    }
		    file.close();
		    tempFile.close();
		
		    if (found== true) 
			{
		        remove(filename.c_str());
		        rename("temp.txt", filename.c_str());
		        cout << "\n\tCredentials reset successfully for " << staffType << "!" << endl;
		    } 
			else
			{
		        remove("temp.txt");
		        cout << "\n\tStaff id not found"<<endl;
		    }
		}
};






void Doctor::addDoctorsdata()
{
		cout << "\tEnter Doctor's ID: ";
		cin >> doctorId;
		while(cin.fail())
		{
			cout << " Invalid input! Enter integers only :" << endl;
			cin >> doctorId;
		}
		while(isdoctoridvalid(doctorId))
		{
			cout<<"There is a doctor against this id ."<<endl;
			cout << "\tEnter Doctor's ID: ";
			cin >> doctorId;
		}
			
		cout << "\tEnter Doctor's name: ";
		cin.ignore();
		getline(cin, doctorName);
			
			
		cout << "\tEnter Doctor's Specializtion: ";
		cin >> specialization;
			
		cout << "\tEnter Doctor's Phone number: ";
		cin >> doctorPhoneNumber;
		if(cin.fail())
		{
			cout << " Invalid input! Enter integers only " << endl;
			return ;
		}
			
		cout << "\tDoctor Working days: ";
		cin.ignore();
		getline(cin, docworkdays);
			
		cout << "\tDoctor working hours: ";
		getline(cin, docworktimings);
		cout << " \n ";
			
		ofstream file;
		file.open("doctors.txt", ios::app);
		if (!file.is_open())
		{
			cout << "\tError opening file " << endl;
		}
		file << doctorName << endl;
		file << doctorId << endl;
		file << specialization << endl;
		file << doctorPhoneNumber << endl;
		file << docworkdays << endl;
		file << docworktimings << endl;
		file.close();
			 
}
void Doctor::removeDoctor()
{
	    int delete_ID;
	    bool found = false;
	    cout << "\n\tEnter Doctor ID to remove: ";
	    cin >> delete_ID;
	
	    ifstream file;
	    file.open("doctors.txt");
	    if (!file.is_open())
	    {
	        cout << "\tError opening file " << endl;
	    }
	    ofstream file_1;
	    file_1.open("fordel.txt");
	
	    if (!file_1.is_open())
	    {
	        cout << " \t Error Opening file " << endl;
	        return;
	    }
	     getline(file, doctorName);
		file >> doctorId >> specialization >> doctorPhoneNumber;
		file.ignore();
		getline(file, docworkdays);
		getline(file, docworktimings);
	    while (!file.eof())
	    {
	        if (delete_ID != doctorId)
	        {
	            file_1 << doctorName << "\n"
	                   << doctorId << "\n"
	                   << specialization << "\n"
	                   << doctorPhoneNumber << "\n"
	                   << docworkdays << "\n"
	                   << docworktimings << endl;
	        }
	        else
	        {
	            found = true;
	        }
	        getline(file, doctorName);
		    file >> doctorId >> specialization >> doctorPhoneNumber;
		    file.ignore();
		    getline(file, docworkdays);
		    getline(file, docworktimings);
	    }
	
	    file.close();
	    file_1.close();
	
	    remove("doctors.txt");
	    rename("fordel.txt", "doctors.txt");
	
	    if (found == false)
	    {
	        cout << "\tThere is no data of any doctor with this ID." << endl;
	    }
	    else
	    {
	        cout << "\tData Deleted Successfully." << endl;
	    }
}

void Doctor::showDoctors()
{
		    bool found = false;
		    ifstream file;
		    file.open("doctors.txt");
		
		    if (!file.is_open())
		    {
		        cout << "\tError opening file." << endl;
		        return;
		    }
		
		    getline(file, doctorName);
		    file >> doctorId >> specialization >> doctorPhoneNumber;
		    file.ignore();
		    getline(file, docworkdays);
		    getline(file, docworktimings);
		
		    while (!file.eof())
		    {
		        cout << "\n";
		        cout << "\n\t\t ***************************************************************************" << endl;
		        cout << "\t\t ||\t               List of Doctor's   "
		             << "\t\t\t\t  || " << endl;
		        cout << "\t\t ||_______________________________________________________________________||" << endl;
		        cout << "\t\t ||                                                                       ||" << endl;
		        cout << "\t\t || Doctor Name             : " << setw(25) << left << doctorName << "\t\t\t  ||" << endl;
		        cout << "\t\t || Doctor ID               : " << setw(25) << left << doctorId << "\t\t\t  ||" << endl;
		        cout << "\t\t || Specialization          : " << setw(25) << left << specialization << "\t\t\t  ||" << endl;
		        cout << "\t\t || Phone Number            : " << setw(25) << left << doctorPhoneNumber << "\t\t\t  ||" << endl;
		        cout << "\t\t || Work Days               : " << setw(25) << left << docworkdays << "\t\t\t  ||" << endl;
		        cout << "\t\t || Work Timings            : " << setw(25) << left << docworktimings << "\t\t\t  ||" << endl;
		        cout << "\t\t ||                                                                       ||";
		        cout << "\n\t\t ***************************************************************************" << endl;
		        cout << "\n";
		
		        getline(file, doctorName);
		        file >> doctorId >> specialization >> doctorPhoneNumber;
		        file.ignore();
		        getline(file, docworkdays);
		        getline(file, docworktimings);
		        found = true;
		    }
		    cout << "\n";
		   
		    file.close();
		
		    if (found == false)
		    {
		        cout << " \t No Data Present to show " << endl;
		    }
}



void Doctor::searchDoctor()
{
	        int temp_id;
	        cout<<"\n\t\tEnter the id of the Doctor you want to search :";
	        cin>>temp_id;
		    bool found = false;
		    ifstream file;
		    file.open("doctors.txt");
		
		    if (!file.is_open())
		    {
		        cout << "\tError opening file." << endl;
		        return;
		    }
		
		    getline(file, doctorName);
		    file >> doctorId >> specialization >> doctorPhoneNumber;
		    file.ignore();
		    getline(file, docworkdays);
		    getline(file, docworktimings);
		
		    while (!file.eof())
		    {
		    	if(temp_id==doctorId)
		    	{
			        cout << "\n";
			        cout << "\n\t\t ***************************************************************************" << endl;
			        cout << "\t\t ||\t               List of Doctor's   "
			             << "\t\t\t\t  || " << endl;
			        cout << "\t\t ||_______________________________________________________________________||" << endl;
			        cout << "\t\t ||                                                                       ||" << endl;
			        cout << "\t\t || Doctor Name             : " << setw(25) << left << doctorName << "\t\t\t  ||" << endl;
			        cout << "\t\t || Doctor ID               : " << setw(25) << left << doctorId << "\t\t\t  ||" << endl;
			        cout << "\t\t || Specialization          : " << setw(25) << left << specialization << "\t\t\t  ||" << endl;
			        cout << "\t\t || Phone Number            : " << setw(25) << left << doctorPhoneNumber << "\t\t\t  ||" << endl;
			        cout << "\t\t || Work Days               : " << setw(25) << left << docworkdays << "\t\t\t  ||" << endl;
			        cout << "\t\t || Work Timings            : " << setw(25) << left << docworktimings << "\t\t\t  ||" << endl;
			        cout << "\t\t ||                                                                       ||";
			        cout << "\n\t\t ***************************************************************************" << endl;
			        cout << "\n";
		        }
		        getline(file, doctorName);
		        file >> doctorId >> specialization >> doctorPhoneNumber;
		        file.ignore();
		        getline(file, docworkdays);
		        getline(file, docworktimings);
		        found = true;
		    }
		    cout << "\n";
		   
		    file.close();
		
		    if (found == false)
		    {
		        cout << " \t No Data Present to show " << endl;
		    }
}

void Doctor::updateDoctor()
{
			    int promote_ID, choice, choose;
			    bool found = false;
			    cout << "\n\tEnter Doctor ID to update: ";
			    cin >> promote_ID;
			
			    fstream file, file_1;
			    file.open("doctors.txt", ios::in);    // ios::in is for reading data form file
			    file_1.open("promote.txt", ios::out); // ios::out is for writing data to the file
			
			    if (!file.is_open())
			    {
			        cout << "\tError opening file." << endl;
			        return;
			    }
			
			    if (!file_1.is_open())
			    {
			        cout << "\tError opening file." << endl;
			        return;
			    }
			    
			     getline(file, doctorName);
			    file >> doctorId >> specialization >> doctorPhoneNumber;
			    file.ignore();
			    getline(file, docworkdays);
			    getline(file, docworktimings);
			    while (!(file.eof()))
			    {
			        if (promote_ID == doctorId)
			        {
			            found = true;
			            cout << "\n\t\t   Doctor ID found. Update the information" << endl;
			            cout << "\n\t\t  What do you want to update ?";
			            cout << "\n\t\t\t   -------------Choose from below------------- " << endl;
			            cout << "\n\t\t    ___________________________________________ ";
			            cout << "\n\t\t   |                                           |";
			            cout << "\n\t\t   |  1--> Specialization                      |"
			                 << "\n\t\t   |  2--> Phone Number                        |"
			                 << "\n\t\t   |  3--> Work Days                           |"
			                 << "\n\t\t   |  4--> Work Timings                        |";
			            cout << "\n\t\t   |___________________________________________|" << endl;
			            choice = getch();
			
			            
			
			            system("CLS");
			            switch (choice)
			            {
			            case '1':
			                cout << "\tEnter the new Specialization: ";
			                cin >> specialization;
			                break;
			
			            case '2':
			                cout << "\tEnter Doctor's new Phone number ";
			                cin >> doctorPhoneNumber;
			                break;
			
			            case '3':
			                cout << "\t Enter doctor new working days: ";
			                cin.ignore();
			                getline(cin, docworkdays);
			                break;
			
			            case '4':
			                cout << "\t Enter doctor new working hours: ";
			                getline(cin, docworktimings);
			                break;
			
			            default:
			                cout << "\n\t Invalid Input .No such update of data available" << endl;
			            }
			            
			            file_1 << doctorName << "\n" 
						       << doctorId << "\n" 
							   << specialization << "\n"
			                   << doctorPhoneNumber << "\n" 
							   << docworkdays << "\n" 
							   << docworktimings << endl;
			            break;
			        }
			        
			        else
			        {
			            file_1 << doctorName << "\n" 
						       << doctorId << "\n" 
							   << specialization << "\n"
			                   << doctorPhoneNumber << "\n" 
							   << docworkdays << "\n" 
							   << docworktimings << endl;
			        }
			        
			        getline(file, doctorName);
				    file >> doctorId >> specialization >> doctorPhoneNumber;
				    file.ignore();
				    getline(file, docworkdays);
				    getline(file, docworktimings);
			    }
			
			    file.close();
			    file_1.close();
			
			    remove("doctors.txt");
			    rename("promote.txt", "doctors.txt");
			
			    if (found==true)
			    {
			        cout << "\tData Updated Successfully." << endl;
			    }
			    else
			    {
			        cout << "\tDoctor ID not found." << endl;
			    }
}



 
void Staff:: addStaff()
{
	
	    cout << "\tData of staff member " << endl;
	    cout << "\tStaff first name: ";
	    cin >> staff_FName;
	
	    cout << "\tStaff last name: ";
	    cin >> staff_LName;
	
	    cout << "\tStaff Id : ";
	    cin >> staffId;
	    if(cin.fail())
	    {
	    	cout << " Invalid input! Enter integers only " << endl;
	    	return ;
		}
	
	    cout << "\tStaff age: ";
	    cin >> staffAge;
	    if(cin.fail())
	    {
	    	cout << " Invalid input! Enter integers only " << endl;
	    	return ;
		}
	
	    cout << "\tStaff phone no: ";
	    cin >> staffPhoneNumber;
	    if(cin.fail())
	    {
	    	cout << " Invalid input! Enter integers only " << endl;
	    	return ;
		}
	
	    cout << "\tStaff designation: ";
	    cin.ignore();
	    getline(cin, staffDesignation);
	    
	    cout << "\tStaff Working days: ";
	    getline(cin, staffworkdays);
	
	    cout << "\tStaff working hours: ";
	    getline(cin, staffworktimings);
	
	    fstream file;
	
	    file.open("staff.txt", ios::out | ios::app);
	    if (!file.is_open())
	    {
		    cout << "\tError opening file " << endl;
	    }
	    file << " " << staff_FName << "\n";
	    file << " " << staff_LName << "\n";
	    file << " " << staffId << "\n";
	    file << " " << staffAge << "\n";
	    file << " " << staffPhoneNumber << "\n";
	    file << " " << staffDesignation << "\n";
	    file << " " << staffworkdays << "\n";
	    file << " " << staffworktimings << "\n";
	    file.close();
	    
	}

void Staff::updateStaff() 
{
	
	    int updateId;
	    bool found = false;
	    cout << "\n\tEnter Staff ID to update: ";
	    cin >> updateId;
	
	    ifstream file("staff.txt");
	    ofstream tempFile("temp.txt");
	
	    if (!file.is_open() || !tempFile.is_open()) {
	        cout << "\tError opening file." << endl;
	        return;
	    }
	
	    while (file >> staff_FName >> staff_LName >> staffId >> staffAge >> staffPhoneNumber) {
	        file.ignore();
	        getline(file, staffDesignation);
	        getline(file, staffworkdays);
	        getline(file, staffworktimings);
	
	        if (updateId == staffId) 
			{
	            found = true;
	            cout << "\n\tUpdating Staff Information:" << endl;
	            cout << "\tStaff first name: ";
	            cin.ignore();
	            getline(cin, staff_FName);
	
	            cout << "\tStaff last name: ";
	            getline(cin,staff_LName);
	
	            cout << "\tStaff Id: " << staffId << endl; // Staff ID remains unchanged
	
	            cout << "\tStaff age: ";
	            cin >> staffAge;
	
	            cout << "\tStaff phone no: ";
	            cin >> staffPhoneNumber;
	
	            cout << "\tStaff designation: ";
	            cin.ignore();
	            getline(cin, staffDesignation);
	
	            cout << "\tStaff Working days: ";
	            getline(cin, staffworkdays);
	
	            cout << "\tStaff working hours: ";
	            getline(cin, staffworktimings);
	        }
	
	        tempFile << staff_FName << "\n"
	                 << staff_LName << "\n"
	                 << staffId << "\n"
	                 << staffAge << "\n"
	                 << staffPhoneNumber << "\n"
	                 << staffDesignation << "\n"
	                 << staffworkdays << "\n"
	                 << staffworktimings << "\n";
	    }
	
	    file.close();
	    tempFile.close();
	
	    remove("staff.txt");
	    rename("temp.txt", "staff.txt");
	
	    if (!found)
		{
	        cout << "\tThere is no data of any staff with this ID." << endl;
	    } 
		else 
		{
	        cout << "\tData Updated Successfully." << endl;
	    }
	}

void Staff::showstaffdata()
	{
		    ifstream file;
		    file.open("staff.txt");
		
		    file >> staff_FName >> staff_LName >> staffId >> staffAge >> staffPhoneNumber;
		    file.ignore();
		    getline(file, staffDesignation);
		    getline(file, staffworkdays);
		    getline(file, staffworktimings);
		    while (!file.eof())
		    {
		
		        cout << "\n";
		        cout << "\n\t\t *************************************************************************" << endl;
		        cout << "\t\t ||\t               Data of Staff Member    "
		             << "\t\t\t        || " << endl;
		        cout << "\t\t ||_____________________________________________________________________||" << endl;
		        cout << "\t\t ||                                                                     ||" << endl;
		        cout << "\t\t || Staff First Name         : " << setw(25) << left << staff_FName << "\t\t||" << endl;
		        cout << "\t\t || Staff Last Name          : " << setw(25) << left << staff_LName << "\t\t||" << endl;
		        cout << "\t\t || Staff Id                 : " << setw(25) << left << staffId << "\t\t||" << endl;
		        cout << "\t\t || Age of Staff             : " << setw(25) << left << staffAge << "\t\t||" << endl;
		        cout << "\t\t || Phone no of Staff        : " << setw(25) << left << staffPhoneNumber << "\t\t||" << endl;
		        cout << "\t\t || Designation of Staff     : " << setw(25) << left << staffDesignation << "\t\t||" << endl;
		        cout << "\t\t || Working Days of Staff     : " << setw(25) << left << staffworkdays << "\t\t||" << endl;
		        cout << "\t\t || Working Hours of Staff    : " << setw(25) << left << staffworktimings << "\t\t||" << endl;
		        cout << "\t\t ||                                                                     ||";
		        cout << "\n\t\t *************************************************************************" << endl;
		        cout << "\n";
		
		        file >> staff_FName >> staff_LName >> staffId >> staffAge >> staffPhoneNumber;
		        file.ignore();
		        getline(file, staffDesignation);
		        getline(file, staffworkdays);
		        getline(file, staffworktimings);
		    }
		    cout << "\n";
		    cout << "\n\n\t\tPress any key to continue " << endl;
		    cin.ignore();
		
		    file.close();
	} 




void Staff :: searchstaffdata()
	{
		    int search_id;
		    bool found = false;
		    cout << "\tEnter the id of the employee you want to search ";
		    cin >> search_id;
		    
		    ifstream file;
		    file.open("staff.txt");
		    
		    if (!file.is_open())
		    {
		        cout << "\tError opening file " << endl;
		        return;
		    }
		    
		    file >> staff_FName >> staff_LName >> staffId >> staffAge >> staffPhoneNumber;
		    file.ignore();
		    getline(file, staffDesignation);
		    getline(file, staffworkdays);
		    getline(file, staffworktimings);
		    while (!file.eof())
		    {
		
		        if (search_id == staffId)
		        {
		            cout << "\n";
		            cout << "\n\t\t *************************************************************************" << endl;
		            cout << "\t\t ||\t               Data of Staff Member    "
		                 << "\t\t\t        || " << endl;
		            cout << "\t\t ||_____________________________________________________________________||" << endl;
		            cout << "\t\t ||                                                                     ||" << endl;
		            cout << "\t\t || Staff First Name         : " << setw(25) << left << staff_FName << "\t\t||" << endl;
		            cout << "\t\t || Staff Last Name          : " << setw(25) << left << staff_LName << "\t\t||" << endl;
		            cout << "\t\t || Staff Id                 : " << setw(25) << left << staffId << "\t\t||" << endl;
		            cout << "\t\t || Age of Staff             : " << setw(25) << left << staffAge << "\t\t||" << endl;
		            cout << "\t\t || Phone no of Staff        : " << setw(25) << left << staffPhoneNumber << "\t\t||" << endl;
		            cout << "\t\t || Designation of Staff     : " << setw(25) << left << staffDesignation << "\t\t||" << endl;
		            cout << "\t\t || Working Days of Staff     : " << setw(25) << left << staffworkdays << "\t\t||" << endl;
		            cout << "\t\t || Working Hours of Staff    : " << setw(25) << left << staffworktimings << "\t\t||" << endl;
		            cout << "\t\t ||                                                                     ||";
		            cout << "\n\t\t *************************************************************************" << endl;
		            cout << "\n";
		            found = true;
		        }
		
		        file >> staff_FName >> staff_LName >> staffId >> staffAge >> staffPhoneNumber;
		        file.ignore();
		        getline(file, staffDesignation);
		        getline(file, staffworkdays);
		        getline(file, staffworktimings);
		    }
		
		    file.close();
		    
		    if (found == false)
		    {
		        cout << "\tThere is no data of any patient with this cnic." << endl;
		    }
	}
	
void Staff::removeStaff()
	{
		    int delete_staff;
		    bool found = false;
		    cout << "\n\tEnter Staff ID to remove: ";
		    cin >> delete_staff;
		
		    ifstream file;
		    file.open("staff.txt");
		
		    ofstream file_1;
		    file_1.open("fordel.txt");
		
		    if (!file.is_open())
		    {
		        cout << " \t Error Opening file " << endl;
		        return;
		    }
		
		    if (!file_1.is_open())
		    {
		        cout << " \t Error Opening file " << endl;
		        return;
		    }
		    file >> staff_FName >> staff_LName >> staffId >> staffAge >> staffPhoneNumber;
		    file.ignore();
		    getline(file, staffDesignation);
		    getline(file, staffworkdays);
		    getline(file, staffworktimings);
		    while (!file.eof())
		    {
		        if (delete_staff != staffId)
		        {
		            file_1 << staff_FName << "\n"
		                   << staff_LName << "\n"
		                   << staffId << "\n"
		                   << staffAge << "\n"
		                   << staffPhoneNumber << "\n"
		                   << staffDesignation << "\n"
		                   << staffworkdays << "\n"
		                   << staffworktimings << endl;
		        }
		        else
		        {
		            found = true;
		        }
		        file >> staff_FName >> staff_LName >> staffId >> staffAge >> staffPhoneNumber;
			    file.ignore();
			    getline(file, staffDesignation);
			    getline(file, staffworkdays);
			    getline(file, staffworktimings);
		    
		    }
		
		    file.close();
		    file_1.close();
		
		    remove("staff.txt");
		    rename("fordel.txt", "staff.txt");
		
		    if (found == false)
		    {
		        cout << "\tThere is no data of any Staff with this ID." << endl;
		    }
		    else
		    {
		        cout << "\tData Deleted Successfully." << endl;
		    }
	}
	
class receptionist:public Staff
{
	private:
		int receptionist_id;
		
	public:
	Patient p;
	
	
		void receptionistlogin()
		{
			int rep_id;
	    		start:              //start point will come here in case of logging out
			system("ClS");
			string username_1,pass_1,password,username;
			bool _found=false;                         //bool found used to check conditions
			
			
			cout << "\n\n\t\t========================================" << endl;
		    cout << "\t\t|        Hospital Management System    |" << endl;
		    cout << "\t\t========================================" << endl;
		    cout << "\t\t| Please login by entering your:       |" << endl;
		    cout << "\t\t| 1. Receptionist ID                   |" << endl;
		    cout << "\t\t| 2. Username                          |" << endl;
		    cout << "\t\t| 3. Password                          |" << endl;
		    cout << "\t\t========================================" << endl;
		    
		    
		    cout<<"\n\n\t\tEnter Your Receptionist_id :  ";
		    cin>>receptionist_id;
		    cout<<"\n\n\t\tEnter Username :  ";
		    username_1.clear();
		    cin.ignore();
		    getline(cin,username_1);
		    cout<<"\n\n\t\tPassword : ";
		    char pass;
		    while((pass=_getch()) !='\r')
		    {
			    if(pass >= 32 && pass <= 126)
	           {
	                cout<<'*';
	                pass_1.push_back(pass);            
	           }
	            else if(pass == 8 && pass_1.length() > 0)     
	           {
	               pass_1.pop_back();                       
	               cout<<"\b \b";
	           }
		    }
		    cout<<"\n";
		    
	        ifstream file;
		    file.open("receptionistlogins.txt");
		    
		    if(!file.is_open())
		    {
		    	cout<<"\t Error opening file ";
			}
			
		    while(file>>rep_id)
		    {  
		        file.ignore();
		        getline(file,username);
		        getline(file,password);
		      
		        
		        if (receptionist_id == rep_id && username==username_1 && password==pass_1)
		        {	  
					_found=true;
					break;
				}
    
			}
			file.close();
			if(_found==true)
			{ 
			       receploginMenu();
		
			}
		
			else{
				cout<<"\n\n\t\tNo account exsists against these credentials "<<endl;
				Sleep(3000);
				system("cls");
				goto start;
			}
		}
		
		void receploginMenu()
		{
			system("cls");
			  while(true)
			  {
			    o:   //point o here
				char choice;
				cout << "\n";
				cout << "\n\t\t *************************************************************************" << endl;
				cout << "\t\t ||\t\t       Patient Management"
				     << "\t\t\t        || " << endl;
				cout << "\t\t ||_____________________________________________________________________||" << endl;
				cout << "\t\t ||                                                                     ||" << endl;
				cout << "\t\t || 1. Enter patient data            " << setw(34) << left << "" << "\t||" << endl;
				cout << "\t\t || 2. Show patient details          " << setw(34) << left << "" << "\t||" << endl;
				cout << "\t\t || 3. Delete patient data           " << setw(34) << left << "" << "\t||" << endl;
				cout << "\t\t || 4. Update patient data           " << setw(34) << left << "" << "\t||" << endl;
				cout << "\t\t || 5. Billing                       " << setw(34) << left << "" << "\t||" << endl;
				cout << "\t\t || 6. Logout                        " << setw(34) << left << "" << "\t||" << endl;
				cout << "\t\t ||                                                                     ||" << endl;
				cout << "\t\t || Enter your choice              : " << setw(34) << left << "" << "\t||" << endl;
				cout << "\t\t ||                                                                     ||" << endl;
				cout << "\t\t *************************************************************************" << endl;
				cout << "\n";


				choice = getch();
				switch(choice)
				{
					case '1':
						p.addpatient();
						break;
					case '2':
						p.searchMenu();
						break;
					case '3':
						p.deleteMenu();
						break;
					case '4':
					    system("cls");	
						p.UpdateMenu();
						break;
					case '5':
						system("cls");
						billing();
						break;
					case '6':
						
						cout<<"\n\n\n\t\tLOGGING OUT";
						for (int i=0;i<5;i++)
						{
							cout<<".";
							Sleep(1000);
						}
						system("cls");
						return;
						break;
					default:
						cout<<"Enter a valid choice .";
						Sleep(2000);
						system("cls");
						goto o;
					
				}
				
			}
	
			
		}

		
		double Calculating_charges(string Room_id ,int Patient_id)
	    {
			int room_occupancy ;
		    string _time_,_date_;  // yeh time walay variable aksr log kahtay wohi use kro jo file ma bhaijay
		   
		     int patient_billing_id = Patient_id;
	     
	     
	      fstream temp_file;
	      temp_file.open("temp.txt" , ios::out | ios::app);
	  //yahan us class ka object banna kar getter sa single,double,triple ka charges lain ga
	    //____________________________________________________________________//
		    Roomadmin room_admin;
			string retrieved_day,retrieved_hour;      string new_hour;
			                                          string _new_day;
			string store_day,store_hour;
			store_day =__DATE__;
		    store_hour = __TIME__;
		    int ID;
		    int room_cap;
		    long long int CNIC;
		    fstream file;
		    
			file.open(Room_id, ios:: in | ios::app);
			if(!file.is_open())
			{
				cout<<"Error Opening File!!"<<endl;
			}
			
			 while(file >>room_occupancy >> ID )
		  	{   
		  	  file.ignore();
			  getline(file, _time_ );  
			  getline(file, _date_ );  
		   }
		
		  	retrieved_day	=_date_;
		  	retrieved_hour  =_time_;
		  	 
		    
			int charges_per_Day;
		    double hourly_charges ;
		    if(room_occupancy == 1 )
		    {
		    	charges_per_Day = room_admin.get_one_bed_room_charges();
		    	hourly_charges = charges_per_Day/24;
		      	
			}
		    else if(room_occupancy == 2 )
		    {
		    	charges_per_Day = room_admin.get_two_bed_room_charges();
		    	hourly_charges = charges_per_Day/24;
		    
			}
			else if(room_occupancy == 3 )
		    {
		    	
		    	charges_per_Day = room_admin.get_three_bed_room_charges();
		    	hourly_charges = charges_per_Day/24;
			}   
		    
		    
		                              // hum file ma DATE and TIME Alag Alag variable sa bhaijain ga
		   // retrieved_day	=R_da_y; // jo file ma jab CNIC match hoga patient ka to wo wala R_da_y yahan store hojai ga
		  //	retrieved_hour  =R_hou_r;// jo file ma jab CNIC match hoga patient ka to wo wala R_hou_r yahan store hojai ga
			
			 string d,a,day;
			d=retrieved_day[4];
			a=retrieved_day[5];	
			day=d+a;
			int old_day;
			old_day=stoi(day);
			
			string retrive_h,retrive_o,retrive_hour;
			retrive_h = retrieved_hour[0];
			retrive_o = retrieved_hour[1];
			retrive_hour = retrive_h + retrive_o;
			int Re_hour;
			Re_hour = stoi(retrive_hour);
			_new_day = __DATE__;
			new_hour = __TIME__;
			string n_d,n_a,n_day;
			
			n_d = _new_day[4];
			n_a = _new_day[5];
			n_day = n_d + n_a;
			int new_day= stoi(n_day);
			string n_h,n_o,n_hour;
			n_h = new_hour[0];
			n_o = new_hour[1];
			n_hour =n_h +  n_o;
			int _hour;
			_hour=stoi(n_hour);
			// _hour jo humaray is waqt ka ghantay hn
			cout<<"\n\t\tThe Value of Now Hour is :"<<_hour<<endl;
			cout<<"\t\tThe Value of old Hour is :"<<Re_hour<<endl;
			double daily_Charges ;
			
			int day_difference ;
			day_difference = new_day - old_day;
			daily_Charges = day_difference * charges_per_Day;
			double Total_charges_is;
			int counter=0;
			   if(Re_hour <_hour )
			   {
			   	
			   		for(int j =Re_hour ; j<=_hour;j++)
				{
					counter++;
				
				}
			   	
				}
				else if(_hour < Re_hour)
				{
				for(int j =_hour ; j<=Re_hour;j++ )
				{
				
				    counter++;
		//			if( _hour == Re_hour  )
		//			break;
				}	
					
				}
				if(counter == 1)
				{
					hourly_charges = hourly_charges *counter  ;
				}
				else if(counter >1)
				{
				    hourly_charges =(hourly_charges *counter ) - hourly_charges ;    	
				}
			    Total_charges_is = hourly_charges + daily_Charges;	
		     	
				 //Removing Patient CNIC
			    cout<<"\n\t\t1 Day Charge is : Rs "<< charges_per_Day <<endl;
				cout<<"\t\t1 Hour Charge is : Rs "<<hourly_charges <<endl;
			
				cout<<"\n\t\tAdmit Date is :"<<retrieved_day<<endl;
				cout<<"\t\tAdmit Time is :"<<retrieved_hour<<endl;
				
				cout<<"\n\t\tNow DATE is :"<<_new_day<<endl;
				cout<<"\t\tNow time is :"<<new_hour<<endl;
					 
				 
				 
			
				 cout<<"\t\tCalculated charges for room "<<ID<<" is Rs"<<Total_charges_is<<endl;
				 return Total_charges_is;
		
	}
 
		
		
		
		void billing()
	    {
	        
	    	bool found = false;
			int p_cnic,cnic;
			int pat_id; // to get Patient Data;
			int patients_ids; // to retrieve patient ID;
			double med_price,total_medbill=0;
			string medicine_name;
			string R_id;
			cout << "\n\t\t *************************************************************************" << endl;
		    cout << "\t\t ||\t\t\t       Patient Billing System"
		         << "\t\t        || " << endl;
		    cout << "\t\t *************************************************************************" << endl;

            cout<<"\n\t\tEnter the Patient ID whose room charges you want to calculate :";
			cin>>pat_id;
			
			//checking wheter the there is a patient against the id
			if(!p.isidvalid(pat_id))
			{
				cout<<"\n\t\tThe patient against this Id "<<pat_id<<" is not present ."<<endl;
				Sleep(5000);
			
				receploginMenu();
			    
			}
			else 
			{ 
			    //if patient is found searching wheter he is admitted in a room or not
				R_id = p.searchindoorpatientdata(pat_id);
				if(!p.is_present_in_room(R_id,pat_id))
				{
					cout<<"\n\t\tThe patient against this Id "<<pat_id<<" is not present or either discharged."<<endl;
					Sleep(5000);
					receploginMenu();
				}
				else
				{
					cout<<"\t\tThe patient is present in Room "<<R_id<<endl;
				}
				
			}
			ifstream file;
			file.open("billing.txt");
			if(!file.is_open())
			{
				cout<<"\t\tError opening file ....."<<endl;
			}
			else
			{
				//calculating the patients medicines bill given by nurse
				while(file>>patients_ids)
				{
					file.ignore();
					getline(file,medicine_name);
					file>>med_price;
					
					if(patients_ids == pat_id)
					{
						cout<<"\n\t\tMedicine names :"<<medicine_name;
						cout<<"\n\t\tMedicine price   :"<<med_price;
						total_medbill += med_price;
						found = true;
						
					}
				
				}
			}
			cout<<"\n\t\tThe total medicine bill is :"<<total_medbill;
			if(found = false)
			{
				cout<<"\t\t Patient against this cnic med record not found in medicine billing ."<<endl;
			}
			
			file.close();
			cout<<"\n\t\tChecking patient doctor visits ....."<<endl;
			
			//visit made by doctors reading throigh file using a counter variable 
		    
			int visit_count=0,Doc_id;
		
			int visit_charge;
			ifstream dfile;
			dfile.open("visits.txt");
			if(!dfile.is_open())
			{
				cout<<"\t\tError opening file ....."<<endl;
			}
			else
			{ 
			    dfile>>patients_ids && dfile>>Doc_id;
				while(!dfile.eof())
				{          
				    
				   
					if(pat_id == patients_ids)
					{
						visit_count++;
					
					}
					dfile>>patients_ids && dfile>>Doc_id;
				}
				
				
			    if(visit_count == 0)
			    {
			    	cout<<"\n\t No doctor visits took place."<<endl;
				}
				else if(visit_count == 1 || visit_count >1)
				{
					
					cout<<"\n\t\tEnter per visit price :";
					cin>>visit_charge;
					while(visit_charge<0)
					{
						cout<<"\t\tVisit charge cannot be in negative.Enter again :";
						cin>>visit_charge;
					}
				    
					 
				
						visit_charge += (visit_charge * visit_count) - visit_charge;
						cout<<"\t\tTotal visit bill is :"<<visit_charge <<" Rs"<<endl;
					
					
				}
				
	     	}
	    	dfile.close();
	    
	    	string _room_id;
	    	Patient p;
	    	
	    	//retriving room_id from the indoor file for calculating room charges
	    	_room_id= p.searchindoorpatientdata(pat_id);
	    	int room_charges;
			 
		    room_charges = Calculating_charges(R_id, pat_id);
		    
			
		    cout << "\n\t\tPatient Room Charges are: " << room_charges << endl;
		    
		
		    double grand_total = room_charges + visit_charge + total_medbill;
		    cout << "\n\t\tYour Total Bill is: Rs " << grand_total << endl;
		
		    char ch;
		    cout << "\n\t\tCharges are paid or not (Y/N): ";
		    cin >> ch;
		    if (ch == 'Y' || ch == 'y') 
			{
				//discharging patient removoing data from every file included in billing.
		        dischargePatient(pat_id);
		        
		    } 
			else 
			{
		        cout << "\n\t\tPatient won't be discharged if the payment has not been made." << endl;
		    }	
		}
		
		
		void dischargePatient(int pat_id) 
		{
			int patient_s_Id;
		    // Remove patient's billing information
		    ifstream billingFile("billing.txt");
		    ofstream tempBilling("temp_billing.txt");
		    int cnic;
		    double med_price;
		    string med_name;
		    bool foundBilling = false;    //variable used for validation
		     
		     //removing the patient from the medicine billing file
		    while (billingFile >>patient_s_Id) 
			{
		        billingFile.ignore();
		        getline(billingFile, med_name);
		        billingFile >> med_price;
		
		        if (pat_id != patient_s_Id) {
		        	tempBilling << patient_s_Id <<endl;
		            tempBilling << med_name << endl;
		            tempBilling << med_price << endl;
		        } 
				
				else
				{
		            foundBilling = true;
		        }
		    }
		    billingFile.close();
		    tempBilling.close();
		
		    remove("billing.txt");
		    rename("temp_billing.txt", "billing.txt");
		
		    if (foundBilling == false) 
			{
		        cout << "Patient's billing record not found!" << endl;
		    }
		
		    // Remove patient's doctor visits
		    ifstream visitsFile("visits.txt");
		    ofstream tempVisits("temp_visits.txt");
		    int docId;
		    bool foundVisits = false;
		
		    while (visitsFile >> patient_s_Id >> docId)
			 {
		        if (pat_id != patient_s_Id) 
				{
		            
		            tempVisits << patient_s_Id << endl;
		            tempVisits << docId << endl;
		        } 
				else 
				{
		            foundVisits = true;
		        }
		    }
		    visitsFile.close();
		    tempVisits.close();
		
		    remove("visits.txt");
		    rename("temp_visits.txt", "visits.txt");
		
		    if (foundVisits == false ) 
			{
		        cout << "Patient's visits record not found!" << endl;
		    }
		
		    // Remove patient's room information
		    ifstream roomFile("indoor.txt");
		    ofstream tempRoom("temp.txt");
		   
		    string firstName, lastName, bloodGroup, diagnosis, roomId, date_, time_;
		    long long int phoneNum;
		    int age , ID_patient;
		    bool foundId =false;
		    bool foundRoom = false;
		    
		
		    while (roomFile >> firstName >> lastName >> ID_patient >> age >> phoneNum >> cnic) 
			{
		        roomFile.ignore();
		        getline(roomFile, bloodGroup);
		        getline(roomFile, diagnosis);
		        roomFile >> roomId;
		        roomFile.ignore();
		        getline(roomFile, date_);
		        getline(roomFile, time_);
		        
		
		        if (ID_patient == pat_id) 
				{
		            
		            foundId = true;
		            break;
		        } 
				
		         
		        
		    }
		     roomFile.close();
		     if(foundId == false)
		     {
		     	cout<<"\n\t\tNo patient with this cnic was alloted a room ."<<endl;
			 }
		     
		    fstream file(roomId,ios::in);
		   
		
		    if(!file.is_open())
		    {
		    	cout<<"\n\t\tError opening file ."<<endl;
			}
		    int room_occupant;
		    file>>room_occupant;
		    tempRoom<<room_occupant<<endl;
		    while(file>>pat_id)
		    {
		    	file.ignore();
		    	getline(file, time_);
		    	getline(file, date_);
		    	
			    	if (patient_s_Id != pat_id) 
					{
			            tempBilling << pat_id << endl;
			            tempBilling << time_ << endl;
			            tempBilling << date_ << endl;
			        }
					else 
					{
			            foundRoom = true;
			        }
						
				
			}
			    file.close();
			    tempRoom.close();
				remove(roomId.c_str());
				rename("temp.txt",roomId.c_str());
			
		   if (foundRoom == false)
			 {
			 
		        cout << "Patient's room record not found!" << endl;
		    }
		   
		
		    if (foundBilling || foundVisits || foundRoom) {
		        cout << "Patient successfully discharged." << endl;
		    }
		    
		}
		
	
	
};

class Nurse:public Staff
{
	private:
		int nurse_id;
	public:
		void Nurselogin()
	    {
	    		start:              //start point will come here in case of logging out
			system("ClS");
			int nus_id;
			string username_1,pass_1,password,username;
			bool found=false;                         //bool found used to check conditions
			cout << "\n\n\t\t========================================" << endl;
		    cout << "\t\t|       Hospital Management System     |" << endl;
		    cout << "\t\t========================================" << endl;
		    cout << "\t\t| Please login by adding your:         |" << endl;
		    cout << "\t\t| 1. ID                                |" << endl;
		    cout << "\t\t| 2. Username                          |" << endl;
		    cout << "\t\t| 3. Password                          |" << endl;
		    cout << "\t\t========================================" << endl;
		    cout<<"\n\n\t\tEnter Your Nurse Id :  ";
		    cin>>nurse_id;
		    cout<<"\n\n\t\tEnter Username :  ";
		    cin.ignore();
		    getline(cin,username_1);
		    cout<<"\n\n\t\tPassword : ";
		    char pass;
		    while((pass=_getch()) !='\r')
		    {
			    if(pass >= 32 && pass <= 126)
	           {
	                cout<<'*';
	                pass_1.push_back(pass);            
	           }
	            else if(pass == 8 && pass_1.length() > 0)     
	           {
	               pass_1.pop_back();                       
	               cout<<"\b \b";
	           }
		    }
		    cout<<"\n";
		    
	        ifstream file;
		    file.open("nurselogins.txt");
		    
		    if(!file.is_open())
		    {
		    	cout<<"\t Error opening file ";
			}
		    
		    //comapring data in file to find login
		    while (file>>nus_id)
		    {  
		        file.ignore();
		        getline(file,username);
		        getline(file,password);
		        
		        if (nurse_id==nus_id && username==username_1 && password==pass_1)
		        {	  
					found=true;
					break;
				}
				    
			}
			file.close();
			fstream ifile;
			string med_name;
			
			//login found from file
			if(found==true)
			{
				Patient p;
				string R_id;
				while(true)
				{
					system("cls");
				 p:     //p declared
					char c;
					cout << "\n";
					cout << "\n\t\t *************************************************************************" << endl;
					cout << "\t\t ||\t\t\t       Patient Treatment"
					     << "\t\t        || " << endl;
					cout << "\t\t ||_____________________________________________________________________||" << endl;
					cout << "\t\t ||                                                                     ||" << endl;
					cout << "\t\t || 1. Enter Medicine detail you are giving to the patient.             ||" << endl;
					cout << "\t\t || 2.  Logout                                                          ||" << endl;
					cout << "\t\t ||                                                                     ||" << endl;
					cout << "\t\t ||                                                                     ||" << endl;
					cout << "\t\t *************************************************************************" << endl;
					cout << "\n";

					c=getch();
					switch(c)
					{
					case '1':
						system("cls");
						int p_cnic,med_price,pat_id;
						cout<<"\n\tEnter Patient ID you are attending :";
						cin>>pat_id;
						 if(!p.isidvalid(pat_id))
							{
								cout<<"\n\t\tThe patient against this Id "<<pat_id<<" is not present ."<<endl;
								Sleep(5000);
								system("cls");
								goto p;
								
							    
							}
							else 
							{ 
						    //if patient is found searching wheter he is admitted in a room or not
								R_id = p.searchindoorpatientdata(pat_id);
								if(!p.is_present_in_room(R_id,pat_id))
								{
									cout<<"\n\t\tThe patient against this Id "<<pat_id<<" is not present or either discharged."<<endl;
									Sleep(5000);
									system("cls");
									goto p;
								}
								else
								{
									cout<<"\t\tThe patient is present in Room "<<R_id<<endl;
								}
						    }
						
						cout<<"Enter the medicines you are giving to the patient :";
						cin.ignore();
						getline(cin,med_name);
						cout<<"Enter the prices of the medicine :";
						cin>>med_price;
						if(med_price<0)
						{
							cout<<"\t\tMedicine price cannot be in negative.Enter again :";
							cin>>med_price;
						}
						ifile.open("billing.txt",ios::out|ios::app);
						if(!ifile.is_open())
						{
							cout<<"Error opening file ...";
						}
						else
						{
						    ifile<<pat_id<<endl;
							ifile<<med_name<<endl;
							ifile<<med_price<<endl;
						}
						break;
					case '2':
						cout<<"Logging out ";
						for(int i=0;i<5;i++)
						{
							cout<<".";
							Sleep(1000);
						}
						system("cls");
						return;
						break;
					default:
						cout<<"Enter a valid choice....";
						Sleep(2000);
						goto p;
			}
				
			}
	   }
	   	else
		{
			cout<<"\n\n\t\tNo account exsists against these credentials "<<endl;
			Sleep(3000);
			system("cls");
			goto start;
		}
   }
};




int main()
{
	       
		cout << "\n\n\n";
	    cout << "\t\t\t\t       +--------------------------------------------------+" << endl;
	    cout << "\t\t\t\t       |                    AUMC                          |" << endl;
	    cout << "\t\t\t\t       |                  HOSPITAL                        |" << endl;
	    cout << "\t\t\t\t       |                                                  |" << endl;
	    cout << "\t\t\t\t       +--------------------------------------------------+" << endl;
	    cout << "\t\t\t\t       |        _____    _____    _____    _____          |" << endl;
	    cout << "\t\t\t\t       |       |     |  |     |  |     |  |     |         |" << endl;
	    cout << "\t\t\t\t       |       |     |  |     |  |     |  |     |         |" << endl;
	    cout << "\t\t\t\t       |       |_____|  |_____|  |_____|  |_____|         |" << endl;
	    cout << "\t\t\t\t       |        _____    _____    _____    _____          |" << endl;
	    cout << "\t\t\t\t       |       |     |  |     |  |     |  |     |         |" << endl;
	    cout << "\t\t\t\t       |       |     |  |     |  |     |  |     |         |" << endl;
	    cout << "\t\t\t\t       |       |_____|  |_____|  |_____|  |_____|         |" << endl;
	    cout << "\t\t\t\t       |                                                  |" << endl;
	    cout << "\t\t\t\t       |        _____    _____    _____    _____          |" << endl;
	    cout << "\t\t\t\t       |       |     |  |     |  |     |  |     |         |" << endl;
	    cout << "\t\t\t\t       |       |     |  |     |  |     |  |     |         |" << endl;
	    cout << "\t\t\t\t       |       |_____|  |_____|  |_____|  |_____|         |" << endl;
	    cout << "\t\t\t\t       |        _____    _____    _____    _____          |" << endl;
	    cout << "\t\t\t\t       |       |     |  |     |  |     |  |     |         |" << endl;
	    cout << "\t\t\t\t       |       |     |  |     |  |     |  |     |         |" << endl;
	    cout << "\t\t\t\t       |       |_____|  |_____|  |_____|  |_____|         |" << endl;
	    cout << "\t\t\t\t       |                                                  |" << endl;
	    cout << "\t\t\t\t       +--------------------------------------------------+" << endl;
	    cout << "\t\t\t\t       |                  ______________                  |" << endl;
	    cout << "\t\t\t\t       |                 |    Welcome   |                 |" << endl;
	    cout << "\t\t\t\t       |                 |       _      |                 |" << endl;
	    cout << "\t\t\t\t       |                 |     _| |_    |                 |" << endl;
	    cout << "\t\t\t\t       |                 |    |_   _|   |                 |" << endl;
	    cout << "\t\t\t\t       |                 |      |_|     |                 |" << endl;
	    cout << "\t\t\t\t       |                 |              |                 |" << endl;
	    cout << "\t\t\t\t       |                 |              |                 |" << endl;
	    cout << "\t\t\t\t       |                 |______________|                 |" << endl;
	    cout << "\t\t\t\t       +--------------------------------------------------+" << endl;
	    cout << "\n\n\n";
		    
		    Sleep(5000);
		    system("cls");
	        cout<<"\n\n\n";
	        cout << "\t\t\t***********************************************************************************" << endl;
		    cout << "\t\t\t**===============================================================================**" << endl;
		    cout << "\t\t\t**|                                                                             |**" << endl;
		    cout << "\t\t\t**|                                                                             |**" << endl;
		    cout << "\t\t\t**|                                                                             |**" << endl;
		    cout << "\t\t\t**|                                                                             |**" << endl;
		    cout << "\t\t\t**|                         Hospital MANAGEMENT SYSTEM                          |**" << endl;
		    cout << "\t\t\t**|                                                                             |**" << endl;
		    cout << "\t\t\t**|                                                                             |**" << endl;
		    cout << "\t\t\t**|                                                                             |**" << endl;
		    cout << "\t\t\t**|                                                                             |**" << endl;
		    cout << "\t\t\t**===============================================================================**" << endl;
		    cout << "\t\t\t***********************************************************************************" << endl;
		    cout << "\n";
		    Sleep(5000);
		    system("cls");
	       Admin a;
	       Roomadmin ro;
		   Nurse n;
		   Doctor d;
		   receptionist r; 
		    while(true)
		    {
		    	p:
	           cout << "\n";
			    cout << "\n\t\t *************************************************************************" << endl;
			    cout << "\t\t ||\t\t\t              MENU"
			         << "\t\t\t\t|| " << endl;
			    cout << "\t\t ||_____________________________________________________________________||" << endl;
			    cout << "\t\t ||                                                                     ||" << endl;
			    cout << "\t\t || 1- Admin login                " << setw(34) << left << "" << "\t||" << endl;
			    cout << "\t\t || 2- Nurse login                " << setw(34) << left << "" << "\t||" << endl;
			    cout << "\t\t || 3- Doctor login               " << setw(34) << left << "" << "\t||" << endl;
			    cout << "\t\t || 4- Receptionist Login         " << setw(34) << left << "" << "\t||" << endl;
			    cout << "\t\t || 5- Room admin login           " << setw(34) << left << "" << "\t||" << endl;
			    cout << "\t\t ||    ENTER YOUR CHOICE          " << setw(34) << left << "" << "\t||" << endl;
			    cout << "\t\t ||                                                                     ||";
			    cout << "\n\t\t *************************************************************************" << endl;
			    cout << "\n";
	           char ch;
	           ch=getch();
	           switch(ch)
	           {
	           	    case '1':
	           	    	system("cls");
	           	    	a.adminlogin();
	           	    	break;
	           	    case '2':
	           	    	system("cls");
	           	    	n.Nurselogin();
	           	    	break;
	           	    case '3':
	           	    	system("cls");
	           	    	d.Doctorlogin();
	           	        break;
	           	    case '4':
	           	    	system("cls");
	           	    	r.receptionistlogin();
	           	        break;
					case '5':
						system("cls");
						ro.roomadminlogin();
						default:
							cout<<"Enter a valid choice....";
							Sleep(2000);
							system("cls");
							goto p;
	           	    	
	           		
			   }
		}
}
