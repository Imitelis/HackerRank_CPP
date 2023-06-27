/* HackerRank - C++ - Challenges - VII - Other Concepts */


/* 1. Other Concepts - C++ Class Templates */
/*
A class template provides a specification for generating classes based on parameters. Class templates are generally used to implement containers. A class template is instantiated by passing a given set of types to it as template arguments. Here is an example of a class, MyTemplate, that can store one element of any type and that has just one member function divideBy2, which divides its value by 2.

template <class T>
class MyTemplate {
T element;
public:
MyTemplate (T arg) {element=arg;}
T divideBy2 () {return element/2;}
};

It is also possible to define a different implementation of a template for a specific type. This is called Template Specialization. For the template given above, we find that a different implementation for type char will be more useful, so we write a function printElement to print the char element:

// class template specialization:
template <>
class MyTemplate <char> {
char element;
public:
MyTemplate (char arg) {element=arg;}
char printElement ()
{
return element;
}
};

You are given a main() function which takes a set of inputs. The type of input governs the kind of operation to be performed, i.e. concatenation for strings and addition for int or float. You need to write the class template AddElements which has a function add() for giving the sum of int or float elements. You also need to write a template specialization for the type string with a function concatenate() to concatenate the second string to the first string.

Input Format

The first line contains an integer n. Input will consist of n + 1 lines where n is the number given in the first line of the input followed by n lines.

Each of the next n line contains the type of the elements provided and depending on the type, either two strings or two integers or two floating point numbers will be given. The type will be one of int, float or string types only. Out of the following two elements, you have to concatenate or add the second element to the first element.

Constraints

  *  1 ≤ n ≤ 5 x 10^5
  *  1.0 ≤ value_float ≤ 10.0, where value_float is any float value
  *  1 ≤ value_int ≤ 10^5, where valueint is any int value
  *  0 ≤ len_string ≤ 10, where len_string is the length of any string

The time limit for this challenge is 4 seconds.

Output Format

The code provided in the code editor will use your class template to add/append elements and give the output.

Sample Input

3
string John Doe
int 1 2
float 4.0 1.5

Sample Output

JohnDoe
3
5.5

Explanation

"Doe" when appended with "John" gives "JohnDoe". 2 added to 1 gives 3, and 1.5 added to 4.0 gives 5.5.
*/
/* Solution */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

/*Write the class AddElements here*/
template <class T>
class AddElements {
    T element;
    public:
    AddElements<T> (T &a){
        element = a;
    }
    T add(T &b){
        return element + b;
    }
    T concatenate (T &b){
        return element + b;
    }
};

int main () {
  int n,i;
  cin >> n;
  for(i=0;i<n;i++) {
    string type;
    cin >> type;
    if(type=="float") {
        double element1,element2;
        cin >> element1 >> element2;
        AddElements<double> myfloat (element1);
        cout << myfloat.add(element2) << endl;
    }
    else if(type == "int") {
        int element1, element2;
        cin >> element1 >> element2;
        AddElements<int> myint (element1);
        cout << myint.add(element2) << endl;
    }
    else if(type == "string") {
        string element1, element2;
        cin >> element1 >> element2;
        AddElements<string> mystring (element1);
        cout << mystring.concatenate(element2) << endl;
    }
  }
  return 0;
}


/* 2. Other Concepts - Preprocessor Solution */
/*
Preprocessor directives are lines included in the code preceded by a hash sign (#). These lines are directives for the preprocessor. The preprocessor examines the code before actual compilation of code begins and resolves all these directives before any code is actually generated by regular statements.

#define INF 10000000
if( val == INF) {
//Do something
}
After the preprocessor has replaced the directives, the code will be
if( val == 10000000) { //Here INF is replaced by the value with which it's defined.
//Do something
}

You can also define function macros which have parameters.

#define add(a, b) a + b
int x = add(a, b);

The second statement after the preprocessor has replaced the directives will be:
int x = a + b;

To know more about preprocessor directives, you can go to this link

You're spending your afternoon at a local school, teaching kids how to code. You give them a simple task: find the difference between the maximum and minimum values in an array of integers.

After a few hours, they came up with some promising source code. Unfortunately, it doesn't compile! Since you don't want to discourage them, you decide to make their code work without modifying it by adding preprocessor macros.

Review the locked stub code in your editor and add the preprocessor macros necessary to make the code work.

Input Format

The first line contains an integer, N, denoting the size of the array.
The second line contains N space-separated integers, x_1, x_2, ..., x_n, describing the elements in the array.

Constraints

  *  1 ≤ N ≤ 10^3
  *  -10^8 ≤ x_i ≤ 10^8

Output Format

You are not responsible for printing any output to stdout. Once the necessary preprocessor macros are written, the locked code in your editor will print a line that says Result = Z, where Z is the difference between the maximum and minimum values in the array.

Sample Input

5
32 332 -23 -154 65

Sample Output

Result = 486

Explanation

332-(-154) = 486
*/
/* Solution */

/* Enter your macros here */
#define FUNCTION(name, operator) void name(int &current, int candidate){ !(current operator candidate) ? current = candidate : false; }
#define foreach(v, i) for(int i = 0; i < v.size(); i++)
#define io(v) cin >> v
#define INF 10000000
#define toStr(S) #S

#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
	int n; cin >> n;
	vector<int> v(n);
	foreach(v, i) {
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	cout << toStr(Result =) <<' '<< ans;
	return 0;

}


/* 3. Other Concepts - Overload Operators */
/*
You are given a class - Complex.

class Complex
{
public:
    int a,b;
};

Operators are overloaded by means of operator functions, which are regular functions with special names. Their name begins with the operator keyword followed by the operator sign that is overloaded. The syntax is:

type operator sign (parameters) { /*... body ...*/ }

You need to overload operators + and << for the Complex class.

The operator + should add complex numbers according to the rules of complex addition:

(a+ib)+(c+id) = (a+c) + i(b+d)  

Overload the stream insertion operator << to add "a + ib" to the stream:

cout<<c<<endl;

The above statement should print "a + ib" followed by a newline where a = c.a and b = c.b.

Input Format

The overloaded operator + should receive two complex numbers (a + ib and c + id) as parameters. It must return a single complex number.

The overloaded operator << should add "a + ib" to the stream where a is the real part and b is the imaginary part of the complex number which is then passed as a parameter to the overloaded operator.

Output Format

As per the problem statement, for the output, print "a + ib" followed by a newline where a = c.a and b = c.b.

Sample Input

3+i4
5+i6

Sample Output

8+i10

Explanation

Given output after performing required operations (overloading + operator) is 8+i10.
*/
/* Solution */

//Operator Overloading

#include<iostream>

using namespace std;

class Complex
{
public:
    int a,b;
    void input(string s)
    {
        int v1=0;
        int i=0;
        while(s[i]!='+')
        {
            v1=v1*10+s[i]-'0';
            i++;
        }
        while(s[i]==' ' || s[i]=='+'||s[i]=='i')
        {
            i++;
        }
        int v2=0;
        while(i<s.length())
        {
            v2=v2*10+s[i]-'0';
            i++;
        }
        a=v1;
        b=v2;
    }
};

//Overload operators + and << for the class complex
//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
//<< should print a complex number in the format "a+ib"
Complex operator+(const Complex X, const Complex Y)
{
    Complex Z;
    Z.a = X.a + Y.a;
    Z.b = X.b + Y.b;
    return Z;
}
ostream& operator<<(ostream& os, const Complex C)
{
    return os << C.a << "+" << "i" << C.b;
}

int main()
{
    Complex x,y;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    x.input(s1);
    y.input(s2);
    Complex z=x+y;
    cout<<z<<endl;
}


/* 4. Other Concepts - Operator Overloading */
/*
Classes define new types in C++. Types in C++ not only interact by means of constructions and assignments but also via operators. For example:

int a=2, b=1, c;
c = b + a;

The result of variable c will be 3.
Similarly, classes can also perform operations using operator overloading (https://learn.microsoft.com/en-us/cpp/cpp/operator-overloading). Operators are overloaded by means of operator functions, which are regular functions with special names. Their name begins with the operator keyword followed by the operator sign that is overloaded. The syntax is:

type operator sign (parameters) { /*... body ...*/ }

You are given a main() function which takes a set of inputs to create two matrices and prints the result of their addition. You need to write the class Matrix which has a member a of type vector<vector<int> >. You also need to write a member function to overload the operator +. The function's job will be to add two objects of Matrix type and return the resultant Matrix.

Input Format

First line will contain the number of test cases T. For each test case, there are three lines of input.

The first line of each test case will contain two integers N and M which denote the number of the rows and columns respectively of the two matrices that will follow on the next two lines. These next two lines will each contain N * M elements describing the two matrices in row-wise format i.e. first M elements belong to the first row, next M elements belong to the second row and so on.

Constraints

  *  1 <= T <= 1000
  *  1 <= N <= 100
  *  1 <= M <= 100
  *  1 <= A_i,j <= 10, where A_i,j is the element in the ith row and jth column of the matrix.

Output Format

The code provided in the editor will use your class Matrix and overloaded operator function to add the two matrices and give the output.

Sample Input

1
2 2
2 2 2 2
1 2 3 4

Sample Output

3 4 
5 6

Explanation

The sum of first matrix and the second matrix is the matrix given in the output.
*/
/* Solution */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Matrix
{
    public:
        vector<vector<int>> a;
        Matrix() {}
        Matrix operator+(const Matrix &o)
        {
            Matrix sum(*this);
            for (size_t i = 0; i < sum.a.size(); i++)
            {
                for (size_t j = 0; j < sum.a[i].size(); j++)
                {
                    sum.a[i][j] += o.a[i][j];
                }
            }
            return sum;
        }
};

int main () {
   int cases,k;
   cin >> cases;
   for(k=0;k<cases;k++) {
      Matrix x;
      Matrix y;
      Matrix result;
      int n,m,i,j;
      cin >> n >> m;
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         x.a.push_back(b);
      }
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         y.a.push_back(b);
      }
      result = x+y;
      for(i=0;i<n;i++) {
         for(j=0;j<m;j++) {
            cout << result.a[i][j] << " ";
         }
         cout << endl;
      }
   }  
   return 0;
}


/* 5. Other Concepts - C++ Class Template Specialization */
/*
You are given a main function which reads the enumeration values for two different types as input, then prints out the corresponding enumeration (https://en.cppreference.com/w/cpp/language/enum) names. Write a class template that can provide the names of the enumeration values for both types. If the enumeration value is not valid, then print unknown.

Input Format

The first line contains t, the number of test cases.
Each of the t subsequent lines contains two space-separated integers. The first integer is a color value, c, and the second integer is a fruit value, f.

Constraints

  *  1 ≤ t ≤ 100
  *  -2 x 10^9 ≤ c ≤ 2 x 10^9
  *  -2 x 10^9 ≤ f ≤ 2 x 10^9

Output Format

The locked stub code in your editor prints t lines containing the color name and the fruit name corresponding to the input enumeration index.

Sample Input

2
1 0
3 3

Sample Output

green apple
unknown unknown

Explanation

Since t = 2, there are two lines of output.

  1.  The two input index values, 1 and 0, correspond to green in the color enumeration and apple in the fruit enumeration. Thus, we print green apple.
  2.  The two input values, 3 and 3, are outside of the range of our enums. Thus, we print unknown unknown.
*/
/* Solution */

#include <iostream>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;

// Define specializations for the Traits class template here.
template<>
struct Traits<Fruit>{
    static string name(int index){
        switch(index){
            case 0: return "apple";
            case 1: return "orange";
            case 2: return "pear";
            default: return "unknown";
        }
    }
};

template<>
struct Traits<Color>{
    static string name(int index){
        switch(index){
            case 0: return "red";
            case 1: return "green";
            case 2: return "orange";
            default: return "unknown";
        }
    }
};

int main()
{
	int t = 0; std::cin >> t;

    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}


/* 6. Other Concepts - Attending Workshops */
/*
A student signed up for n workshops and wants to attend the maximum number of workshops where no two workshops overlap. You must do the following:

Implement 2 structures (https://cplusplus.com/doc/tutorial/structures/):

  1.  struct Workshop having the following members:
      *  The workshop's start time.
      *  The workshop's duration.
      *  The workshop's end time.

  2.  struct Available_Workshops having the following members:
      *  An integer, n (the number of workshops the student signed up for).
      *  An array of type Workshop array having size n.

Implement 2 functions (https://cplusplus.com/doc/tutorial/functions/):

  1.  Available_Workshops* initialize (int start_time[], int duration[], int n)
    Creates an Available_Workshops object and initializes its elements using the elements in the start_time[] and duration[] parameters (both are of size n). Here, start_time[i] and duration[i] are the respective start time and duration for the ith workshop. This function must return a pointer to an Available_Workshops object.

  2.  int CalculateMaxWorkshops(Available_Workshops* ptr)
    Returns the maximum number of workshops the student can attend—without overlap. The next workshop cannot be attended until the previous workshop ends.

Note: An array of unknown size (n) should be declared as follows:

DataType* arrayName = new DataType[n];

Input Format

Input from stdin is handled by the locked code in the editor; you simply need to write your functions to meet the specifications of the problem statement above.

Constraints

  *  1 ≤ N ≤ 10^5
  *  0 ≤ start_time_i ≤ 10^3
  *  0 ≤ duration_i ≤ 10^3

Output Format

Output to stdout is handled for you.

Your initialize function must return a pointer to an Available_Workshops object.
Your CalculateMaxWorkshops function must return maximum number of non-overlapping workshops the student can attend.

Sample Input

6
1 3 0 5 5 8
1 1 6 2 4 1

Sample Output

CalculateMaxWorkshops should return 4.

Explanation

The first line denotes n, the number of workshops.
The next line contains n space-separated integers where the ith integer is the ith workshop's start time.
The next line contains n space-separated integers where the ith integer is the ith workshop's duration.
The student can attend the workshops 0, 1, 3, and 5 without overlap, so CalculateMaxWorkshops returns 4 to main (which then prints 4 to stdout).
*/
/* Solution */

#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
#include <vector>
#include <iostream>

typedef pair<int,int> p;
typedef vector<p> Available_Workshops;

Available_Workshops* initialize(int *start_time, int *duration, int n) {
    auto aw = new Available_Workshops(n);
    for(int i = 0; i < n; i++){
        aw->at(i).first = start_time[i];
        aw->at(i).second = start_time[i]+duration[i];
    }
    return aw;
}

int CalculateMaxWorkshops(Available_Workshops* data) {
    sort(data->begin(),data->end(), [](const p &a, const p &b) { return a.second < b.second; });
    int f = 0, res = 0;
    for(int i = 0; i < data->size(); i++){
        if(data->at(i).first >= f){
            res++;
            f = data->at(i).second;
        }
    }
    return res;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}


/* 7. Other Concepts - C++ Variadics */
/*
A template parameter pack is a template parameter that accepts zero or more template arguments (non-types, types, or templates). To read more about parameter pack, click here (https://en.cppreference.com/w/cpp/language/parameter_pack).

Create a template function named reversed_binary_value. It must take an arbitrary number of bool values as template parameters. These booleans represent binary digits in reverse order. Your function must return an integer corresponding to the binary value of the digits represented by the booleans. For example: reversed_binary_value<0,0,1>() should return 4.

Input Format

The first line contains an integer, t, the number of test cases. Each of the t subsequent lines contains a test case. A test case is described as 2 space-separated integers, x and y, respectively.

  *  x is the value to compare against.
  *  y represents the range to compare: 64 * y to 64 * y + 63.

Constraints

  *  0 ≤ x ≤ 65535
  *  0 ≤ y ≤ 1023
  *  The number of template parameters passed to reversed_binary_value will be ≤ 16.

Output Format

Each line of output contains 64 binary characters (i.e., 0's and 1's). Each character represents one value in the range. The first character corresponds to the first value in the range. The last character corresponds to the last value in the range. The character is 1 if the value in the range matches X; otherwise, the character is 0.

Sample Input

2
65 1
10 0

Sample Output

0100000000000000000000000000000000000000000000000000000000000000
0000000000100000000000000000000000000000000000000000000000000000

Explanation

The second character on the first line is a 1, because the second value in the range 64..127 is 65 and x is 65.

The eleventh character on the second line is a 1, because the eleventh value in the range 0..63 is 10 and x is 10.

All other characters are zero, because the corresponding values in the range do not match x.
*/
/* Solution */

#include <iostream>
using namespace std;

// Enter your code for reversed_binary_value<bool...>()
template<bool...digits>
int reversed_binary_value(){
    int output = 0;
    int power = 1;
    for(bool b : {digits...}){
        if(b)
            output += 1*power;     
        power *= 2;
    }
    return output;
}

template <int n, bool...digits>
struct CheckValues {
  	static void check(int x, int y)
  	{
    	CheckValues<n-1, 0, digits...>::check(x, y);
    	CheckValues<n-1, 1, digits...>::check(x, y);
  	}
};

template <bool...digits>
struct CheckValues<0, digits...> {
  	static void check(int x, int y)
  	{
    	int z = reversed_binary_value<digits...>();
    	std::cout << (z+64*y==x);
  	}
};

int main()
{
  	int t; std::cin >> t;

  	for (int i=0; i!=t; ++i) {
		int x, y;
    	cin >> x >> y;
    	CheckValues<6>::check(x, y);
    	cout << "\n";
  	}
}


/* 8. Other Concepts - Bit Array */
/*
You are given four integers: N, S, P, Q. You will use them in order to create the sequence a with the following pseudo-code.

a[0] = S (modulo 2^31)
for i = 1 to N-1
    a[i] = a[i-1]*P+Q (modulo 2^31) 

Your task is to calculate the number of distinct integers in the sequence a.

Input Format

Four space separated integers on a single line, N, S, P, and Q respectively.

Output Format

A single integer that denotes the number of distinct integers in the sequence a.

Constraints

  *  1 ≤ N ≤ 10^8
  *  0 ≤ S, P, Q < 2^31

Sample Input

3 1 1 1

Sample Output

3

Explanation

a = [1, 2, 3]

Hence, there are 3 different integers in the sequence.
*/
/* Solution */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    uint_fast64_t po = (uint_fast64_t)(pow(2, 31));
    uint_fast64_t N, S, P, Q;
    cin >> N >> S >> P >> Q;
    bool r = false;
    uint_fast64_t c = 0;
    uint_fast64_t prv = S % po;
    uint_fast64_t crn = -1;
    uint_fast64_t i = 1;
    do {
        crn = (prv * P + Q) % po;
        if (crn != prv) {
            prv = crn;
            ++c;
        }
        else {
            r = true;
        }
        ++i;
    } while (i < N && !r);
    cout << c + 1 << endl;
    return 0;
}


