#include <iostream>
#include <iomanip>
#include <iterator>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <ctime>

#define TIME

using namespace std;

class line_iterator
{
    istream*  in;
    string   line;
    bool     at_end;

    void read( ) {
        if (*in)
            getline(*in, line);
        at_end = (*in) ? true : false;
    }

public:
    typedef  input_iterator_tag  iterator_category;
    typedef  string  value_type;
    typedef  ptrdiff_t  difference_type;
    typedef  const string*  pointer;
    typedef  const string&  reference;

    line_iterator( ) : in(&cin), at_end(false) { }
    line_iterator(istream& s) : in(&s) { read( ); }
    reference operator*( ) const { return line; }
    pointer operator->( ) const { return &line; }

    line_iterator operator++( ) {  // prefix ++
        read( );
        return *this;
    }

    line_iterator operator++(int) {  // postfix ++
        line_iterator  tmp = *this;
        read();
        return tmp;
    }

    bool operator==(const line_iterator& i) const {
        return (in == i.in && at_end == i.at_end) ||
               (at_end == false && i.at_end == false);
    }

    bool operator!=(const line_iterator& i) const {
        return !(*this == i);
    }
}; // end  of class line_iterator

int  main()
{
    freopen("random_string.out", "r", stdin);
    freopen("iterator_out.out", "w", stdout);

    clock_t start = clock();
    clock_t t = clock();

    //input
    line_iterator  iter(cin);
    line_iterator  end_of_file;

    vector<string>  V(iter, end_of_file);

    t = clock()-t;
    cout << "Input: " << (double)t/CLOCKS_PER_SEC << "sec" << endl;
    //end input
    
    //sort
    t = clock();
    sort( V.begin(), V.end() ); // sort( V.begin(), V.end(), greater<string>() );
    t = clock()-t;
    cout << "Sorting: " << (double)t/CLOCKS_PER_SEC << "sec" << endl;
    //end sort

    //output
    t = clock();
    copy( V.begin(), V.end(), ostream_iterator<string>(cout, "\n"));
    t = clock()-t;
    cout << "Output: " << (double)t/CLOCKS_PER_SEC << "sec" << endl;
    //end output

    //total time
    cout << "Total time: " << ((float)clock() - start) / CLOCKS_PER_SEC << " sec" << endl;

    return 0;
}
