#include<iostream>
#include<conio.h>
#include<fstream>
#include<Fl/Fl.H>
#include<FL/Fl_Window.H>
#include<FL/Fl_Button.H>
#include<FL/Fl_Box.H>
#include<FL/Fl_Scroll.H>
using namespace std;
class Helper
{
public:
	static int StringLenght(const char* str)
	{
		int Length = 0;
		for (int i = 0; str[i] != '\0'; i++)
			Length++;
		return Length;
	}
	static char* GetStringFromBuffer(const char* str)
	{
		int strLen = StringLenght(str);
		char* mystr = new char[strLen + 1];
		for (int i = 0; str[i] != '\0'; i++)
			mystr[i] = str[i];
		mystr[strLen] = '\0';
		return mystr;
	}

	static void Stringcopy(char*des, const char*source)
	{
		//des = nullptr;
		int j = 0;
		for (int i = 0; source[i] != '\0'; i++)
		{
			des[j] = source[i];
			j++;
		}
		des[j] = '\0';
	}
	static bool Stringcmp(const char*str1, const char*str2)
	{
		int j = 0;
		int cnt = 0;
		int strLen1 = StringLenght(str1);
		int strLen2 = StringLenght(str2);
		if (strLen1 != strLen2)
		{
			return false;
		}
		for (int i = 0; str2[i] != '\0'; i++)
		{
			if (str1[j] == str2[i])
			{
				cnt++;
			}
			else
			{
				return false;
			}
			j++;
		}
		if (cnt == strLen1)
		{
			return true;
		}
		return false;
	}
	static bool Stringcmp1(char*str1, const char*str2)
	{
		int j = 0;
		int cnt = 0;
		int strLen1 = StringLenght(str1);
		int strLen2 = StringLenght(str2);

		if (strLen1 == 4 || strLen1 == 6)
		{
			if (strLen1 != strLen2 + 2)
			{
				return false;
			}
			for (int i = 1; i < strLen1 - 1; i++)
			{
				if (str1[i] == str2[j])
				{
					cnt++;
				}
				else
				{
					return false;
				}
				j++;
			}
			if (cnt == strLen1 - 2)
			{
				return true;
			}
		}
		if (strLen1 == 13)
		{
			for (int i = 1; i < strLen2 + 1; i++)
			{
				if (i == 5)
				{
					cnt++;
				}
				else
				{
					if (str1[i] == str2[j])
					{
						cnt++;
					}
					else
					{
						return false;
					}
				}
				j++;
			}
			if (cnt == strLen1 - 8)
			{
				return true;
			}
		}
		return false;
	}
	static void chartoint(char ary[5], int val1, int val2)
	{
		int rem = 0;
		int val = val1;
		if (val1 <= 9)
		{
			ary[0] = val1 + 48;
		}
		if (val1 >= 10)
		{
			rem = val1 % 10;
			ary[1] = rem + 48;
			val1 = val1 / 10;
			rem = val1;
			ary[0] = rem + 48;
		}
		/*	if (val <= 9)
			{*/
		if (val <= 9 && val2 <= 9)
		{
			ary[1] = ':';
			ary[2] = val2 + 48;
			ary[3] = '\0';
		}
		if (val >= 10 && val2 <= 9)
		{
			ary[2] = ':';
			ary[3] = val2 + 48;
			ary[4] = '\0';
		}
		//}
		//else
		//{
		if (val <= 9 && val2 >= 10)
		{
			ary[1] = ':';
			rem = val2 % 10;
			ary[3] = rem + 48;
			val2 = val2 / 10;
			rem = val2;
			ary[2] = rem + 48;
			ary[4] = '\0';
		}
		if (val >= 10 && val2 >= 10)
		{
			ary[2] = ':';
			rem = val2 % 10;
			ary[4] = rem + 48;
			val2 = val2 / 10;
			rem = val2;
			ary[3] = rem + 48;
			ary[5] = '\0';
		}
		//}
	}
	static void concatinationstrings(char ary1[20], char ary2[20])
	{
		int len1 = StringLenght(ary1);
		int len2 = StringLenght(ary2);
		int j = len1;
		if (ary1[j - 2] == ':')
		{
			ary1[j] = '0';
			j++;
		}
		ary1[j] = '-';
		j++;
		for (int i = 0; i < len2; i++)
		{
			ary1[j] = ary2[i];
			j++;
		}
		if (ary1[j - 2] == ':')
		{
			ary1[j] = '0';
			j++;
		}
		ary1[j] = '\0';
	}
};
struct Time
{
	int hours;
	int mints;

};

struct time_node
{
	Time start_time;
	Time end_time;

};
void incrementtime(Time&t1)
{
	t1.hours = t1.hours + 1;
	if (t1.hours == 13)
	{
		t1.hours = t1.hours % 12;
	}
	t1.mints = t1.mints + 30;
	if (t1.mints == 60)
	{
		t1.mints = t1.mints % 60;
		t1.hours = t1.hours + 1;
		if (t1.hours == 13)
		{
			t1.hours = t1.hours % 12;
		}
	}

}
struct classlist
{
	int countstudents;
	char names[60][15]; //60 students in class, first name only.
	char rollNo[60][10];
	classlist()
	{
		countstudents = 0;
	}
};
class subject_node
{
public:
	classlist*students;
	char subject_name[100];
	char section_name[20];
	char room_no[20];
	time_node timeslots;
	subject_node*next;
	subject_node()
	{
		students = nullptr;
	}
};
struct node
{
	subject_node*subject;
	char day[20];
	node()
	{
		subject = nullptr;
	}
};
struct subsec
{
	int cntstd;
	char stion[10][10];
	char bokname[10][40];
	subsec()
	{
		cntstd = 0;
	}
};
struct node1
{
	subsec *ptr1;
	char rolnum[10];
	node1*next1;
	node1()
	{
		ptr1 = nullptr;
	}
};
void button1(Fl_Widget* o, void* ab)
{

	Fl_Window window(2000, 2000, "Window title");
	Fl_Scroll scroll(0, 0, 1500, 1000);
	classlist* studentlist = new classlist;
	studentlist = static_cast<classlist*>(ab);
	int Width = 200, Height = 40;
	int X = 0, Y = 0;
	if (studentlist != NULL)
		for (int i = 0; i <studentlist->countstudents; i++)
		{
			Fl_Button *Roll_No = new Fl_Button(X, Y, Width, Height, studentlist->rollNo[i]);
			Y = Y + 50;
		}
	window.end();
	window.show();
	Fl::run();
}
ostream& operator<<(ostream& out, const Time& rhs)
{
	cout << "  ";
	out << rhs.hours << " : ";
	if (rhs.mints == 0)
		out << " 00 " << " ";
	else
		out << rhs.mints;
	return out;
}
ostream& operator<<(ostream& out, const node& rhs)
{
	out << " " << rhs.day;
	return out;
}

class TTADT
{
	node * days;
	node1*nptr;
	int sizee = 2;
public:
	TTADT()
	{
		days = new node[5];
	}
	friend ostream& operator<<(ostream& out, const node& rhs);
	friend ostream& operator<<(ostream& out, const Time& rhs);
	void load(const char filename[])
	{
		ifstream fin;
		fin.open(filename);
		char buffer[100];
		char buffer1[100];
		int count = 7;
		int cnt = 0;
		int cnt1 = 0;
		Time temp1;
		if (fin.is_open())
		{
			for (int i = 0; i < 5; i++)
			{
				fin >> buffer;
				Helper::Stringcopy(days[i].day, buffer);
				count = 7;
				for (int j = 0; j < 26; j++)
				{
					fin >> buffer1;
					temp1.hours = 8;
					temp1.mints = 0;
					for (int k = 0; k < count; k++)
					{
						subject_node *temp = new subject_node;
						Helper::Stringcopy(temp->room_no, buffer1);
						fin >> buffer;
						if (Helper::Stringcmp(buffer, "null") == true)
						{
							Helper::Stringcopy(temp->subject_name, "null");
							Helper::Stringcopy(temp->section_name, "null");
						}
						else
						{
							Helper::Stringcopy(temp->subject_name, buffer);
							fin >> buffer;
							Helper::Stringcopy(temp->section_name, buffer);
						}
						if (k == 0)
						{
							temp->timeslots.end_time.hours = temp1.hours;
							temp->timeslots.end_time.mints = temp1.mints;
							temp->timeslots.start_time.hours = temp1.hours;
							temp->timeslots.start_time.mints = temp1.mints;
						}
						temp->timeslots.start_time = temp1;
						incrementtime(temp1);
						if (k == 6 || j >= 19)
						{
							incrementtime(temp1);
							temp->timeslots.end_time = temp1;
						}
						else
						{
							temp->timeslots.end_time = temp1;
						}

						temp->next = nullptr;
						if (days[i].subject == nullptr)
						{
							days[i].subject = temp;
						}
						else
						{
							subject_node* curr = days[i].subject;
							while (curr->next != nullptr)
							{
								curr = curr->next;
							}
							curr->next = temp;
						}
						if (j >= 19)
						{
							count = 4;
						}
					}
				}
			}
		}
	}
	void loadStudentInfo(const char filename[])
	{
		bool flag = 1;
		ifstream fin;
		fin.open(filename);
		if (fin.is_open())
		{
			char rn[10], name[5], sec[50], regc[100];
			while (!fin.eof())
			{
				flag = 1;
				fin >> rn;
				fin >> name;

				fin >> regc;
				fin >> sec;

				for (int j = 0; j < 5; j++)
				{
					int cnt = 0;
					subject_node*curr = days[j].subject;
					while (curr != 0)
					{
						if (Helper::Stringcmp(curr->subject_name, regc) == true && Helper::Stringcmp1(curr->section_name, sec) == true)
						{
							if (curr->students == nullptr)
							{
								curr->students = new classlist;
								int k = j + 2;
								if (k < 5)
								{
									int cnt1 = cnt;
									subject_node*newcurr = days[k].subject;
									while (cnt1 != 0 && newcurr != 0)
									{
										cnt1--;
										newcurr = newcurr->next;
									}
									if (Helper::Stringcmp(curr->subject_name, newcurr->subject_name) == true && Helper::Stringcmp(curr->section_name, newcurr->section_name) == true)
									{
										newcurr->students = new classlist;
										newcurr->students = curr->students;
									}
									else
									{
										while (k < 5)
										{
											subject_node*newcurr1 = days[k].subject;
											while (newcurr1 != 0)
											{
												if (Helper::Stringcmp(curr->subject_name, newcurr1->subject_name) == true && Helper::Stringcmp(curr->section_name, newcurr1->section_name) == true)
												{
													newcurr1->students = new classlist;
													newcurr1->students = curr->students;
													break;
												}
												newcurr1 = newcurr1->next;
											}
											k++;
										}
									}
								}
							}
							if (curr->students->countstudents < 60)
							{
								Helper::Stringcopy(curr->students->rollNo[curr->students->countstudents], rn);
								Helper::Stringcopy(curr->students->names[curr->students->countstudents], name);
								curr->students->countstudents++;
								flag = 0;
								break;
							}
						}
						curr = curr->next;
						cnt++;
					}
					if (flag == 0)
					{
						break;
					}
				}
			}
		}
	}
	void printStudentTimeTable(const char rollno[])
	{
		char*ptr = nullptr;
		bool flag = 0;
		int cnt = 0, p = 0;
		char ary[20][100];
		for (int j = 0; j < 5; j++)
		{
			cnt = 0;
			flag = 0;
			subject_node*curr1 = days[j].subject;
			while (curr1 != 0)
			{
				if (curr1->students != nullptr)
				{
					int cntt = curr1->students->countstudents;
					while (cntt != 0)
					{
						if (Helper::Stringcmp(curr1->students->rollNo[cntt - 1], rollno) == true)
						{
							Helper::Stringcopy(ary[p], curr1->subject_name);
							p++;
							int m = 0, n = 0;
							while (m != p)
							{
								if (Helper::Stringcmp(ary[m], curr1->subject_name) == true)
								{
									n++;
								}
								m++;
							}
							if (n != 2)
							{
								cout << curr1->subject_name;
								cout << curr1->section_name;
								cout << endl;
								cout << days[j];
								cout << curr1->timeslots.start_time;
								cout << curr1->timeslots.end_time;
								cout << " ";
								cout << curr1->room_no;
								flag = 1;
								if (flag == 1)
								{
									int k = j + 2;
									if (k < 5)
									{
										subject_node*curr2 = days[k].subject;
										int cnt1 = cnt;
										while (cnt1 != 0 && curr2 != 0)
										{
											curr2 = curr2->next;
											cnt1--;
										}
										cout << "||";

										if (Helper::Stringcmp(curr2->subject_name, curr1->subject_name) == true && Helper::Stringcmp(curr2->section_name, curr1->section_name) == true)
										{
											cout << days[k];
											cout << curr2->timeslots.start_time;
											cout << curr2->timeslots.end_time;
											cout << " ";
											cout << curr2->room_no;
											cout << endl;
											break;
										}
										else
										{
											while (k < 5)
											{
												bool nflag = 1;
												subject_node*newcurr1 = days[k].subject;
												while (newcurr1 != 0)
												{
													if (Helper::Stringcmp(curr2->subject_name, newcurr1->subject_name) == true && Helper::Stringcmp(curr2->section_name, newcurr1->section_name) == true)
													{
														cout << days[k];
														cout << curr2->timeslots.start_time;
														cout << curr2->timeslots.end_time;
														cout << " ";
														cout << curr2->room_no;
														nflag = 0;
														break;
													}
													newcurr1 = newcurr1->next;
												}
												if (nflag == 0)
												{
													break;
												}
												k++;
											}
										}
									}
									cout << endl;
								}
							}
						}
						cntt--;
					}
				}
				curr1 = curr1->next;
				cnt++;
			}
		}
	}

	void printCourseTimings(const char coursename[], const char section[])
	{
		for (int i = 0; i < 5; i++)
		{
			bool flag = 0;
			int cnt = 0;
			subject_node*curr1 = days[i].subject;
			while (curr1 != 0)
			{
				if (Helper::Stringcmp(curr1->subject_name, coursename) == true && Helper::Stringcmp1(curr1->section_name, section) == true)
				{
					cout << days[i];
					cout << curr1->timeslots.start_time;
					cout << curr1->timeslots.end_time;
					cout << endl;
					int k = i + 2;
					if (k < 5)
					{
						subject_node*curr2 = days[k].subject;
						while (cnt != 0 && curr2 != 0)
						{
							curr2 = curr2->next;
							cnt--;
						}
						if (Helper::Stringcmp(curr2->subject_name, coursename) == true && Helper::Stringcmp1(curr2->section_name, section) == true)
						{
							cout << days[k];
							cout << curr2->timeslots.start_time;
							cout << curr2->timeslots.end_time;
							cout << endl;
							flag = 1;
							break;
						}
						else
						{
							while (k < 5)
							{
								subject_node*curr3 = days[k].subject;
								while (curr3 != 0)
								{
									if (Helper::Stringcmp(curr3->subject_name, coursename) == true && Helper::Stringcmp1(curr1->section_name, section) == true)
									{
										cout << days[k];
										cout << curr3->timeslots.start_time;
										cout << curr3->timeslots.end_time;
										cout << endl;
										flag = 1;
										break;
									}
								}
								k++;
							}
						}
					}
				}
				curr1 = curr1->next;
				cnt++;
				if (flag == 1)
				{
					break;
				}
			}
			if (flag == 1)
			{
				break;
			}
		}
	}

	void printCourse(const char cday[], const char ctime[], const char cclassroom[])
	{
		for (int i = 0; i < 5; i++)
		{
			if (Helper::Stringcmp(days[i].day, cday) == true)
			{
				subject_node *curr = days[i].subject;
				while (curr != 0)
				{
					if (Helper::Stringcmp(curr->room_no, cclassroom) == true)
					{
						char ary[5];
						Helper::chartoint(ary, curr->timeslots.start_time.hours, curr->timeslots.start_time.mints);
						if (Helper::Stringcmp(ary, ctime) == true)
						{
							cout << curr->subject_name;
							cout << " ";
							cout << curr->section_name;
							break;
						}
					}
					curr = curr->next;
				}
			}
		}
	}

	void storecourseofstudents(const char filename[])
	{
		bool flag = 1;
		ifstream fin;
		fin.open(filename);
		if (fin.is_open())
		{
			char rn1[10], name1[5], sec1[50], regc1[100];
			while (!fin.eof())
			{
				fin >> rn1;
				fin >> name1;
				fin >> regc1;
				fin >> sec1;
				if (flag == 0)
				{
					node1 *newptr = nptr;
					int cnt = 1;
					while (newptr != 0)
					{
						if (Helper::Stringcmp(newptr->rolnum, rn1) == true)
						{
							Helper::Stringcopy(newptr->ptr1->bokname[newptr->ptr1->cntstd], regc1);
							Helper::Stringcopy(newptr->ptr1->stion[newptr->ptr1->cntstd], sec1);
							newptr->ptr1->cntstd++;
							cnt = 0;
						}
						newptr = newptr->next1;
					}
					if (cnt == 1)
					{
						flag = 1;
					}
				}
				if (flag == 1)
				{
					node1 *newtemp = new node1;
					Helper::Stringcopy(newtemp->rolnum, rn1);
					if (newtemp->ptr1 == nullptr)
					{
						newtemp->ptr1 = new subsec;
						Helper::Stringcopy(newtemp->ptr1->bokname[newtemp->ptr1->cntstd], regc1);
						Helper::Stringcopy(newtemp->ptr1->stion[newtemp->ptr1->cntstd], sec1);
						newtemp->ptr1->cntstd++;
					}
					newtemp->next1 = nullptr;
					if (nptr == nullptr)
					{
						nptr = newtemp;
					}
					else
					{
						node1 *ncurr = nptr;
						while (ncurr->next1 != nullptr)
						{
							ncurr = ncurr->next1;
						}
						ncurr->next1 = newtemp;
					}
					flag = 0;
				}
			}
		}
	}

	void printtimetable()
	{
		int X = 0, Y = 0;
		int Width = 200, Height = 40;
		
		Fl_Window window(8000, 9000, "Window title");
		Fl_Scroll scroll(0, 0, 1500, 1000);
		//cout << curr1->day << endl;
		for (int k = 0; k < 5; k++)
		{
			subject_node*curr1 = days[k].subject;
			Fl_Button *DAY = new Fl_Button(X, Y, Width, Height, days[k].day);
		
			Y = Y + 50;
			X = 100;
			

			//cout << curr->ClassRoom << " " << curr->coursename << " " << curr->section << " " << " " << " " << curr->timeofclass << endl;




			for (int j = 0; j < 26; j++)
			{
				Fl_Button *ClassRoom = new Fl_Button(X, Y, Width, Height, curr1->room_no);


				for (int i = 0; i < 8; i++)
				{
					X = X + 200;
					Fl_Button *CourseName = new Fl_Button(X, Y, Width, Height, curr1->subject_name);
					CourseName->callback(button1, (classlist*)curr1->students);
					
					if (curr1->next != nullptr)
						curr1 = curr1->next;
				}
				Y = Y + 50;
				X = 100;
			}

			X = 0;
			if (curr1->next != nullptr)
				curr1 = curr1->next;

		}

		window.end();
		window.show();
		Fl::run();
	}
	void saveClashes()
	{
		ofstream fout;
		fout.open("clash.txt");
		node1 *newptr = nptr;
		while (newptr != 0)
		{
			bool flag = 1;
			int cntsub = 0;
			char ary3[20];
			char ary1[8][20];
			char ary2[8][20];
			char ary4[8][20];
			char ary5[8][30];
			int cntp = newptr->ptr1->cntstd;
			int count1 = cntp;
			int newcnt = cntp;
			while (cntp != 0)
			{
				flag = 1;
				for (int i = 0; i < 5; i++)
				{
					subject_node* curr = days[i].subject;
					while (curr != 0)
					{
						newptr->ptr1->bokname[cntp - 1];
						newptr->ptr1->stion[cntp - 1];
						if (Helper::Stringcmp(curr->subject_name, newptr->ptr1->bokname[cntp - 1]) == true)
						{
							if (Helper::Stringcmp1(curr->section_name, newptr->ptr1->stion[cntp - 1]) == true)
							{
								Helper::Stringcopy(ary5[cntsub], newptr->ptr1->bokname[cntp - 1]);
								Helper::Stringcopy(ary4[cntsub], newptr->ptr1->stion[cntp - 1]);
								curr->timeslots.start_time.hours;
								curr->timeslots.start_time.mints;
								Helper::chartoint(ary3, curr->timeslots.start_time.hours, curr->timeslots.start_time.mints);
								Helper::Stringcopy(ary1[cntsub], ary3);
								curr->timeslots.end_time.hours;
								curr->timeslots.end_time.mints;
								Helper::chartoint(ary3, curr->timeslots.end_time.hours, curr->timeslots.end_time.mints);
								Helper::concatinationstrings(ary1[cntsub], ary3);
								Helper::Stringcopy(ary2[cntsub], days[i].day);
								cntsub++;
								flag = 0;
								break;
							}
						}
						curr = curr->next;
					}
					if (flag == 0)
					{
						break;
					}
				}
				cntp--;
			}
			for (int m = 0; m < count1; m++)
			{
				for (int n = m; n < count1; n++)
				{
					if (m != n)
					{
						if (Helper::Stringcmp(ary2[m], ary2[n]) == true)
						{
							if (Helper::Stringcmp(ary1[m], ary1[n]) == true)
							{
								if (Helper::Stringcmp(ary5[m], ary5[n]) != true)
								{
									fout << newptr->rolnum << " " << "Ali" << " " << ary5[m] << " " << ary4[m] << " ";
									fout << ary5[n] << " " << ary4[n] << " " << ary1[m] << " " << ary2[m];
									fout << endl;
								}
							}
						}
					}
				}
			}
			newptr = newptr->next1;
		}
	}
	~TTADT()
	{
		for (int i = 0; i < 5; i++)
		{
			int k = 0;
			subject_node* curr = days[i].subject;
			subject_node* front = nullptr;
			while (curr != 0)
			{
				front = curr;
				curr = curr->next;
				k++;
				delete front;
			}
		}
		delete[] days;
		node1* curr1 = nptr;
		node1* front1 = nullptr;
		while (curr1 != nullptr)
		{
			front1 = curr1;
			curr1 = curr1->next1;
			if (front1->ptr1 != nullptr)
			{
				delete front1->ptr1;
			}
			delete front1;
		}
	}
};

int main()
{
	system("color 8b");

	TTADT in;
	in.load("CStimetable1.txt");
	in.loadStudentInfo("Registrationdata.txt");
	cout << "TimeTable :" << endl;
	in.printStudentTimeTable("34");
	cout << "CourseTiming :" << endl;
	in.printCourseTimings("AdvancedProgramming", "CS");
	cout << "PrintCourse :" << endl;
	in.printCourse("Monday", "8:0", "CS-3");
	in.storecourseofstudents("Registrationdata.txt");
	in.saveClashes();
	cout << endl;
	in.printtimetable();
	_getch();
}