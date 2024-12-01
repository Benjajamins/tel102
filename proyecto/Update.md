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
