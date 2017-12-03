#include<iostream>
#include<cstdio>
using namespace std;
void encode(string s,int m,int n,int c,char res[])
{
   
	char d[m][n];
   		int pos=0,l=0;
    	 if(c==1)
		{
           for(int i=0;i<m;i++)
   			{
     			for(int j=0;j<n;j++)
      			d[i][j]= s.at(pos++);

   			}  
       
          for(int i=0;i<n;i++)
             for(int j=0;j<m;j++)
             {
                res[l++]= d[j][i];

             }
        }
        else{
              for(int i=0;i<n;i++)
   			{
     			for(int j=0;j<m;j++)
      			d[j][i]= s.at(pos++);

   			}  
           
          for(int i=0;i<m;i++)
          {
             for(int j=0;j<n;j++)
             {
                res[l++]= d[i][j];

             }
             }
        	}
            res[l]='\0';
 		 cout<<"\nencoded string:"<<res;
       
}

void decode(string s,int m,int n,int c,char res[])
{
   
	char d[m][n];
   		int pos=0,l=0;
    	 if(c==2)
		{
           for(int i=0;i<m;i++)
   			{
     			for(int j=0;j<n;j++)
      			d[i][j]= s.at(pos++);

   			}  
       
          for(int i=0;i<n;i++)
             for(int j=0;j<m;j++)
             {
                res[l++]= d[j][i];

             }
        }
        else{
              for(int i=0;i<n;i++)
   			{
     			for(int j=0;j<m;j++)
      			d[j][i]= s.at(pos++);

   			}  
       
          for(int i=0;i<m;i++)
             for(int j=0;j<n;j++)
             {
                res[l++]= d[i][j];

             }
             }
        	
            res[l]='\0';
 		 cout<<"\ndecoded string:"<<res;
       
}

int main()
{
	char temp;
	int c;char ch='y';
	cout<<"Welcome to transposition encryption demonstration :\n";
	do
	{
		cout<<"press 1 for encoding a text\n";
		cout<<"press 2 for decoding a text\n";
		cout<<"input your choice";
		cin>>c;
		if(c==1)
		{
			string s; int k,choice;
 			cout<<"\nFor columnwise encryption press 1";
			cout<<"\nFor rowwise encryption press 2";
  			cin>>choice;
  			cout<<"\ninput the key: ";
  			cin>>k;
   			cout<<"input the message to be encrypted: ";
   			cin.ignore();
   			getline(cin,s);
   			int len=s.length(),row,col,de;
                col=k;
				row=len/k;
                if(len%k!=0)
				{
                row++;
					
				}
                de=col; 
            	if(len%de!=0)
		   			{
		        		for(int i=0;i<(de-(len%de));i++)
		          		s.insert(s.end(),'x');
		       			cout<<"\nappended string is: "<<s;
	       
		   			}
        len=s.length();
        char cipher_text[len];
   		encode(s,row,col,choice,cipher_text);
  
		}
     else{
	        string s; int k,choice;
 			cout<<"\nFor columnwise decryption press 1";
			cout<<"\nFor rowwise decryption press 2";
  			cin>>choice;
  			cout<<"\ninput the key: ";
  			cin>>k;
  			
   			cout<<"input the message to be decrypted: ";
   			cin.ignore();
   			getline(cin,s);
   			int len=s.length(),row,col;
            	col=k;
				row=len/k;
                if(len%k!=0)
				{
                row++;
					
				}
        len=s.length();
        char cipher_text[len];
   		decode(s,row,col,choice,cipher_text);
   		}
		cout<<"\ndo you wish to continue if yes y else n";
		cin>>ch;
	}while(ch=='y');
	cout<<"\n\n\n- by Roll no 34 Shivam Agarwal \n";
}
