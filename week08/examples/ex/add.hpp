#pragma once 
#include <iostream>
#include <vector>
using namespace std;

vector<float> add(const vector<float>& a,const vector<float>& b);

vector<float> add_avx2(const vector<float>& a,const vector<float>& b);

vector<float> add_avx2_omp(const vector<float>& a,const vector<float>& b);

vector<float> add_omp(const vector<float>& a,const vector<float>& b);


