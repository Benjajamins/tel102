Update 30/11/2024- José Flores

Hice el Menú principal, teniendo los widgets funcionales de:

-Botón de máximo o mínimo: Si es máximo, el atributo maxmin se vuelve True, si es mínimo, False.

-Botón de Salir: Cierra ventana.

-QLineEdit: Casilla para que el usuario escriba su función.

-Botón de calcular: Botón que abre la ventana con el gráfico de máximos o mínimos.

Si el input es incorrecto(vacío o con carácteres no válidos) se abre un QmessageBox con la "retroalimentación" y cierra la ventana.

Si es correcto, se abre la ventana del gráfico.

            
Falta destacar que falta implementar completamente el botón del registro, como también volver un poco más amena la interfaz.
-Falta también implementar el rango para modelar la función.

Imagen de la interfaz:


![image](https://github.com/user-attachments/assets/f737de4c-24e2-42ef-9f95-9d094c90f124)


(También, abajo a la derecha se puede ver la fecha como prueba)



Ventana secundaria:
-Lo que hice fue que pudiera heredar, a través de su constructor, el texto que había en la mainwindow y si maxmin era true o false.
Falta implementar todo el gráfico y menú.



Update 02/12/2024

Desarrollé la ventana de gráficos:

-El gráfico se genera inicialmente con el método iniciarGrafico()

-El gráfico funciona de forma dinámica con los botones que determinan el rango del X o Y.

-Se intentó seguir implementando los puntos, pero hubieron muchos errores.

-Se cambiaron distintos elementos de la clase polinomio como métodos y atributos para facilitar el cálculo y desarrollo de la ventana del gráfico.

Falta desarrollar los puntos y el sistema de registro, que no se ve complicado.

Imagen de la interfaz:

![image](https://github.com/user-attachments/assets/c35e86b7-70a1-4ea3-9f17-8728850b9e44)


(También, abajo a la derecha se puede ver la fecha como prueba)

