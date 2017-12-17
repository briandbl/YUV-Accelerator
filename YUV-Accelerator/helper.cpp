//
//  helper.cpp
//  YUV-Accelerator
//
//  Created by 朱芄蓉 on 17/12/2017.
//  Copyright © 2017 朱芄蓉. All rights reserved.
//

#include "helper.hpp"

/* clip num to [lower_bound, upper_bound] */
double clip(int lower_bound, int upper_bound, double num){
    if(num > upper_bound){
        num = upper_bound;
    }
    if(num < lower_bound){
        num = lower_bound;
    }
    return num;
}

void print_64(__m64 num){
    int16_t* p = (int16_t*)(&num);
    for(int i = 0; i < 4; ++i){
        cout << *(p + i) << " ";
    }
    cout << endl;
}

void write_back(__m64 num, uint8_t* dst, int pos){
    int16_t* p = (int16_t*)(&num);
    for(int i = 0; i < 4; ++i){
        dst[pos + i] = (uint8_t)clip(0, 255, *(p + i));
    }
}
