set xrange [0:6000]
set yrange [0:2]
set xlabel "Amount data"
set ylabel "Time, s"
set key right top inside
plot "InsertSortRandL.txt", "InsertSortRightL.txt", "InsertSortReversL.txt"
