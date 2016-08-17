#include <chrono>
#include <iostream>
#include "tbb/tbb.h"

//using namespace tbb;

//void ParallelApplyFoo( float a[], int n ) {
//    tbb::parallel_for( 0, n, 1, [&]( int i ) {(a[i]=sqrt(sqrt(i)*sqrt(i)*sqrt(i) / sin(sqrt(i)*sqrt(i)*sqrt(i))) );}  );
//}

//int main()
//{
//    int arraysize=10000000;
//    float *atoFill=new float[arraysize];

//    //Intel TBB paralellized
//    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
//    ParallelApplyFoo(atoFill, arraysize);
//    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
//    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>( end - start ).count();

//    std::cout<<"Intel TBB loop took: "<<duration1<<" millisecs"<<std::endl;

//    start = std::chrono::high_resolution_clock::now();
//    for(int i=0; i<arraysize; i++)  {(atoFill[i]=sqrt(sqrt(i)*sqrt(i)*sqrt(i) / sin(sqrt(i)*sqrt(i)*sqrt(i))) );}
//    end = std::chrono::high_resolution_clock::now();
//    auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>( end - start ).count();

//    std::cout<<"Traditional for loop took: "<<duration2<<" millisecs"<<std::endl;

//    std::cout<<"That's "<<((float)duration2/(float)duration1)<<" times faster"<<std::endl;

//    delete atoFill;

//    return 0;
//}






#include <vector>

#include "tbb/tbb.h"

using namespace std;

tbb::concurrent_vector<int> my_list;

void add_element(int i) {

    my_list.push_back(i);

}

std::vector<int> my_listTradionalVector;

void add_elementTraditionalVector(int i) {

    my_listTradionalVector.push_back(i);

}



int main() {
    const int size = 10000000;

    //Intel TBB paralellized
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    tbb::parallel_for(0,size,1, [=](int i) {
       add_element(i);
   } );

    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>( end - start ).count();

    std::cout<<"Intel TBB loop took: "<<duration1<<" millisecs"<<std::endl;




    start = std::chrono::high_resolution_clock::now();
    for(int i=0; i<size; i++)  {add_elementTraditionalVector(i);}
    end = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>( end - start ).count();

    std::cout<<"Traditional for loop took: "<<duration2<<" millisecs"<<std::endl;

    std::cout<<"That's "<<((float)duration2/(float)duration1)<<" times faster"<<std::endl;



    return 0;
}
