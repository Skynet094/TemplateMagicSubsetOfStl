#include "iGraphics.h"
#include<iostream>
#include<string>
#include<cstring>
#include "Algorithm.h"
#include "Deque.h"
#include "Map.h"

using namespace project;
using namespace std;

bool sortFlag = false;
bool sortFlag2 = false;
bool sortFlag3 = false;
int inputFlag = 0;
int iterindex = 0;
char* id = new char[50];
char* name = new char[50];
char* score = new char[50];
int idindex=0;
int nameindex=0;
int scoreindex=0;
boolean flagfordot = false;
map_<int, string> NAME;
map_<int, int> SCORE;
int compareSetter=0;
string buffer1[30];
string buffer2[30];
string buffer3[30];
char* cbuffer1 = NULL;
char* cbuffer2 = NULL;
char* cbuffer3 = NULL;
int saveindex = 0;


Deque<class student>::iterator iter;

class student
{
      int student_id;
public:
      student(){student_id=0;}
	  student(const student& ob)
	  {
		  student_id = ob.student_id;
	  }
      student(int student_id, string name, int score)
      {
           this->student_id = student_id;
           NAME[student_id] = name;
           SCORE[student_id] = score;
      }
      void setStudentInfo(int student_id, string name, int score)
      {
           this->student_id = student_id;
           NAME[student_id] = name;
           SCORE[student_id] = score;
      }
      bool operator>(const class student& ob)
      {
           if(compareSetter == 0)
           {
                return student_id>ob.student_id;
           }
           else if(compareSetter == 1)
           {
                string s1 = NAME[student_id];
                string s2 = NAME[ob.student_id];
                return s1>s2;
           }
           else
           {
               int f1 = SCORE[student_id];
               int f2 = SCORE[ob.student_id];
               return f1>f2;
           }
      }
      bool operator<(const class student& ob)
      {
           if(compareSetter == 0)
           {
                return student_id<ob.student_id;
           }
           else if(compareSetter == 1)
           {
                string s1 = NAME[student_id];
                string s2 = NAME[ob.student_id];
                return s1<s2;
           }
           else
           {
               int f1 = SCORE[student_id];
               int f2 = SCORE[ob.student_id];
               return f1<f2;
           }
      }
	  bool operator==(const student& ob)
	  {
		   if(compareSetter == 0)
           {
                return student_id==ob.student_id;
           }
           else if(compareSetter == 1)
           {
                string s1 = NAME[student_id];
                string s2 = NAME[ob.student_id];
                return s1==s2;
           }
           else
           {
               int f1 = SCORE[student_id];
               int f2 = SCORE[ob.student_id];
               return f1==f2;
           }
	  }
      int getStudentId()
      {
           return student_id;
      }
	  string getStudentName()
	  {
		  return NAME[student_id];
	  }
	  int getStudentScore()
	  {
		  return SCORE[student_id];
	  }
};
Deque<class student> student_list;

/* 
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	iSetcolor(255,255,255);
	iFilledRectangle(0,0,1366,768);
	iSetcolor(0,0,0);
	iText(89,696,"Student Id: ", GLUT_BITMAP_TIMES_ROMAN_24);
	iRectangle(300,690,600,30);
	iText(300,696, id, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(89, 696-60, "Student Name: ",GLUT_BITMAP_TIMES_ROMAN_24);
	iRectangle(300, 690-60, 600, 30);
	iText(300,696-60, name, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(89, 696-120, "Score: ",GLUT_BITMAP_TIMES_ROMAN_24);
	iRectangle(300, 690-120, 600, 30);
	iText(300,696-120, score, GLUT_BITMAP_TIMES_ROMAN_24);
	iRectangle(260, 485, 350, 40);
	iText(365, 497, "Insert Data",GLUT_BITMAP_TIMES_ROMAN_24);
	iRectangle(150, 50, 600, 400);
	iLine(350, 50, 350, 450);
	iLine(550, 50, 550, 450);
	iLine(750, 50, 750, 450);
	for(int i=1;i<=10; i++)
	{
		iLine(150, 50+(i*40),750, 50+(i*40));
	}
	iText(160,420,"STUDENT ID",GLUT_BITMAP_HELVETICA_18); 
	iText(360,420,"NAME", GLUT_BITMAP_HELVETICA_18);
	iText(560,420,"SCORE", GLUT_BITMAP_HELVETICA_18);
	for(int i=0; i<saveindex; i++)
	{
		iText(160, 380-(40*i),(char*)buffer1[i].c_str(), GLUT_BITMAP_HELVETICA_18);
		iText(360, 380-(40*i),(char*)buffer2[i].c_str() , GLUT_BITMAP_HELVETICA_18);
		iText(560, 380-(40*i),(char*)buffer3[i].c_str() , GLUT_BITMAP_HELVETICA_18);
	}
}

/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		cout << "x: " << mx << " " << "y: " << my << endl;
		if((mx>=200)&&(mx<=700)&&(my>=690)&&(my<=720))
		{
			inputFlag = 1;
			cout << inputFlag << endl;
		}
		else if((mx>=200)&&(mx<=700)&&(my>=630)&&(my<=660))
		{
			inputFlag = 2;
			cout << inputFlag << endl;
		}
		else if((mx>=200)&&(mx<=700)&&(my>=570)&&(my<=600))
		{
			inputFlag = 3;
			cout << inputFlag << endl;
		}
		else if((mx>=260)&&(mx<=610)&&(my>=485)&&(my<=525))
		{
			if((name[0]!='\0')||(score[0] != '\0')||(id[0]!='\0'))
			{
				inputFlag = 0;
				int s_id = atoi(id);
				int s_score = atoi(score);
				student_list.push_back(*(new student(s_id,string(name),s_score)));
				iter = student_list.begin();
				while(iter!=student_list.end())
				{ 
					buffer1[iterindex] = to_string((*iter).data.getStudentId());
					buffer2[iterindex] = (*iter).data.getStudentName();
					buffer3[iterindex] = to_string((*iter).data.getStudentScore());
					iterindex++;
					iter++;
				}
				iterindex = 0;
				idindex = 0;
				id[0] = '\0';
				nameindex = 0;
				name[0] = '\0';
				scoreindex = 0;
				score[0] = '\0';
				saveindex++;
				cout << saveindex;
			}
		}
		else if((mx>=150)&&(mx<=350)&&(my>=410)&&(my<=450))
		{
			compareSetter = 0;
			iterindex = 0;
			if(sortFlag == false)
			{
				Sort(student_list.begin(), student_list.end());
				iter = student_list.begin();
				while(iter!=student_list.end())
				{ 
					buffer1[iterindex] = to_string((*iter).data.getStudentId());
					buffer2[iterindex] = (*iter).data.getStudentName();
					buffer3[iterindex] = to_string((*iter).data.getStudentScore());
					iterindex++;
					iter++;
				}
				sortFlag = true;
			}
			if(sortFlag == true)
			{
				Reverse(student_list.begin(), student_list.end());
				iter = student_list.begin();
				while(iter!=student_list.end())
				{ 
					buffer1[iterindex] = to_string((*iter).data.getStudentId());
					buffer2[iterindex] = (*iter).data.getStudentName();
					buffer3[iterindex] = to_string((*iter).data.getStudentScore());
					iterindex++;
					iter++;
				}
			}
		}
		else if((mx>=350)&&(mx<=550)&&(my>=410)&&(my<=450))
		{
			compareSetter = 1;
			iterindex = 0;
			if(sortFlag2 == false)
			{
				Sort(student_list.begin(), student_list.end());
				iter = student_list.begin();
				while(iter!=student_list.end())
				{ 
					buffer1[iterindex] = to_string((*iter).data.getStudentId());
					buffer2[iterindex] = (*iter).data.getStudentName();
					buffer3[iterindex] = to_string((*iter).data.getStudentScore());
					iterindex++;
					iter++;
				}
				sortFlag2 = true;
			}
			if(sortFlag2 == true)
			{
				Reverse(student_list.begin(), student_list.end());
				iter = student_list.begin();
				while(iter!=student_list.end())
				{ 
					buffer1[iterindex] = to_string((*iter).data.getStudentId());
					buffer2[iterindex] = (*iter).data.getStudentName();
					buffer3[iterindex] = to_string((*iter).data.getStudentScore());
					iterindex++;
					iter++;
				}
			}
		}
		else if((mx>=550)&&(mx<=750)&&(my>=410)&&(my<=450))
		{
			compareSetter = 2;
			iterindex = 0;
			if(sortFlag3 == false)
			{
				Sort(student_list.begin(), student_list.end());
				iter = student_list.begin();
				while(iter!=student_list.end())
				{ 
					buffer1[iterindex] = to_string((*iter).data.getStudentId());
					buffer2[iterindex] = (*iter).data.getStudentName();
					buffer3[iterindex] = to_string((*iter).data.getStudentScore());
					iterindex++;
					iter++;
				}
				sortFlag3 = true;
			}
			if(sortFlag3 == true)
			{
				Reverse(student_list.begin(), student_list.end());
				iter = student_list.begin();
				while(iter!=student_list.end())
				{ 
					buffer1[iterindex] = to_string((*iter).data.getStudentId());
					buffer2[iterindex] = (*iter).data.getStudentName();
					buffer3[iterindex] = to_string((*iter).data.getStudentScore());
					iterindex++;
					iter++;
				}
			}
		}
		else
		{
			inputFlag = 0;
		}
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.	
*/
void iKeyboard(unsigned char key)
{
	if((((key>=65)&&(key<=90))||((key>=97)&&(key<=122)))||(key==32))
	{
		if(inputFlag == 2)
		{
			name[nameindex++] = key;
			name[nameindex] = '\0';
		}
	}
	if((key>=48)&&(key<=57))
	{
		if(inputFlag == 1)
		{
			id[idindex++] = key;
			id[idindex] = '\0';
		}
		if(inputFlag == 3)
		{
			score[scoreindex++] = key;
			score[scoreindex] = '\0';
		}
	}
	if(key==8)
	{
		if(inputFlag == 1)
		{
			if(idindex>0) id[--idindex] = '\0';
		}
		if(inputFlag == 2)
		{
			if(nameindex>0) name[--nameindex] = '\0';
		}
		if(inputFlag == 3)
		{
			if(scoreindex>0) score[--scoreindex] = '\0';
		}
	}
}


int main()
{ 	
    name[0] = '\0';
	score[0] = '\0';
	id[0] = '\0';
	iInitialize(1366, 768, "demooo");
	return 0;
}	