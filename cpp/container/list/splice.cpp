//
// Created by 陈希明 on 18/1/26.
//

#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> l1 = {1,2,3};
    list<int> l2 = {4,5,6};
    ostream_iterator<int> out_itr(cout," ");

    /*
     * function1. ls1.splice(p,ls2)
     */

    auto l1_itr = l1.begin();
    l1_itr++; //point to 2

    l1.splice(l1_itr,l2);

    copy(l1.begin(),l1.end(),out_itr);//l1: 1 (4 5 6) 2 3
    cout<<endl;
    copy(l2.begin(),l2.end(),out_itr);//l2: empty
    cout<<endl;

    /*
     * function2. ls1.splice(p,ls2,p2)
     */

    //l1_itr still point to 2
    *out_itr = *l1_itr;
    cout<<endl;

    list<int> l3 = {7,8,9};
    auto l3_itr = l3.begin();
    l3_itr++;//point to 8

    l1.splice(l1_itr,l3,l3_itr);

    copy(l1.begin(),l1.end(),out_itr);//l1: 1 4 5 6 (8) 2 3
    cout<<endl;
    copy(l3.begin(),l3.end(),out_itr);//l3: 7 9
    cout<<endl;

    /*
     * function3. ls1.splice(p,ls2,b,e)
     */

    //l1_itr still point to 2

    l1.splice(l1_itr,l3,l3.begin(),l3.end());
    copy(l1.begin(),l1.end(),out_itr);//l1: 1 4 5 6 8 (7 9) 2 3
    cout<<endl;
    copy(l3.begin(),l3.end(),out_itr);//l3: empty
    cout<<endl;

    return EXIT_SUCCESS;
}

