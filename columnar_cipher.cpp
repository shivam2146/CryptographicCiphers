#include<iostream>
#include<cstdio>
using namespace std;
int const maxi=100;
void assign_order(int order[],string s)
{ 
  int n= s.length(),last_assgn,temp;
  order[0]=1;
  last_assgn=1;
  for(int i=1;i<n;i++)
  {
     order[i]=++last_assgn;
     for(int j=i-1;j>=0;j--)
     {
        if(s[i]<s[j])
        {
           order[i]--;
 		   order[j]++;
        }
     }
   }
//    for(int k=0;k<n;k++)
//    cout<<order[k]<<"   ";
}

void encode(char d[][maxi],int row,int col,char res[],int order[])
{
	int res_in=0;
  for(int i=1;i<=col;i++)
   {
       for(int j=0;j<col;j++)
        {
        	if(order[j]==i)
        	   {
        	   	for(int k=0;k<row;k++)
        	   	{
				   res[res_in++]=d[k][j];
				}
				   
			   }
		}
   }
   res[res_in]='\0';
   cout<<"\nencoded text is : "<<res<<endl;
}
void decode(string s,int row,int col,int order[])
{
	char res[row][col];
	int pos=0;
	for(int i=1;i<=col;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(order[j]==i)
			{
				for(int k=0;k<row;k++)
				{
					res[k][j]=s.at(pos++);
				}
			}
		}
	}
	cout<<"\ndecoded text:";
	for(int m=0;m<row;m++)
	{
		for(int n=0;n<col;n++)
		cout<<res[m][n];
	}
}

int main()
{
	char temp;
	int c;char ch='y';
	cout<<"Welcome to Columnar encryption demonstration :\n";
	do
	{
		cout<<"press 1 for encoding a text\n";
		cout<<"press 2 for decoding a text\n";
		cout<<"input your choice";
		cin>>c;
		if(c==1)
		{
			string k,s;
  			INPUT:
  			cout<<"\ninput the key word: ";
  			cin>>k;
  			int n=k.length();
  			for(int i=0;i<n;i++)
  			{
     			temp=k.at(i);
     			for(int j=i+1;j<n;j++)
     			{
        			 if(temp==k.at(j))
        			 {
   		    			cout<<"\nenter a key word with different letters";
  						goto INPUT; 
        			 }
      
     			 }
   			  }
   
   			cout<<"input the message to be encrypted: ";
   			cin.ignore();
   			getline(cin,s);
   			int order[n];
   			assign_order(order,k);
   			int len=s.length(),rem=len%n;
   			if(rem!=0)
   			{
        		for(int i=0;i<(n-rem);i++)
          		s.insert(s.end(),'x');
       			cout<<"\nappended string is: "<<s;
       
   			}
   		len=s.length();
   		int row=len/n;
   		char d[row][maxi],cipher_text[len];
   		int pos=0;
    	for(int i=0;i<row;i++)
   		{
     		for(int j=0;j<n;j++)
      		d[i][j]= s.at(pos++);

   		}  
   		cout<<endl;
		// for(int i=0;i<row;i++)
		//   {
		//     for(int j=0;j<n;j++)
		//     cout<<d[i][j]<<" ";
		//      cout<<endl;   
		//   }
   		encode(d,row,n,cipher_text,order);
      
  
		}else{
	
   		
   		string s1,k1;
   		cin.ignore();
   		INPUT1:
   		cout<<"\nenter the key word for decoding: ";
   		getline(cin,k1);
   		int n1=k1.length();
  		for(int i=0;i<n1;i++)
  		{
    	 temp=k1.at(i);
    	 for(int j=i+1;j<n1;j++)
    	 {
         if(temp==k1.at(j))
         {
   		    cout<<"\nenter a key word with different letters";
  			goto INPUT1; 
         }
      
     	 }
   		}
   		cout<<"\nenter the text to be decrypted: ";
   		getline(cin,s1);
   		int order1[n1];
   		assign_order(order1,k1);
   
   		decode(s1,s1.length()/k1.length(),n1,order1);
		}
		cout<<"\ndo you wish to continue if yes y else n";
		cin>>ch;
	}while(ch=='y');
	cout<<"\n\n\n- by Roll no 34 Shivam Agarwal \n";
}
