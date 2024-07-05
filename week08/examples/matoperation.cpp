#include <iostream>
#include "matoperation.hpp"


#ifdef WITH_AVX2
#include <immintrin.h>
#endif 


#ifdef WITH_NEON
#include <arm_neon.h>
#endif

#ifdef _OPENMP
#include <omp.h>
#endif

float dotproduct(const float *p1, const float * p2, size_t n)//传统单线操作，每次判断条件都比较昂贵
{
    float sum = 0.0f;
    for (size_t i = 0; i < n ; i++)
        sum += (p1[i] * p2[i]);
    return sum;
}


float dotproduct_unloop(const float *p1, const float * p2, size_t n)//一次处理八个数据，减少条件判断的时间
{
    if(n % 8 != 0)
    {
        std::cerr << "The size n must be a multiple of 8." <<std::endl;
        return 0.0f;
    }

    float sum = 0.0f;
    for (size_t i = 0; i < n; i+=8)
    {
        sum += (p1[i] * p2[i]);
        sum += (p1[i+1] * p2[i+1]);
        sum += (p1[i+2] * p2[i+2]);
        sum += (p1[i+3] * p2[i+3]);
        sum += (p1[i+4] * p2[i+4]);
        sum += (p1[i+5] * p2[i+5]);
        sum += (p1[i+6] * p2[i+6]);
        sum += (p1[i+7] * p2[i+7]);
    }
    return sum;

}

float dotproduct_avx2(const float *p1, const float * p2, size_t n)//使用intel 自带
{
#ifdef WITH_AVX2//宏定义指定
    if(n % 8 != 0)//一次处理八位
    {
        std::cerr << "The size n must be a multiple of 8." <<std::endl;
        return 0.0f;
    }

    float sum[8] = {0};
    __m256 a, b;//寄存器类型，256位寄存器，刚好8个32位float
    __m256 c = _mm256_setzero_ps();//初始化为0

    for (size_t i = 0; i < n; i+=8)
    {
        a = _mm256_loadu_ps(p1 + i);//一次处理8位
        b = _mm256_loadu_ps(p2 + i);//加载进寄存器
        c =  _mm256_add_ps(c, _mm256_mul_ps(a, b));//ab寄存器相乘加进寄存器c
    }
    _mm256_storeu_ps(sum, c);//将寄存器c内变量取出存入sum变量
    return (sum[0]+sum[1]+sum[2]+sum[3]+sum[4]+sum[5]+sum[6]+sum[7]);
#else
    std::cerr << "AVX2 is not supported" << std::endl;//std::cerr 专用处理报错
    return 0.0;
#endif
}

float dotproduct_avx2_omp(const float *p1, const float * p2, size_t n)
{
#ifdef WITH_AVX2
    if(n % 8 != 0)
    {
        std::cerr << "The size n must be a multiple of 8." <<std::endl;
        return 0.0f;
    }

    float sum[8] = {0};
    __m256 a, b;
    __m256 c = _mm256_setzero_ps();

    #pragma omp parallel for//在 for循环前加入该指令，会自动化多线程,通常，你会在并行区域中进行计算，而不是 I/O 操作
    for (size_t i = 0; i < n; i+=8)
    {
        a = _mm256_loadu_ps(p1 + i);
        b = _mm256_loadu_ps(p2 + i);
        c =  _mm256_add_ps(c, _mm256_mul_ps(a, b));
    }
    _mm256_storeu_ps(sum, c);
    return (sum[0]+sum[1]+sum[2]+sum[3]+sum[4]+sum[5]+sum[6]+sum[7]);
#else
    std::cerr << "AVX2 is not supported" << std::endl;
    return 0.0;
#endif
}


float dotproduct_neon(const float *p1, const float * p2, size_t n)
{
#ifdef WITH_NEON//arm内核使用
    if(n % 4 != 0)
    {
        std::cerr << "The size n must be a multiple of 4." <<std::endl;
        return 0.0f;
    }

    float sum[4] = {0};
    float32x4_t a, b;//arm内核可操作128位寄存器，即4位32float
    float32x4_t c = vdupq_n_f32(0);//初始化为0

    for (size_t i = 0; i < n; i+=4)
    {
        a = vld1q_f32(p1 + i);
        b = vld1q_f32(p2 + i);
        c =  vaddq_f32(c, vmulq_f32(a, b));
    }
    vst1q_f32(sum, c);
    return (sum[0]+sum[1]+sum[2]+sum[3]);
#else
    std::cerr << "NEON is not supported" << std::endl;
    return 0.0;
#endif
}

float dotproduct_neon_omp(const float *p1, const float * p2, size_t n)
{
#ifdef WITH_NEON
    if(n % 4 != 0)
    {
        std::cerr << "The size n must be a multiple of 4." <<std::endl;
        return 0.0f;
    }

    float sum[4] = {0};
    float32x4_t a, b;
    float32x4_t c = vdupq_n_f32(0);

    #pragma omp parallel for
    for (size_t i = 0; i < n; i+=4)
    {
        a = vld1q_f32(p1 + i);
        b = vld1q_f32(p2 + i);
        c =  vaddq_f32(c, vmulq_f32(a, b));
    }
    vst1q_f32(sum, c);
    return (sum[0]+sum[1]+sum[2]+sum[3]);
#else
    std::cerr << "NEON is not supported" << std::endl;
    return 0.0;
#endif
}
