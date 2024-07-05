#include "add.hpp"

#ifdef WITH_AVX2
#include <immintrin.h>
#endif

#ifdef _OPENMP
#include <omp.h>
#endif


vector<float> add(const vector<float>& a,const vector<float>& b){
    
    if(a.size()!=b.size()){
        cerr<<"the two vector size is not match!"<<endl;
        return vector<float>(a.size(),0.f);//匿名实例化
    }

    vector<float> c(a.size());

    for(size_t i=0;i<a.size();i++){
        c.at(i)=b.at(i)+a.at(i);
    }

    return c;
}


vector<float> add_omp(const vector<float>& a,const vector<float>& b){
    
    if(a.size()!=b.size()){
        cerr<<"the two vector size is not match!"<<endl;
        return vector<float>(a.size(),0.f);//匿名实例化
    }

    vector<float> c(a.size());
    #pragma omp parallel for
    for(size_t i=0;i<a.size();i++){
        c.at(i)=b.at(i)+a.at(i);
    }

    return c;
}
//Vector 容器内存连续
vector<float> add_avx2(const vector<float>& a,const vector<float>& b){
#ifdef WITH_AVX2
    if(a.size()!=b.size()){
        cerr<<"the two vector size is not match!"<<endl;
        return vector<float>(a.size(),0.f);//匿名实例化
    }

    if (a.size() % 8 != 0) {  
        // 如果向量大小不是8的倍数，则可能无法充分利用AVX2  
        // 这里可以选择抛出异常、返回错误码或仅处理前n*8个元素  
        std::cerr << "Vector size is not a multiple of 8!" << std::endl;  
        return std::vector<float>(a.size(), 0.0f); // 返回一个所有元素为0的向量  
    }  
  
    __m256 ar,br;
    //__m256 cr= _mm256_setzero_ps();
    vector<float> c(a.size());

    for(size_t i=0;i<a.size();i+=8){
        ar = _mm256_loadu_ps(&a[i]);//s代表float,d代表double
        br = _mm256_loadu_ps(&b[i]);
        br = _mm256_add_ps(br,ar);


        //cr =  _mm256_add_ps(ar,br);
        _mm256_storeu_ps(&c[i], br);
    }

    return c;
#else
    cerr<<"AVX2 is not supported"<<endl;
    return vector<float>{-1.f};
#endif
}

vector<float> add_avx2_omp(const vector<float>& a,const vector<float>& b){
#ifdef WITH_AVX2
    if(a.size()!=b.size()){
        cerr<<"the two vector size is not match!"<<endl;
        return vector<float>(a.size(),0.f);//匿名实例化
    }

    if (a.size() % 8 != 0) {  
        // 如果向量大小不是8的倍数，则可能无法充分利用AVX2  
        // 这里可以选择抛出异常、返回错误码或仅处理前n*8个元素  
        std::cerr << "Vector size is not a multiple of 8!" << std::endl;  
        return std::vector<float>(a.size(), 0.0f); // 返回一个所有元素为0的向量  
    }  
  
    __m256 ar,br;
    __m256 cr= _mm256_setzero_ps();
    vector<float> c(a.size());
    #pragma omp parallel for
    for(size_t i=0;i<a.size();i+=8){
        ar = _mm256_loadu_ps(&a[i]);//s代表float,d代表double
        br = _mm256_loadu_ps(&b[i]);
        cr =  _mm256_add_ps(ar,br);
        _mm256_storeu_ps(&c[i], cr);
    }

    return c;
#else
    cerr<<"AVX2 is not supported"<<endl;
    return vector<float>{-1.f};
#endif
}

//v.data()返回指向v中第一个元素的指针，V是Vector类型

//()非直接赋值操作
//{}主要用来直接给值

//extend(vector 的初始化)
//std::vector<int> v;

//std::vector<int> v(10, 0);  // 创建一个包含10个整数的vector，所有元素都初始化为0

//std::vector<int> v1{1, 2, 3, 4, 5};  
//std::vector<int> v2(v1.begin(), v1.end());  // 创建一个与v1具有相同元素的vector
//std::vector<int> v = {1, 2, 3, 4, 5};

// std::vector<int> v1{1, 2, 3, 4, 5};  
// std::vector<int> v2(v1);  // 创建一个与v1具有相同元素的vector

//std::vector<int> v = std::initializer_list<int>{1, 2, 3, 4, 5};  
// 但通常，你会直接使用列表初始化语法，如上所述。

// std::vector<int> v1{1, 2, 3, 4, 5};  
// std::vector<int> v2(std::move(v1));  // v2现在拥有v1的元素，v1不再有效

// std::vector<int> v;  
// std::copy(std::array<int, 5>{1, 2, 3, 4, 5}.begin(), std::array<int, 5>{1, 2, 3, 4, 5}.end(), std::back_inserter(v));