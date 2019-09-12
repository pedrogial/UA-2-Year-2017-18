set terminal png

set xlabel "Size of arrays"
set ylabel "Millions of program steps"
set yrange [0:]
set xtics ("2¹⁵" 32768, "2²⁰" 1048576, "2²¹" 2097152, "2²²" 4194304, "2²³" 8388608)

####################################
set output "quicksort.png"
set title  "Quicksort"

plot "qs-vs-hs.Msteps" using 1:2 with lines title "random arrays",\
     "qs-vs-hs.Msteps" using 1:4 with lines title "sorted arrays",\
     "qs-vs-hs.Msteps" using 1:6 with lines title "reverse-sorted arrays"
####################################
set output "heapsort.png"
set title  "Heapsort"

plot "qs-vs-hs.Msteps" using 1:3 with lines title "random arrays",\
     "qs-vs-hs.Msteps" using 1:5 with lines title "sorted arrays",\
     "qs-vs-hs.Msteps" using 1:7 with lines title "reverse-sorted arrays"
####################################
set output "qs-vs-hs-RA.png"
set title  "Quicksort versus Heapsort (random arrays)"

y(x)=a1*x*log(x)+b1*x+c1
z(x)=a2*x*log(x)+b2*x+c2

fit y(x) "qs-vs-hs.Msteps" using 1:2 via a1,b1,c1
fit z(x) "qs-vs-hs.Msteps" using 1:3 via a2,b2,c2

plot "qs-vs-hs.Msteps" using 1:2 with lines title "Quicksort",\
     "qs-vs-hs.Msteps" using 1:3 with lines title "Heapsort",\
      y(x) with lines title "fitting Quicksort time values to  nlog(n)+n",\
      z(x) with lines title "fitting Heapsort time values to  nlog(n)+n"
####################################
set output "qs-vs-hs-SA.png"
set title  "Quicksort versus Heapsort (sorted arrays)"

y(x)=a1*x*log(x)+b1*x+c1
z(x)=a2*x*log(x)+b2*x+c2

fit y(x) "qs-vs-hs.Msteps" using 1:4 via a1,b1,c1
fit z(x) "qs-vs-hs.Msteps" using 1:5 via a2,b2,c2

plot "qs-vs-hs.Msteps" using 1:4 with lines title "Quicksort",\
     "qs-vs-hs.Msteps" using 1:5 with lines title "Heapsort",\
      y(x) with lines title "fitting Quicksort time values to  nlog(n)+n",\
      z(x) with lines title "fitting Quicksort time values to  nlog(n)+n"
####################################
set output "qs-vs-hs-RSA.png"
set title  "Quicksort versus Heapsort (reverse-sorted arrays)"

y(x)=a1*x*log(x)+b1*x+c1
z(x)=a2*x*log(x)+b2*x+c2

fit y(x) "qs-vs-hs.Msteps" using 1:6 via a1,b1,c1
fit z(x) "qs-vs-hs.Msteps" using 1:7 via a2,b2,c2

plot "qs-vs-hs.Msteps" using 1:6 with lines title "Quicksort",\
     "qs-vs-hs.Msteps" using 1:7 with lines title "Heapsort",\
      y(x) with lines title "fitting Quicksort time values to  nlog(n)+n",\
      z(x) with lines title "fitting Quicksort time values to  nlog(n)+n"
####################################