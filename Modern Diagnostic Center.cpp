#include<fstream.h>
#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
struct date
{
int dt;
int month;
int year;
};
class doctor
{
private:
char name[20];
char title[100][50];
int gender;
date dob;
char qual[20];
long int lis;
long int centerid;
char address[50];
char contno[15];
char eid[50];
public:
void getdata()
{
cout<<"\nDoctor's name: ";
gets(name);
cout<<"Specialisation: ";
gets(title[0]);
cout<<"GENDER"
<<"\n1.male"
<<"\n2.female"
<<"\n3.others"
<<"\nenter the choice: ";
cin>>gender;
cout<<"Date Of Birth DATE: ";
cin>>dob.dt;
cout<<"  MONTH: ";
cin>>dob.month;
cout<<"  YEAR: ";
cin>>dob.year;
cout<<"Qualification: ";
gets(qual);
cout<<"Medical license number: ";
cin>>lis;
cout<<"Center ID: ";
cin>>centerid;
cout<<"Address: ";
gets(address);
cout<<"Contact Number: ";
gets(contno);
cout<<"Email Id: ";
gets(eid);
}
void addtitle(int &j)
{
++j;
cout<<"Add New Specifcation: ";
gets(title[j]);
cout<<"Title added!";
getch();
};
void showdata(int &ik)
{
cout<<"\nDoctor's Name: "<<name;
if(gender==1)
{
cout<<"\nGender: MALE";
}
else if(gender==2)
{
cout<<"\nGender: FEMALE";
}
else
{
cout<<"\nGender: OTHERS";
}
cout<<"\nSpecification: ";
for(int o=0;o<ik;o++)
{
cout<<o+1<<". "<<title[o]<<".";
}

cout<<"\nDate Of Birth: "<<dob.dt<<"/"<<dob.month<<"/"<<dob.year;
cout<<"\nQualification: "<<qual;
cout<<"\nMedical license number: "<<lis;
cout<<"\nCenter ID: "<<centerid;
cout<<"\nAddress: "<<address;
cout<<"\nContact number: "<<contno;
cout<<"\nEmail ID: "<<eid;


}
long int retlis()
{
return lis;
}
int retname(char* nm)
{
if(strcmpi(nm,name)==0)
{
return 1;
}
else
{
return 0;
}
}
}d;
class patient
{
private:
long int regno;
date regdate;
char name1[30];
int gender1;
date dob1;
char address1[50];
char contno1;
char refed[50];
date tstdate;
char tsttype[50][20];
char docname[50];
long int fees;
public:
void getdata1()
{
cout<<"Name: ";
gets(name1);
cout<<"Registration number: ";
cin>>regno;
cout<<"GENDER"
<<"\n1.male"
<<"\n2.female"
<<"\n3.others"
<<"\nenter the choice: ";
cin>>gender1;
cout<<"Date Of Birth     DATE: ";
cin>>dob1.dt;
cout<<"    MONTH: ";
cin>>dob1.month;
cout<<"    YEAR: ";
cin>>dob1.year;
cout<<"Address: ";
gets(address1);
cout<<"Contact Number: ";
gets(contno1);
cout<<"Hospital Reffered by: ";
gets(refed);
cout<<"test Date     DATE: ";
cin>>tstdate.dt;
cout<<"    MONTH: ";
cin>>tstdate.month;
cout<<"    YEAR: ";
cin>>tstdate.year;
cout<<"Test type: ";
gets(tsttype[0]);
cout<<"Doctor's name: ";
gets(docname);
cout<<"Fees: ";
cin>>fees;
}
void showdata1(int &jk)
{
cout<<"\nName: "<<name1
<<"\nRegistration number: "<<regno;
if(gender1==1)
{
cout<<"\nGender: MALE";
}
else if(gender1==2)
{
cout<<"\nGender: FEMALE";
}
else
{
cout<<"\nGender: OTHERS";
}
cout<<"\nDate Of Birth     DATE: ";
cout<<dob1.dt;
cout<<"    MONTH: ";
cout<<dob1.month;
cout<<"    YEAR: ";
cout<<dob1.year;
cout<<"\nAddress: ";
puts(address1);
cout<<"\nContact Number: ";
cout<<contno1;
cout<<"\nHospital Reffered by";
puts(refed);
cout<<"\ntest Date     DATE: ";
cout<<tstdate.dt;
cout<<"    MONTH: ";
cout<<tstdate.month;
cout<<"    YEAR: ";
cout<<tstdate.year;
cout<<"\nTest type: ";
for(int o=0;o<=jk;o++)
{
cout<<o+1<<"."<<tsttype[o];
}
cout<<"\nDoctor's name: "<<docname;
cout<<"\nFees: "<<fees;
getch();
}

int retnreg(int t)
{
if(t==regno)
{
return 1;
}
else
{
return 0;
}
}
void addtests(int &jk)
{
jk++;
cout<<"Enter the New Test: ";
gets(tsttype[jk]);
}
int retname1(char *nme)
{
if(strcmpi(nme,name1)==0)
{
return 1;
}
else
{
return 0;
}
}
}p;
fstream f1;
fstream f2;
void main()
{
while(1)
{
clrscr();
int z=20;
int ch;
int ui=1;
int mn=1;
char *password;
cout<<"\n\t\tMAIN MENU"
<<"\n\t1.Administrative Officer"
<<"\n\t2.Doctor"
<<"\n\t3.Exit"
<<"\n\t\tChoice: ";
cin>>ch;
int k;
char user[50];
switch(ch)
{
case 1:
cout<<"USERNAME: ";
gets(user);
password=getpass("Input the password: ");
if(strcmpi(password,"admin")==0)
{
k=10;
while(k!=3)
{
clrscr();
cout<<"\n\t\tSUB MENU"
<<"\n\t1.Doctor's Access"
<<"\n\t2.Patient's Access"
<<"\n\t3.Exit to main menu"
<<"\n\tCHOICE: ";
cin>>k;
switch(k)
{
case 1:
while(z!=6)
{
clrscr();
cout<<"\n\t\tSub Sub Menu"
<<"\n\t1.Add a new doctor"
<<"\n\t2.Search Doctor on medical lisence"
<<"\n\t3.Search Doctor with Name"
<<"\n\t4.Add a New Title"
<<"\n\t5.Modify Doctor Details"
<<"\n\t6.Go to sub menu"
<<"\n\tChoice: ";
cin>>z;
switch(z)
{
case 1:
clrscr();
int yup;
cout<<"How many doctors do you want to enter: ";
cin>>yup;//yup==no. of doctors newly entered(temp)
f1.open("spartan.dat",ios::binary|ios::out);
for(int p=0;p<yup;p++)

{
d.getdata();
f1.write((char*)&d,sizeof(d));
}
f1.close();
break;
case 2:
long int search1;
int flag=1;
cout<<"enter the lisence no. you want to search: ";
cin>>search1;
f1.open("spartan.dat",ios::binary|ios::in);
while(f1.read((char*)&d,sizeof(d)))
{
long int w=d.retlis();
cout<<w;


if(w==search1)
{
cout<<"Found";
flag=0;
d.showdata(ui);
}
}
if(flag==1)
{
cout<<"Not Found";
}
f1.close();
getch();
break;
case 3:
char* dname;
int flag1=1;
cout<<"Enter the doctor name: ";
gets(dname);
f1.open("spartan.dat",ios::binary|ios::in);
while(f1.read((char*)&d,sizeof(d)))
{
int l=d.retname(dname);
if(l==1)
{
cout<<"Found";
d.showdata(ui);
flag1=0;
}
}
f1.close();
if(flag1==1)
{
cout<<"Not Found";
}
getch();
break;
case 4:                 int recn=0;
char zxc[20];
int flag2=1;
cout<<"doctor whose title is to added: ";
gets(zxc);
f1.open("spartan.dat",ios::binary|ios::in|ios::out);
while(f1.read((char*)&d,sizeof(d)))
{
int l=d.retname(zxc);
if(l==1)
{
flag2=0;
}
else recn++;
}
f1.close();
if(flag2==1)
{
cout<<"Doctor does not exist!";
getch();
}
else
{
f1.open("spartan.dat",ios::in|ios::binary|ios::out);
f1.seekg(recn*sizeof(d),ios::beg);
f1.read((char*)&d,sizeof(d));
d.addtitle(ui);
f1.seekg(recn*sizeof(d),ios::beg);
f1.write((char*)&d,sizeof(d));
f1.close();
}
break;
case 5: char* rnum;
int temp;
int found=0;
int recno=0;
cout<<"Enter the doctor to be modified: ";
gets(rnum);
f1.open("spartan.dat",ios::binary|ios::out|ios::in);
while(f1.read((char*)&d,sizeof(d)))
{
temp=d.retname(rnum);
if(temp==1)
{
cout<<"Name found: "<<endl;
d.showdata(mn);
getch();
found=1;
break;
}
else
recno++;
}
f1.close();
if(found==0)
{
cout<<"This name is not present.";
}
else
{
f1.open("spartan.dat",ios::in|ios::binary|ios::out);
f1.seekg(recno*sizeof(d),ios::beg);
f1.read((char*)&d,sizeof(d));
d.getdata();
f1.seekg(recno*sizeof(d),ios::beg);
f1.write((char*)&d,sizeof(d));
f1.close();
}
cout<<"Record modified";
getch();
break;
case 6:
break;
}
}
break;
case 2: int u=9;
while(u!=6)
{
clrscr();
cout<<"\n\t\tSub Sub Menu"
<<"\n\t1.Add a New Patient"
<<"\n\t2.Add More Tests"
<<"\n\t3.Modify patient details"
<<"\n\t4.Search on Resgistration number"
<<"\n\t5.Search on patient name"
<<"\n\t6.exit to sub menu"
<<"\n\t\tChoice: ";
cin>>u;
switch(u)
{
case 1:
clrscr();
int qw;//qw==(temp)no. of patients
cout<<"How many patients you want to enter: ";
cin>>qw;
f1.open("spartan1.dat",ios::binary|ios::out);
for(int pw=0;pw<qw;pw++)
{
p.getdata1();
f1.write((char*)&p,sizeof(p));
}
f1.close();
break;
case 2:
char zxc[20];
int flag2=1;
cout<<"Patient whose test is to added: ";
gets(zxc);
f1.open("spartan1.dat",ios::binary|ios::in|ios::out);
while(f1.read((char*)&p,sizeof(d)))
{
int l=p.retname1(zxc);
if(l==1)
{
p.addtests(ui);
flag2=0;
cout<<"Test added!";
}
}
f1.close();
if(flag2==1)
{
cout<<"Patient does not exist!";
}
f1.close();
getch();
break;
case 3:char* rnum;
int temp;
int found=0;
int recno=0;
cout<<"Enter the patients to be searched: ";
gets(rnum);
f1.open("spartan1.dat",ios::binary|ios::out|ios::in);
while(f1.read((char*)&p,sizeof(p)))
{
temp=p.retname1(rnum);
if(temp==1)
{
cout<<"Name found: ";
p.showdata1(mn);
getch();
found=1;
break;
}
else
recno++;
}
f1.close();
if(found==0)
{
cout<<"This name is not present.";
}
else
{
f1.open("spartan1.dat",ios::in|ios::binary|ios::out);
f1.seekg(recno*sizeof(p),ios::beg);
f1.read((char*)&p,sizeof(p));
p.getdata1();
f1.seekg(recno*sizeof(p),ios::beg);
f1.write((char*)&p,sizeof(p));
f1.close();
}
cout<<"Record modified";
getch();
break;
case 4:
long int rno;
flag2=1;
cout<<"Enter the registration number: ";
cin>>rno;
f1.open("spartan1.dat",ios::in|ios::binary);
int r=p.retnreg(rno);
while(f1.read((char*)&p,sizeof(p)))
{
if(r==1)
{
flag2=0;
cout<<"Found";
p.showdata1(mn);
}
}
f1.close();
if(flag2==1)
{
cout<<"Not found";
}
getch();
break;
case 5:
char* pname;
int flag3=1;
cout<<"Enter the patient's name";
cin>>pname;
f1.open("spartan1.dat",ios::binary|ios::in);
while(f1.read((char*)&d,sizeof(d)))
{
int l=p.retname1(pname);
if(l==1)
{
cout<<"Found";
p.showdata1(mn);
flag3=0;
}
}
f1.close();
if(flag3==1)
{
cout<<"Not Found";
}
getch();
break;
case 6:
break;
}
}
break;
case 3:
break;
}
}
}
case 2: int u=49;
char *pass;
cout<<"USERNAME: "
;
gets(user);
pass=getpass("Input the password: ");
if(strcmpi(pass,"doc123")==0)
{
while(u!=6)
{
clrscr();
cout<<"\n\t\tSub Sub Menu"
<<"\n\t1.Add a New Patient"
<<"\n\t2.Add More Tests"
<<"\n\t3.Modify patient"
<<"\n\t4.Search on Resgistration number"
<<"\n\t5.Search on patient name"
<<"\n\t6.exit to sub menu"
<<"\n\t\tChoice: ";
cin>>u;
switch(u)
{
case 1:
clrscr();
int pqw;//qw==(temp)no. of patients
cout<<"How many patients you want to enter: ";
cin>>pqw;
f1.open("spartan1.dat",ios::binary|ios::out);
for(int pqw1=0;pqw1<pqw;pqw1++)
{
p.getdata1();
f1.write((char*)&p,sizeof(p));
}
f1.close();
break;
case 2:	char zxc[20];
int flag2=1;
cout<<"Patient whose test is to added: ";
gets(zxc);
f1.open("spartan1.dat",ios::binary|ios::in|ios::out);
while(f1.read((char*)&p,sizeof(d)))
{
int l=p.retname1(zxc);
if(l==1)
{
p.addtests(ui);
flag2=0;
cout<<"Test added!";
}
}
f1.close();
if(flag2==1)
{
cout<<"Patient does not exist!";
}
f1.close();
getch();
break;
case 3:
char* rnum;
int temp;
int found=0;
int recno=0;
cout<<"Enter the patients to be searched: ";
gets(rnum);
f1.open("spartan1.dat",ios::binary|ios::in|ios::out);
while(f1.read((char*)&p,sizeof(p)))
{
temp=p.retname1(rnum);
if(temp==1)
{
cout<<"Name found: ";
p.showdata1(mn);
getch();
found=1;
break;
}
else
recno++;
}
f1.close();
if(found==0)
{
cout<<"This name is not present.";
}
else
{
f1.open("spartan1.dat",ios::in|ios::out|ios::binary);
f1.seekg(recno*sizeof(p),ios::beg);
f1.read((char*)&p,sizeof(p));
p.getdata1();
f1.seekg(recno*sizeof(p),ios::beg);
f1.write((char*)&p,sizeof(p));
f1.close();
}
cout<<"Record modified";
getch();
break;
case 4:
long int rno;
flag2=1;
cout<<"Enter the registration number: ";
cin>>rno;
f1.open("spartan1.dat",ios::in|ios::binary);
int r=p.retnreg(rno);
while(f1.read((char*)&p,sizeof(p)))
{
if(r==1)
{
flag2=0;
cout<<"Found";
p.showdata1(mn);

}
}
f1.close();
if(flag2==1)
{
cout<<"Not found";
}
getch();
break;
case 5:
char* pname;
int flag3=1;
cout<<"Enter the patient name";
cin>>pname;
f1.open("spartan1.dat",ios::binary|ios::in);
while(f1.read((char*)&d,sizeof(d)))
{
int l=p.retname1(pname);
if(l==1)
{
cout<<"Found";
p.showdata1(mn);
flag3=0;

}
}
if(flag3==1)
{
cout<<"Not Found";
}
f1.close();
getch();
break;
case 6:
break;
}
}
}
break;
case 3:
exit(0);
}
getch();
}
}
