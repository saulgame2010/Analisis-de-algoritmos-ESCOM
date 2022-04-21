%%VALORES DE X
x=[100 1000 5000 6000 7000 10000 20000 30000 40000 50000 100000 200000 300000 400000 500000 600000 700000 800000 900000 1000000];
 
%%VALORES DE Y = F(x)
y=[0.0000181198 0.0013468266 0.1684110165 0.1977450848 0.1977450848 0.1961019039 0.6910150051 1.5014197826 2.6849219799 4.1058280468 16.2450020313 66.8964540958 147.9996249676 266.2399590015 418.1758389473 600.2635281086 816.3263509274 1069.9553780556 1350.5419118404 1678.7060060501];

%%OBTENER UN POLINOMIO QUE SE AJUSTE A LOS PUNTOS X Y Y
n=8; 				%%GRADO DEL POLINOMIO DE AJUSTE
p=polyfit(x,y,n)	%%FUNCION QUE REALIZA EL AJUSTE POLINOMIAL

%%DONDE SE COMPARA LA CURVA AJUSTADA CONTRA LOS 
%%VALORES EXPERIMENTALES
xi=linspace(100,1000000);	%%ESPACIO DE PUNTOS PARA Xi
z=polyval(p,xi);				%%EVALUACION DEL POLINOMIO P EN EL ESPACIO Xi

%%SE CREA UN ESPACIO PARA REALIZAR UNA GRAFICA EN 
%%SE REALIZA LA FIGURA CORRESPONDIENTE
figure(1);
plot(x,y,'o',xi,z,'-'),grid;
ylabel('F(Y)');
xlabel('X');
title('Ajuste de minimos cuadrados');