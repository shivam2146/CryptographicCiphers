#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int klen=0;


void decode(char ar[],int ts,char kr[])
{
	int a=0;
	for(int i=0;ar[i]!='\0';i++)
	{
		if(a==klen)
		a=0;
		ar[i]=((ar[i]-97)+(26-(kr[a]-97)))%26+97;
		a++;
	}
	ar[ts]='\0';
	cout<<endl<<endl;
	cout<<"The PlainText was:  "<<ar<<endl;
}


void encode(char ar[],int ts,char kr[])
{
	int a=0;
	for(int i=0;ar[i]!='\0';i++)
	{
		if(a==klen)
		a=0;
		ar[i]=(((ar[i]-97)+(kr[a]-97))%26)+97;
		a++;
	}
	ar[ts]='\0';
	cout<<"The Ciphertext is:";
	cout<<ar;
	cout<<endl;
	cout<<"calling decode...";
	decode(ar,ts,kr);
}

int main()
{
	cout<<"Welcome to Vignere encryption demonstration :\n";
	string key;	
	string text;
	cout<<"Enter the key:";  
	getline(cin,key);

	klen=key.length();
	
	char kr[klen];

	int i,j;
	for(i=0;i<klen;i++)
	{
		if(isupper(key[i]))
		key[i]=tolower(key[i]);
		kr[i]=key[i];
	}
	kr[i]='\0';
	
	cout<<"Enter the text:";
	getline(cin,text);
	
	int ts=text.length();
	char ar[ts+6];

	for(int i=0;i<ts;i++)
	ar[i]=text.at(i);
	ar[ts]='\0';
	
	if(ts%klen!=0)
	{
		int temp=ts%klen;
		temp=klen-temp;
		for(i=0,j=ts;i<temp;i++)
			ar[j++]='x';
		ar[j]='\0';
		ts=j;
	 cout<<"\nthe appended plaintext is:"<<ar<<endl;
	}
	
//	for(int i=0;i<ts;i++)
//	cout<<ar[i]<<" ";
//	cout<<endl<<"the text size is:"<<ts;
//	cout<<endl;
	
	encode(ar,ts,kr);
	cout<<"\n\n\n- by Roll no 34 Shivam Agarwal \n";
	return 0;
}

 
