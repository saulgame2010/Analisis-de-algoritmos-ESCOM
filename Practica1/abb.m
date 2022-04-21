%%VALORES DE X
x=[100 1000 5000 6000 7000 10000 20000 30000 40000 50000 100000 200000 300000 400000 500000 600000 700000 800000 900000 1000000]; 
%%VALORES DE Y = F(x)
y=[0.120420456 0.000800848 0.008854151 0.006333113 0.109780073 0.330989838 1.30 1.59];

%%OBTENER UN POLINOMIO QUE SE AJUSTE A LOS PUNTOS X Y Y
n=8; 				%%GRADO DEL POLINOMIO DE AJUSTE
p=polyfit(x,y,n)	%%FUNCION QUE REALIZA EL AJUSTE POLINOMIAL

%%DONDE SE COMPARA LA CURVA AJUSTADA CONTRA LOS 
%%VALORES EXPERIMENTALES
xi=linspace(100,500000);	%%ESPACIO DE PUNTOS PARA Xi
z=polyval(p,xi);				%%EVALUACION DEL POLINOMIO P EN EL ESPACIO Xi

%%SE CREA UN ESPACIO PARA REALIZAR UNA GRAFICA EN 
%%SE REALIZA LA FIGURA CORRESPONDIENTE
figure(1);
plot(x,y,'o',xi,z,'-'),grid;
ylabel('F(Y)');
xlabel('X');
title('Ajuste de minimos cuadrados');
