# Advance Problem Solving - 1

#### 1. Big Integer
- Implementation of Big integers Library to support mathematical operations for arbitarily big integers
- Operations supported 
    1) Addition & Subtraction 
    2) Multiplication & Division
    3) GCD 
    4) Exponant
    5) Factorial 

#### 2. DE-QUEUE
- Implementation of Dequeue which supports automatic resizing when elements are deleted and inserted.
- Support amortized constant time complexity for Insertion and Deletion.
- Linear time complexity for insertion and deletion from middle of the queue 
- Operations Supported :
    1) Deque() , Deque(n,x) -- Dequeue Intialization 
    2) Push_front(x) , Push_back(x) -- Insertion in front and back 
    3) Pop_front() , Pop_back() -- Deletion from front and back
    4) Resize(x) -- Resize the deque Dynamically

#### 3. LRU Cache 
- Implementation of LRU Cache using the Dequeue datastructure implemented before 
- Supported Operation 
    1) Get( key )  - Gets the value of key if it exists in cache
    2) Set( key , Value ) - Sets the value of key
