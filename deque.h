#include<iostream>

using namespace std;

#define UNIT 4

template<class T>
class deque
{
	public:

		T *a;
		int f;
		int r;
		int Asize = 0;

		deque()
		{
			a = new T[UNIT]{};
			f = -1;
			r = 0;
			Asize = UNIT;
		}

		deque(int len ,T x)
		{
			a = new T[len]{};

			Asize = len;

			for(int i=0 ;i<len; i++)
			{
				a[i] = x;
			}

			f = 0;
			r = len-1;
		}

		void extend()
		{
			T *temp = NULL;
			temp = a;

			a = new T[Asize*UNIT]{};

			int o_ind = f;
			int n_ind = f;

			while( o_ind  != r )
			{
				if(o_ind == Asize)
				{
					o_ind = 0;
				}

				a[n_ind] = temp[o_ind];
				n_ind++;
				o_ind++;
			}

			a[n_ind] = temp[r];
			r = n_ind;

			Asize = Asize*UNIT;

			delete(temp);
		}

		void push_back(T n)
		{
			if( (f == 0 && r == Asize-1) || ( f == (r+1)  ))
			{
		
				this->extend();
			}

			if( f == -1)
			{
				f  = 0;
				r = 0;
			}
			else if( r == Asize - 1)
			{
				r = 0;
			}
			else
			{
				r++;
			}

			a[r] = n;
		}

		void push_front(T n)
		{
			if( (f==0 && r == Asize-1) || (f == r+1))
			{
				/*cout<<"Overflow"<<endl;
				return;*/
				this->extend();
			}

			if(f==-1)
			{
				f=0;
				r=0;
			}
			else if(f == 0)
			{
				f = Asize-1;
			}
			else
			{
				f--;
			}

			a[f] = n;
		}

		void pop_front()
		{
			if( f == -1)
			{
				cout<<"Underflow"<<endl;
				return ;
			}

			if( f == r )
			{
				f = r = -1;
				//a[f] = 0;
			}
			else
			{
				if( f == Asize-1)
				{
					//a[f] = 0;
					f = 0;
				}
				else
				{
					//a[f] = 0;
					f = f + 1;
				}
			}
		}

		void pop_back()
		{
			if( f == -1 )
			{
				cout<<"Underflow"<<endl;
				return ;
			}

			if( f == r )
			{
				//a[f] = 0;
				f = r = -1;
			}
			else if( r == 0 )
			{
				//a[r] = 0;
				r = Asize-1;
			}
			else
			{
				//a[r] = 0;
				r--;
			}
		}

		T front()
		{
			if( f == -1 )
			{
				cout<<"Empty Queue "<<endl;
				exit(0);
			}

			return a[f];
		}

		T back()
		{
			if( f==-1 )
			{
				cout<<"Empty Queue "<<endl;
				exit(0);
			}
			
			return a[r];
		}

		bool empty()
		{
			if( f == -1)
			{
				return 1;
			}

			return 0;
		}

		int size()
		{
			int c = 0;

			if( f>r)
			{
				c = ((Asize) - f) + r + 1;
			}
			else
			{
				c = r-f+1;
			}

			return c;
		}

		int resize(int n)
		{
			if( n<(this->size()) )
			{
				for(int i=0 ;i<n ;i++)
				{
					if( r<0 )
					{
						r=Asize-1;
					}

					//a[r] = 0;
					r--;
				}
			}
			else
			{
				for(int i=0 ;i<n ;i++)
				{
					if( (f == 0 && r == Asize-1) || ( f == (r+1) ))
					{
						this->extend();
					}

					if( r == Asize)
					{
						r  = 0;
					}
				
					//a[r] = 0;
					r++;
				}
			}
		}

		void clear()
		{
			/*for(int i=0 ;i<Asize ;i++)
			{
				a[i] = 0;
			}*/

			f = -1;
			r = 0;
		}

		T operator [] (int n)
		{
			cout<<n<<endl;
			if( n > this->size()-1)
			{
				cout<<"Index Out of bounds  :";
				exit(0);
			}

			if( f+n > Asize-1)
			{
				return a[ (f+n)%Asize ];
			}

			return a[f+n];
		}

		void erase(T n)
		{
			int index = -1;

			for(int i=0 ;i<Asize ;i++)
			{
				if( a[i] == n )
				{
					index = i;
					break;
				}
			}

			if( index == -1 )
			{
				cout<<"Element Not Exist";
				return;
			}
			else
			{
				while( (index) != r )
				{
					if( index == Asize-1 && r==0 )
					{
						a[index] = a[r];
						break;
					}

					if(index == Asize-1)
					{
						a[index] = a[0];
						index = 0;
					}
					else
					{
						a[index] = a[index+1];
						index++;
					}
				}

				if( r==0 )
				{
					r = Asize-1;
				} 
				else
				{
					r--;
				}
			}
		}

		void print_deque()
		{
			for(int i=0 ;i<Asize ;i++)
			{
				cout<<a[i]<<" ";
			}
		}

};

/*main()
{
		deque<string> q(4,"abcd");

		q.traverse();
		cout<<endl;

		while(1)
		{
			cout<<"1.push_back"<<endl;
			cout<<"2.push_front"<<endl;
			cout<<"3.pop_back"<<endl;
			cout<<"4.pop_front"<<endl;
			cout<<"5.front"<<endl;
			cout<<"6.back"<<endl;
			cout<<"7.empty"<<endl;
			cout<<"8.size"<<endl;
			cout<<"9.Resize"<<endl;
			cout<<"10.[]"<<endl;
			cout<<"11.Erase"<<endl;
			cout<<"12.Clear"<<endl<<endl;

			int n;
			cin>>n;

			string c;

			switch(n)
			{
				case 1:
					cin>>c;
					q.push_back(c);
					break;

				case 2:
					cin>>c;
					q.push_front(c);
					break;

				case 3:
					q.pop_back();
					break;

				case 4:
					q.pop_front();
					break;

				case 5:
					cout<<q.front()<<endl;
					break;

				case 6:
					cout<<q.back()<<endl;
					break;

				case 7:
					cout<<q.empty()<<endl;
					break;

				case 8:
					cout<<q.size()<<endl;;
					break;

				case 9:
					int p;
					cin>>p;
					q.resize(p);
					break;

				case 10:
					int v;
					cin>>v;
					cout<<q[v]<<endl;;
					break;

				case 11:
					cin>>c;
					q.erase(c);
					break;

				case 12:
					q.clear();

			}

			q.traverse();

			cout<<endl<<endl;
				
		}
}*/