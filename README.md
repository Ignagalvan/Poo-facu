Repsoitorio poo 2024 ignacio galvan.  
  
Ejercicio 1:  
  
Instalar Qt. Lo cual incluye las herramientas de compilación C++, la biblioteca Qt y Qt Creator.  
Crear un primer programa que muestre por la consola de QtCreator 10 números aleatorios en el intervalo [ 2, 20 ]
Cada vez que se ejecute el programa, los números deberán ser aleatorios y distintos en cada ejecución.

Ejercicio 2:  
Objetivo: Familiarización con librerías, archivos DLL y variable de entorno PATH. Tener presente la distinción entre biblioteca, librería y library.  
Descripción: Crear un programa simple en C++ que utilice una librería externa (en forma de archivo DLL o similar en otros sistemas operativos) y que haga uso de la variable de entorno PATH para ubicar dicha librería.  
Pasos a seguir:  
Crear una librería en C++ y compilarla como un archivo DLL 8o similar en otros sistemas operativos). Programar en la librería una función que imprima un mensaje simple, como "Hola, desde la biblioteca".  
Crear un programa principal en C++ que utilice esta librería. Hacer referencia (o linkear) a la librería de manera dinámica.  
Incluir la ruta al archivo DLL en la variable de entorno PATH.  
En el programa principal, cargar la librería, invocar a la función y mostrar el mensaje.  

Ejercicio 3:  
Elija un nombre para su propio espacio de nombres para todo lo que se haga en este asignatura.  
Luego de elegido el nombre para su namespace, defina una función dentro de ese namespace para devolver el número de versión junto con la fecha de la última actualización de la biblioteca  
QString getVersion();  // Devuelve un texto como "v0.0.1 - 20240318"  

  
