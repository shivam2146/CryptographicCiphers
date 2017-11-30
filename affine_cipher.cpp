#include<iostream>
#include<cstdio>

using namespace std;
char encode(char ch,int k)
{
    char c= (((ch-97)*k)%26)+97;
    return c;
}
char encode_add(char ch,int k)
{
    char c= ((ch-97+k)%26)+97;
    return c;
}
char decode_add(char ch,int k)
{
  char c=((ch-97+(26-k))%26)+97;
  return c;	
}
void find_key(int pkey[],int n)
{
  int c=0;
  int min;
  for(int i=1;i<n;i++)
  {
    min=i;
    for(;min>=1;min--)
    {
      if(i%min==0 && n%min==0)
      {
	if(min==1)
	  pkey[c++]=i;
	  break;
      }
    }
    
  }
  
}
char decode(char ch,int k,int k_inv)
{
  char c=(((ch-97)*(k_inv))%26)+97;
  return c;	
}

int main()
{
        int pkey[12];
	find_key(pkey,26);
        int k,k2;
	int k_inv=0;
	
	     
	string s;
   	char cha='y';
	int z;
	cout<<"Welcome to affine encryption demonstration :\n";
	do
	{
        
		cout<<"press 1 for encoding a text\n";
		cout<<"press 2 for decoding a text\n";
		cout<<"input choice";
		cin>>z;
		if(z==1)
		{
		 string s;
          condtion:
          cout<<"enter the multiplicative key for cipher: ";
	  cin>>k;
	   cout<<"enter the additive key for cipher: ";
	  cin>>k2;
	  
	  for(int i=0;i<12;i++)
	  {
	    if(pkey[i]==k)
	    {
	      break;
	    }
	    else if(i==11)
	    {
	      cout<<"Wrong key: enter key from following:"<<endl;
	      for(int j=0;j<12;j++)
		cout<<pkey[j]<<" ";
	      goto condtion;
	    }
	    
	  }
	  cout<<"enter the plaintext: ";
          cin.ignore();
	  getline(cin,s);
    	  
    	 int n= s.length();
   		 char ch[n];
    	 for(int i=0;i<n;i++)
		{        	
			ch[i]=s.at(i);	
		}
 			ch[n]='\0';
    	 for(int j=0;j<n;j++)
    	   {
        	if(ch[j]!=' '){
        	ch[j]=encode(ch[j],k);
            ch[j]=encode_add(ch[j],k2);
			}
    	   }

     	cout<<"encrypted text: \n";
     	cout<<ch<<endl;

		}
		else
		{
	    string s;
	    condtion1:
	    cout<<"enter the multiplicative key for decipher: ";
	    cin>>k;
		cout<<"enter the additive key for decipher: ";
	    cin>>k2;
	     for(int i=0;i<12;i++)
	  {
	    if(pkey[i]==k)
	    {
	      break;
	    }
	    else if(i==11)
	    {
	      cout<<"Wrong key: enter key from following:"<<endl;
	      for(int j=0;j<12;j++)
		cout<<pkey[j]<<" ";
	      goto condtion1;
	    }
	    
	  }
	 
        cout<<"enter the message to decrypt: ";
    	cin.ignore();
		getline(cin,s);
    	for(int k1=0;k1<12;k1++)
	{
	  if((k*pkey[k1])% 26 == 1)
	    k_inv= pkey[k1];
	}
    	int n= s.length();
   		 char ch[n];
    	for(int i=0;i<n;i++)
        	ch[i]=s.at(i);
    	for(int j=0;j<n;j++)
    	{
        	if(ch[j]!=' '){
			ch[j]=decode_add(ch[j],k2);        	
			ch[j]=decode(ch[j],k,k_inv);
        	}
    	}

     	cout<<"decrypted text \n";
     	cout<<ch<<endl;

		}
		cout<<"do you wish to continue if yes y else n";
		cin>>cha;
	}while(cha=='y');
    cout<<"\n\n\n- by Roll no 34 Shivam Agarwal \n";
	
}
