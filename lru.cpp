#include<iostream>
#include<map>
#include "deque.h"

using namespace std;

#define UNIT 4

template<class KEY ,class VAL>
class lru
{
	public:

		deque<KEY> q;
		int frame;
		int filled;	
		map<KEY,VAL> m;

		lru(int n)
		{
			frame = n;
			filled=0;
		}

		void ins(KEY k ,VAL v)
		{
			if( m.find(k) == m.end() )
			{
				if(filled < frame)
				{
					m.insert(make_pair(k,v));
					filled++;
					q.push_back(k);
				}
				else
				{
					int temp = q.front();
					q.pop_front();

					m.erase(temp);
					m.insert(make_pair(k,v));

					q.push_back(k);
				}
			}
			else
			{
				m[k] = v;
				q.erase(k);
				q.push_back(k);
			}
		}

		VAL get(KEY key)
		{
			if( m.find(key) == m.end() )
			{
				return -1;
			}

			q.erase(key);
			q.push_back(key);

			return m[key];
		}
};

main()
{
	int n;
	cin>>n;

	lru<float ,float> l(n);

	int que;
	cin>>que;

	while(que--)
	{
		char c;
		cin>>c;

		if( c == 'G')
		{
			KEY k;
			cin>>k;

			cout<<l.get(k)<<endl;
		}
		else
		{
			KEY k
			VALUE v;
			cin>>k>>v;

			l.ins(k,v);
		}
	}

}