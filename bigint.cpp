#include<iostream>
#include<vector>
#include<algorithm> 

using namespace std;

int compair(string s1, string s2)
{
	if( s1.size() > s2.size())
	{
		return 1;
	}
	else if( s1.size() < s2.size() )
	{
		return 2;
	}
	else
	{
		for(int i=s1.size()-1 ;i>=0 ;i--)
		{
			if( s1[i] > s2[i])
			{
				return 1;
			}

			if( s1[i] < s2[i])
			{
				return 2;
			}
		}

		return 0;
	}
}

string remove(string s)
{
	string ans;

	int flag = 0;
	int i=0;

	if( s[i] == '-')
	{
		ans.push_back('-');
		i++;
	}

	while(s[i] == '0')
	{
		i++;
	}

	while(i<s.size())
	{
		ans.push_back(s[i]);
		i++;
	}

	return ans;
}

string bigsum(string s1 ,string s2);

string bigsub(string s1 ,string s2)
{

	if( s1[0]=='-' && s2[0]=='-')
	{
		s1 = s1.substr(1,s1.size()-1);
		s2 = s2.substr(1,s2.size()-1);

		string ans = bigsub(s2,s1);
		return ans;
	}
	else if( s1[0] == '-')
	{
		s1 = s1.substr(1,s1.size()-1);
		string ans = bigsum(s1,s2);
		ans = '-'+ans;

		return ans;
	}
	else if( s2[0] == '-')
	{
		s2 = s2.substr(1,s2.size()-1);
		
		string ans = bigsum(s1,s2);

		return ans;
	}
	else
	{
		int i=0 ,j=0;

		int diff ,borrow=0;

		string ans;

		if( compair( s1 ,s2) == 1) 
		{
			
			int i,j;

			for(i=s1.size()-1 ,j=s2.size()-1 ;j>=0 ;i--,j--)
			{
				diff = ((s1[i]-'0') - (s2[j]-'0'))-borrow;

				if( diff < 0)
				{
					diff += 10;
					borrow = 1;
				}
				else
				{
					borrow = 0;
				}

				ans.push_back(diff+'0');
			}

			for(int k=i ;k>=0 ;k--)
			{
				diff = (s1[k]-'0')-borrow;

				if( diff < 0)
				{
					diff += 10;
					borrow = 1;
				}
				else
				{
					borrow = 0;
				}

				ans.push_back(diff+'0');
			}

			reverse(ans.begin() ,ans.end());
			ans = remove(ans);

			return ans;
		}
		else if( compair(s1,s2) == 2)
		{
			string ans = bigsub(s2,s1);
			ans = "-"+ans;
			ans = remove(ans);
			return ans;
		}
		else
		{
			return "0";
		}
	}
}

string bigsum(string s1 ,string s2)
{
	if( s1[0] == '-' && s2[0] == '-')
	{
		s1 = s1.substr(1,s1.size()-1);
		s2 = s2.substr(1,s2.size()-1);

		string ans = bigsum(s1 ,s2);
		ans	= "-" + ans;
		return ans;
	}
	else if( s1[0] == '-')
	{
		s1 = s1.substr(1,s1.size()-1);
		string ans = bigsub(s2,s1);

		return ans;
	}
	else if( s2[0] == '-')
	{
		s2 = s2.substr(1,s2.size()-1);
		string ans = bigsub(s1,s2);

		return ans;
	}
	else
	{
		if (s1.size() > s2.size()) 
        {
        	swap(s1, s2); 
		}

		int n1 = s1.size();
		int n2 = s2.size();

		int sum = 0;
		int carry = 0;

		string ans;

		for(int i=n1-1,j=n2-1 ;i>=0 ;i--,j--)
		{
			sum = (s1[i] - '0') + (s2[j] - '0') + carry;
			int temp = sum%10;

			ans.push_back(temp + '0');
			carry = sum/10;
		}	

		for(int i = n2-n1-1 ;i>=0 ;i--)
		{
			sum = (s2[i]-'0') + carry;
			ans.push_back(sum%10 + '0');
			carry = sum /10; 
		}

		if( carry > 0 )
		{
			ans.push_back(carry + '0');
		}

		reverse(ans.begin() ,ans.end());

		ans = remove(ans);
		return ans;
	}
}

string bigmul(string s1 ,string s2)
{
	vector<int> a(s1.size() + s2.size(),0) ;
	string ans;

	int p=0,q=0;

	for(int i=s1.size()-1 ;i>=0 ;i--)
	{
		int t1 = s1[i] - '0';
		int sum = 0;
		int carry = 0;
		q = 0;

		for(int j=s2.size()-1 ;j>=0 ;j--)
		{
			int t2 = s2[j] - '0';

			sum = t1*t2 + a[p+q] + carry;
			carry = sum/10;
			a[p+q] = sum%10;

			q++;

		}

		if( carry > 0 )
		{
			a[p+q] = a[p+q] + carry;
		}

		p++;
	}
	
	int temp = s1.size() + s2.size()-1;

	while(temp >= 0 && a[temp] == 0 )
	{
		temp--;
	}
	
	while(temp>=0)
	{
		ans.push_back(a[temp]+'0');
		temp--;
	}

	return ans;
}

string gcd(string a ,string b)
{
	 while ( compair(a,b) != 0 ) 
	 { 
        if( compair(a ,b) == 1)
        {         
            a = bigsub(a,b);         
        }
        else 
        {       
            b = bigsub(b,a);         
    	} 
	}
	return a;
}

string fact(string n)
{
	if( compair(n,"0") == 0 )
	{
		return "1";
	}
	
	string ans = "1";

	string i = "1";

	while( compair(i,n) != 0 )
	{
		ans = bigmul(ans ,i);

		i = bigsum(i,"1");
	}

	return bigmul(ans,i);
}

string div_2(string s)
{
	string ans;

	int res = 0;
	int rem = 0;

	for(int i=0 ;i<s.size() ;i++)
	{
		int temp = s[i] - '0';

		res = (temp + rem*10)/2 ; 
		rem = temp%2 ;

		ans.push_back(res+'0');
	}

	ans = remove(ans);
	return ans;
}

int mod_2(string s)
{
	int temp = s[ s.size()-1 ] - '0';

	if( temp%2 == 0)
	{
		return 0;
	}

	return 1;
}

string exp(string a ,string b)
{
	string res = "1";

	while( compair(b ,"") != 0 )
	{
		if( mod_2(b) == 1 )
		{
			res = bigmul(	res , a);
		}	

		b = div_2(b);

		//cout<<b<<endl;

		a = bigmul(a,a);
	}

	return res;
}



main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int c;
		cin>>c;

		if( c == 1 )
		{
			string s1,s2;
			cin>>s1;
			cin>>s2;

			string ans = exp(s1,s2);
			cout<<ans<<endl;
		}
		else if( c==2 )
		{
			string s1,s2;
			cin>>s1>>s2;

			string ans = gcd(s1,s2);
			cout<<ans<<endl;
		}
		else
		{
			string s1;
			cin>>s1;

			string ans = fact(s1);
			cout<<ans<<endl;
		}
	}

	return 0;

}