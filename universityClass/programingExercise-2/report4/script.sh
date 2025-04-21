#!/bin/bash

file='./l-select'

num_array=(10000000 20000000 30000000 40000000 50000000 60000000 70000000 80000000 90000000 100000000)


echo $file の実行時間の平均
for num in "${num_array[@]}"; do
    target_num=$((10000))
    total_time=0
    for i in {1..10}; do
        output=$($file 'for-select.dat' $num $target_num 2>&1)

    time=$(echo "$output" | grep -oP '実行時間 = \K[0-9.]+')
        total_time=$(echo "scale=6; $total_time + $time" | bc)

    done
    av_time=$(echo "scale=6; $total_time / 10" | bc)
    echo "$num 個のデータ中 $target_num 番目を調べる実行時間の平均 $av_time"
done