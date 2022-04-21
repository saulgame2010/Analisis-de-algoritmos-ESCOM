x = [ 10 100 200 300 400 500 600 1000];
 y = [ 0.8447 1.4494 3.5760 10.9288 23.1908 44.6963 114.9254 344.6238];
 loglog(x,y,'bd');
 axis([0 1000 0 1000])
 p = polyfit(log(x),log(y),1)
 z = polyval(p,log(x));
 hold on;loglog(x,exp(z))