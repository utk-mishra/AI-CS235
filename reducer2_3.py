#!/usr/bin/env python3
"""
reducer.py
"""

import sys

cand1_x=0
cand1_y=0
cand2_x=0
cand2_y=0
cand3_x=0
cand3_y=0
cand1_cnt=0
cand2_cnt=0
cand3_cnt=0

for line in sys.stdin:
#read line and split by comma
#recall, we used comma as delimiter in mapper
    line = line.strip().split(',')
    #get the key and val, in this case
    #word is the key and count is the val
    point0, point1, cand0, cand1, label = float(line[0]), float(line[1]), float(line[2]), float(line[3]), int(line[4])
    if label==1:
        cand1_x+=point0
        cand1_y+=point1
        cand1_cnt+=1
    elif label==2:
        cand2_x+=point0
        cand2_y+=point1
        cand2_cnt+=1
    else:
        cand3_x+=point0
        cand3_y+=point1
        cand3_cnt+=1

print(f'{cand1_x/cand1_cnt},{cand1_y/cand1_cnt}')
print(f'{cand2_x/cand2_cnt},{cand2_y/cand2_cnt}')
print(f'{cand3_x/cand3_cnt},{cand3_y/cand3_cnt}')